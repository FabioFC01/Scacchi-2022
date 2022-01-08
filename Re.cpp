#include "Re.h"

//costruttore
Re::Re(const bool color) {
	setColore(color);

	//bianco
	if (getColore()) {
		setSimbolo('r');
	}
	//nero
	else {
		setSimbolo('R');
	}

}

//metodo move
//serve per capire se pu� fare quella mossa (immaginando una scacchiera tutta vuota
//cattura = true se con questo spostamento posso catturare un pezzo avversario
bool Re::move(const Casella inizio, const Casella arrivo, const bool cattura) {

	int absSpostRighe = arrivo.getRiga() - inizio.getRiga(); //spostamento lungo le righe (in alto e in basso)
	int absSpostColonne = arrivo.getColonna() - inizio.getColonna(); //spostamento lungo le colonne (dx/sx)

	//rendiamo questi valori assoluti
	if (absSpostRighe < 0) { absSpostRighe *= -1; }
	if (absSpostColonne < 0) { absSpostColonne *= -1;}


	int rig = arrivo.getRiga();
	int col = arrivo.getColonna();

	//primo controllo da fare, se la posizione di arrivo � dentro la scacchiera
	if (!dentroScacchiera(rig, col)) {
		return false;
	}

	//il re ha comportamenti nel movimento indipendenti dal suo colore

	//il re pu� muoversi in tutte le direzioni adiacenti

	//movimento su / gi�
	if (absSpostRighe == 1 && absSpostColonne == 0) { return true; }
	//movimenti diagonale (tutti e 4)
	if (absSpostRighe == 1 && absSpostColonne == 1) { return true; }
	//movimenti dx/sx
	if (absSpostRighe == 0 && absSpostColonne == 1) { return true; }

	//se non � nessuno di questi deve essere un movimento errato per forza
	return false;


}


//il re si muove soltanto nelle caselle adiacenti, quindi non bisogna controllare nulla
std::vector<Casella> Re::getCaselleIntermedie(const Casella inizio, const Casella fine) {

	return vector<Casella> ();

}