#include "FacturableParUnite.h"
FacturableParUnite::FacturableParUnite(std::string le_nom, double le_prix, int la_quantite) :ElementFacturable(le_nom, le_prix) {
	this->quantite = la_quantite;
}
double FacturableParUnite::calculerMontantFacture() {
	return (prix*quantite) + (prix*quantite*0.13);
}

