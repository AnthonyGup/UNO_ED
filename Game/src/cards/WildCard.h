#ifndef WILDCARD_H
#define WILDCARD_H

#include "Card.h"

class WildCard : public Card {
protected:
    int chosenColor;
    int flipChosenColor;
    bool hasFlip;

public:
    WildCard();
    ~WildCard() override;

    virtual void applyEffect() = 0;

    void setChosenColor(int color);
    int getChosenColor();

    void setFlipChosenColor(int color);
    int getChosenColor(bool flipped);

    void enableFlipSide();
    bool hasFlipSide();
};

#endif
