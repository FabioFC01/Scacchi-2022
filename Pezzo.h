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
			riga sarà l'indice delle righe della matrice (da 0 a 7)
			colonna sarà la stessa cosa (da 0 a 7)


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
	void setRiga(const int r);
	void setColonna(const int c);
	void setColore(const bool b);

	//per ottenere la posizione
	int getRiga() const { return riga; }
	int getColonna() const { return colonna; }
	bool getColore() const { return colore; }
	bool dentroScacchiera(const int rig, const int col);




	//METODO MOVE
	//metodo più importante, quello per muovere il pezzo
	//deve fare il controllo che sia possibile far tale mossa
	//se dovesse essere possibile farlo allora la muove e ritorna true
	//sennò ritorna false e non muove nulla
	/*
		Se da una parte questo metodo della classe di un pezzo (derivata 
		dalla classe Pezzo) deve capire se è possibile spostarsi lì seguendo le regole 
		di spostamento di tale pezzo, dall'altra parte pure la classe Chess deve controllare che 
		sia possibile spostarsi lì (ad es. non puoi spostare un tuo pezzo in una tale posizione se 
		facendo tale movimento metti il tuo stesso re sotto scacco).
		La classe Chess deve fare dei controlli sulle conseguenze di tale spostamento
		sulla partita mentre la classe del pezzo chiamata in causa con questo metodo move deve cercare 
		di capire se è possibile spostare il pezzo guardando soltanto alle sue regole di spostamento
		(ad es. la torre può fare solo movimenti in alto/basso/dx/sx  
		        l'alfiere può solo muoversi per le diagonali 
				ecc...)
	*/
	
	 virtual bool move(const int r, const int c) = 0;
	//che poi questa funzione la faccio virtuale pura
	//oppure no? boh idk 
	//per ora virtuale pura
	 //da notare che la classe Pedone non ha implementato questa mossa ma ha
	 //un metodo move alternativo con bool cattura
	 //questo perchè il pedone è l'unico pezzo che quando deve catturare
	 //un pezzo avversario può muoversi non seguendo le sue regole convenzionali
	 //ovvero spostandosi in diagonale
	 //ma per gli altri pezzi bisogna fare l'override del metodo move





	 


};



#endif