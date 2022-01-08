#include "Torre.h"

//costruttore
Torre::Torre(const bool color) {
	setColore(color);

	//bianco
	if (getColore()) {
		setSimbolo('t');
	}
	//nero
	else {
		setSimbolo('T');
	}

}

//metodo move
bool Torre::move(const Casella inizio, const Casella arrivo, const bool cattura) {
	//la torre si muove in alto e in basso, sx , dx
	//mai in diagonale



	int spostRighe = arrivo.getRiga() - inizio.getRiga(); //spostamento lungo le righe (in alto e in basso)
	int spostColonne = arrivo.getColonna() - inizio.getColonna(); //spostamento lungo le colonne (dx/sx)

	int rig = arrivo.getRiga();
	int col = arrivo.getColonna();

	int absSpostRighe;
	int absSpostCol;

	if (spostRighe >= 0) { absSpostRighe = spostRighe; }
	else { absSpostRighe = spostRighe * (-1); }

	if (spostColonne >= 0) { absSpostCol = spostColonne; }
	else { absSpostCol = spostColonne * (-1); }



	 
	//spostamento in alto e in basso
	if (spostColonne == 0 && spostRighe != 0) {
		return true;
	}
	//spostamento a sx/dx
	if (spostColonne != 0 && spostRighe == 0) {
		return true;
	}

	//se sei arrivato qui la mossa deve essere errata
	return false;


}


std::vector<Casella> Torre::getCaselleIntermedie(const Casella inizio, const Casella fine) {

	int spostRighe = fine.getRiga() - inizio.getRiga(); //spostamento lungo le righe (in alto e in basso)
	int spostColonne = fine.getColonna() - inizio.getColonna(); //spostamento lungo le colonne (dx/sx)

	int rig = fine.getRiga();
	int col = fine.getColonna();



	int absSpostRighe;
	int absSpostCol;

	if (spostRighe >= 0) { absSpostRighe = spostRighe; }
	else { absSpostRighe = spostRighe * (-1); }

	if (spostColonne >= 0) { absSpostCol = spostColonne; }
	else { absSpostCol = spostColonne * (-1); }



	//movimenti lungo una sola coordinata

	//torre si sposta lungo una riga (cio� un movimento sx/dx)
	if (spostColonne != 0 && spostRighe == 0) {

		//indice della riga nella quale si muove
		int riga = rig;

		//indici delle colonne dove la torre vuole partire e arrivare
		int colPartenza = inizio.getColonna();
		int colArrivo = fine.getColonna();


		int colMinore;
		int colMaggiore;

		if (colPartenza < colArrivo) {
			colMinore = colPartenza;
			colMaggiore = colArrivo;
		}
		else {
			colMinore = colArrivo;
			colMaggiore = colPartenza;
		}

		//creo il vettore con le varie caselle
		std::vector<Casella> cas;

		//lo riempio
		for (int j = colMinore + 1; j < colMaggiore; j++) {
			Casella temp(riga, j);
			cas.push_back(temp);
		}

		return cas;

	}


	//spostamento in alto/basso
	if (spostColonne == 0 && spostRighe != 0) {
		//indice colonna (rimane costante nel movimento)
		int colonna = col;

		//indici delle righe dove la torre vuole partire e arrivare
		int rigPartenza = inizio.getRiga();
		int rigArrivo = fine.getRiga();

		int rigMinore;
		int rigMaggiore;

		if (rigPartenza < rigArrivo) {
			rigMinore = rigPartenza;
			rigMaggiore = rigArrivo;
		}
		else {
			rigMinore = rigArrivo;
			rigMaggiore = rigPartenza;
		}

		//creo il vettore con le varie caselle
		std::vector<Casella> cas;

		for (int j = rigMinore + 1; j < rigMaggiore; j++) {
			Casella temp(j, colonna);
			cas.push_back(temp);
		}

		return cas;

	}
}