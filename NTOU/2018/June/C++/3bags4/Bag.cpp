#include "Bag.h"
#include "Ball.h"
#include <cstdlib> // rand()

Bag::Bag(Ball::Colors color1, Ball::Colors color2,  Ball::Colors color3)
    : m_numberOfBalls(3)
{
    m_balls[0] = new Ball(color1);
    m_balls[1] = new Ball(color2);
	m_balls[2] = new Ball(color3);
}

Bag::~Bag()
{
    delete m_balls[0];
    delete m_balls[1];
	delete m_balls[2];
}

Ball *Bag::getABall()
{
    if (m_numberOfBalls == 0)
        return 0;
    else if (m_numberOfBalls == 1)
    {
        m_numberOfBalls = 0;
        return m_balls[0];
    }

	else if (m_numberOfBalls == 2)
    {
        int iPicked = rand()%2;
        Ball *pickedBall = m_balls[iPicked];
        if (iPicked == 0)
        {
            m_balls[0] = m_balls[1];
            m_balls[1] = pickedBall;
        }
        m_numberOfBalls = 1;
        return pickedBall;
    }
    else
    {
        int iPicked = rand()%3;
        Ball *pickedBall = m_balls[iPicked];
        if (iPicked == 0)
        {
            m_balls[0] = m_balls[1];
			m_balls[1] = m_balls[2];
            m_balls[2] = pickedBall;
        }
		else if(iPicked == 1){
			m_balls[1] = m_balls[2];
            m_balls[2] = pickedBall;
		}
        m_numberOfBalls = 2;
        return pickedBall;
    }
}

void Bag::putBallsBack()
{
    m_numberOfBalls = 3;
}