#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;
class Card {

protected:
    const string RESET = "\033[0m"; // Código ANSI para resetear el color
    const int WIDTH = 6; // Ancho fijo para renderizar las cartas
    const int HEIGHT = 3; // Alto fijo para renderizar las cartas
    const string COLORS_N[4] = {"Rojo", "Amarillo", "Azul", "Verde"}; // Colores (CODIGOS ANSI) para cartas normales
    const string COLORS_F[4] = {"Rosa", "Naranja", "Turquesa", "Violeta"};// Colores (CODIGOS ANSI) para cartas flipped
    
    string simbolo[2]; // Simbolo que tendra la carta dependiendo si es normal o flipped
    const int INDEX_COLOR; // Índice para acceder a los colores en los arrays COLORS_N y COLORS_F
    int indexColorFlip; // Índice para acceder a los colores en los arrays COLORS_N y COLORS_F cuando la carta está flipped
    int HandIndex;

    string actualColor; // Color actual de la carta
    string acutalSymbol; // Representación visual de la carta

    bool hasFlip = false; // Indica a la carta si se esta jugando en modo flip o no
    bool flipped = false; // Indica si la carta esta actualmente flipped o no

    /**
     * Función para centrar el texto dentro de la carta. Si el texto es mayor a 2 caracteres, se recorta a 2 caracteres.
     * Luego se calculan los espacios necesarios a la izquierda y derecha para centrar el texto y se devuelve el texto centrado con los espacios correspondientes.
     * @param text El texto a centrar.
     */
    string center(string& text);

    /**
     * Función para cambiar el estado de flip de la carta. Si la carta está flipped, se cambia a normal y viceversa. 
     * Además, se actualiza el símbolo y el color de la carta según su nuevo estado.
     */
    virtual void changeFlip() = 0;
    
public:

    Card(string& symbol, bool hasFlip, int iColor);
	virtual ~Card() = 0;
    void setSimbolo(string& sim, int index);

    /**
     * Funcion para dibujar la carta en la consola.
     * @param index El índice de la línea a renderizar (0 para la primera línea, 1 para la segunda línea, 2 para la tercera línea).
     * @param valor El valor que se mostrará en la carta (por ejemplo, el número o símbolo de la carta).
     * @return La cadena de texto que representa la línea de la carta con el valor centrado y el color correspondiente.
     */
    string renderLine(int index, string& valor);

    
    /**
     * Metodos que manejan el estado flip del la carta.
     */
    void setFlipped(bool flipped);
    bool isFlipped();
    void setFlipAtributes(int colorFlip, string& simbolFlip);
    void flip();

    /**
     * Metodos para manejar el indice en la mano del jugador
     */
    void setHandIndex(int newIndex);
    int getHandIndex();
};

#endif
