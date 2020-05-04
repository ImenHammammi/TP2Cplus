#ifndef DEF_FACTURABLEPARUNITE
#define DEF_FACTURABLEPARUNITE

#include <iostream>
#include <string>
#include "ElementFacturable.h"
class FacturableParUnite: public ElementFacturable{
private:
	int quantite;
public:
	FacturableParUnite(std::string le_nom, double le_prix, int quantite);
	double calculerMontantFacture();
	virtual ~FacturableParUnite() {
	}
	void afficherFacture() {
		std::printf("%-16s Quant: %-6d Prix       : %8.2f\n", nom.c_str(), quantite , quantite*prix);
	}
	double calculerTaxeFacture() {
		return (prix*quantite*0.13);
		
	}
};

#endif