#ifndef DEF_RATIOGAIN
#define DEF_RATIOGAIN

#include <iostream>
#include <string>
#include "Personnage.h"
#include "Arme.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Gains.h"


class Ratio
{

public :

	Ratio();
	int rand_a_b(int a, int b);
	int GainArme(Personnage &ciblepersonnage, Gain &ciblegain, Arme &ciblearme);
	void GainPotion(Personnage &ciblepersonnage);
	void GainOr(Personnage &ciblepersonnage, Gain &ciblegain);
	void GainExperience(Personnage &ciblepersonnage, Gain &ciblegain, int numeroCombat);
	bool* sortirArmeEnPossession();
	int GainArmeLegende(Personnage &ciblepersonnage, Gain &ciblegain, Arme &ciblearme);




private :

		bool armeDejaPossede[21];
		bool dejaEnPossession;




};







#endif