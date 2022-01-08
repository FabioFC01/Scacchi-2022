#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <string>
#include <vector>


#include "Pezzo.h"

#include "Pedone.h"
#include "Re.h"
#include "Regina.h"
#include "Cavallo.h"
#include "Alfiere.h"
#include "Torre.h"



#include "Player.h"
#include "Mossa.h"
#include "Casella.h"


using namespace std;

class ChessBoard {
	//classe con la scacchiera, gestione dei pezzi
	//e della partita


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

private:
	//scacchiera dove metteremo i pezzi segnati da lettere
	// utile per la stampa
	//          [ riga ]  [ colonna ]
	char scacchiera_char[8][8];


	//scacchiera con i puntatori a superclasse
	Pezzo* scacchiera[8][8];


	//0 per partita giocatore - pc
	//1 per partita pc - pc
	bool tipoPartita;



	//valore booleano per capire di chi è il turno
	/*
	* turno = 0 significa che è il turno del bianco
	* turno = 1 significa che è il turno del nero
	* 
	* viene inizializzato con valore 0, in quanto per regolamento il primo a fare la mossa è il bianco
	
	*/
	bool turno;


	//valore booleano per capire se si è arrivati allo scacco matto
	//inizializzato a false, diventa true se si verifica la situazione di scacco matto
	bool scaccoMatto;



public:
	ChessBoard();	//costruttore



	void resetScacchiera();

	Pezzo* getPezzo(int rig, int col) const;




	//funzione di chiamata per il move
	bool call(Pezzo* pez, const Casella inizio, const Casella arrivo, const bool cattura);




	void sceltaPartita();


	//gestione della partita giocatore - pc
	//viene lanciato quando si vuole cominciare la partita
	//e termina con il termine di essa
	void partita_0(); 

	//gestione della partita pc - pc
	void partita_1();




	//metodo che dopo toglierò 
	//partita giocatore-giocatore
	void partita_2();


	//metodo stampa
	void stampa() const;


	//metodo per chiedere al giocatore umano l'input per la mossa
	Mossa input();


	//metodo per controllare che l'input per il movimento sia corretto
	//es. B1 C3 è un corretto comando, deve avere la coordinata di partenza
	//e quella di arrivo
	bool inputCorretto(const Mossa &prossimaMossa);




	
	
	
};



#endif