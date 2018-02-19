#ifndef DEF_NOMAIN
#define DEF_NOMAIN

#include "constante.h"


int test(int retry)
{

	// Initialisation du chargement + dessin 
#pragma region chargement
	if (!t_chargement.loadFromFile("Images/chargement.png"))
	{
		return 0;
	}
	Chargement();
#pragma endregion chargement
	if (retry != 0)
	{
		Reinitialisation();
		tim.restart();
	}
	// IPS définie 
		window.setFramerateLimit(60);

#pragma region matriceEnnemi
	definition_presence_ennemie();
#pragma endregion matriceEnemmi

	if (retry == 0)
	{
#pragma region texture
		MiseEnPlaceTextureGeneral();
#pragma endregion texture
	}
	else 
		hero.setPosition(sf::Vector2f(64, 720));
	// on fait tourner la boucle principale
	while (window.isOpen() && reponseContinuer)
	{
		Recuperation();

		// on gère les évènements
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			Evenements();

		} // fin while (window.pollEvent(event))

		tempo_pause++;

		if (!pause && play)
		{
			EnJeu();
		} // fin if (!pause && play)

#pragma region temps jeu
		GestionDuTemps();
#pragma endregion temps jeu
	
#pragma region reglage police
		ReglagePolice();

#pragma endregion reglage police

#pragma region affichage du niveau
		niveau = tim.sortirNiveau();
		AffichageNiveau();
#pragma endregion affichage du niveau

		// Choix sprite personnage
#pragma region sprite perso

		MouvementSprite();

		hero.setTextureRect(sf::IntRect(anim.x * 52, anim.y * 47, 52, 47));

#pragma endregion sprite perso
		// View
#pragma region view

		LaView();

#pragma endregion view

#pragma region affichage 
		AffichageSetPosition();
#pragma endregion affichage

		// Affichage description arme
#pragma region description arme( rajoute )
		DescriptionArme();

#pragma endregion description arme( rajoute )
		// Gestion de tout ce qui est barres de vie + exp


#pragma region barre de vie + xp ( rajoute )
		
		AffichagePV();
		experience = tim.sortirxp();
		sf::RectangleShape barre_vie_hero(sf::Vector2f((vie_hero * 200) / vie_hero_max, 30));
		sf::RectangleShape barre_vie_ennemi(sf::Vector2f((vie_adversaire * 200) / vie_adversaire_max, 30));
		sf::RectangleShape barre_exp(sf::Vector2f((experience * 185) / (200 + 50 * niveau), 10));

		// Positions des barre de vie + experience
		barre_exp.setPosition(position.x + 7, position.y + 30);
		barre_exp_max.setPosition(position.x + 7, position.y + 30);
		barre_vie_ennemi.setPosition(position.x + 982, position.y + 180);
		barre_vie_hero.setPosition(position.x + 194, position.y + 537);

		// couleur barres
		barre_vie_hero.setFillColor(sf::Color(6, 249, 0));
		barre_vie_ennemi.setFillColor(sf::Color(6, 249, 0));
		barre_exp_max.setFillColor(sf::Color(78, 78, 78));
		barre_exp.setFillColor(sf::Color(0, 18, 249));

#pragma endregion barre de vie + xp ( rajoute )


#pragma region position arme inventaire ( rajoute )
		SetPositionArmeInventaire();
#pragma endregion position arme inventaire ( rajoute )

#pragma region boutons
		TextureBouton();

#pragma endregion boutons


#pragma region Debut_du_Combat
		DebutCombat();
#pragma endregion Debut_du_Combat

		// Nombre de popo
#pragma region variable popo
		AffichagePotion();
#pragma endregion variable popo


		// position debloque et level up message
		up.setPosition(position.x + 450, position.y + 250);
		debloque.setPosition(position.x + 450, position.y + 275);
		// Position de la game_over
		game_over.setPosition(position.x, position.y);

		NouvelleArmeGagnee();

		// on dessine le niveau
		#pragma region draw
		DrawTout();
		if (quelCombat != 0 && tim.estVivant())
		{
			window.draw(barre_vie_ennemi);
			window.draw(barre_vie_hero);
			window.draw(barre_vie_ennemi);
			window.draw(barre_vie_hero);
			window.draw(niveau_perso_fight);
		}
		
		#pragma endregion draw
		if (inventaire)
			window.draw(barre_exp);

		window.display();
	
	} // fin while (window.isOpen() && reponseContinuer)
	
	if (reponseRetry && !reponseContinuer)
		return 0;
	else
		return 1;
}

#endif

int main()
{
	while (recommencer == 0)
	{
		recommencer = test(retry);
		retry += 1;
	}
	if (window.isOpen())
		window.close();

	return 0;
}