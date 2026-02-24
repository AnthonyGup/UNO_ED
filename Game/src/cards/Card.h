#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;
class Card
{

protected:
    const string RESET = "\033[0m";
    const int WIDTH = 6;
    const int HEIGHT = 3;
    const string COLORS_N[4] = {"\033[31m", "\033[33m", "\033[34m", "\033[32m"};
    const string COLORS_F[4] = {"\033[91m", "\033[93m", "\033[96m", "\033[95m"};

    string simbolo[2];
    const int INDEX_COLOR;
    int indexColorFlip;
    int HandIndex;

    string actualColor;
    string acutalSymbol;

    bool hasFlip = false;
    bool flipped = false;

    /**
     * Función para centrar el texto dentro de la carta. Si el texto es mayor a 2 caracteres, se recorta a 2 caracteres.
     * Luego se calculan los espacios necesarios a la izquierda y derecha para centrar el texto y se devuelve el texto centrado con los espacios correspondientes.
     * @param text El texto a centrar.
     */
    string center(const string &text);

    /**
     * Función para cambiar el estado de flip de la carta. Si la carta está flipped, se cambia a normal y viceversa.
     * Además, se actualiza el símbolo y el color de la carta según su nuevo estado.
     */
    virtual void changeFlip() = 0;

public:
    virtual int getColorIndex();
    Card(const string &symbol, bool hasFlip, int iColor);
    virtual ~Card() = 0;
    void setSimbolo(const string &sim, int index);

    /**
     * Funcion para dibujar la carta en la consola.
     * @param index El índice de la línea a renderizar (0 para la primera línea, 1 para la segunda línea, 2 para la tercera línea).
     * @param valor El valor que se mostrará en la carta (por ejemplo, el número o símbolo de la carta).
     * @return La cadena de texto que representa la línea de la carta con el valor centrado y el color correspondiente.
     */
    string renderLine(int index, const string &valor);

    /**
     * Metodos que manejan el estado flip del la carta.
     */
    void setFlipped(bool flipped);
    bool isFlipped();
    void setFlipAtributes(int colorFlip, const string &simbolFlip);
    void flip();

    /**
     * Metodos para manejar el indice en la mano del jugador
     */
    void setHandIndex(int newIndex);
    int getHandIndex();

    int getSortColorIndex();
    string getSortSymbol();
};

#endif
