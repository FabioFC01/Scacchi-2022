#ifndef Pedone_h
#define Pedone_h

#include "Pezzo.h"
#include <iostream>

using namespace std;

class Pedone : public Pezzo {
	//classe del pezzo Pedone
	//� una classe derivata della classe Pezzo

private:
	//valore booleano che � true se il pedone si trova nella posizione iniziale
	//perch� se fosse cos� pu� fare un salto in avanti di due caselle
	//dopo la prima mossa questo valore sar� sempre false
	bool primaMossa;



public:
	//costruttore
	Pedone(const int rig, const int col, const bool color);

	//metodo move della classe Pezzo modificato
	//Non c'� override
	bool move (const int r, const int c, const bool cattura);


};

#endif