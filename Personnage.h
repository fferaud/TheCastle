#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include "Arme.h"
#include "Gains.h"

//#include "Adversaire.h"
//#include "Combat.h"

class Adversaire;
class Personnage
{
public:

	Personnage();
	~Personnage();
	void recevoirDegats(int nbDegats, int bonus2, std::string nomAttaque);
	void attaquer(Adversaire &cibleb, std::string nomAttaque);
	void boirePotionDeVie(std::string nomPotion, Potion &ciblePotion);
	void changerArme(int numero, Arme &ciblea);
	bool estVivant();
	void afficherEtat();
	bool fullLife();
	void sortirArme(int numero, Gain &ciblegain, Arme &ciblearme);
	void sortirPotion(int nouvellePotion, int nombreNouvellePotion);
	void sortirArgent(int gainOr, Gain &cible3gain);
	void sortirExperience(int gainExperience, Gain &cible4gain);
	int sortirNiveau();
	float sortirPV();
	float sortirPVmax();
	std::string sortirnomArme();
	int sortirdegatArme();
	int sortirxp();
	int* sortirNombrePotion();
	void restart();


private:
	
	float m_vieMax;
	float m_vie;
	float m_mana;
	std::string m_nomArme;
	int m_degatArme;
	std::string m_nomArmure;
	int m_defenseArmure;
	float m_efficacePopo;
	int m_degats;
	int m_defense;
	int m_OR;
	int m_experience;
	int m_niveau;
	int nombrePotion[4];
};
#endif

#ifndef DEF_ADVERSAIRE
#define DEF_ADVERSAIRE

#include <iostream>
#include <string>
#include "Arme.h "

class Adversaire
{
public:

	Adversaire(int niveau); //Loup
	Adversaire(int nom, int niveau); // Squelette
	Adversaire(std::string nom, int niveau); // Dragon
	~Adversaire();
	void recevoirDegats(int nbDegats, int bonus, std::string nomAttaque);
	void attaquer(Personnage &cible4, std::string nomAttaque);
	void boirePotionDeVie(std::string nomPotion, Potion &cible2Potion);
	bool estVivant();
	void afficherEtat();
	bool fullLife();
	float sortirPV();
	float sortirPVmax();

private:

	float m_AvieMax;
	float m_Avie;
	float m_Amana;
	std::string m_AnomArme;
	int m_AdegatArme;
	std::string m_AnomArmure;
	int m_AdefenseArmure;
	float m_AefficacePopo;
	int m_Adegats;
	int m_Adefense;
	int nombrePotion[4];
};

#endif


