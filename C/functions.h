#ifndef FUNCTIONS_H

  #define FUNCTIONS_H

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>


  // Estructuras utilizadas

  typedef struct {

    int columna;
    int fila;

  } Casilla;


  typedef struct {

    int x;
    int y;

  } VectorDireccion;


  typedef struct {

    char *nombreJugador;
    char colorJugador;

  } Jugador;


  typedef struct {

    char **casillas;
    int dimension;

  } Tablero;


  typedef struct {

    Casilla *coordenadas;
    int cantidad;

  } Volteadas;


  // Prototipos de funciones en functions.c

  /*
  crearCasilla toma dos enteros y nos devuelve una estructura
  de tipo casilla con sus dos campos inicializados con los valores
  pasados.
  */
  Casilla crearCasilla(int columna, int fila);

  /*
  crearVector toma dos enteros y nos devuelve una estructura
  de tipo VectorDireccion con sus dos campos inicializados con los valores
  pasados.
  */
  VectorDireccion crearVector(int x, int y);

  /*
  vertificarCantidadArgumentos toma la cantidad de argumentos
  pasados al programa y verifica que sean la cantidad correcta.
  */
  int verificarCantidadArgumentos(int cantidadArgumentos);

  /*
  leerInformacionPreliminar se encarga de tomar la informacion del
  archivo y verificarla. En caso de que la informacion sea correcta,
  almacena dicha informacion en las variables que referencian los
  punteros pasados.
  Si consigue pasar la informacion a las variables, devuelve 1.
  Si no consigue hacerlo, devuelve 0.
  */
  int leerInformacionPreliminar(Jugador *jugadores, char *colorInicio, FILE *archivoJuego);

  /*
  verificarInformacionPreliminar toma el color de los jugadores y el 
  color de inicio leido del archivo y nos determina si todos estos
  valores se encuentren dentro de las opciones correctas.
  */
  int verificarInformacionPreliminar(char *color1, char *color2, char *colorI);

  /*
  verificarColor toma un color y verifica que se encuentre dentro de
  las opciones correctas. En caso de verificar devuelve 1, y en caso
  contrario devuelve 0.
  */
  int verificarColor(char *colorJugador);

  /*
  coloresJugadoresDistintos toma los dos colores de los jugadores y 
  determina si estos son distintos. En caso de serlo devuelve 1, si no
  devuelve 0.
  */
  int coloresDistintos(char *color1, char *color2);

  /*
  partidaTerminada toma la cantidad de fichas colocadas por color, las
  jugadas realizadas, y los jugadores, y nos determina si la partida ya termino,
  o si se puede seguir jugando. Va a verificar que:
  - No hayamos colocado todas las fichas.
  - Ningun jugador se haya quedado sin fichas.
  - No se haya salteado dos veces el turno de manera consecutiva.
  Si la partida no termino devuelve 1, si no 0.
  */
  int partidaTerminada(int *cantidadFichasColor, Casilla *jugadasRealizadas, Jugador *jugadores);

  /*
  finLectura toma el puntero que devuelve la funcion fgets, y mientras dicho
  puntero no sea null (es decir que no se termino de leer el achivo), devolvera
  1, en caso contrario devuelve 0.
  */
  int finLectura(char *verificadorLectura);

  /*
  jugadaVerifica toma la jugada que se leyo, el turno actual y el tablero y los jugadores, 
  y nos determina si la jugada leida es una jugada correcta. En caso de serlo retorna 1
  y en caso contrario devuelve 0.
  */
  int jugadaVerifica(char *jugada, char turnoActual, Tablero *tableroJuego, Volteadas *fichasVolteadas, Jugador * jugadores);

  /*
  partidaIncompleta toma el verificador de lectura, la cantidad de fichas de cada
  color y las jugadas realizadas, y se encarga de determinar si la partida quedo
  a medio terminar, para asi poder determinar si se debe generar el archivo para 
  continuar con la partida en el programa de Python.
  */
  int partidaIncompleta(char *verificadorLectura, int *cantidadFichasColor, Casilla *jugadasRealizadas);

  /*
  dobleSaltoTurno toma las jugadas y determina si se hizo un doble salto de turno.
  En el caso de que eso ocurra devuelve 1, en caso contrario devuelve 0.
  */
  int dobleSaltoTurno(Casilla *jugadasRealizadas);

  /*
  existenJugadasPosibles toma el turno actual, y el tablerod de juego, y determina
  si existen jugadas posibles con dichas condiciones.
  */
  int existenJugadasPosibles(char turnoActual, Tablero *tableroJuego);

  /*
  verificarFormato toma la jugada realizada y nos determina si cumple con el formato
  estipulado. En caso de serlo devuelve 1 en caso contrario devuelve 0.
  */
  int verificarFormato(char *jugada);

  /*
  verificarLargo se encarga de tomar la jugada y determinar si cumple con el largo
  que debe tener. En caso de serlo devuelve 1, en caso contrario devuelve 0.
  */
  int verificarLargo(char *jugada);

  /*
  verificarRango toma la jugada realizada, y el tamanio del tablero, nos determina
  si la jugada se encuentra dentro del rango del tablero.
  */
  int verificarRango(char *jugada, int tamTablero);

  /*
  ocupada toma la jugada realizada y el tablero de juego, y nos determina si dicha
  casilla se encuentra ocupada. En caso de estarlo devuelve 1, si no 0. 
  */
  int ocupada(Casilla jugada, char **tableroJuego);

  /*
  convertirJugada toma la jugada realizada y el tamanio del tablero, y nos devuelve
  la conversion de la jugada con la que trabajaremos en el programa, que es de tipo
  Casilla.
  */
  Casilla convertirJugada(char *jugada, int tamTablero);

  /*
  cambiarTurno toma el color del turno actual y se encarga de devolvernos
  el color del turno opuesto. Es decir:
  - Si recibe 'B' devuelve 'N'
  - Si recibe 'N' devuelve 'B'
  */
  char cambiarTurno(char turnoActual);

  /*
  agregarJugada toma la jugada agregada y las jugadas realizadas, y 
  la agrega como la ultima jugada hecha.
  */
  void agregarJugada(Casilla jugadaAgregada, Casilla *jugadasRealizadas);

  /*
  buscarArray toma un objetivo a encontrar, un array y el tamanio de dicho array,
  nos determina si dicho obetivo es un elemento del array. En caso de serlo devuelve 1,
  si no 0.
  */
  int buscarArray(char objetivo, char *arrayValores, int tamArray);

  /*
  fichasVolteadaJugada toma la jugada realizada, el turno actual, y el tablero de
  juego. Si luego de analizar todas las direcciones y sentidos, 
  se encontro que la jugada realiza volteos, pide memoria dinamicamente para 
  almacenar todas las coordenadas de las fichas que fueron volteadas, y almacena
  dicha direccion en el registroVolteadas.
  */
  int fichasVolteadasJugada(Casilla jugada, char turnoActual, Tablero *tableroJuego, Casilla **registroVolteadas);

  /*
  enRango toma las la casilla analizada, el sentido y la direccion en donde
  nos estamos moviendo, y el tamanio del tablero, y nos determina si la casilla
  que estamos analizando se encuentra dentro del rango para que podamos encontrar
  una ficha que encierre a todas las demas. En caso de que se encuentre en rango, 
  devuelve 1, si no 0.
  */
  int enRango(Casilla casilla, int sentido, VectorDireccion direccion, int tamTablero);

  /*
  copiarCasillas toma el destino de guardado, a partir de donde vamos a guardar,
  el origen de copiado y la cantidad elementos a copiar, y se encarga de realizar
  la copia de datos. 
  */
  void copiarCasillas(Casilla *destino, int inicio, Casilla *origen, int cantidad);

  /*
  almacenarInformacionVolteadas toma el registroVolteadas, y tambien toma las fichas
  que fueron volteadas por la jugada y su cantidad. Luego, dependiendo de si ya se
  le habia asignado una direccion de memoria al registro o no, libera o no la memoria
  y le asigna un nuevo espacio para guardad las nuevas fichasVolteadas.
  */
  void almacenarInformacionVolteadas(Casilla **registroVolteadas, int cantidadVolteadas, Casilla *fichasVolteadas);

  /*
  inicializarTablero toma un tablero de juego y su tamanio y se encarga
  de inicializarlo para poder comenzar a jugar.
  */
  void inicializarTablero(Tablero *tableroJuego, int tamTablero);

  /*
  mostrarTablero toma el tablero de juego actual y se encarga
  de mostrarlo por consola.
  */
  void mostrarTablero(Tablero *tableroJuego);

  /*
  actualizarCantidadFichasColor toma el la cantidad de fichas de cada color, la 
  cantidad de fichas volteadas y el turno actual, y se encarga de actualizar
  la cantidad de fichas de cada uno de los colores.
  */
  void actualizarCantidadFichasColor(int *cantidadFichasColor, int cantidadFichasVolteadas, char turno);

  /*
  voltearFichas toma la jugada que se realizo, las fichas volteadas por dicha
  jugada, el turno actual y el tablero, y se encarga de modificar el tablero en 
  base a la jugada y sus fichas volteadas para dicho turno.
  */
  void voltearFichas(Casilla jugada, Volteadas *fichasVolteadas, char turnoActual, Tablero *tableroJuego);

  /*
  mensajeInicio toma la informacion de los jugadores y el color de inicio y 
  se encarga de mostrarnos por consola la informacion antes de comenzar a jugar.
  */
  void mensajeInicio(Jugador *jugadores, char colorInicio);

  /*
  mensajeGanador toma la cantidad de fichas de ambos colores, y los jugadores , y
  muestra un mensaje por consola en donde dice quien gano, o si hubo un empate.
  */
  void mensajeGanador(int *cantidadFichasColor, Jugador *jugadores);

  /*
  mensajeErrorJugador toma la jugada realizada, el turno del que jugo dicha jugada
  y los jugadores se encarga de mostrarnos un mensaje con la informacion del error.
  */
  void mensajeErrorJugador(char *jugada, char turno, Jugador *jugadores);

  /*
  nombreTurno toma a los jugadores y el color del turno, y nos devuelve la direccion
  de memoria del nombre del jugador correspondiente a dicho color.
  */
  char *nombreTurno(char turno, Jugador *jugadores);

  /*
  generarArchivo el tablero final del juego y el ultimo turno, y se encarga
  de generar un archivo con la informacion necesaria para continuar la partida
  desde la ultima jugada.
  */
  void generarArchivo(Tablero *tableroFinal, char turnoFinal);

  /*
  liberarMemoriaJugadores se encarga de liberar la memoria pedida dinamicamente para
  los nombres de los jugadores.
  */
  void liberarMemoriaJugadores(Jugador *jugadores);

  /*
  liberarMemoriaVolteadas se encarga de liberar la memoria pedida dinamicamente
  siempre que se haya pedido.
  */
  void liberarMemoriaVolteadas(Volteadas *fichasVolteadas);

  /*
  liberarMemoriaTablero se encarga de liberar la memoria pedida dinamicamente
  para almacenar las fichas colocadas en el tablero.
  */
   void liberarMemoriaTablero(Tablero *tableroJuego);

#endif