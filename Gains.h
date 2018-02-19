#ifndef DEF_Gain
#define DEF_Gain

#include <iostream>
#include <string>
#include "Arme.h"


class Gain
{
public:
	Gain();
	void gains();
	void Experience(float *vieJoueur, float* vieMaxJoueur, int *niveauJoueur, int *experienceJoueur, int gainExperience);
	void GainOR(int *orJoueur, int gainOr);
	void GainArme(std::string *nomArme, int *degatArme, int numero, Arme &ciblearme);
	

private:

	

};
#endif;
