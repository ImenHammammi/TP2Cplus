// TP2Cplus.cpp : 

#include <iostream>
#include <string>
#include <map>
#include "ElementFacturable.h"
#include "FacturableParUnite.h"
#include "FacturableFraisFixe.h"
#include "InvalideException.h"
using namespace std;
bool existInMap(int priorite, std::map<int, ElementFacturable*> &les_elments_de_la_facture);
void ajouterAccesAuSpa(double prix, std::map<int, ElementFacturable*> &les_elments_de_la_facture);
void ajouterAccesAuGym(double prix, std::map<int, ElementFacturable*> &les_elments_de_la_facture);
void ajouterNuitees(double prix, int quantite, std::map<int, ElementFacturable*> &les_elments_de_la_facture);
void ajouterRepas(double prix, int quantite, std::map<int, ElementFacturable*> &les_elments_de_la_facture);
void afficherTotal(std::map<int, ElementFacturable*> &les_elments_de_la_facture);

int main()
{
	
	int menu;
	int quantite;
	int priorite;
	std::map<int, ElementFacturable*> les_elments_de_la_facture;
	
	do
	{
	    cout << endl << " ----------------------- MENU -----------------------" << endl << endl;
		cout << "1. Ajouter des nuitees" << endl;
		cout << "2. Ajouter des repas" << endl;
		cout << "3. Ajouter un acces au spa" << endl;
		cout << "4. Ajouter un acces au gym" << endl;
		cout << "5. Afficher la facture et quitter" << endl;
		cout << "Choix : ";
		cin >> menu;
		cout << endl;

		switch (menu)
		{
		
		case 1:
		{
			double prixNuitees = 100.0;
			priorite = 1;
			cout << "Entrez le nombre de nuitees a facturer" << endl;
			cin >> quantite;
			try {
			if(quantite<=0)
				throw InvalideException("La quantite doit etre superieur a 0");
			if (les_elments_de_la_facture.find(priorite) != les_elments_de_la_facture.end())
				throw InvalideException("Cet element est deja facture");
			ajouterNuitees(prixNuitees, quantite, les_elments_de_la_facture);
			}
			catch (InvalideException ex){
				std::cout << ex.what();
			}

			break;
		}
		case 2: 
		{
			double prixRepas = 20.0;
			priorite = 2;
			cout << "Entrez le nombre de repas a facturer" << endl;
			cin >> quantite;
			try {
				if (quantite <= 0)
					throw InvalideException("La quantite doit etre superieur a 0");
				if (les_elments_de_la_facture.find(priorite) != les_elments_de_la_facture.end())
					throw InvalideException("Cet element est deja facture");
				ajouterRepas(prixRepas, quantite, les_elments_de_la_facture);
			}
			catch (InvalideException ex) {
				std::cout << ex.what();
			}
			
			break;
		}
		case 3: 
		{
			priorite = 3;
			double prixSpa = 75.0;
			try {
			if (les_elments_de_la_facture.find(priorite) != les_elments_de_la_facture.end())
				throw InvalideException("Cet element est deja facture");
			ajouterAccesAuSpa(prixSpa, les_elments_de_la_facture);
			}
			catch (InvalideException ex) {
				std::cout << ex.what();
			}
			break;
		}
		case 4: 
		{
			priorite = 4;
            double prixGym = 50.0;
			try {
				if (les_elments_de_la_facture.find(priorite) != les_elments_de_la_facture.end())
					throw InvalideException("Cet element est deja facture");
			ajouterAccesAuGym(prixGym, les_elments_de_la_facture);
		}
		    catch (InvalideException ex) {
			std::cout << ex.what();
		    }
			break;
		}
		case 5: 
			afficherTotal(les_elments_de_la_facture);
			std::map<int, ElementFacturable*>::iterator iter;
			for (iter = les_elments_de_la_facture.begin();iter != les_elments_de_la_facture.end();iter++) {
				delete iter->second;
				iter->second = NULL;
			}
			menu = 0;
			break;
		}
	} while (menu != 0);
}

void ajouterAccesAuSpa(double prix, std::map<int, ElementFacturable*> &les_elments_de_la_facture) {
	string nom = "Spa  ";
	int priorite = 3;
	FacturableFraisFixe* accesSpa = NULL;
	accesSpa = new FacturableFraisFixe(nom,prix );
	les_elments_de_la_facture.insert(std::pair<int, ElementFacturable*>(priorite, accesSpa));
}

void ajouterAccesAuGym(double prix, std::map<int, ElementFacturable*> &les_elments_de_la_facture) {
	string nom = "Gym  ";
	int priorite = 4;
	FacturableFraisFixe* accesGym = NULL;
	accesGym = new FacturableFraisFixe(nom, prix);
	les_elments_de_la_facture.insert(std::pair<int, ElementFacturable*>(priorite, accesGym));
}

void ajouterNuitees(double prix, int quantite, std::map<int, ElementFacturable*> &les_elments_de_la_facture){
	string nom = "Nuitee";
	int priorite = 1;
	FacturableParUnite* accesNuitees = NULL;
	accesNuitees = new FacturableParUnite(nom, prix, quantite);
	les_elments_de_la_facture.insert(std::pair<int, ElementFacturable*>(priorite, accesNuitees));
}

void ajouterRepas(double prix, int quantite, std::map<int, ElementFacturable*> &les_elments_de_la_facture) {
	string nom = "Repas";
	int priorite = 2;
	FacturableParUnite* accesRepas = NULL;
	accesRepas = new FacturableParUnite(nom, prix, quantite);
	les_elments_de_la_facture.insert(std::pair<int, ElementFacturable*>(priorite, accesRepas));
}

void afficherTotal( std::map<int, ElementFacturable*> &les_elments_de_la_facture) {
	double total = 0;
	double taxe = 0;
	std::map<int, ElementFacturable*>::iterator iter;
	std::cout << "-----------------------------------------------------"<<std::endl;
	std::cout << "                       FACTURE                       " << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	for (iter = les_elments_de_la_facture.begin();iter != les_elments_de_la_facture.end();iter++) {
		iter->second->afficherFacture();
		total += iter->second->calculerMontantFacture();
		taxe += iter->second->calculerTaxeFacture();
	}
	string chaine_taxe = "Taxes";
	string chaine_total = "Total";
	std::printf("%36s      :%9.2f\n", chaine_taxe.c_str(), taxe);
	std::printf("%36s      :%9.2f\n", chaine_total.c_str(), total);
}