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
	scaccoMatto = 0;



	//inizialmente, per pulire la scacchiera char
	//tutte le righe dalla 6 alla 3
	//che hanno indice da 2 a 5
	//verranno settate a ' ' 

	for (int riga = 2; riga <= 5; riga++) {
		for (int colonna = 0; colonna < 8; colonna++) {
			scacchiera_char[riga][colonna] = ' ';
		}
	}



	//mettiamo i pedoni bianchi (p) nella riga 2
	//che ha numero 6
	for (int col = 0; col < 8; col++) {
		scacchiera_char[1][col] = 'p';	//pedoni bianchi
	}

	//mettiamo i pedoni neri (P) nella riga 7
	//che ha numero 1
	for (int col = 0; col < 8; col++) {
		scacchiera_char[6][col] = 'P';	//pedoni neri P
	}

	//facciamo la riga 1, che ha indice 0
	//pezzi bianchi in minuscolo

	//due torri bianche, riga 1 con indice 0
	scacchiera_char[0][0] = 't';
	scacchiera_char[0][7] = 't';

	//due cavalli bianchi
	scacchiera_char[0][1] = 'c';
	scacchiera_char[0][6] = 'c';

	//due alfieri bianchi
	scacchiera_char[0][2] = 'a';
	scacchiera_char[0][5] = 'a';

	//regina bianca
	scacchiera_char[0][3] = 'd';

	//re bianco
	scacchiera_char[0][4] = 'r';

	//--- fine pezzi bianchi
	// 
	// 
	//mettiamo riga 8 di pezzi neri
	//che ha indice 0

	//pezzi neri in MAIUSCOLO

	//due torri nere, riga 1 con indice 7
	scacchiera_char[7][0] = 'T';
	scacchiera_char[7][7] = 'T';

	//due cavalli neri
	scacchiera_char[7][1] = 'C';
	scacchiera_char[7][6] = 'C';

	//due alfieri neri
	scacchiera_char[7][2] = 'A';
	scacchiera_char[7][5] = 'A';

	//regina nera
	scacchiera_char[7][3] = 'D';

	//re nero
	scacchiera_char[7][4] = 'R';



	
	//------------------ ZONA TEST ------------------
	//inizializziamo due pedoni perchè si
	//con gli indici da 0 a 7
	//Pedone(int rig, int col, bool color)
	//color ha 0 bianco, 1 nero

	/*
	Pedone ped1(1, 0, false); //bianco
	Pedone ped2(1, 1, false);
	Pedone ped3N(6, 0, true);


	ped1.move(2, 0);
	ped3N.move(5, 0);
	
	cout << ped1.getRiga() << ped1.getColonna() << endl; //30
	//cout << ped3N.getRiga() << ped3N.getColonna() << endl; //50

	*/



	this->resetScacchiera();





	
}	//fine  costruttore



void ChessBoard::stampa() const {
	//per stampare come vogliono le istruzioni le righe vanno stampate
	//in ordine decrescente seguendo la numerazione della nostra matrice
	
	int riga;
	int colonna;

	cout << endl << "  ---------------------  " << endl;


	//scorrimento di riga
	for (riga = 7; riga >= 0; riga--) {


		//per stampare le righe a fianco della scacchiera
		std::cout << (riga + 1) << " ";


		//scorrimento di colonne, lungo la riga prestabilita
		for (colonna = 0; colonna < 8; colonna++) {

			//se c'è qualcosa in quella casella
			if (scacchiera[riga][colonna] != nullptr) {
				std::cout << (*scacchiera[riga][colonna]).getSimbolo();
			}
			else {
				std::cout << " ";
			}
		}

		//arrivati a fine riga si va a capo
		std::cout << endl;


	}
	//finito di stampare la scacchiera stampiamo 
	//le lettere che denominano le colonne
	std::cout << endl;
	std::cout << "  ABCDEFGH" << endl << endl;

}


//metodo per chiedere e ottenere l'input per la successiva mossa
//del giocatore umano
Mossa ChessBoard::input() {
	string in;



	bool idoneo = false;



	do {
		//chiedi input
		std::cout << "Inserisci input :   ";
		getline(cin, in);   //B1 C2


		//controlla che la lunghezza sia corretta e che
		//all'indice 2 ci sia uno spazio
		if (in.length() == 5 && in[2] == ' ') {

			idoneo = true;
		}
		else {
			idoneo = false;
		}



	} while (!idoneo);

	//a questo punto l'input è corretto


//tiene i 4 valori delle coordinate


	int dati[4];

	string input_minuscolo = "";

	char c;
	int temp;

	char lettera;


	for (unsigned int i = 0; i < in.length(); i++) {
		//leggo un carattere della stringa
		c = in[i];

		//conversione
		temp = tolower(c);

		lettera = char(temp);

		//aggiunta alla stringa
		input_minuscolo += lettera;



	}




	//std::cout << input_minuscolo << endl;  //funziona

	//mettiamo gli indici ascii delle lettere in dati[4]


	//in dati ci sono i valori ascii di lettere e numeri
	dati[0] = input_minuscolo[0];	//colonna partenza
	dati[1] = input_minuscolo[1];	//riga partenza
	dati[2] = input_minuscolo[3];	//colonna arrivo
	dati[3] = input_minuscolo[4];	//riga arrivo



	//ora dobbiamo convertirli negli indici che usiamo nella scacchiera quindi
	//a --> 0 , b --> 1 , ... , h --> 7    per le colonne
	//1 --> 0 , 2 --> 1 , ... , 8 --> 7    per le righe

	//le due lettere minuscole
	dati[0] -= 97;
	dati[2] -= 97;

	//i due numeri
	dati[1] -= 49;
	dati[3] -= 49;


	//funziona
	//ora posso mandarli alle funzioni move ecc...

	Casella iniz(dati[1], dati[0]);
	Casella arr(dati[3], dati[2]);

	Mossa moss(iniz, arr);

	//facciamo il return

	return moss;



}

void ChessBoard::sceltaPartita() {
	//scelta del tipo di partita
	string input;

	std::cout << "Vuoi fare una partita giocatore - pc (inserisci 1)     o assistere ad una partita pc - pc  (inserisci 2) ?" << endl;
	cin >> input;

	while (!(input == "1" || input == "2")) {
		std::cout << "Input errato, riprovare " << endl;
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
	//condizione iniziale, diventerà true con il termine della partita
	scaccoMatto = false;








}


//gestione della partita pc - pc
void  ChessBoard::partita_1() {
	scaccoMatto = false;

}







//gestione partita giocatore-giocatore
void ChessBoard::partita_2() {

	//giocatore             bianco, umano
	Player giocatoreBianco(true, true);
	Player giocatoreNero(false, true);

	

	
	for (int i = 0; i < 7; i++) {

		Pezzo* pez;

		//caselle valide
		bool caselleValide = false;
		//per le regole di tale pezzo
		bool mossaFattibile = false;
		// variabile che è vera se non devi mangiare nulla,
		//oppure se devi mangiare un pezzo avversario non re
		bool catturaCorretta = false;




		//---------------------

		bool pezzoDaCatturare = false;
		bool pezzoDaCatturareCorr = false;




		//input
		Mossa prossimaMossa = input();
		Casella iniz = prossimaMossa.getCasellaPartenza();
		Casella fine = prossimaMossa.getCasellaArrivo();
		//controlliamo che la mossa sia corretta
		

		//caselle valide, nella casella di partenza c'è un pezzo
		caselleValide = inputCorretto(prossimaMossa);

		//c'è un pezzo da mangiare?
		pezzoDaCatturare = scacchiera[fine.getRiga()][fine.getColonna()] != nullptr;
		//se si, controlla che sia dell'avversario e che non sia il re
		if (pezzoDaCatturare) {
			pezzoDaCatturareCorr = ((*scacchiera[fine.getRiga()][fine.getColonna()]).getColore() == turno) && (  char((*scacchiera[fine.getRiga()][fine.getColonna()]).getSimbolo()) !=  ('r' && 'R'));
		}


		catturaCorretta = (!pezzoDaCatturare && !pezzoDaCatturareCorr) || (pezzoDaCatturare && pezzoDaCatturareCorr);
		
		 
	
		//mossa corretta per le regole di quel pezzo
		if (scacchiera[iniz.getRiga()][iniz.getColonna()] != nullptr) {
			pez = scacchiera[iniz.getRiga()][iniz.getColonna()];
			mossaFattibile = (*pez).move(iniz, fine, pezzoDaCatturare);
		}



		//finchè non sono rispettate tutte le regole ripeti il procedimento
		while (! (caselleValide && mossaFattibile && catturaCorretta) ) {
			caselleValide = false;
			mossaFattibile = false; 
			pezzoDaCatturare = false;
			pezzoDaCatturareCorr = false;
			catturaCorretta = false;


			prossimaMossa = input();

			iniz = prossimaMossa.getCasellaPartenza();
			fine = prossimaMossa.getCasellaArrivo();
			
			caselleValide = inputCorretto(prossimaMossa);
			pezzoDaCatturare = scacchiera[fine.getRiga()][fine.getColonna()] != nullptr;

			if (pezzoDaCatturare) {
				pezzoDaCatturareCorr = ((*scacchiera[fine.getRiga()][fine.getColonna()]).getColore() == turno) && ((*scacchiera[fine.getRiga()][fine.getColonna()]).getSimbolo() != ('r' && 'R'));
			}


			catturaCorretta = (!pezzoDaCatturare && !pezzoDaCatturareCorr) || (pezzoDaCatturare && pezzoDaCatturareCorr);


			if (scacchiera[iniz.getRiga()][iniz.getColonna()] != nullptr) {
				pez = scacchiera[iniz.getRiga()][iniz.getColonna()];
				mossaFattibile = pez->move(iniz, fine, pezzoDaCatturare);
				//mossaFattibile = call(pez, iniz, fine, pezzoDaCatturare);
			}


		}	//fine while

		//ora la mossa è corretta (caselle valide, nella casella di partenza c'è un pezzo) 
		//e che è fattibile per le regole del pezzo



		
		


		//movimento dei pezzi
		pez = scacchiera[iniz.getRiga()][iniz.getColonna()];

		scacchiera[fine.getRiga()][fine.getColonna()] = pez;

		scacchiera[iniz.getRiga()][iniz.getColonna()] = nullptr;

		//scacchiera di char
		char c = scacchiera_char[iniz.getRiga()][iniz.getColonna()];

		scacchiera_char[iniz.getRiga()][iniz.getColonna()] = ' ';
		scacchiera_char[fine.getRiga()][fine.getColonna()] = c;



		



		vector<Casella> cas = (*pez).getCaselleIntermedie(iniz, fine);



		stampa();
		
	}	//fine del movimento di un singolo pezzo
	




}	//fine partita 2










//metodo per ottenere una det. pezzo
	//date le coordinate
Pezzo* ChessBoard::getPezzo(int rig, int col) const {
	//se la casella scelta è fuori dalla scacchiera
	if (rig < 0 || rig > 7 || col < 0 || col > 7) {
		throw new exception("error: out of bounds");
	}

	return scacchiera[rig][col];

}


//funzione di chiamata alla funzione move
bool   ChessBoard::call(Pezzo* pez, const Casella inizio, const Casella arrivo, const bool cattura) {

	return  (*pez).move(inizio,arrivo,cattura);

}





//metodo resetScacchiera
void ChessBoard::resetScacchiera() {

	//scacchiera_char[riga][colonna]

	//inizializza tutta la scacchiera a nullptr
	for (int riga = 0; riga < 8; riga++) {
		for (int colonna = 0; colonna < 8; colonna++) {
			scacchiera[riga][colonna] = nullptr;
		}
	}

	//inizializziamo i pedoni bianchi
	Pezzo* ped1B = new Pedone(true);
	Pezzo* ped2B = new Pedone(true);
	Pezzo* ped3B = new Pedone(true);
	Pezzo* ped4B = new Pedone(true);
	Pezzo* ped5B = new Pedone(true);
	Pezzo* ped6B = new Pedone(true);
	Pezzo* ped7B = new Pedone(true);
	Pezzo* ped8B = new Pedone(true);

	scacchiera[1][0] = ped1B;
	scacchiera[1][1] = ped2B;
	scacchiera[1][2] = ped3B;
	scacchiera[1][3] = ped4B;
	scacchiera[1][4] = ped5B;
	scacchiera[1][5] = ped6B;
	scacchiera[1][6] = ped7B;
	scacchiera[1][7] = ped8B;
	
	//inizializziamo i pedoni neri
	Pezzo* ped1N = new Pedone(false);
	Pezzo* ped2N = new Pedone(false);
	Pezzo* ped3N = new Pedone(false);
	Pezzo* ped4N = new Pedone(false);
	Pezzo* ped5N = new Pedone(false);
	Pezzo* ped6N = new Pedone(false);
	Pezzo* ped7N = new Pedone(false);
	Pezzo* ped8N = new Pedone(false);

	scacchiera[6][0] = ped1N;
	scacchiera[6][1] = ped2N;
	scacchiera[6][2] = ped3N;
	scacchiera[6][3] = ped4N;
	scacchiera[6][4] = ped5N;
	scacchiera[6][5] = ped6N;
	scacchiera[6][6] = ped7N;
	scacchiera[6][7] = ped8N;
	
	//ci rimane da inizializzare il resto della scacchiera

	//due re (nero e bianco)
	Pezzo* rB = new Re(true);
	Pezzo* rN = new Re(false);

	scacchiera[0][4] = rB;
	scacchiera[7][4] = rN;


	//due regine
	Pezzo* regB = new Regina(true);
	Pezzo* regN = new Regina(false);

	scacchiera[0][3] = regB;
	scacchiera[7][3] = regN;



	//i 4 cavalli
	Pezzo* cav1B = new Cavallo(true);
	Pezzo* cav2B = new Cavallo(true);
	Pezzo* cav1N = new Cavallo(false);
	Pezzo* cav2N = new Cavallo(false);

	scacchiera[0][1] = cav1B;
	scacchiera[0][6] = cav2B;
	scacchiera[7][1] = cav1N;
	scacchiera[7][6] = cav2N;


	//4 alfieri
	Pezzo* alf1B = new Alfiere(true);
	Pezzo* alf2B = new Alfiere(true);
	Pezzo* alf1N = new Alfiere(false);
	Pezzo* alf2N = new Alfiere(false);

	scacchiera[0][2] = alf1B;
	scacchiera[0][5] = alf2B;
	scacchiera[7][2] = alf1N;
	scacchiera[7][5] = alf2N;

	//4 torri
	Pezzo* tor1B = new Torre(true);
	Pezzo* tor2B = new Torre(true);
	Pezzo* tor1N = new Torre(false);
	Pezzo* tor2N = new Torre(false);

	scacchiera[0][0] = tor1B;
	scacchiera[0][7] = tor2B;
	scacchiera[7][0] = tor1N;
	scacchiera[7][7] = tor2N;



	

	//----------------------------
	//----------------------------
	//----------------------------
	//TEST
	/*
	int rig_f = 3;
	int col_f = 0;

	Casella iniz(1, 0);
	Casella fine(3, 0);

	//STA ROBA FUNZIONA
	//cerchiamo se c'è un oggetto
	if (  (scacchiera[iniz.getRiga()][iniz.getColonna()]) != nullptr) {

		Pezzo* pe = scacchiera[iniz.getRiga()][iniz.getColonna()];

		//se non c'è oggetto dove vogliamo andare
		if ( scacchiera[fine.getRiga()][fine.getColonna()] == nullptr) {




			


			// cerchiamo se il pedone può muoversi lì
			//call(pe, iniz, fin, true) funziona
			//(*pe).move(iniz,fin,true) funziona
			//pe->move(iniz, fin, true) funziona

			if ( (*pe).move(iniz,fine,true) ) {
								
				  //il pezzo può muoversi
					//spostiamolo
				//una scacchiera
				scacchiera[fine.getRiga()][fine.getColonna()] = pe;
				scacchiera[iniz.getRiga()][iniz.getColonna()] = nullptr;


				//l'altra
				char c = scacchiera_char[1][0];

				scacchiera_char[iniz.getRiga()][iniz.getColonna()] = ' ';
				scacchiera_char[fine.getRiga()][fine.getColonna()] = c;

			}

		}
	}
	

	//test vari

	std::cout << endl << endl;

	std::cout << scacchiera_char[fine.getRiga()][fine.getColonna()] << endl;

	std::cout << "ciaoo sono fuori" << endl;

	
	*/


}


bool ChessBoard::inputCorretto(const  Mossa &prossimaMossa) {

	//controlliamo che le caselle di partenza e arrivo siano corrette
	//e che ci sia un pezzo nella casella di partenza
	
	//controlla casella di partenza
	if (!prossimaMossa.getCasellaPartenza().casellaValida()) {
		return false;
	}
	//controlla casella d'arrivo
	if (!prossimaMossa.getCasellaArrivo().casellaValida()) {
		return false;
	}

	//controlla che nella casella di partenza ci sia un pezzo
	if (scacchiera[prossimaMossa.getCasellaPartenza().getRiga()][prossimaMossa.getCasellaPartenza().getColonna()] == nullptr) {

		return false;
	}


	//se sei qui allora l'input è corretto
	return true;


}

