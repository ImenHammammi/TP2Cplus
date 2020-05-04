#include "FacturableFraisFixe.h"
FacturableFraisFixe::FacturableFraisFixe(std::string le_nom, double le_prix):ElementFacturable(le_nom, le_prix){
}
double FacturableFraisFixe::calculerMontantFacture(){
	return (prix)+ (prix*0.15);
}

