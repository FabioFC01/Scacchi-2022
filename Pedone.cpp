#include "Pedone.h"


//costruttore della classe pedonei
Pedone::Pedone(int rig, int col, bool color) {
	
	//inizializziamo la var. booleana a true
	primaMossa = true;


	//chiamo i metodi della classe Pezzo
	//per inizializzare la posizione del pedone
	setRiga(rig);
	setColonna(col);
	setColore(color);


	//test vari con i metodi della classe madre Pezzo

	//cout << getRiga() << endl;
	//cout << getColonna() << endl;



}


//ovviamente è ancora da scrivere la definizione
//questa funzione deve soltanto vedere se il pedone può fare quella mossa
//sapendo il suo modo di muoversi
//NON deve controllare le conseguenze per gli altri pezzi della scacchiera
//es. se il suo re è sotto scacco

//il pedone solitamente si muove andando lungo le righe e non cambia colonna
//i pedoni bianchi si muovono in ordine crescente di righe,
//i neri in ordine decrescente di righe

//rig e col designano le coordinate di arrivo
//cattura = true se con questo spostamento posso catturare un pezzo avversario
bool Pedone::move(int rig, int col, bool cattura) {

	int spostRighe = rig - getRiga(); //spostamento lungo le righe (in alto e in basso)
	int spostColonne = col - getColonna(); //spostamento lungo le colonne (dx/sx)

	//primo controllo da fare, se la posizione di arrivo è dentro la scacchiera
	if (! dentroScacchiera(rig, col)) {
		return false;
	}

	//se è pedone bianco
	if (! getColore()) {
		//se non ha ancora fatto la prima mossa può spostarsi di due in avanti
		if (primaMossa && (spostRighe == 2 || spostRighe == 1 ) && spostColonne == 0) {

			setRiga(rig);	//spostamento lungo le righe
			primaMossa = false;

			return true;	//successo

		}
		//se lo spostamento lungo le righe è di uno in alto
		if (spostRighe == 1 && spostColonne == 0) {
			setRiga(rig);
			return true;
		}
		//le due mosse laterali che si possono fare solo se puoi catturare un pezzo avversario
		if (cattura && ((spostRighe==1 && spostColonne == 1) || (spostRighe == 1 && spostColonne == -1)) ) {
			setRiga(rig);
			setColonna(col);

			if (primaMossa) { primaMossa = false; }

			return true;

		}
		else {
			//fallimento nello spostamento
			//c'è ovviamente ancora da mettere il mangiare gli altri
			//l'en passant
			//il pedone che diventa altro
			
			return false;
		}



	}
	//se è pedone nero
	else {
		//se non ha ancora fatto la prima mossa può spostarsi di due in avanti
		if (primaMossa && (spostRighe == -2 || spostRighe == -1) && spostColonne == 0) {
			setRiga(rig);	//spostamento lungo le righe
			primaMossa = false;

			return true;	//successo
		}
		//mossa di 1 in avanti
		if (spostRighe == -1 && spostColonne == 0) {
			setRiga(rig);
			return true;
		}
		//le due mosse laterali che si possono fare solo se puoi catturare un pezzo avversario
		if (cattura && ((spostRighe == -1 && spostColonne == 1) || (spostRighe == -1 && spostColonne == -1))) {
			setRiga(rig);
			setColonna(col);

			if (primaMossa) { primaMossa = false; }

			return true;

		}

		else {
			//vedi note nel caso del pedone bianco
			return false;
		}

	}


	return true;
}