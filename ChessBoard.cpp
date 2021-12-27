#include "ChessBoard.h"



//costruttore
/*
	*
	* Configurazione iniziale scacchiera

	8 TCADRACT
	7 PPPPPPPP
	6
	5
	4
	3
	2 pppppppp
	1 tcadract
	  ABCDEFGH


	  dove
	  P pedone
	  T torre
	  C cavallo
	  A alfiere
	  D regina
	  R re
	  ---
	  MAIUSCOLE --- PEZZI NERI
	  minuscole --- pezzi bianchi

	  inizia il bianco
	*/

/*
* 
* indici per la nostra matrice
* 
*	bianchi minuscoli
* 
*   0 tcadract
	1 pppppppp
	2
	3
	4
	5
	6 PPPPPPPP
	7 TCADRACT
	  01234567
	  ABCDEFGH

	  neri


	quindi è come se la scacchiera fosse vista dall'altra parte
	con i numeri delle righe diminuiti di 1


*/
ChessBoard::ChessBoard() {
	//inizializziamo il booleano turno a 0
	//significa che è il turno del bianco
	turno = 0;



	//inizialmente, per pulire la scacchiera char
	//tutte le righe dalla 6 alla 3
	//che hanno indice da 2 a 5
	//verranno settate a ' ' 

	for (int riga = 2; riga <= 5; riga++) {
		for (int colonna = 0; colonna < 8; colonna++) {
			scacchiera[riga][colonna] = ' ';
		}
	}



	//mettiamo i pedoni bianchi (p) nella riga 2
	//che ha numero 6
	for (int col = 0; col < 8; col++) {
		scacchiera[1][col] = 'p';	//pedoni bianchi
	}

	//mettiamo i pedoni neri (P) nella riga 7
	//che ha numero 1
	for (int col = 0; col < 8; col++) {
		scacchiera[6][col] = 'P';	//pedoni neri P
	}

	//facciamo la riga 1, che ha indice 0
	//pezzi bianchi in minuscolo

	//due torri bianche, riga 1 con indice 0
	scacchiera[0][0] = 't';
	scacchiera[0][7] = 't';

	//due cavalli bianchi
	scacchiera[0][1] = 'c';
	scacchiera[0][6] = 'c';

	//due alfieri bianchi
	scacchiera[0][2] = 'a';
	scacchiera[0][5] = 'a';

	//regina bianca
	scacchiera[0][3] = 'd';

	//re bianco
	scacchiera[0][4] = 'r';

	//--- fine pezzi bianchi
	// 
	// 
	//mettiamo riga 8 di pezzi neri
	//che ha indice 0

	//pezzi neri in MAIUSCOLO

	//due torri nere, riga 1 con indice 7
	scacchiera[7][0] = 'T';
	scacchiera[7][7] = 'T';

	//due cavalli neri
	scacchiera[7][1] = 'C';
	scacchiera[7][6] = 'C';

	//due alfieri neri
	scacchiera[7][2] = 'A';
	scacchiera[7][5] = 'A';

	//regina nera
	scacchiera[7][3] = 'D';

	//re nero
	scacchiera[7][4] = 'R';



	//in teoria ho finito la costruzione
	//della scacchiera con matrice char



	//------------------ ZONA TEST ------------------
	//inizializziamo due pedoni perchè si
	//con gli indici da 0 a 7
	//Pedone(int rig, int col, bool color)
	//color ha 0 bianco, 1 nero

	Pedone ped1(1, 0, 0);
	Pedone ped2(1, 1, 0);
	Pedone ped3N(6, 0, 1);

	ped1.move(3, 0);
	ped3N.move(5, 0);

	cout << ped1.getRiga() << ped1.getColonna() << endl; //30
	cout << ped3N.getRiga() << ped3N.getColonna() << endl; //50







	
}	//fine  costruttore



void ChessBoard::stampa() {
	//per stampare come vogliono le istruzioni le righe vanno stampate
	//in ordine decrescente seguendo la numerazione della nostra matrice
	
	int riga;
	int colonna;

	//scorrimento di riga
	for (riga = 7; riga >= 0 ; riga--) {  


		//per stampare le righe a fianco della scacchiera
		cout << (riga+1) << " ";	


		//scorrimento di colonne, lungo la riga prestabilita
		for (colonna = 0; colonna < 8; colonna++) {
			cout << scacchiera[riga][colonna] ;
		}
		
		//arrivati a fine riga si va a capo
		cout << endl ;


	}
	//finito di stampare la scacchiera stampiamo 
	//le lettere che denominano le colonne
	cout << endl;
	cout << "  ABCDEFGH" << endl << endl;

}

void ChessBoard::sceltaPartita() {
	//scelta del tipo di partita
	string input;

	cout << "Vuoi fare una partita giocatore - pc (inserisci 1)     o assistere ad una partita pc - pc  (inserisci 2) ?" << endl;
	cin >> input;

	while (!(input == "1" || input == "2")) {
		cout << "Input errato, riprovare " << endl;
		cin >> input;
	}
	//input corretto
	if (input == "1") {
		tipoPartita = 0;
	}
	if (input == "2") {
		tipoPartita = 1;
	}

}



//metodo principale che gestisce la partita giocatore - pc
void ChessBoard::partita_0() {





}


//gestione della partita pc - pc
void  ChessBoard::partita_1() {

}