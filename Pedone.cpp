#include "Pedone.h"


//costruttore della classe pedonei
Pedone::Pedone( const bool color) {
	
	//inizializziamo la var. booleana a true
	primaMossa = true;


	//chiamo i metodi della classe Pezzo
	//per inizializzare il colore
	setColore(color);


	//bianco
	if (getColore()) {
		setSimbolo('p');
	}
	//nero
	else {
		setSimbolo('P');
	}

	



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
bool Pedone::move(const Casella inizio, const Casella arrivo, const bool cattura) {

	int spostRighe = arrivo.getRiga() - inizio.getRiga(); //spostamento lungo le righe (in alto e in basso)
	int spostColonne = arrivo.getColonna() - inizio.getColonna(); //spostamento lungo le colonne (dx/sx)

	int rig = arrivo.getRiga();
	int col = arrivo.getColonna();

	//primo controllo da fare, se la posizione di arrivo è dentro la scacchiera
	if (! dentroScacchiera(rig, col)) {
		return false;
	}

	//se è pedone bianco
	if (getColore()) {
		//se non ha ancora fatto la prima mossa può spostarsi di due in avanti
		if (primaMossa && (spostRighe == 2 || spostRighe == 1 ) && spostColonne == 0) {

			//spostamento lungo le righe
			primaMossa = false;

			return true;	//successo, puoi muoverti

		}
		//se lo spostamento lungo le righe è di uno in alto
		if (spostRighe == 1 && spostColonne == 0) {
			
			return true;
		}
		//le due mosse laterali che si possono fare solo se puoi catturare un pezzo avversario
		if (cattura && ((spostRighe==1 && spostColonne == 1) || (spostRighe == 1 && spostColonne == -1)) ) {
			
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
			primaMossa = false;

			return true;	//successo
		}
		//mossa di 1 in avanti
		if (spostRighe == -1 && spostColonne == 0) {
			return true;
		}
		//le due mosse laterali che si possono fare solo se puoi catturare un pezzo avversario
		if (cattura && ((spostRighe == -1 && spostColonne == 1) || (spostRighe == -1 && spostColonne == -1))) {
			

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


//DA IMPLEMENTARE
std::vector<Casella> Pedone::getCaselleIntermedie(const Casella inizio, const Casella fine) {

	//l'unico caso nel quale c'è una casella da controllare è quando fa la prima mossa
	//e fa un salto di due in avanti, in tutti gli altri casi si ritorna un vector vuoto

	int spostRighe = fine.getRiga() - inizio.getRiga(); //spostamento lungo le righe (in alto e in basso)
	int spostColonne = fine.getColonna() - inizio.getColonna(); //spostamento lungo le colonne (dx/sx)

	//valore assoluto di spostamento di indici di riga
	int absSpostRighe;

	if (spostRighe > 0) { absSpostRighe = spostRighe; }
	else { absSpostRighe = spostRighe * (-1); }
	

	//se si tratta di uno spostamento di due in alto/basso (dipende dal colore del pezzo)
	if (absSpostRighe == 2 && spostColonne == 0) {






	}











	//crea vettore a caso
	return vector<Casella> ();

	

}