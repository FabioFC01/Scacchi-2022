#include "Pezzo.h"

//implementiamo i vari metodi della classe Pezzo

void Pezzo::setColonna(const int c) {
	//non metto controlli 
	//dovrei metterli?

	colonna = c;
}

void Pezzo::setRiga(const int r) {
	//non metto controlli 
	//dovrei metterli?

	riga = r;
}

void Pezzo::setColore(const bool b) {
	colore = b;
}


bool Pezzo::move(int r, int c) {

	return true;
}

bool Pezzo::dentroScacchiera(const int rig, const int col) {
	if ((rig <= 7 && rig >= 0) && (col <= 7 && col >= 0)) {
		//tale casella è all'interno della scacchiera
		return true;
	}
	else {
		return false;
	}
}
