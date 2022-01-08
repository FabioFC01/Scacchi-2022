#ifndef Regina_h
#define Regina_h

#include "Pezzo.h"
#include <iostream>

using namespace std;

class Regina : public Pezzo {
	//classe del pezzo Regina

private:






public:
	//costruttore
	Regina(const bool color);
	//color true per bianco
	//false per nero

	//metodo move della classe Pezzo
	bool move(const Casella inizio, const Casella arrivo, const bool cattura) override;

	//metodo getCaselleIntermedie della classe Pezzo
	std::vector<Casella> getCaselleIntermedie(const Casella inizio, const Casella fine) override;




};

#endif