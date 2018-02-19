#include "Personnage.h"


using namespace std;



Personnage::Personnage()
{
	m_vieMax = 100;
	m_vie = 100;
	m_mana = 0;
	Arme Arme;
	Potion Potion;
	changerArme(0, Arme);
	m_efficacePopo = 1;
	m_degats = 3;
	m_defense = 3;
	m_OR = m_experience = m_niveau = 0;
	nombrePotion[0] = 5;
	nombrePotion[1] = 3;
	nombrePotion[2] = 2;
	nombrePotion[3] = 1;
	
}

Personnage::~Personnage()
{

}

void Personnage::recevoirDegats(int nbDegats, int bonus, string nomAttaque)
{
	int nombreDegat = 0;
	if (nomAttaque == "Defense")
	{
		nombreDegat = ((nbDegats + bonus) - 2 * (m_defense + m_defenseArmure + m_defenseArmure * m_niveau));
		if (nombreDegat > 0)
			m_vie -= ((nbDegats + bonus) - (m_defense + m_defenseArmure + m_defenseArmure * m_niveau));
	}
	else
	{
		nombreDegat = ((nbDegats + bonus) - (m_defense + m_defenseArmure + m_defenseArmure * m_niveau));
		if (nombreDegat > 0)
			m_vie -= ((nbDegats + bonus) - (m_defense + m_defenseArmure + m_defenseArmure * m_niveau));
	}

	if (m_vie <= 0)
		m_vie = 0;
}

void Personnage::attaquer(Adversaire &cibleb, string nomAttaque)
{	
	cibleb.recevoirDegats(m_degatArme, m_degats + (m_degats * m_niveau), nomAttaque);

}

void Personnage::boirePotionDeVie(string nomPotion, Potion &ciblePotion)
{
	ciblePotion.boire(nomPotion, &m_vie, &m_efficacePopo, m_niveau, nombrePotion );

	if (m_vie > m_vieMax)
	{
		m_vie = m_vieMax;
	}
}

void Personnage::changerArme(int numero, Arme &ciblea)
{
	ciblea.changer(numero, &m_nomArme, &m_degatArme);
}

bool Personnage::estVivant()
{
	return (m_vie > 0);
}

void Personnage::afficherEtat()
{
	cout << "Vie : " << m_vie << endl;
	cout << "Expérience : " << m_experience << "\n";
	cout << "Argent : " << m_OR << "\n";
	cout << "Arme : " << m_nomArme << " (Degats : " << m_degatArme << ")" << endl<<"\n";
	cout << "Petite potion : " << nombrePotion[0] << "\n";
	cout << "Moyenne potion : " << nombrePotion[1] << "\n";
	cout << "Grande potion : " << nombrePotion[2] << "\n";
	cout << "Potion Miraculeuse : " << nombrePotion[3] << "\n";
}

bool Personnage::fullLife()
{
	return (m_vie == m_vieMax);
}

void Personnage::sortirArme(int numero, Gain &ciblegain, Arme &ciblearme)
{
	ciblegain.GainArme(&m_nomArme, &m_degatArme, numero, ciblearme);
}

void Personnage::sortirPotion(int nouvellePotion, int nombreNouvellePotion)
{
	nombrePotion[nouvellePotion] += nombreNouvellePotion;
}

void Personnage::sortirArgent(int gainOr, Gain &cible3gain)
{
	cible3gain.GainOR(&m_OR, gainOr);
}

void Personnage::sortirExperience(int gainExperience, Gain &cible4gain)
{
	cible4gain.Experience(&m_vie, &m_vieMax, &m_niveau, &m_experience, gainExperience);
}

// En dessous, sortir pour affichage
int Personnage::sortirNiveau()
{
	return m_niveau;
}

float Personnage::sortirPV()
{
	return m_vie;
}

float Personnage::sortirPVmax()
{
	return m_vieMax;
}

string Personnage::sortirnomArme()
{
	return m_nomArme;
}

int Personnage::sortirdegatArme()
{
	return m_degatArme;
}

int Personnage::sortirxp()
{
	return m_experience;
}

int* Personnage::sortirNombrePotion()
{
	return nombrePotion;
}

void Personnage::restart()
{
	m_vieMax = 100;
	m_vie = 100;
	m_mana = 0;
	Arme Arme;
	Potion Potion;
	changerArme(0, Arme);
	m_efficacePopo = 1;
	m_degats = 3;
	m_defense = 3;
	m_OR = m_experience = m_niveau = 0;
	nombrePotion[0] = 5;
	nombrePotion[1] = 3;
	nombrePotion[2] = 2;
	nombrePotion[3] = 1;
}






Adversaire::Adversaire(int niveau) // Loup
{
	m_AvieMax = 30+(5*niveau);
	m_Avie = 30+(5*niveau);
	m_Amana = 0;
	m_AnomArme = "Aucune arme";
	m_AdegatArme = 0;
	m_AnomArmure = "Aucune armure";
	m_AdefenseArmure = 0;
	m_AefficacePopo = 0.0;
	m_Adegats = 12+(0.5*niveau);
	m_Adefense = 3+(0.5*niveau);

}

Adversaire::Adversaire(int nom, int niveau) // Squelette
{
	m_AvieMax = 50+(10*niveau);
	m_Avie = 50+(10*niveau);
	m_Amana = 0;
	m_AnomArme = "Epee";
	m_AdegatArme = 15;
	m_AnomArmure = "Fer";
	m_AdefenseArmure = 6;
	m_AefficacePopo = 0.7;
	m_Adegats = 1+(1*niveau);
	m_Adefense = 1+(0.5*niveau);
	nombrePotion[0] = 2;
	nombrePotion[1] = 1;
	nombrePotion[2] = 0;
	nombrePotion[3] = 0;

}

Adversaire::Adversaire(string nom, int niveau) // Dragon
{
	m_AvieMax = 300+(15 * niveau);
	m_Avie = 300 + (15 * niveau);
	m_Amana = 0;
	m_AnomArme = "Aucune Arme";
	m_AdegatArme = 0;
	m_AnomArmure = "Aucune Armure";
	m_AdefenseArmure = 0;
	m_AefficacePopo = 0.0;
	m_Adegats = 35 + (5 * niveau);
	m_Adefense = 50 + (9 * niveau);
}

Adversaire::~Adversaire()
{

}

void Adversaire::recevoirDegats(int nbDegats, int bonus, string nomAttaque)
{
	int degat = 0;
	if (nomAttaque == "Tranche")
	{
		degat = ((nbDegats + bonus) - (m_Adefense + m_AdefenseArmure));
		if (degat > 0)
			m_Avie -= degat;
	}
	else if (nomAttaque == "Coup de tete")
	{
		degat = 0.3*((nbDegats + bonus) - (m_Adefense + m_AdefenseArmure));
		if (degat > 0)
			m_Avie -= degat;
	}
	else
	{
		degat = 0.6*((nbDegats + bonus));
		if (degat > 0)
			m_Avie -= degat;
	}

	if (m_Avie <= 0)
		m_Avie = 0;
}

void Adversaire::attaquer(Personnage &cible4, string nomAttaque)
{
	cible4.recevoirDegats(m_AdegatArme, m_Adegats, nomAttaque);

}

void Adversaire::boirePotionDeVie(string nomPotion, Potion &cible2Potion)
{
	cible2Potion.boire(nomPotion, &m_Avie, &m_AefficacePopo, 0, nombrePotion);

	if (m_Avie > m_AvieMax)
	{
		m_Avie = m_AvieMax;
	}
}


bool Adversaire::estVivant()
{
	return (m_Avie > 0);
}

void Adversaire::afficherEtat()
{
	cout << "Vie : " << m_Avie << endl;
	//cout << "Mana : " << m_mana << endl;
	cout << "Arme : " << m_AnomArme << " (Degats : " << m_AdegatArme << ")" << endl;
	cout << "Armure : " << m_AnomArmure << " (Defense : " << m_AdefenseArmure << ")" << "\n" << "\n";
}

bool Adversaire::fullLife()
{
	return (m_Avie == m_AvieMax);
}

float Adversaire::sortirPV()
{
	return m_Avie;
}

float Adversaire::sortirPVmax()
{
	return m_AvieMax;
}