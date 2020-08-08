#include "Game.h"
#include "Bag.h"
#include "Ball.h"
#include <cstdlib> // rand()
#include <cassert>
#include <ctime>// time()
#include <cstdlib>// srand() system()
#include <iostream>

using namespace std;

Game::Game()
	: m_numberOfBags(4)
{
    m_bags[0] = new Bag(Ball::Red, Ball::Red, Ball::Red);
    m_bags[1] = new Bag(Ball::Red, Ball::Red, Ball::White);
    m_bags[2] = new Bag(Ball::Red, Ball::White, Ball::White);
	m_bags[3] = new Bag(Ball::White, Ball::White, Ball::White);
	double diceProbs1[] = {1.0/6, 1.0/6, 1.0/6, 1.0/6, 1.0/6, 1.0/6};
	dices[0] = new Dice(diceProbs1);
	double diceProbs2[] = {1.0/4, 1.0/6, 1.0/12, 1.0/12, 1.0/6, 1.0/4};
	dices[1] = new Dice(diceProbs2);
}

Game::~Game()
{
    int i;
    for (i=0; i<4; i++)
        delete m_bags[i];
}

Bag *Game::getABag()
{
    return m_bags[rand()%4];
}

void Game::game1(void){
	int   i;
    Game  theGame;
    Bag  *pickedBag;
    Ball *pickedBall;
    int   totalCount = 0;
    int   thirdIsAlsoRed = 0;

    //srand((unsigned int)time(0));
	srand(0);
    for (i=0; i<10000; i++)
    {
        pickedBag = theGame.getABag();
        pickedBall = pickedBag->getABall();
        if (pickedBall->isRed() && pickedBag->getABall()->isRed())
        {
            totalCount++;
            if (pickedBag->getABall()->isRed())
                thirdIsAlsoRed++;
        }
        pickedBag->putBallsBack();
    }
	assert(thirdIsAlsoRed == 2482);
    std::cout << "The probability that remaining ball is red = " 
              << ((double)thirdIsAlsoRed/totalCount) << "\n";
}

void Game::game2(void){
	int   i;
    Game  theGame;
    Bag  *pickedBag;
    Ball *pickedBall;
    int   totalCount = 0;
    int   finalWhite = 0;

    //srand((unsigned int)time(0));
	srand(0);
    for (i=0; i<10000; i++)
    {
        pickedBag = theGame.getABag();//不能直接getBag()因為game2()是static function
        pickedBall = pickedBag->getABall();
		if(pickedBall->isRed()){
			pickedBag->putBallsBack();
			continue;
		}
		else
        {
            totalCount++;
			if((theGame.dices[rand() % 2]->randThrow() % 2) == 0);//回傳為奇數不做事，偶數抽一個
				pickedBag->getABall();
            if (!pickedBag->getABall()->isRed())
                finalWhite++;
        }
        pickedBag->putBallsBack();
    }
	assert(finalWhite == 3393);
    std::cout << "The probability that the ball is white at step 4 = " 
              << ((double)finalWhite/totalCount) << "\n";
}