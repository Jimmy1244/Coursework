#ifndef game_h
#define game_h
#include "Dice.h"

class Bag;

class Game
{
public:
    Bag *getABag();
    Game();
    ~Game();
private:
    Bag *m_bags[4];
	const int m_numberOfBags;
	Dice *dices[2];
	int a;
public:
	static void game1(void);
	static void game2(void);
};

#endif