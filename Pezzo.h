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
	//per la posizione del pezzo
	int riga;
	char colonna;


public:
	//per avere la posizione
	void setRiga(int r);
	void setColonna(char c);

	//per ottenere la posizione
	int getRiga() { return riga; }
	char getColonna() { return colonna; }





	//METODO MOVE
	//metodo più importante, quello per muovere il pezzo
	//deve fare il controllo che sia possibile far tale mossa
	//se dovesse essere possibile farlo allora la muove e ritorna true
	//sennò ritorna false e non muove nulla
	/*
		però non sono sicurissimo di sta cosa
		cioè se da una parte questo metodo della classe di un pezzo (derivata 
		dalla classe Pezzo) deve capire se è possibile spostarsi lì seguendo le regole 
		di spostamento di tale pezzo, dall'altra parte pure la classe Chess deve controllare che 
		sia possibile spostarsi lì (ad es. non puoi spostare un tuo pezzo in una tale posizione se 
		facendo tale movimento metti il tuo stesso re sotto scacco).
		Quindi immagino che la classe Chess debba fare dei controlli sulle conseguenze di tale spostamento
		sulla partita mentre la classe del pezzo chiamata in causa con questo metodo move deve cercare 
		di capire se è possibile spostare il pezzo guardando soltanto alle sue regole di spostamento
		(ad es. la torre può fare solo movimenti in alto/basso/dx/sx  
		        l'alfiere può solo muoversi per le diagonali 
				ecc...)
	*/
	 virtual bool move(int r, char c) = 0;
	//che poi questa funzione la faccio virtuale pura
	//oppure no? boh idk


};



#endif