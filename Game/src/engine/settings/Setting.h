#ifndef SETTING_H
#define SETTING_H

class Setting {
    private:
        //Stacking
            bool plusTwoStacking = true;
            bool plusFourStacking = true;
        //+4 dare
            bool plusFourDare = true;
        //Steal mode
            int optionStealMode = 0; //0: steal only one card, 1: steal until can play
        //Shout UNO
            bool soutUno = true;
        //Win whit black card

    public:
        // Constructores
        Setting(); // Constructor por defecto
        Setting(bool plusTwo, bool plusFour, bool dare, int stealMode, bool uno); // Constructor con parámetros

        //Stacking
            bool getPlusTwoStacking();
            void setPlusTwoStacking(bool value);
            bool getPlusFourStacking();
            void setPlusFourStacking(bool value);
        //+4 dare
            bool getPlusFourDare();
            void setPlusFourDare(bool value);
        //Steal mode
            int getOptionStealMode();
            void setOptionStealMode(int value);
        //Shout UNO
            bool getSoutUno();
            void setSoutUno(bool value);
        //Win whit black card

};

#endif