#include "Arme.h"

using namespace std;

Arme::Arme()
{
	// On cree le tableau d'arme et leur degat pour pouvoir les utiliser
	tableauNomArme[0] = "Dague Bleue";
	tableauNomArme[1] = "Epee Bleue";
	tableauNomArme[2] = "Arme 3";
	tableauNomArme[3] = "Arme 4";
	tableauNomArme[4] = "Belle Epee Bleue";
	tableauNomArme[5] = "Sabre Bleu";
	tableauNomArme[6] = "Flamme Bleu";
	tableauNomArme[7] = "Dague Verte";
	tableauNomArme[8] = "Lame Tordue Verte";
	tableauNomArme[9] = "Arme 10";
	tableauNomArme[10] = "Flamme Verte";
	tableauNomArme[11] = "Arme 12";
	tableauNomArme[12] = "Epee Dragon Verte";
	tableauNomArme[13] = "Sabre Vert";
	tableauNomArme[14] = "Dague Feu";
	tableauNomArme[15] = "Serpe Feu";
	tableauNomArme[16] = "Arme 17";
	tableauNomArme[17] = "Arme 18";
	tableauNomArme[18] = "Epee Masse";
	tableauNomArme[19] = "Epee Feu";
	tableauNomArme[20] = "Armageddon";

	tableauDegatArme[0] = 15;
	tableauDegatArme[1] = 20;
	tableauDegatArme[2] = 22;
	tableauDegatArme[3] = 30;
	tableauDegatArme[4] = 25;
	tableauDegatArme[5] = 40;
	tableauDegatArme[6] = 100;
	tableauDegatArme[7] = 20;
	tableauDegatArme[8] = 30;
	tableauDegatArme[9] = 35;
	tableauDegatArme[10] = 100;
	tableauDegatArme[11] = 40;
	tableauDegatArme[12] = 120;
	tableauDegatArme[13] = 45;
	tableauDegatArme[14] = 15;
	tableauDegatArme[15] = 20;
	tableauDegatArme[16] = 35;
	tableauDegatArme[17] = 40;
	tableauDegatArme[18] = 100;
	tableauDegatArme[19] = 25;
	tableauDegatArme[20] = 150;
}

void Arme::changer(int numero, string *nomArme, int *degatArme)
{
	
		*nomArme = tableauNomArme[numero];
		*degatArme = tableauDegatArme[numero];
	
}

Potion::Potion()
{
	tableauNomPotion[0] = "Petite";
	tableauNomPotion[1] = "Moyenne";
	tableauNomPotion[2] = "Grande";
	tableauNomPotion[3] = "Miraculeuse";
	tableauRegenPotion[0] = 15;
	tableauRegenPotion[1] = 35;
	tableauRegenPotion[2] = 55;
	tableauRegenPotion[3] = 80;
	m_regen =  0;

}

void Potion::boire(string nom, float *vie, float *efficacePopo, int niveau, int* nombrePotion)
{
	*vie += 0;
	int regen = 0;
	bool retrouve = false;
	int i = 0;
	while (!retrouve && i <= 3)
	{
		if (nom == tableauNomPotion[i])
		{
			regen = tableauRegenPotion[i];
			retrouve = true;
			nombrePotion[i] -= 1;
		}
		else
			i += 1;
	}
	*vie += (regen * *efficacePopo + (regen * (*efficacePopo * niveau))/10);

}