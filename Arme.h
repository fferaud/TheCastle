#ifndef DEF_ARME
#define DEF_ARME

#include <iostream>
#include <string>

class Arme
{
public:

	Arme();
	void changer(int numero, std::string *nomArme, int *degatArme);

private:

	std::string m_nom;
	int m_degats;
	int tableauDegatArme[21];
	std::string tableauNomArme[21];
};

#endif


#ifndef DEF_POTION
#define DEF_POTION

#include <iostream>
#include <string>

class Potion
{
public:

	Potion();
	void boire(std::string nom, float *vie, float *efficacePopo, int niveau, int* nombrePotion);

private:

	int m_regen;
	int tableauRegenPotion[4];
	std::string tableauNomPotion[4];
};



#endif