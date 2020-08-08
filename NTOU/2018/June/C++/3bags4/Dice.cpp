#include "Dice.h"
#include<cstdlib>


Dice::Dice(double *prob)
{
	int i;
	for(i = 0; i < 6; i++){
		probs[i] = prob[i];
	}
}


Dice::~Dice(void)
{
}


int Dice::randThrow()
{
	double boundary[6];
	double cumulative = 0;
	int i;
	for(i = 0; i < 6; i++){
		cumulative += this->probs[i];
		boundary[i] = cumulative * RAND_MAX;
	}
	int x = rand();
	for(i = 0; i < 6; i++){
		if(x < boundary[i])
			break;
	}
	return i;
}
