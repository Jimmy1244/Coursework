#pragma once
class Dice
{
public:
	Dice(double *prob);
	~Dice(void);
	int randThrow();
private:
	double probs[6];
};