#ifndef DEF_FACTURABLEFRAISFIXE
#define DEF_FACTURABLEFRAISFIXE

//#include <iostream>
//#include <string>
#include "ElementFacturable.h"
class FacturableFraisFixe : public ElementFacturable{
	public:
	FacturableFraisFixe(std::string le_nom, double le_prix);
	double calculerMontantFacture();
	virtual ~FacturableFraisFixe() {
	}
};
#endif