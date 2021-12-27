#ifndef PEZZO_H
#define PEZZO_H

class Pezzo {
	//classe di un pezzo casuale
	//le classi del pedone, torre, regina ecc...
	//saranno classi derivate di classe Pezzo


	/*
	scacchiera

	8
	7
	6
	5
	4
	3
	2
	1
	    A B C D E F G H
	
	
	
	
	
	*/

private:

	/*
		nella classe Pezzo :
			riga sar� l'indice delle righe della matrice (da 0 a 7)
			colonna sar� la stessa cosa (da 0 a 7)


			es. B7 ---> riga (7-1) = 6
						colonna B --> 1


				A	0
				B	1
				C	2
				D	3
				E	4
				F	5
				G	6
				H	7


	
	*/
	//per la posizione del pezzo
	int riga;
	int colonna;

	//0 per i bianchi
	//1 per i neri
	bool colore;
		




public:
	//per avere la posizione
	void setRiga(int r);
	void setColonna(int c);
	void setColore(bool b);

	//per ottenere la posizione
	int getRiga() { return riga; }
	int getColonna() { return colonna; }
	bool getColore() { return colore; }
	bool dentroScacchiera(int rig, int col);




	//METODO MOVE
	//metodo pi� importante, quello per muovere il pezzo
	//deve fare il controllo che sia possibile far tale mossa
	//se dovesse essere possibile farlo allora la muove e ritorna true
	//senn� ritorna false e non muove nulla
	/*
		per� non sono sicurissimo di sta cosa
		cio� se da una parte questo metodo della classe di un pezzo (derivata 
		dalla classe Pezzo) deve capire se � possibile spostarsi l� seguendo le regole 
		di spostamento di tale pezzo, dall'altra parte pure la classe Chess deve controllare che 
		sia possibile spostarsi l� (ad es. non puoi spostare un tuo pezzo in una tale posizione se 
		facendo tale movimento metti il tuo stesso re sotto scacco).
		Quindi immagino che la classe Chess debba fare dei controlli sulle conseguenze di tale spostamento
		sulla partita mentre la classe del pezzo chiamata in causa con questo metodo move deve cercare 
		di capire se � possibile spostare il pezzo guardando soltanto alle sue regole di spostamento
		(ad es. la torre pu� fare solo movimenti in alto/basso/dx/sx  
		        l'alfiere pu� solo muoversi per le diagonali 
				ecc...)
	*/
	 virtual bool move(int r, int c) = 0;
	//che poi questa funzione la faccio virtuale pura
	//oppure no? boh idk





	 


};



#endif