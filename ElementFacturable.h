#ifndef DEF_ELEMENTFACTURABLE
#define DEF_ELEMENTFACTURABLE
#include <string>
#include <iostream>
class ElementFacturable
{
protected:
	std::string nom;
	double prix;
public:
	ElementFacturable(std::string le_nom, double le_prix);
	virtual double calculerMontantFacture()=0;
	virtual ~ElementFacturable() {
	}
    virtual void afficherFacture(){
		std::printf("%-16s Quant:        Prix       : %8.2f\n", nom.c_str(),prix);
	}
	virtual double calculerTaxeFacture() {
		return (prix*0.15);

	}
};
#endif
