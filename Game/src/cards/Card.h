#include <string>
#ifndef CARD_H
#define CARD_H

using namespace std;
class Card {

private:
    const int width = 6; // Ancho fijo para renderizar las cartas
    const int height = 3; // Alto fijo para renderizar las cartas

    string center(string& text);

public:
	virtual ~Card() = 0;
    
    string renderLine(int index, string& valor);

};

#endif
