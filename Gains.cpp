#include "Gains.h"

using namespace std;

Gain::Gain(){}

void Gain::Experience(float *vieJoueur, float* vieMaxJoueur, int *niveauJoueur, int *experienceJoueur, int gainExperience) 
{
	*experienceJoueur += gainExperience;
	if (*experienceJoueur > (200 + (50**niveauJoueur)))
	{
		cout << "level up " << "\n";
		*experienceJoueur -= (200 + (50 * *niveauJoueur));
		*niveauJoueur += 1;
		*vieJoueur += (10 + *niveauJoueur);
		*vieMaxJoueur += (10+ *niveauJoueur);
		cout << "Vous etes maintenant niveau : " << *niveauJoueur << "\n";

	}
}

void Gain::GainOR(int *orJoueur, int gainOr) 
{
	*orJoueur += gainOr;
}

void Gain::GainArme(string *nomArme, int *degatArme, int numero, Arme &ciblearme) 
{
	ciblearme.changer(numero, nomArme, degatArme);
}







