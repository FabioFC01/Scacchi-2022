#include "Pedone.h"


//costruttore della classe pedonei
Pedone::Pedone(int rig, char col) {
	
	//inizializziamo la var. booleana a true
	primaMossa = true;


	//chiamo i metodi della classe Pezzo
	//per inizializzare la posizione del pedone
	setRiga(rig);
	setColonna(col);


	//test vari con i metodi della classe madre Pezzo

	cout << getRiga() << endl;
	cout << getColonna() << endl;



}


//ovviamente è ancora da scrivere la definizione
bool Pedone::move(int r, char c) {


	return true;
}