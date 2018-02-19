#ifndef DEF_CONSTANTE
#define DEF_CONSTANTE

#include <iostream>
#include <SFML\Graphics.hpp>
#include <cmath>
#include <string>
#include <SFML\Graphics.hpp>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>

#include "Personnage.h"
#include "ratiogain.h"
#include "tilemap.cpp"
#include "Arme.h"
#include "Gains.h"
#include "map.cpp"


std::string toString(const int nb)
{
	std::ostringstream oos;
	oos << nb;
	return oos.str();
}

int rand_a_b(int a, int b)
{
	//C'est notre fonction aleatoire
	return rand() % (b - a) + a;
}


#define HAUTEUR_FENETRE 600
#define LARGEUR_FENETRE 1200
#define HAUTEUR_VIEW 129
#define LARGEUR_VIEW 304
#define TAILLE_BLOCK 32
#define NB_BLOCK_LARGEUR 50
#define NB_BLOCK_HAUTEUR 40

// on crée la fenêtre
sf::RenderWindow window(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "The Castle");

// Chargement
sf::Texture t_chargement;
sf::Sprite chargement;

// View
sf::View view;

// Musique de fond
//sf::Music music;

// Temps de jeu
sf::Text temps_de_jeu;
sf::Font font;


// on crée la tilemap avec le niveau précédemment défini
TileMap map;

//Création du personnage
sf::Texture t_hero;
sf::Sprite hero;
enum Dir{S,Q,D,Z};
sf::Vector2i anim(0, S);

// Création du menu pause
sf::Texture t_menu_pause;
sf::Sprite menu_pause;

// Armes
sf::Texture t_armes;
sf::Sprite armes;

// Pont
sf::Texture t_pont;
sf::Sprite pont;

// Boutons
sf::Texture t_boutons;
sf::Sprite boutons;

// Retour au jeu
sf::Sprite retour_jeu;

// Quitter

sf::Sprite quitter;

// Son "on" et "off"

sf::Sprite bouton_son;

// quetes
sf::Sprite quetes;

// Jouer
sf::Sprite jouer;

// Credits
sf::Sprite credits;

//Regle/commandes
sf::Sprite regle_comm;

// Launcher
sf::Texture t_launcher;
sf::Sprite launcher;

// Fight --------------------------------------------------------------- rajoute -------------------------------------------
sf::Texture t_fight;
sf::Sprite fight_squelette;
sf::Sprite fight_loup;
sf::Sprite fight_boss;

// Bouton choix en fight
sf::Texture t_choix_fight;
sf::Sprite choix;
sf::Sprite attaques;
sf::Sprite potions;

// triangle choix sort
sf::Texture t_triangle;
sf::Sprite triangle_hg; // triangle haut gauche position_choix = 0, 1 ou 2
sf::Sprite triangle_bg; // triangle haut gauche position_choix = 0, 1 ou 2
sf::Sprite triangle_hd0; // triangle haut droite position_choix = 0
sf::Sprite triangle_hd12; // triangle haut droite position_choix = 1 ou 2
sf::Sprite triangle_m12; // triangle milieu position_choix = 1 ou 2
sf::Sprite triangle_bd12; // triangle bas droite position_choix = 1 ou 2

// Interface
sf::Texture t_interface;
sf::Sprite interface;

// Potions
sf::Texture t_potions;
sf::Sprite petite_potion;
sf::Sprite moyenne_potion;
sf::Sprite grande_potion;
sf::Sprite miraculeuse_potion;

// Loup fight
sf::Texture t_loup_fight;
sf::Sprite loup_fight;

// Squelette fight
sf::Texture t_squelette_fight;
sf::Sprite squelette_fight;

// Dragon fight
sf::Texture t_boss_fight;
sf::Sprite boss_fight;

// Hero fight
sf::Texture t_hero_fight;
sf::Sprite hero_fight;

// Background quete
sf::Texture t_bg_quete;
sf::Sprite bg_quete;

// Background quete
sf::Texture t_expliq_quete;
sf::Sprite quete1;
sf::Sprite quete1V;
sf::Sprite quete2;
sf::Sprite quete2V;
sf::Sprite quete3;
sf::Sprite quete3V;

// barres de vie + exp
sf::RectangleShape barre_vie_hero(sf::Vector2f(200, 30));
sf::RectangleShape barre_vie_ennemi(sf::Vector2f(200, 30));
sf::RectangleShape barre_exp_max(sf::Vector2f(185, 10));
sf::RectangleShape barre_exp(sf::Vector2f(0, 10));

// Niveau du perso en string
sf::Text niveau_perso;
sf::Text niveau_perso_fight;
sf::Font font_niveau;


// Tableau de sprite qui définit les armes 
sf::Sprite s_Armes[21];
sf::Sprite ArmeEquipe;
sf::IntRect Armes[21];

// Descriptif map
sf::Texture t_descript;
sf::Sprite Descript_arme[21];
sf::IntRect Description[21];

// Nb popo restantes----------------------------- --------------------------------------------
sf::Text popo_p;
sf::Text popo_m;
sf::Text popo_g;
sf::Text popo_M;
sf::Font font_popo;

// Arme debloque et level up
sf::Texture t_up;
sf::Sprite up;

sf::Texture t_debloque;
sf::Sprite debloque;

sf::Vector2i pixelPos;
sf::Vector2f worldPos;

sf::Vector2i souris_local;
sf::Vector2f souris_world;

sf::Vector2f position;

// image de mort

sf::Texture t_game_over;
sf::Sprite game_over;


int quelCombat = 0;
int speed = 2, vx = 0, vy = 0, tempo_pause = 0, tps, tps_sec, tps_min, vitesse_sprite = 0, position_choix = 0;
bool pause = false;
bool temps_jeu = true;
bool lecture_music = true;
bool animation_x = false, animation_y = false;
bool son = true;
bool play = false;
bool boss = false;
bool inventaire = false;
bool quete = false;
int colonne_inventaire = 0;
int ligne_inventaire = 0;
int DoitEtreEquipe = 0;
int EstEquipe = 0;
int* position2;
bool debutCombat = false;
bool continu = true;
std::string reponse;
int armeChoisie;
std::string armureChoisie;
std::string potionChoisie;
bool estVivantJoueur = true;
bool estVivantAdversaire = true;
bool ChoixAttaque = false;
int effetAleatoire;
int pxd;
int pxg;
int pyh;
int pyb;
int combatOu = 0;
int Descriptif_quel_arme = 25; //------------------------------------------------
bool descript_equipe = false;
int tempo_up = 0;
int ancien_lvl = 0;
int tempo_arme_debloque = 0;
int nombre_arme_true = 0;
int ancien_nombre_arme_true = 1;
int nouvelleArme = 0;
bool bossEnVie = true;
std::string coupPlusUn = "";
float vie_hero;
float vie_hero_max;
float experience;
float vie_adversaire;
float vie_adversaire_max;
int niveau;
bool* armePossede;
int* potions_restante;
std::string affichage_niveau;
std::string temps_min;
std::string temps_sec;
std::string stemps1;
std::string stemps2;
std::string temps;
std::string popo[4];
int recommencer =0;
bool reponseContinuer = true;
bool reponseRetry = true;
int retry = 0;


Adversaire Loup(0);
Adversaire Squelette(0, 0);
Adversaire Dragon("BaertZilla", 0);
#pragma region matrice

int level_presence[] =
{

	// C'est la matrice dans laquelle on va stocker les potentiels ennemis
	// Les 1 sont les positions où le joueur ne pourra pas aller, et les 0 vont possiblement etre remplaces par un 1 ou un 2 (un loup ou un squelette)
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
	0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
	0, 0, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
	0, 0, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 9, 9, 9, 9,
	0, 0, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 0, 0, 0, 0, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9,
	0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9,
	0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
	1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
	1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 8, 0, 1, 1, 0, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
	1, 1, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
	1, 1, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
	1, 1, 8, 8, 8, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 8, 1, 1, 1, 1, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 1, 1, 1, 1, 1, 1, 1, 1, 8, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

#pragma endregion matrice

#pragma region initialisation

Personnage tim;  //Creation du personnage (a renommer)
int nombreAleatoire, nombreAleatoireGain;
bool ecombat = false; // booleen qui va permettre de savoir si on se bat 
std::string stop = "non"; // Texte qui permettra de savoir si le joueur veut arrêter le combat
Ratio ratiogain; // Creation d'un objet qui déterminera les gains
Gain gain; // Creation d'un objet qui distribuera le gain
Arme arme; // Creation d'un objet qui permettra le changement d'arme
int nombreEnemi = 0, nombreEnemi2 = 0; // Variables qui vont stocker le nombre de loups et de squelettes
bool nonfuite = true;
bool derniereArme = false;
int bouclepresence = 0;
bool redirenbennemi = true;

#pragma endregion initialisation

bool collision_map(int position_x, int position_y, bool boss)
{
	//position x à gauche du perso
	int pxd = (position_x + 32) / 32;

	//position x à droite du perso
	int pxg = (position_x + 16) / 32;

	// position y en haut du perso
	int pyh = (position_y + 47) / 32;

	//position y en bas du perso
	int pyb = (position_y + 35) / 32;


	if (level_collision[pxg + pyh * 50] == 0 && level_collision[pxd + pyh * 50] == 0 && level_collision[pxg + pyb * 50] == 0 && level_collision[pxd + pyb * 50] == 0)
	{
		return false;
	}

	else if (((level_collision[pxg + pyh * 50] == 0 && level_collision[pxd + pyh * 50] == 9 && level_collision[pxg + pyb * 50] == 0 && level_collision[pxd + pyb * 50] == 9) || (level_collision[pxg + pyh * 50] == 9 && level_collision[pxd + pyh * 50] == 9 && level_collision[pxg + pyb * 50] == 9 && level_collision[pxd + pyb * 50] == 9) || (level_collision[pxg + pyh * 50] == 9 && level_collision[pxd + pyh * 50] == 0 && level_collision[pxg + pyb * 50] == 9 && level_collision[pxd + pyb * 50] == 0)) && boss)
	{
		return false;
	}

	else if ((level_collision[pxg + pyh * 50] == 0 && level_collision[pxd + pyh * 50] == 0 && level_collision[pxg + pyb * 50] == 8 && level_collision[pxd + pyb * 50] == 8) ||
		(level_collision[pxg + pyh * 50] == 8 && level_collision[pxd + pyh * 50] == 8 && level_collision[pxg + pyb * 50] == 8 && level_collision[pxd + pyb * 50] == 8) ||
		(level_collision[pxg + pyh * 50] == 8 && level_collision[pxd + pyh * 50] == 8 && level_collision[pxg + pyb * 50] == 0 && level_collision[pxd + pyb * 50] == 0) ||
		(level_collision[pxg + pyh * 50] == 8 && level_collision[pxd + pyh * 50] == 0 && level_collision[pxg + pyb * 50] == 8 && level_collision[pxd + pyb * 50] == 0) ||
		(level_collision[pxg + pyh * 50] == 0 && level_collision[pxd + pyh * 50] == 8 && level_collision[pxg + pyb * 50] == 0 && level_collision[pxd + pyb * 50] == 8))
		return false;

	else
		return true;
}

bool collision_ennemi(int position_x, int position_y)
{
	// C'est la fonction qui va permettre de savoir si dans la case ou est le joueur il y a un ennemi
	// Si il y en a un, on precisera si c'est un loup (1) ou un squelette (2) dans la variable "quelCombat"
	//position x à gauche du perso
	int pxd = (position_x + 32) / 32;

	//position x à droite du perso
	int pxg = (position_x + 16) / 32;

	// position y en haut du perso
	int pyh = (position_y + 47) / 32;

	//position y en bas du perso
	int pyb = (position_y + 35) / 32;


	if ((level_presence[pxg + pyh * 50] != 0 && level_presence[pxd + pyh * 50] != 0 && level_presence[pxg + pyb * 50] != 0 && level_presence[pxd + pyb * 50] != 0) && (level_presence[pxg + pyh * 50] != 8 && level_presence[pxd + pyh * 50] != 8 && level_presence[pxg + pyb * 50] != 8 && level_presence[pxd + pyb * 50] != 8))
	{
		if (level_presence[pxg + pyh * 50] == 2 && level_presence[pxd + pyh * 50] == 2 && level_presence[pxg + pyb * 50] == 2 && level_presence[pxd + pyb * 50] == 2)
			quelCombat = 1;
		else if ((level_presence[pxg + pyh * 50] == 3 && level_presence[pxd + pyh * 50] == 3 && level_presence[pxg + pyb * 50] == 3 && level_presence[pxd + pyb * 50] == 3))
			quelCombat = 2;
		else if ((level_presence[pxg + pyh * 50] == 4 && level_presence[pxd + pyh * 50] == 4 && level_presence[pxg + pyb * 50] == 4 && level_presence[pxd + pyb * 50] == 4))
			quelCombat = 3;
		return false;
	}
	else
		return true;
}

void definition_presence_ennemie()
{
	do
	{
		level_presence[348] = level_presence[349] = level_presence[350] = level_presence[398] = level_presence[399] = level_presence[400] = level_presence[448] = level_presence[449] = level_presence[450] = 4;
		for (int i = 0; i < 2000; i++) // Pour chaque case où le joueur peut aller, on definit s'il y aura un ennemi ou non. 
		{
			if (level_collision[i] == 0)
			{
				if (rand_a_b(0, 50) > 33)
				{
					if (rand_a_b(0, 6) > 3)
					{
						level_presence[i] = 3;
						nombreEnemi2 += 1;
					}
					else
					{
						level_presence[i] = 2;
						nombreEnemi += 1;
					}

				}
			}
		}
	} while ((nombreEnemi + nombreEnemi2) > 350 && (nombreEnemi + nombreEnemi2) < 250);
}

bool apparitionBoss()
{
	if (!boss)
		return(nombreEnemi <= 100 && nombreEnemi2 <= 50);
	else
		return boss;
}

void miseEnPlaceVieAdversaire()
{
	if (quelCombat == 1)
		estVivantAdversaire = Loup.estVivant();
	else if (quelCombat == 2)
		estVivantAdversaire = Squelette.estVivant();
	else if (quelCombat == 3)
		estVivantAdversaire = Dragon.estVivant();
}

void Tranche()
{
	if (quelCombat == 1)
	{
		tim.attaquer(Loup, "Tranche");
		if (estVivantAdversaire)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Loup.attaquer(tim, "Tranche");
			}
			else
				Loup.attaquer(tim, "Tranche");
		}
	}
	else if (quelCombat == 2)
	{
		tim.attaquer(Squelette, "Tranche");
		if (estVivantAdversaire)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Squelette.attaquer(tim, "Tranche");
			}
			else
				Squelette.attaquer(tim, "Tranche");

		}
	}
	else if (quelCombat == 3)
	{
		tim.attaquer(Dragon, "Tranche");
		if (estVivantAdversaire)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Dragon.attaquer(tim, "Tranche");
			}
			else
				Dragon.attaquer(tim, "Tranche");

		}
	}
	position_choix = 0;
	coupPlusUn = "";
}

void Charge()
{
	if (quelCombat == 1)
	{
		tim.attaquer(Loup, "Charge");
		if (estVivantAdversaire)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Loup.attaquer(tim, "Charge");
			}
			else
				Loup.attaquer(tim, "Charge");

		}
	}
	else if (quelCombat == 2)
	{
		tim.attaquer(Squelette, "Charge");
		if (estVivantAdversaire)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Squelette.attaquer(tim, "Charge");
			}
			else
				Squelette.attaquer(tim, "Charge");

		}
	}
	else if (quelCombat == 3)
	{
		tim.attaquer(Dragon, "Charge");
		if (estVivantAdversaire)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Dragon.attaquer(tim, "Charge");
			}
			else
				Dragon.attaquer(tim, "Charge");

		}
	}
	position_choix = 0;
	coupPlusUn = "";
}

void CoupDeTete()
{
	if (quelCombat == 1)
	{
		tim.attaquer(Loup, "Coup_de_tete");
		if (estVivantAdversaire)
		{
			effetAleatoire = rand_a_b(0, 5);
			if (effetAleatoire > 3)
			{
				if (coupPlusUn == "Defense")
				{
					effetAleatoire = rand_a_b(0, 5);
					if (effetAleatoire > 3)
						Loup.attaquer(tim, "Coup_de_tete");
				}
				else
					Loup.attaquer(tim, "Coup_de_tete");
			}
		}
	}
	else if (quelCombat == 2)
	{
		tim.attaquer(Squelette, "Coup_de_tete");
		if (estVivantAdversaire)
		{
			effetAleatoire = rand_a_b(0, 5);
			if (effetAleatoire > 3)
			{
				if (coupPlusUn == "Defense")
				{
					effetAleatoire = rand_a_b(0, 5);
					if (effetAleatoire > 3)
						Squelette.attaquer(tim, "Coup_de_tete");
				}
				else
					Squelette.attaquer(tim, "Coup_de_tete");
			}
		}
	}
	else if (quelCombat == 3)
	{
		tim.attaquer(Dragon, "Coup_de_tete");
		if (estVivantAdversaire)
		{
			effetAleatoire = rand_a_b(0, 5);
			if (effetAleatoire > 3)
			{
				if (coupPlusUn == "Defense")
				{
					effetAleatoire = rand_a_b(0, 5);
					if (effetAleatoire > 3)
						Dragon.attaquer(tim, "Coup_de_tete");
				}
				else
					Dragon.attaquer(tim, "Coup_de_tete");
			}

		}
	}
	position_choix = 0;
	coupPlusUn = "";
}

void Parade()
{
	if (estVivantAdversaire)
	{
		if (quelCombat == 1)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Loup.attaquer(tim, "Defense");
			}
			else
				Loup.attaquer(tim, "Defense");
		}
		else if (quelCombat == 2)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Squelette.attaquer(tim, "Defense");
			}
			else
				Squelette.attaquer(tim, "Defense");
		}
		else if (quelCombat == 3)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Dragon.attaquer(tim, "Defense");
			}
			else
				Dragon.attaquer(tim, "Defense");

		}

		position_choix = 0;
		coupPlusUn = "Defense";

	}
}

void UtilisePetitePotion()
{
	if (tim.sortirNombrePotion()[0] > 0)
	{
		tim.boirePotionDeVie("Petite", Potion());
		if (quelCombat == 1)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Loup.attaquer(tim, "Tranche");
			}
			else
				Loup.attaquer(tim, "Tranche");

		}
		else if (quelCombat == 2)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Squelette.attaquer(tim, "Tranche");
			}
			else
				Squelette.attaquer(tim, "Tranche");
		}
		else if (quelCombat == 3)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Dragon.attaquer(tim, "Tranche");
			}
			else
				Dragon.attaquer(tim, "Tranche");
		}
	}
	position_choix = 0;
	coupPlusUn = "";
}

void UtiliseMoyennePotion()
{
	if (tim.sortirNombrePotion()[1]>0)
	{
		tim.boirePotionDeVie("Moyenne", Potion());
		if (quelCombat == 1)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Loup.attaquer(tim, "Tranche");
			}
			else
				Loup.attaquer(tim, "Tranche");

		}
		else if (quelCombat == 2)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Squelette.attaquer(tim, "Tranche");
			}
			else
				Squelette.attaquer(tim, "Tranche");
		}
		else if (quelCombat == 3)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Dragon.attaquer(tim, "Tranche");
			}
			else
				Dragon.attaquer(tim, "Tranche");
		}
	}
	position_choix = 0;
	coupPlusUn = "";
}

void UtiliseGrandePotion()
{
	if (tim.sortirNombrePotion()[2])
	{
		tim.boirePotionDeVie("Grande", Potion());
		if (quelCombat == 1)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Loup.attaquer(tim, "Tranche");
			}
			else
				Loup.attaquer(tim, "Tranche");

		}
		else if (quelCombat == 2)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Squelette.attaquer(tim, "Tranche");
			}
			else
				Squelette.attaquer(tim, "Tranche");
		}
		else if (quelCombat == 3)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Dragon.attaquer(tim, "Tranche");
			}
			else
				Dragon.attaquer(tim, "Tranche");
		}
	}
	position_choix = 0;
	coupPlusUn = "";
}

void UtiliseMiraculeusePotion()
{
	if (tim.sortirNombrePotion()[3] > 0)
	{
		tim.boirePotionDeVie("Miraculeuse", Potion());
		if (quelCombat == 1)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Loup.attaquer(tim, "Tranche");
			}
			else
				Loup.attaquer(tim, "Tranche");

		}
		else if (quelCombat == 2)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Squelette.attaquer(tim, "Tranche");
			}
			else
				Squelette.attaquer(tim, "Tranche");
		}
		else if (quelCombat == 3)
		{
			if (coupPlusUn == "Defense")
			{
				effetAleatoire = rand_a_b(0, 5);
				if (effetAleatoire > 3)
					Dragon.attaquer(tim, "Tranche");
			}
			else
				Dragon.attaquer(tim, "Tranche");
		}
	}
	position_choix = 0;
	coupPlusUn = "";
}

void Combat()
{
	if (nonfuite && (quelCombat == 2 || quelCombat == 1))
	{
		if (quelCombat == 1)
			estVivantAdversaire = Loup.estVivant();
		else
			estVivantAdversaire = Squelette.estVivant();
		if (tim.estVivant() && !estVivantAdversaire)
		{
			level_presence[pxg + pyh * 50] = level_presence[pxd + pyh * 50] = level_presence[pxg + pyb * 50] = level_presence[pxd + pyb * 50] = 0;
			if (quelCombat == 1)
				nombreEnemi -= 1;
			else
				nombreEnemi2 -= 1;
			nombreAleatoireGain = rand_a_b(0, 10); // On attribu aleatoirement un gain entre de l'or et une nouvelle arme
			if (nombreAleatoireGain < 0)
				ratiogain.GainOr(tim, gain);
			else if (nombreAleatoireGain > 6)
				ratiogain.GainPotion(tim);
			else if (nombreAleatoireGain < 2)
				nouvelleArme = ratiogain.GainArme(tim, gain, arme);
			ratiogain.GainExperience(tim, gain, quelCombat); // Dans tous les cas, le joueur gagne de l'experience
			if (nombreEnemi <= 100 && nombreEnemi2 <= 50 && !derniereArme)
			{
				derniereArme = true;
				ratiogain.GainArmeLegende(tim, gain, arme);
			}
			quelCombat = 0;
		}
	}
	else if (!nonfuite || !tim.estVivant())
	{
		quelCombat = 0;
	}
	else if (nonfuite && quelCombat == 3)
	{
		estVivantAdversaire = Dragon.estVivant();
		if (tim.estVivant() && !estVivantAdversaire)
		{
			level_presence[346] = level_presence[347] = level_presence[348] = level_presence[349] = level_presence[350] = level_presence[397] = level_presence[398] = level_presence[399] = level_presence[400] = level_presence[447] = level_presence[448] = level_presence[449] = level_presence[450] = 0;
			nombreAleatoireGain = rand_a_b(0, 10); // On attribu aleatoirement un gain entre de l'or et une nouvelle arme
			if (nombreAleatoireGain < 0)
				ratiogain.GainOr(tim, gain);
			else if (nombreAleatoireGain > 6)
				ratiogain.GainPotion(tim);
			ratiogain.GainArme(tim, gain, arme);
			ratiogain.GainExperience(tim, gain, quelCombat);
			bossEnVie = false;
			quelCombat = 0;
		}
	}
}

void Collision()
{
	if (quelCombat == 0)
	{
		int potentiel_x = hero.getPosition().x + vx;
		int potentiel_y = hero.getPosition().y + vy;

		if (!collision_map(potentiel_x, hero.getPosition().y, boss))
		{
			hero.setPosition(potentiel_x, hero.getPosition().y);
		}

		if (!collision_map(hero.getPosition().x, potentiel_y, boss))
		{
			hero.setPosition(hero.getPosition().x, potentiel_y);
		}
	}
}

void CollisionEnnemie()
{
	if (quelCombat == 0)
	{
		int potentiel_x = hero.getPosition().x + vx;
		int potentiel_y = hero.getPosition().y + vy;



		if (!collision_ennemi(potentiel_x, hero.getPosition().y))
		{
			//position x à gauche du perso
			pxd = (potentiel_x + 32) / 32;

			//position x à droite du perso
			pxg = (potentiel_x + 16) / 32;

			// position y en haut du perso
			pyh = (hero.getPosition().y + 47) / 32;

			//position y en bas du perso
			pyb = (hero.getPosition().y + 35) / 32;
			combatOu = 1;
			debutCombat = true;

		}

		if (!collision_ennemi(hero.getPosition().x, potentiel_y))
		{
			//position x à gauche du perso
			pxd = (hero.getPosition().x + 32) / 32;

			//position x à droite du perso
			pxg = (hero.getPosition().x + 16) / 32;

			// position y en haut du perso
			pyh = (potentiel_y + 47) / 32;

			//position y en bas du perso
			pyb = (potentiel_y + 35) / 32;
			combatOu = 2;
			debutCombat = true;



		}
	}
}

void CollisionBords()
{
	if (hero.getPosition().x < 0)hero.setPosition(0, hero.getPosition().y);
	if (hero.getPosition().x > 1550)hero.setPosition(1550, hero.getPosition().y);
	if (hero.getPosition().y < 0)hero.setPosition(hero.getPosition().x, 0);
	if (hero.getPosition().y > 1230)hero.setPosition(hero.getPosition().x, 1230);
}

void MouvementSprite()
{
	vitesse_sprite++;
	if (vitesse_sprite > 4 && (animation_x || animation_y))
	{
		anim.x++;
		if (anim.x * 52 >= 208)
			anim.x = 0;
		vitesse_sprite = 0;
	}
}

void DescriptionArme()
{
	Descriptif_quel_arme = 25;
	sf::Vector2i souris_local = sf::Mouse::getPosition(window); // coo local
	sf::Vector2f souris_world = window.mapPixelToCoords(souris_local); // coo monde

	if (souris_local.x > 71 && souris_local.x < 128 &&
		souris_local.y > 187 && souris_local.y < 215)
	{
		Descriptif_quel_arme = EstEquipe;
		descript_equipe = true;
	}

	else
		descript_equipe = false;


	if (souris_local.x > 7 && souris_local.x < 64)
	{
		if (souris_local.y > 310 && souris_local.y < 338)
		{
			Descriptif_quel_arme = 0;
		}

		else if (souris_local.y > 351 && souris_local.y < 379)
		{
			Descriptif_quel_arme = 1;
		}

		else if (souris_local.y > 392 && souris_local.y < 420)
		{
			Descriptif_quel_arme = 2;
		}

		else if (souris_local.y > 433 && souris_local.y < 461)
		{
			Descriptif_quel_arme = 3;
		}

		else if (souris_local.y > 474 && souris_local.y < 502)
		{
			Descriptif_quel_arme = 4;
		}

		else if (souris_local.y > 515 && souris_local.y < 543)
		{
			Descriptif_quel_arme = 5;
		}

		else if (souris_local.y > 556 && souris_local.y < 584)
		{
			Descriptif_quel_arme = 6;
		}
	}

	else if (souris_local.x > 71 && souris_local.x < 128)
	{
		if (souris_local.y > 310 && souris_local.y < 338)
		{
			Descriptif_quel_arme = 7;
		}

		else if (souris_local.y > 351 && souris_local.y < 379)
		{
			Descriptif_quel_arme = 8;
		}

		else if (souris_local.y > 392 && souris_local.y < 420)
		{
			Descriptif_quel_arme = 9;
		}

		else if (souris_local.y > 433 && souris_local.y < 461)
		{
			Descriptif_quel_arme = 10;
		}

		else if (souris_local.y > 474 && souris_local.y < 502)
		{
			Descriptif_quel_arme = 11;
		}

		else if (souris_local.y > 515 && souris_local.y < 543)
		{
			Descriptif_quel_arme = 12;
		}

		else if (souris_local.y > 556 && souris_local.y < 584)
		{
			Descriptif_quel_arme = 13;
		}
	}

	else if (souris_local.x > 135 && souris_local.x < 192)
	{
		if (souris_local.y > 310 && souris_local.y < 338)
		{
			Descriptif_quel_arme = 14;
		}

		else if (souris_local.y > 351 && souris_local.y < 379)
		{
			Descriptif_quel_arme = 15;
		}

		else if (souris_local.y > 392 && souris_local.y < 420)
		{
			Descriptif_quel_arme = 16;
		}

		else if (souris_local.y > 433 && souris_local.y < 461)
		{
			Descriptif_quel_arme = 17;
		}

		else if (souris_local.y > 474 && souris_local.y < 502)
		{
			Descriptif_quel_arme = 18;
		}

		else if (souris_local.y > 515 && souris_local.y < 543)
		{
			Descriptif_quel_arme = 19;
		}

		else if (souris_local.y > 556 && souris_local.y < 584)
		{
			Descriptif_quel_arme = 20;
		}
	}
}

void AffichagePV()
{
	vie_hero = tim.sortirPV();
	vie_hero_max = tim.sortirPVmax();
	niveau = tim.sortirNiveau();
	experience = tim.sortirxp();
	vie_adversaire = 0;
	vie_adversaire_max = 0;
	if (quelCombat == 1)
	{
		vie_adversaire = Loup.sortirPV();
		vie_adversaire_max = Loup.sortirPVmax();
	}
	else if (quelCombat == 2)
	{
		vie_adversaire = Squelette.sortirPV();
		vie_adversaire_max = Squelette.sortirPVmax();
	}
	else if (quelCombat == 3)
	{
		vie_adversaire = Dragon.sortirPV();
		vie_adversaire_max = Dragon.sortirPVmax();
	}
}

void DebutCombat()
{
	if (debutCombat)
	{
		continu = true;
		srand(time(NULL));
		estVivantJoueur = true;
		estVivantAdversaire = true;
		debutCombat = false;

		if (quelCombat == 1)
		{
			Adversaire bob(tim.sortirNiveau());
			Loup = bob;

		}
		else if (quelCombat == 2)
		{
			Adversaire bob(quelCombat, tim.sortirNiveau());
			Squelette = bob;

		}
		else
		{
			Adversaire bob("BaertZilla", tim.sortirNiveau());
			Dragon = bob;
		}
	}
}

void NouvelleArmeGagnee()
{
	nombre_arme_true = 0;
	for (int i = 0; i < 21; i++)
	{
		if (armePossede[i] == true)
			nombre_arme_true += 1;
	}
}

void DrawTout()
{
	window.clear();
	sf::Vector2i souris_local = sf::Mouse::getPosition(window); // coo local

	if (quelCombat == 0 && tim.estVivant())
	{
		window.draw(map);

		// accès boss
		if (boss)
			window.draw(pont);

		window.draw(hero);

		if (ancien_nombre_arme_true != nombre_arme_true)
		{
			tempo_arme_debloque++;
			if (tempo_arme_debloque >= 100)
			{
				ancien_nombre_arme_true = nombre_arme_true;
				tempo_arme_debloque = 0;
			}
			else
				window.draw(debloque);
		}

		if (ancien_lvl != niveau)
		{
			tempo_up++;
			if (tempo_up >= 100)
			{
				ancien_lvl = niveau;
				tempo_up = 0;
			}
			else
				window.draw(up);
		}

		// dessin de l'interface
		if (inventaire)
		{
			window.draw(interface);
			window.draw(temps_de_jeu);
			window.draw(barre_exp_max);
			window.draw(barre_exp);
			window.draw(niveau_perso);
			for (int i = 0; i < 21; i++)
				if (armePossede[i] == true)
					window.draw(s_Armes[i]);
			if (armePossede[DoitEtreEquipe] == true)
			{
				window.draw(ArmeEquipe);
				EstEquipe = DoitEtreEquipe;
			}
			else
			{
				ArmeEquipe.setTextureRect(Armes[EstEquipe]);
				window.draw(ArmeEquipe);
			}

			if (Descriptif_quel_arme < 25)
				window.draw(Descript_arme[Descriptif_quel_arme]);

			window.draw(popo_p);
			window.draw(popo_m);
			window.draw(popo_g);
			window.draw(popo_M);
		}

		// launcher
		if (!play)
		{
			window.draw(launcher);
			window.draw(jouer);
			window.draw(credits);
			window.draw(regle_comm);
		}
	}

	if (quelCombat == 1 && tim.estVivant()) // ------------------------------------------------------------------------- rajoute if et else if --------------------------------------------------------------------
	{
		window.draw(fight_loup);
		window.draw(loup_fight);
		window.draw(hero_fight);
	}
	else if (quelCombat == 2 && tim.estVivant())
	{
		window.draw(fight_squelette);
		window.draw(squelette_fight);
		window.draw(hero_fight);
	}

	else if (quelCombat == 3 && tim.estVivant())
	{
		window.draw(fight_boss);
		window.draw(boss_fight);
		window.draw(hero_fight);
	}

	if (quelCombat != 0 && tim.estVivant())
	{
		window.draw(barre_vie_ennemi);
		window.draw(barre_vie_hero);
		window.draw(barre_vie_ennemi);
		window.draw(barre_vie_hero);
		window.draw(niveau_perso_fight);


		if (position_choix == 1)
		{
			window.draw(attaques);
			window.draw(triangle_hg);
			window.draw(triangle_bg);
			window.draw(triangle_hd12);
			window.draw(triangle_m12);
			window.draw(triangle_bd12);
		}

		else if (position_choix == 2)
		{
			window.draw(potions);
			window.draw(triangle_hg);
			window.draw(triangle_bg);
			window.draw(triangle_hd12);
			window.draw(triangle_m12);
			window.draw(triangle_bd12);
			window.draw(popo_p);
			window.draw(popo_m);
			window.draw(popo_g);
			window.draw(popo_M);
		}
		else
		{
			window.draw(choix);
			window.draw(triangle_hg);
			window.draw(triangle_bg);
			window.draw(triangle_hd0);
		}
	}
	//window.draw(armes);
	if (pause && !inventaire) // ----------------- ATTENTION J'AI RAJOUTE DES CONDITIONS
	{
		window.draw(menu_pause);
		std::cout << "x : " << souris_local.x << " y : " << souris_local.y << std::endl;
		window.draw(retour_jeu);
		window.draw(quitter);
		window.draw(quetes);
		window.draw(bouton_son);
		// --------------------------------------------------------- rajoute 
		if (quete)
		{
			window.draw(bg_quete);

			//validation ou non quete tuer le boss 
			if (!bossEnVie)
				window.draw(quete1V);
			else
				window.draw(quete1);

			// validation ou non quete tuer tous les ennemis
			if (nombreEnemi == 0 && nombreEnemi2 == 0)
				window.draw(quete2V);
			else
				window.draw(quete2);

			// validation ou non d'arme l'arme legendaire
			if (armePossede[20] == true)
				window.draw(quete3V);
			else
				window.draw(quete3);
		}
		// ------------------------------ fin ------
		
	}
	if (tim.estVivant() == false)
		window.draw(game_over);
	
}

void Chargement()
{
	chargement.setTexture(t_chargement);
	chargement.setPosition(sf::Vector2f(0, 0));
	window.draw(chargement);
	window.display();
}

void MiseEnPlaceTextureDecorFight()
{
	fight_loup.setTexture(t_fight);
	fight_loup.setTextureRect(sf::IntRect(0, 0, 1200, 600));
	fight_squelette.setTexture(t_fight);
	fight_squelette.setTextureRect(sf::IntRect(0, 600, 1200, 600));
	fight_boss.setTexture(t_fight);
	fight_boss.setTextureRect(sf::IntRect(0, 1200, 1200, 600));
}

void MiseEnPlaceTextureBoutonFight()
{
	choix.setTexture(t_choix_fight);
	choix.setTextureRect(sf::IntRect(0, 0, 550, 175));
	attaques.setTexture(t_choix_fight);
	attaques.setTextureRect(sf::IntRect(0, 175, 550, 175));
	potions.setTexture(t_choix_fight);
	potions.setTextureRect(sf::IntRect(0, 350, 550, 175));
}

void MiseEnPlaceTextureTriangleChoix()
{
	triangle_hg.setTexture(t_triangle);
	triangle_bg.setTexture(t_triangle);
	triangle_hd0.setTexture(t_triangle);
	triangle_hd12.setTexture(t_triangle);
	triangle_m12.setTexture(t_triangle);
	triangle_bd12.setTexture(t_triangle);
}

void MiseEnPlaceTexturePotion()
{
	petite_potion.setTexture(t_potions);
	petite_potion.setTextureRect(sf::IntRect(0, 0, 57, 28));
	moyenne_potion.setTexture(t_potions);
	moyenne_potion.setTextureRect(sf::IntRect(28, 0, 57, 28));
	grande_potion.setTexture(t_potions);
	grande_potion.setTextureRect(sf::IntRect(56, 0, 57, 28));
	miraculeuse_potion.setTexture(t_potions);
	miraculeuse_potion.setTextureRect(sf::IntRect(84, 0, 57, 28));
}

void MiseEnPlaceTextureExplicationQuete()
{
	quete1.setTexture(t_expliq_quete);
	quete1.setTextureRect(sf::IntRect(0, 0, 284, 117));
	quete1V.setTexture(t_expliq_quete);
	quete1V.setTextureRect(sf::IntRect(117, 0, 284, 117));
	quete2.setTexture(t_expliq_quete);
	quete2.setTextureRect(sf::IntRect(0, 234, 284, 117));
	quete2V.setTexture(t_expliq_quete);
	quete2V.setTextureRect(sf::IntRect(0, 351, 284, 117));
	quete3.setTexture(t_expliq_quete);
	quete3.setTextureRect(sf::IntRect(0, 468, 284, 117));
	quete3V.setTexture(t_expliq_quete);
	quete3V.setTextureRect(sf::IntRect(0, 585, 284, 117));
}

int MiseEnPlaceTexturePolice()
{
	if (!font.loadFromFile("Police/game_over.ttf"))
	{
		return 0;
	}

	if (!font_niveau.loadFromFile("Police/game_over.ttf"))
	{
		return 0;
	}

	if (!font_popo.loadFromFile("Police/game_over.ttf")) // ----------------------------------------------
	{
		return 0;
	}
}

int MiseEnPlaceTextureArmes()
{
	if (!t_armes.loadFromFile("Images/sprite_armes.png"))
	{
		return 0;
	}

	if (!t_descript.loadFromFile("Images/Descriptif_armes.png"))
	{
		return 0;
	}

	for (int i = 0; i < 21; i++)
	{
		s_Armes[i].setTexture(t_armes);
		Armes[i] = sf::IntRect(0, i * 28, 57, 28);
		s_Armes[i].setTextureRect(Armes[i]);

	}

	for (int j = 0; j < 21; j++)
	{
		Descript_arme[j].setTexture(t_descript);
		Description[j] = sf::IntRect(0, j * 70, 170, 70);
		Descript_arme[j].setTextureRect(Description[j]);

	}
	ArmeEquipe.setTexture(t_armes);
	ArmeEquipe.setTextureRect(Armes[0]);
}

int MiseEnPlaceTextureUp()
{
	if (!t_debloque.loadFromFile("Images/debloque.png"))
	{
		return 0;
	}

	debloque.setTexture(t_debloque);


	if (!t_up.loadFromFile("Images/up.png"))
	{
		return 0;
	}

	up.setTexture(t_up);
}

int MiseEnPlaceTextureBoutonsMenu()
{
	if (!t_boutons.loadFromFile("Images/boutons.png"))
	{
		return 0;
	}

	retour_jeu.setTexture(t_boutons);
	quitter.setTexture(t_boutons);
	quetes.setTexture(t_boutons);
	bouton_son.setTexture(t_boutons);
	jouer.setTexture(t_boutons);
	credits.setTexture(t_boutons);
	regle_comm.setTexture(t_boutons);
}

int MiseEnPlaceTextureMenuPause()
{

	if (!t_menu_pause.loadFromFile("Images/pause2.png"))
	{
		return 0;
	}
	menu_pause.setTexture(t_menu_pause);
}

int MiseEnPlaceTextureGeneral()
{
	// Initialisation du launcher
#pragma region launcher
	if (!t_launcher.loadFromFile("Images/launcher.png"))
	{
		return 0;
	}
	launcher.setTexture(t_launcher);
#pragma endregion launcher

	// on crée la tilemap avec le niveau précédemment défini
#pragma region tilemapimage
	if (!map.load("Images/big_tileset.png", sf::Vector2u(TAILLE_BLOCK, TAILLE_BLOCK), level, NB_BLOCK_LARGEUR, NB_BLOCK_HAUTEUR))
		return 0;

	// pont levis
	if (!t_pont.loadFromFile("Images/pont_levis.png"))
	{
		return 0;
	}
	pont.setTexture(t_pont);
#pragma endregion tilemapimage

	// environnement du fight ---------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region decor fight 
	if (!t_fight.loadFromFile("Images/sprite_combat.png"))
	{
		return 0;
	}
	MiseEnPlaceTextureDecorFight();
#pragma endregion decor fight 

#pragma region bouton fight ( rajoute)
	if (!t_choix_fight.loadFromFile("Images/fight_sort.png"))
	{
		return 0;
	}
	MiseEnPlaceTextureBoutonFight();
#pragma endregion bouton fight ( rajoute)

	// Triangle choix sort en fight
#pragma region triangle choix ( rajoute )
	if (!t_triangle.loadFromFile("Images/fight_triangle.png"))
	{
		return 0;
	}
	MiseEnPlaceTextureTriangleChoix();
#pragma endregion triangle choix ( rajoute )

	// Interface
#pragma region interface ( rajoute )
	if (!t_interface.loadFromFile("Images/interface.png"))
	{
		return 0;
	}
	interface.setTexture(t_interface);
#pragma endregion interface ( rajoute )

	// loup fight
#pragma region loup fight ( rajoute )
	if (!t_loup_fight.loadFromFile("Images/loup_fight.png"))
	{
		return 0;
	}
	loup_fight.setTexture(t_loup_fight);
#pragma endregion loup fight ( rajoute )

	// squelette fight
#pragma region squelette fight ( rajoute )
	if (!t_squelette_fight.loadFromFile("Images/guerrier_fight.png"))
	{
		return 0;
	}
	squelette_fight.setTexture(t_squelette_fight);
#pragma endregion squelette fight ( rajoute )

	// boss fight
#pragma region boss fight ( rajoute )
	if (!t_boss_fight.loadFromFile("Images/dragon_fight.png"))
	{
		return 0;
	}
	boss_fight.setTexture(t_boss_fight);
#pragma endregion boss fight ( rajoute )

	// hero fight
#pragma region hero fight ( rajoute )
	if (!t_hero_fight.loadFromFile("Images/hero_fight.png"))
	{
		return 0;
	}
	hero_fight.setTexture(t_hero_fight);
#pragma endregion hero fight ( rajoute )

	// Potions
#pragma region potions ( rajoute )
	if (!t_potions.loadFromFile("Images/potions.png"))
	{
		return 0;
	}
	MiseEnPlaceTexturePotion();
#pragma endregion potions ( rajoute )

	// background quete
#pragma region background quete ( rajoute )
	if (!t_bg_quete.loadFromFile("Images/quete.png"))
	{
		return 0;
	}
	bg_quete.setTexture(t_bg_quete);
#pragma endregion background quete ( rajoute )

	// explications des quetes
#pragma region expliq quete ( rajoute )
	if (!t_expliq_quete.loadFromFile("Images/descriptif_quetes.png"))
	{
		return 0;
	}
	MiseEnPlaceTextureExplicationQuete();
#pragma endregion expliq quete ( rajoute )

	// création du personnages
#pragma region perso
	if (!t_hero.loadFromFile("Images/sprite_heroes.png"))
	{
		return 0;
	}
	hero.setTexture(t_hero);
	hero.setPosition(sf::Vector2f(64, 720));
#pragma endregion perso



	// Police
#pragma region police
	MiseEnPlaceTexturePolice();
#pragma endregion police

	//Tableau armes
#pragma region armes
	MiseEnPlaceTextureArmes();

#pragma endregion armes

	// Level up et arme debloque message ----------------------------------------------------------------
#pragma region debloque + up
	MiseEnPlaceTextureUp();

#pragma endregion debloque + up


	// initialisation des boutons
#pragma region initialisation des boutons
	MiseEnPlaceTextureBoutonsMenu();
#pragma endregion initialisation des boutons



	// Création du menu pause
#pragma region menu pause
	MiseEnPlaceTextureMenuPause();
#pragma endregion menu pause

	// Création du game_over ----------------------------------

#pragma region game over



	if (!t_game_over.loadFromFile("Images/game_over.png"))

	{
		return 0;
	}
	game_over.setTexture(t_game_over);



#pragma endregion game over

}

void Recuperation()
{
	boss = apparitionBoss();

	// Recupère le tableau de booléen qui gère la posséssion d'arme du personnage
	armePossede = ratiogain.sortirArmeEnPossession();

	// Recuperation des potions 
	potions_restante = tim.sortirNombrePotion();
}

void DeplacementClavier()
{
	// Lancement boss
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && !boss && tempo_pause > 40)
	{
		boss = true;
		tempo_pause = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !tim.estVivant())
	{
		reponseRetry = false;
		reponseContinuer = false;
		tempo_pause = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !tim.estVivant())
	{
		reponseRetry = true;
		reponseContinuer = false;
		tempo_pause = 0;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && boss && tempo_pause > 40)
	{
		boss = false;
		tempo_pause = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && !boss && tempo_pause > 40)
	{
		nombreEnemi = nombreEnemi2 = 0;
		for (int i = 0; i < 2000; i++) // Pour chaque case où le joueur peut aller, on definit s'il y aura un ennemi ou non. 
		{
			if (level_collision[i] != 9)
				level_presence[i] = 0;


		}
		level_presence[346] = level_presence[345] = 2;
		nombreEnemi = 2;
		nombreEnemi2 = 0;
		boss = true;
		tempo_pause = 0;
	}

	if (quelCombat == 0)
		// déplacements clavier droite gauche
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			anim.y = Q;
			vx = -speed;
			vy = 0;
			animation_x = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			anim.y = D;
			vx = speed;
			vy = 0;
			animation_x = true;
		}

		// deplacement haut bas
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			anim.y = Z;
			vy = -speed;
			vx = 0;
			animation_y = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			anim.y = S;
			vy = speed;
			vx = 0;
			animation_y = true;
		}
		else
		{
			vy = 0;
			vx = 0;
			animation_y = false;
			animation_x = false;
			anim.y = S;
			anim.x = 0;
		}
	}
}

void RaccourciPause()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !pause && tempo_pause > 40)
	{
		pause = true;
		tempo_pause = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && pause && tempo_pause > 40)
	{
		pause = false;
		tempo_pause = 0;
	}
}

void ActionDansLeMenu()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pause && tempo_pause > 40)
	{
		// Quitter

		if (pixelPos.x > 470 && pixelPos.x <  727 &&
			pixelPos.y > 290 && pixelPos.y < 330)

			window.close();

		// Reprendre le jeu
		if (pixelPos.x > 470 && pixelPos.x <  727 &&
			pixelPos.y > 430 && pixelPos.y < 470)
		{
			pause = false;
			tempo_pause = 0;
		}

		// Quetes
		if (pixelPos.x > 470 && pixelPos.x <  727 &&
			pixelPos.y > 230 && pixelPos.y < 270 && !quete)
		{
			quete = true;
		}

		else if (pixelPos.x > 470 && pixelPos.x <  727 &&
			pixelPos.y > 230 && pixelPos.y < 270 && quete)
		{
			quete = false;
		}

		// son "on" / "off"

		if ((pixelPos.x > 470 && pixelPos.x < 727 &&
			pixelPos.y > 170 && pixelPos.y < 210) && son)
			son = false;
		else if ((pixelPos.x > 470 && pixelPos.x < 727 &&
			pixelPos.y > 170 && pixelPos.y < 210) && !son)
			son = true;

		// on arrête la lecture et on se replace au début
		//music.stop();
	}
}

void LancerLeJeu()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !play)
	{
		if (pixelPos.x > 470 && pixelPos.x < 727 &&
			pixelPos.y > 320 && pixelPos.y < 400)
			play = true;
	}
}

void ChoixSort()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && quelCombat != 0 && position_choix == 0 && tempo_pause > 15)
	{
		if (pixelPos.x > 641 && pixelPos.x < 850 &&
			pixelPos.y > 430 && pixelPos.y < 472)
			position_choix = 1;

		else if (pixelPos.x > 641 && pixelPos.x < 850 &&
			pixelPos.y > 495 && pixelPos.y < 537)
			quelCombat = 0;

		else if (pixelPos.x > 914 && pixelPos.x < 1123 &&
			pixelPos.y > 430 && pixelPos.y < 472)
			position_choix = 2;

		tempo_pause = 0;

	}

	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && quelCombat != 0 && position_choix == 1 && tempo_pause > 15)
	{
		if (pixelPos.x > 641 && pixelPos.x < 850 &&
			pixelPos.y > 430 && pixelPos.y < 472)
		{// lance tranche
			Tranche();
		}

		else if (pixelPos.x > 641 && pixelPos.x < 850 &&
			pixelPos.y > 495 && pixelPos.y < 537)
		{//lance charge
			Charge();
		}

		else if (pixelPos.x > 914 && pixelPos.x < 1123 &&
			pixelPos.y > 409 && pixelPos.y < 451)
		{// lance l'attaque coup de tête
			CoupDeTete();
		}

		else if (pixelPos.x > 914 && pixelPos.x < 1123 &&
			pixelPos.y > 462 && pixelPos.y < 504)
		{// lance defense
			Parade();
		}

		else if (pixelPos.x > 914 && pixelPos.x < 1123 &&
			pixelPos.y > 516 && pixelPos.y < 558)
			//retour
			position_choix = 0;

		tempo_pause = 0;
	}

	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && quelCombat != 0 && position_choix == 2 && tempo_pause > 15)
	{
		if (pixelPos.x > 641 && pixelPos.x < 850 &&
			pixelPos.y > 430 && pixelPos.y < 472)
		{// lance petite popo
			UtilisePetitePotion();
		}

		else if (pixelPos.x > 641 && pixelPos.x < 850 &&
			pixelPos.y > 495 && pixelPos.y < 537)
		{//lance moyenne popo
			UtiliseMoyennePotion();
		}

		else if (pixelPos.x > 914 && pixelPos.x < 1123 &&
			pixelPos.y > 409 && pixelPos.y < 451)
		{// lance grande popo
			UtiliseGrandePotion();
		}

		else if (pixelPos.x > 914 && pixelPos.x < 1123 &&
			pixelPos.y > 462 && pixelPos.y < 504)
		{// lance miraculeuse popo
			UtiliseMiraculeusePotion();
		}

		else if (pixelPos.x > 914 && pixelPos.x < 1123 &&
			pixelPos.y > 516 && pixelPos.y < 558)
			//retour
			position_choix = 0;
		tempo_pause = 0;
	}
}

void Inventaire()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && !pause && !inventaire && tempo_pause > 10)
	{
		inventaire = true;
		pause = true;
		tempo_pause = 0;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && pause && inventaire && tempo_pause > 10)
	{
		inventaire = false;
		pause = false;
		tempo_pause = 0;
	}
}

void ChangementArme()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && inventaire)
	{
		if (pixelPos.x > 7 && pixelPos.x < 64)
		{
			if (pixelPos.y > 310 && pixelPos.y < 338)
			{
				ArmeEquipe.setTextureRect(Armes[0]);
				DoitEtreEquipe = 0;
			}

			else if (pixelPos.y > 351 && pixelPos.y < 379)
			{
				ArmeEquipe.setTextureRect(Armes[1]);
				DoitEtreEquipe = 1;
			}

			else if (pixelPos.y > 392 && pixelPos.y < 420)
			{
				ArmeEquipe.setTextureRect(Armes[2]);
				DoitEtreEquipe = 2;
			}

			else if (pixelPos.y > 433 && pixelPos.y < 461)
			{
				ArmeEquipe.setTextureRect(Armes[3]);
				DoitEtreEquipe = 3;
			}

			else if (pixelPos.y > 474 && pixelPos.y < 502)
			{
				ArmeEquipe.setTextureRect(Armes[4]);
				DoitEtreEquipe = 4;
			}

			else if (pixelPos.y > 515 && pixelPos.y < 543)
			{
				ArmeEquipe.setTextureRect(Armes[5]);
				DoitEtreEquipe = 5;
			}

			else if (pixelPos.y > 556 && pixelPos.y < 584)
			{
				ArmeEquipe.setTextureRect(Armes[6]);
				DoitEtreEquipe = 6;
			}
		}

		else if (pixelPos.x > 71 && pixelPos.x < 128)
		{
			if (pixelPos.y > 310 && pixelPos.y < 338)
			{
				ArmeEquipe.setTextureRect(Armes[7]);
				DoitEtreEquipe = 7;
			}

			else if (pixelPos.y > 351 && pixelPos.y < 379)
			{
				ArmeEquipe.setTextureRect(Armes[8]);
				DoitEtreEquipe = 8;
			}

			else if (pixelPos.y > 392 && pixelPos.y < 420)
			{
				ArmeEquipe.setTextureRect(Armes[9]);
				DoitEtreEquipe = 9;
			}

			else if (pixelPos.y > 433 && pixelPos.y < 461)
			{
				ArmeEquipe.setTextureRect(Armes[10]);
				DoitEtreEquipe = 10;
			}

			else if (pixelPos.y > 474 && pixelPos.y < 502)
			{
				ArmeEquipe.setTextureRect(Armes[11]);
				DoitEtreEquipe = 11;
			}

			else if (pixelPos.y > 515 && pixelPos.y < 543)
			{
				ArmeEquipe.setTextureRect(Armes[12]);
				DoitEtreEquipe = 12;
			}

			else if (pixelPos.y > 556 && pixelPos.y < 584)
			{
				ArmeEquipe.setTextureRect(Armes[13]);
				DoitEtreEquipe = 13;
			}
		}

		else if (pixelPos.x > 135 && pixelPos.x < 192)
		{
			if (pixelPos.y > 310 && pixelPos.y < 338)
			{
				ArmeEquipe.setTextureRect(Armes[14]);
				DoitEtreEquipe = 14;
			}

			else if (pixelPos.y > 351 && pixelPos.y < 379)
			{
				ArmeEquipe.setTextureRect(Armes[15]);
				DoitEtreEquipe = 15;
			}

			else if (pixelPos.y > 392 && pixelPos.y < 420)
			{
				ArmeEquipe.setTextureRect(Armes[16]);
				DoitEtreEquipe = 16;
			}

			else if (pixelPos.y > 433 && pixelPos.y < 461)
			{
				ArmeEquipe.setTextureRect(Armes[17]);
				DoitEtreEquipe = 17;
			}

			else if (pixelPos.y > 474 && pixelPos.y < 502)
			{
				ArmeEquipe.setTextureRect(Armes[18]);
				DoitEtreEquipe = 18;
			}

			else if (pixelPos.y > 515 && pixelPos.y < 543)
			{
				ArmeEquipe.setTextureRect(Armes[19]);
				DoitEtreEquipe = 19;
			}

			else if (pixelPos.y > 556 && pixelPos.y < 584)
			{
				ArmeEquipe.setTextureRect(Armes[20]);
				DoitEtreEquipe = 20;
			}
		}
		if (armePossede[DoitEtreEquipe])
			tim.sortirArme(DoitEtreEquipe, gain, arme);
	}
}

void EnJeu()
{
	// Temps de jeu
#pragma region temps jeu
	temps_jeu = true;
	tps++;
	tps_sec = (tps / 60) % 60;
	tps_min = tps / 3600;

	// Mettre variable temps en tant que variable text et regler police

	std::string temps_min = toString(tps_min);
	std::string temps_sec = toString(tps_sec);
	std::string stemps1 = " min ";
	std::string stemps2 = " sec ";
	std::string temps = (temps_min + stemps1 + temps_sec + stemps2);

#pragma endregion temps jeu

#pragma region reglage police
	// choix de la police à utiliser
	temps_de_jeu.setFont(font); // font est un sf::Font

	// choix de la chaîne de caractères à afficher
	temps_de_jeu.setString(temps);

	// choix de la taille des caractères
	temps_de_jeu.setCharacterSize(25); // exprimée en pixels, pas en points !

	// choix de la couleur du texte
	temps_de_jeu.setColor(sf::Color::Black);

	/* choix du style du texte
	temps_de_jeu.setStyle(sf::Text::Bold);*/

#pragma endregion reglage police


	// collision avec objet
#pragma region collision

	Collision();

#pragma endregion collision


#pragma region collisionEnnemi 
	// On regarde s'il y a un ennemi et s'il y en a un on lance le combat qui differe selon si l'adversaire est un loup ou un squelette
	CollisionEnnemie();

#pragma endregion collisionEnnemi




	// collision avec les bords
#pragma region bords

	CollisionBords();

#pragma endregion bords

}

void Evenements()
{
	// Déplacement clavier
#pragma region deplacemet clavier
	DeplacementClavier();
#pragma endregion deplacement clavier

	// Activer/Desactiver le menu pause
#pragma region raccourcis pause
	RaccourciPause();
#pragma endregion raccourcis pause

	// Recuperation coo souris + adaptation monde
	pixelPos = sf::Mouse::getPosition(window);
	worldPos = window.mapPixelToCoords(pixelPos);

	// Action menu pause avec clic souris
#pragma region action via menu
	ActionDansLeMenu();
#pragma endregion action via menu

	// Lancer le jeu
	LancerLeJeu();

	miseEnPlaceVieAdversaire();

#pragma region choix sort
	ChoixSort();
#pragma endregion choix sort

#pragma region Le_Combat
	Combat();
#pragma endregion Le_Combat

	// Raccourcis inventaire
#pragma region inventaire
	Inventaire();
#pragma endregion inventaire

#pragma region changement_arme

	// Changement d'arme dans l'inventaire
	ChangementArme();
#pragma endregion changement_arme
}

void GestionDuTemps()
{
	temps_jeu = true;
	tps++;
	tps_sec = (tps / 60) % 60;
	tps_min = tps / 3600;

	// Mettre variable temps en tant que variable text et regler police

	temps_min = toString(tps_min);
	temps_sec = toString(tps_sec);
	stemps1 = " min ";
	stemps2 = " sec ";
	temps = (temps_min + stemps1 + temps_sec + stemps2);
}

void ReglagePolice()
{
	// choix de la police à utiliser
	temps_de_jeu.setFont(font); // font est un sf::Font

	// choix de la chaîne de caractères à afficher
	temps_de_jeu.setString(temps);

	// choix de la taille des caractères
	temps_de_jeu.setCharacterSize(30); // exprimée en pixels, pas en points !

	// choix de la couleur du texte
	temps_de_jeu.setColor(sf::Color::Black);

	/* choix du style du texte
	temps_de_jeu.setStyle(sf::Text::Bold);*/
}

void AffichageNiveau()
{
	affichage_niveau = toString(niveau);
	// choix de la police à utiliser
	niveau_perso.setFont(font_niveau); // font_niveau est un sf::Font
	niveau_perso_fight.setFont(font_niveau);

	// choix de la chaîne de caractères à afficher
	niveau_perso.setString(affichage_niveau);
	niveau_perso_fight.setString(affichage_niveau);

	// choix de la taille des caractères
	niveau_perso.setCharacterSize(60); // exprimée en pixels, pas en points !
	niveau_perso_fight.setCharacterSize(45);

	// choix de la couleur du texte
	niveau_perso.setColor(sf::Color::Black);
	niveau_perso_fight.setColor(sf::Color::Yellow);

	/* choix du style du texte
	temps_de_jeu.setStyle(sf::Text::Bold);*/
}

void LaView()
{
	view.reset(sf::FloatRect(0, 0, LARGEUR_FENETRE, HAUTEUR_FENETRE));
	position.x = (hero.getPosition().x - LARGEUR_FENETRE / 2);
	position.y = (hero.getPosition().y - HAUTEUR_FENETRE / 2);

	if (position.x < 0) position.x = 0;
	else if (position.x > NB_BLOCK_LARGEUR*TAILLE_BLOCK - LARGEUR_FENETRE) position.x = NB_BLOCK_LARGEUR*TAILLE_BLOCK - LARGEUR_FENETRE;

	if (position.y < 0) position.y = 0;
	else if (position.y > NB_BLOCK_HAUTEUR*TAILLE_BLOCK - HAUTEUR_FENETRE) position.y = NB_BLOCK_HAUTEUR*TAILLE_BLOCK - HAUTEUR_FENETRE;

	view.reset(sf::FloatRect(position.x, position.y, LARGEUR_FENETRE, HAUTEUR_FENETRE));
	window.setView(view);
}

void AffichageSetPosition()
{
	// Positionner le niveau sur la map
	niveau_perso.setPosition(position.x + 128, position.y + 12);
	niveau_perso_fight.setPosition(position.x + 82, position.y + 529);

	// Position boutons du menu pause
	bouton_son.setPosition((position.x + LARGEUR_FENETRE / 2) - 130, (position.y + HAUTEUR_FENETRE / 2) - 130);

	quetes.setPosition((position.x + LARGEUR_FENETRE / 2) - 130, (position.y + HAUTEUR_FENETRE / 2) - 70);
	quitter.setPosition((position.x + LARGEUR_FENETRE / 2) - 130, (position.y + HAUTEUR_FENETRE / 2) - 10);
	retour_jeu.setPosition((position.x + LARGEUR_FENETRE / 2) - 130, (position.y + HAUTEUR_FENETRE / 2) + 130);

	// Positionnement du launcher
	launcher.setPosition(position.x, position.y);
	jouer.setPosition((position.x + LARGEUR_FENETRE / 2) - 130, (position.y + HAUTEUR_FENETRE / 2) + 20);
	credits.setPosition((position.x + 30), (position.y + HAUTEUR_FENETRE - 70));
	regle_comm.setPosition((position.x + 317), (position.y + HAUTEUR_FENETRE - 70));

	//position du pont
	pont.setPosition(1472, 192);

	// recupération coo de la souris
	souris_local = sf::Mouse::getPosition(window); // coo local
	souris_world = window.mapPixelToCoords(souris_local); // coo monde


	// Position fenetre de combat ------------------------------------------------------------------- rajoute 2 qui suivent en comptant celui là premier------------------------------------------------------------------
	fight_loup.setPosition(position.x, position.y);
	fight_squelette.setPosition(position.x, position.y);
	fight_boss.setPosition(position.x, position.y);

	// Position des entités lors du combat
	loup_fight.setPosition(position.x + 500, position.y + 15);
	squelette_fight.setPosition(position.x + 640, position.y);
	boss_fight.setPosition(position.x + 392, position.y + 12);
	hero_fight.setPosition(position.x + 182, position.y + 234);

	// Position bouton de choix en combat
	choix.setPosition(position.x + 620, position.y + 406);
	attaques.setPosition(position.x + 620, position.y + 406);
	potions.setPosition(position.x + 620, position.y + 406);

	// TRIANGLE DE CHOIX EN FIGHT
	triangle_hg.setPosition(position.x + 631, position.y + 451);
	triangle_bg.setPosition(position.x + 631, position.y + 516);
	triangle_hd0.setPosition(position.x + 894, position.y + 451);
	triangle_hd12.setPosition(position.x + 894, position.y + 430);
	triangle_m12.setPosition(position.x + 894, position.y + 483);
	triangle_bd12.setPosition(position.x + 894, position.y + 537);

	// Position de l'interface
	interface.setPosition(position.x, position.y);

	// Position BG quete
	bg_quete.setPosition((position.x + LARGEUR_FENETRE / 2) + 160, (position.y + HAUTEUR_FENETRE / 2) - 209);

	// Position du menu pause
	menu_pause.setPosition((position.x + LARGEUR_FENETRE / 2) - 160, (position.y + HAUTEUR_FENETRE / 2) - 224);

	// Positionner le temps sur la map temps de jeu
	temps_de_jeu.setPosition(position.x + 115, position.y - 12);

	// Position des descriptif des quetes
	quete1.setPosition((position.x + LARGEUR_FENETRE / 2) + 178, (position.y + HAUTEUR_FENETRE / 2) - 168);
	quete1V.setPosition((position.x + LARGEUR_FENETRE / 2) + 178, (position.y + HAUTEUR_FENETRE / 2) - 168);
	quete2.setPosition((position.x + LARGEUR_FENETRE / 2) + 178, (position.y + HAUTEUR_FENETRE / 2) - 51);
	quete2V.setPosition((position.x + LARGEUR_FENETRE / 2) + 178, (position.y + HAUTEUR_FENETRE / 2) - 51);
	quete3.setPosition((position.x + LARGEUR_FENETRE / 2) + 178, (position.y + HAUTEUR_FENETRE / 2) + 66);
	quete3V.setPosition((position.x + LARGEUR_FENETRE / 2) + 178, (position.y + HAUTEUR_FENETRE / 2) + 66);



	// association du triangle quand on passe la souris sur un bouton
	// haut gauche
	if (souris_local.x > 641 && souris_local.x < 850 &&
		souris_local.y > 430 && souris_local.y < 472)
		triangle_hg.setTextureRect(sf::IntRect(0, 0, 20, 20));
	else
		triangle_hg.setTextureRect(sf::IntRect(0, 20, 20, 20));

	// bas gauche
	if (souris_local.x > 641 && souris_local.x < 850 &&
		souris_local.y > 495 && souris_local.y < 537)
		triangle_bg.setTextureRect(sf::IntRect(0, 0, 20, 20));
	else
		triangle_bg.setTextureRect(sf::IntRect(0, 20, 20, 20));

	// haut droite position_choix = 0
	if (souris_local.x > 914 && souris_local.x < 1123 &&
		souris_local.y > 430 && souris_local.y < 472)
		triangle_hd0.setTextureRect(sf::IntRect(0, 0, 20, 20));
	else
		triangle_hd0.setTextureRect(sf::IntRect(0, 20, 20, 20));

	// haut droite position_choix = 1 et 2
	if (souris_local.x > 914 && souris_local.x < 1123 &&
		souris_local.y > 409 && souris_local.y < 451)
		triangle_hd12.setTextureRect(sf::IntRect(0, 0, 20, 20));
	else
		triangle_hd12.setTextureRect(sf::IntRect(0, 20, 20, 20));

	//milieu position_choix = 1 et 2
	if (souris_local.x > 914 && souris_local.x < 1123 &&
		souris_local.y > 462 && souris_local.y < 504)
		triangle_m12.setTextureRect(sf::IntRect(0, 0, 20, 20));
	else
		triangle_m12.setTextureRect(sf::IntRect(0, 20, 20, 20));

	// bas droite position_choix = 1 et 2
	if (souris_local.x > 914 && souris_local.x < 1123 &&
		souris_local.y > 516 && souris_local.y < 558)
		triangle_bd12.setTextureRect(sf::IntRect(0, 0, 20, 20));
	else
		triangle_bd12.setTextureRect(sf::IntRect(0, 20, 20, 20));
}

void SetPositionArmeInventaire()
{
	ligne_inventaire = 0;
	for (int i = 0; i < 21; i++)
	{
		colonne_inventaire = i / 7;
		s_Armes[i].setPosition(position.x + 7 + colonne_inventaire * 64, position.y + 310 + ligne_inventaire * 41);
		Descript_arme[i].setPosition(position.x + 64 + colonne_inventaire * 64, position.y + 268 + ligne_inventaire * 41);
		if (ligne_inventaire == 6)
			ligne_inventaire = 0;
		else
			ligne_inventaire += 1;
	}

	ArmeEquipe.setPosition(position.x + 71, position.y + 187);
	if (descript_equipe == true)
		Descript_arme[Descriptif_quel_arme].setPosition(position.x + 128, position.y + 187);
}

void TextureBouton()
{
	// Position boutons du menu pause
	bouton_son.setPosition((position.x + LARGEUR_FENETRE / 2) - 130, (position.y + HAUTEUR_FENETRE / 2) - 130);
	quetes.setPosition((position.x + LARGEUR_FENETRE / 2) - 130, (position.y + HAUTEUR_FENETRE / 2) - 70);
	quitter.setPosition((position.x + LARGEUR_FENETRE / 2) - 130, (position.y + HAUTEUR_FENETRE / 2) - 10);
	retour_jeu.setPosition((position.x + LARGEUR_FENETRE / 2) - 130, (position.y + HAUTEUR_FENETRE / 2) + 130);

	// Position boutons du launcher
	jouer.setPosition((position.x + LARGEUR_FENETRE / 2) - 130, (position.y + HAUTEUR_FENETRE / 2) + 20);
	credits.setPosition((position.x + 30), (position.y + HAUTEUR_FENETRE - 70));
	regle_comm.setPosition((position.x + 317), (position.y + HAUTEUR_FENETRE - 70));

	// choix sprite bouton son
	// son "on"
	if (son)
	{
		if (souris_local.x > 470 && souris_local.x < 727 &&
			souris_local.y > 170 && souris_local.y < 210)
			bouton_son.setTextureRect(sf::IntRect(0, 360, 257, 40));
		else
			bouton_son.setTextureRect(sf::IntRect(0, 320, 257, 40));
	}

	// son "off"
	else
	{
		if (souris_local.x > 470 && souris_local.x < 727 &&
			souris_local.y > 170 && souris_local.y < 210)
			bouton_son.setTextureRect(sf::IntRect(0, 280, 257, 40));
		else
			bouton_son.setTextureRect(sf::IntRect(0, 240, 257, 40));
	}

	// choix sprite bouton quete
	if (souris_local.x > 470 && souris_local.x <  727 &&
		souris_local.y > 230 && souris_local.y < 270)
		quetes.setTextureRect(sf::IntRect(0, 200, 257, 40));
	else
		quetes.setTextureRect(sf::IntRect(0, 160, 257, 40));

	// choix sprite bouton quitter
	if (souris_local.x > 470 && souris_local.x <  727 &&
		souris_local.y > 290 && souris_local.y < 330)
		quitter.setTextureRect(sf::IntRect(0, 120, 257, 40));
	else
		quitter.setTextureRect(sf::IntRect(0, 80, 257, 40));

	// choix sprite bouton retour au jeu
	if (souris_local.x > 470 && souris_local.x <  727 &&
		souris_local.y > 430 && souris_local.y < 470)
		retour_jeu.setTextureRect(sf::IntRect(0, 40, 257, 40));
	else
		retour_jeu.setTextureRect(sf::IntRect(0, 0, 257, 40));

	// choix sprite bouton jouer
	if (souris_local.x > 470 && souris_local.x <  727 &&
		souris_local.y > 320 && souris_local.y < 400)
		jouer.setTextureRect(sf::IntRect(0, 640, 257, 80));
	else
		jouer.setTextureRect(sf::IntRect(0, 560, 257, 80));

	// choix sprite bouton credits
	if (souris_local.x > 30 && souris_local.x <  287 &&
		souris_local.y > 530 && souris_local.y < 570)
		credits.setTextureRect(sf::IntRect(0, 520, 257, 40));
	else
		credits.setTextureRect(sf::IntRect(0, 480, 257, 40));

	// choix sprite bouton regle/commandes
	if (souris_local.x > 317 && souris_local.x <  574 &&
		souris_local.y > 530 && souris_local.y < 570)
		regle_comm.setTextureRect(sf::IntRect(0, 440, 257, 40));
	else
		regle_comm.setTextureRect(sf::IntRect(0, 400, 257, 40));
}

void AffichagePotion()
{
	for (int i = 0; i < 4; i++)
	{
		popo[i] = toString(potions_restante[i]);
	}

	// choix de la police à utiliser
	popo_p.setFont(font_popo);
	popo_m.setFont(font_popo);
	popo_g.setFont(font_popo);
	popo_M.setFont(font_popo);

	// choix de la chaîne de caractères à afficher
	popo_p.setString(popo[0]);
	popo_m.setString(popo[1]);
	popo_g.setString(popo[2]);
	popo_M.setString(popo[3]);

	// choix de la taille des caractères
	popo_p.setCharacterSize(30); // exprimée en pixels, pas en points !
	popo_m.setCharacterSize(30);
	popo_g.setCharacterSize(30);
	popo_M.setCharacterSize(30);

	// choix de la couleur du texte
	if (inventaire)
	{
		popo_p.setColor(sf::Color::White);
		popo_m.setColor(sf::Color::White);
		popo_g.setColor(sf::Color::White);
		popo_M.setColor(sf::Color::White);
	}

	else
	{
		popo_p.setColor(sf::Color::Black);
		popo_m.setColor(sf::Color::Black);
		popo_g.setColor(sf::Color::Black);
		popo_M.setColor(sf::Color::Black);
	}

	// Position des variable popo
	if (inventaire)
	{
		popo_p.setPosition(position.x + 54, position.y + 213);
		popo_m.setPosition(position.x + 54, position.y + 251);
		popo_g.setPosition(position.x + 114, position.y + 251);
		popo_M.setPosition(position.x + 180, position.y + 251);
	}
	else
	{
		popo_p.setPosition(position.x + 836, position.y + 433);
		popo_m.setPosition(position.x + 836, position.y + 504);
		popo_g.setPosition(position.x + 1121, position.y + 417);
		popo_M.setPosition(position.x + 1121, position.y + 472);
	}
}

void Reinitialisation()
{
	quelCombat = 0;
	speed = 2; vx = 0; vy = 0; tempo_pause = 0; vitesse_sprite = 0; position_choix = 0;
	pause = false;
	temps_jeu = true;
	lecture_music = true;
	animation_x = false, animation_y = false;
	son = true;
	play = false;
	boss = false;
	inventaire = false;
	quete = false;
	colonne_inventaire = 0;
	ligne_inventaire = 0;
	DoitEtreEquipe = 0;
	EstEquipe = 0;
	debutCombat = false;
	continu = true;
	estVivantJoueur = true;
	estVivantAdversaire = true;
	ChoixAttaque = false;
	effetAleatoire;
	combatOu = 0;
	Descriptif_quel_arme = 25; //------------------------------------------------
	descript_equipe = false;
	tempo_up = 0;
	ancien_lvl = 0;
	tempo_arme_debloque = 0;
	nombre_arme_true = 0;
	ancien_nombre_arme_true = 1;
	nouvelleArme = 0;
	bossEnVie = true;
	coupPlusUn = "";
	recommencer = 0;
	reponseContinuer = true;
	reponseRetry = true;

	ecombat = false; // booleen qui va permettre de savoir si on se bat 
	stop = "non"; // Texte qui permettra de savoir si le joueur veut arrêter le combat
	Ratio newratiogain; // Creation d'un objet qui déterminera les gains
	Gain newgain; // Creation d'un objet qui distribuera le gain
	Arme newarme; // Creation d'un objet qui permettra le changement d'arme
	ratiogain = newratiogain;
	gain = newgain;
	arme = newarme;
	nombreEnemi = 0; nombreEnemi2 = 0; // Variables qui vont stocker le nombre de loups et de squelettes
	nonfuite = true;
	derniereArme = false;
	bouclepresence = 0;
	redirenbennemi = true;
}

#endif