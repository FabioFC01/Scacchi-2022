#ifndef Pedone_h
#define Pedone_h

#include "Pezzo.h"
#include <iostream>

using namespace std;

class Pedone : public Pezzo {
	//classe del pezzo Pedone
	//è una classe derivata della classe Pezzo

private:
	//valore booleano che è true se il pedone si trova nella posizione iniziale
	//perchè se fosse così può fare un salto in avanti di due caselle
	//dopo la prima mossa questo valore sarà sempre false
	bool primaMossa;



public:
	//costruttore
	Pedone(const int rig, const int col, const bool color);

	//metodo move della classe Pezzo modificato
	//Non c'è override
	bool move (const int r, const int c, const bool cattura);


};

#endif