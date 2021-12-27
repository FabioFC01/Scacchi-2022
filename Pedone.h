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
	Pedone(int rig, int col, bool color);

	//override del metodo move
	bool move (int r, int c) override;

};

#endif