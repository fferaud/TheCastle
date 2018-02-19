#include "ratiogain.h"
using namespace std;

Ratio::Ratio()
{
	for (int i = 0; i < 21; i++)
		armeDejaPossede[i] = false;
	armeDejaPossede[0] = true;
}

int Ratio::rand_a_b(int a, int b)
{
	return rand() % (b - a) + a;
}

int Ratio::GainArme(Personnage &ciblepersonnage, Gain &ciblegain, Arme &ciblearme)
{
	bool dejaTout = true;
	dejaEnPossession = false;
	int nombreAleatoire = 0;
	do {
		dejaEnPossession = false;
		nombreAleatoire = rand_a_b(1, 20);
		if (nombreAleatoire == 6 || nombreAleatoire == 10 || nombreAleatoire == 12 || nombreAleatoire == 18)
			nombreAleatoire = rand_a_b(1, 20);
			if (armeDejaPossede[nombreAleatoire])
				dejaEnPossession = true;
		
		if (!dejaEnPossession)
		{
			armeDejaPossede[nombreAleatoire] = true;
		}

		for (int i = 0; i < 20; i++)
		{
			if (armeDejaPossede[i] == false)
				dejaTout = false;
		}

		if (dejaTout)
			dejaEnPossession = false;

	} while (dejaEnPossession);
	
	if (dejaTout)
		return 0;
	else
		return nombreAleatoire;
}

bool* Ratio::sortirArmeEnPossession()
{
	return armeDejaPossede;
}

void Ratio::GainPotion(Personnage &ciblepersonnage)
{
	int nombreAleatoire = rand_a_b(0, 6);
	int nombrePotion = rand_a_b(0, 6);
	int nouvellePotion=0;
	if (nombreAleatoire = 5)
	{
		nouvellePotion = 2;
		nombrePotion = 1;
	}
	else if (nombreAleatoire > 2 && nombreAleatoire < 5)
	{
		nouvellePotion = 1;
		if (nombrePotion < 4)
			nombrePotion = 1;
		else
			nombrePotion = 2;
	}
	else if (nombreAleatoire < 3)
	{
		nouvellePotion = 0;
		if (nombrePotion < 3)
			nombrePotion = 1;
		else if (nombrePotion < 5)
			nombrePotion = 2;
		else
			nombrePotion = 3;
	}

	ciblepersonnage.sortirPotion(nouvellePotion, nombrePotion);
}

void Ratio::GainOr(Personnage &ciblepersonnage, Gain &ciblegain)
{
	int nombreAleatoire = rand_a_b(0, 6);
	int Or;
	if (nombreAleatoire = 1)
		Or = 100;
	else if (nombreAleatoire > 1 && nombreAleatoire < 4)
		Or = 50;
	else if (nombreAleatoire >3 && nombreAleatoire < 7)
		Or = 30;

	ciblepersonnage.sortirArgent(Or, ciblegain);
}

void Ratio::GainExperience(Personnage &ciblepersonnage, Gain &ciblegain, int numeroCombat)
{
	int nombreAleatoire = rand_a_b(0, 6);
	int xp=0;
	if (numeroCombat == 1)
		xp = 50 + (10 * nombreAleatoire);
	else if (numeroCombat == 2)
		xp = 100 + (10 * nombreAleatoire);
	else if (numeroCombat == 3)
		xp = 300 + (20 * nombreAleatoire);
	
	ciblepersonnage.sortirExperience(xp, ciblegain);
}

int Ratio::GainArmeLegende(Personnage &ciblepersonnage, Gain &ciblegain, Arme &ciblearme)
{
	int nombreAleatoire = 20;
	armeDejaPossede[nombreAleatoire] = true;

	return nombreAleatoire;
}
