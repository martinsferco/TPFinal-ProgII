#include "main.h"

int main(int argv, char *argc[]) {

  int tamTablero = 8;
  int maxLecturaBuffer = 100;

  // Chequeamos la cantidad de argumentos
  if (! verificarCantidadArgumentos(argv))
    return 1;

  // Abrimos el archivo con el nombre pasado como argumentos
  FILE *archivoJuego = fopen(argc[1], "r");

  // Verificamos que dicho nombre corresponda a un archivo valido
  if (archivoJuego == NULL) {
    printf("ERROR: El nombre pasado no corresponde a ningun archivo. Finalizando el programa...\n");
    return 1;
  }

  Jugador jugadores[2];
  char colorInicio;

  // Leemos la informacion, verificamos que sea correcta, y la almacenamos
  if (! leerInformacionPreliminar(jugadores, &colorInicio, archivoJuego)) {
    fclose(archivoJuego);
    return 1;
  }

  mensajeInicio(jugadores, colorInicio);

  char turnoActual = colorInicio;

  // Creamos e inicializamos el tablero
  Tablero tableroJuego;
  inicializarTablero(&tableroJuego, tamTablero);

  // Aqui almacenamos las jugadas que vamos leyendo del archivo
  char jugadaLeida[maxLecturaBuffer];
  Casilla jugadaConvertida;

  // Leemos la primer jugada
  char *verificadorLectura = fgets(jugadaLeida, maxLecturaBuffer, archivoJuego);

  // Iremos almacenando las dos ultimas jugadas que se realizaron
  Casilla jugadasRealizadas[2] = { crearCasilla(0, 0), crearCasilla(0, 0) };

  // La cantidad de fichas que tiene cada uno de los colores
  int cantidadFichasColor[] = { 2, 2 };

  // Iremos guardando las fichas que fueron volteadas
  Volteadas fichasVolteadas;
  fichasVolteadas.coordenadas = NULL;


  while (! finLectura(verificadorLectura) &&
           jugadaVerifica(jugadaLeida, turnoActual, &tableroJuego, &fichasVolteadas, jugadores)) {

    // Convertimos la jugada
    jugadaConvertida = convertirJugada(jugadaLeida, tamTablero);

    // Agregamos la jugada a nuestro registro de jugadas
    agregarJugada(jugadaConvertida, jugadasRealizadas);

    // Vemos si no se salteo el turno
    if (jugadaConvertida.columna != -1 && jugadaConvertida.fila != -1) {

      voltearFichas(jugadaConvertida, &fichasVolteadas, turnoActual, &tableroJuego);

      actualizarCantidadFichasColor(cantidadFichasColor, fichasVolteadas.cantidad, turnoActual);

    }

    // Cambiamos el turno
    turnoActual = cambiarTurno(turnoActual);

    // Leemos la nueva jugada
    verificadorLectura = fgets(jugadaLeida, maxLecturaBuffer, archivoJuego);

  }

  fclose(archivoJuego);

  // Mostramos el tablero final
  mostrarTablero(&tableroJuego);

  // Vemos si la partida termino o si quedo a medias
  if (finLectura(verificadorLectura) && ! partidaTerminada(cantidadFichasColor,jugadasRealizadas,jugadores)) {
    
    // Si quedo a medias, generamos el archivo correspondiente
    printf("La partida a quedado a medias, no se puede determinar un ganador...\n");
    printf("\nAVISO: Generando archivo para continuacion de partida...\n");
    generarArchivo(&tableroJuego, turnoActual);
  
  }
  
  // Liberamos la memoria pedida dinamicamente
  liberarMemoriaJugadores(jugadores);
  liberarMemoriaVolteadas(&fichasVolteadas);
  liberarMemoriaTablero(&tableroJuego);

  return 0;
}
