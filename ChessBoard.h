#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include "Pezzo.h"
#include "Pedone.h"
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
	//          [ riga ]  [ colonna ]
	char scacchiera[8][8];


	//0 per partita giocatore - pc
	//1 per partita pc - pc
	bool tipoPartita;



	//valore booleano per capire di chi è il turno
	/*
	* turno = 0 significa che è il turno del bianco, deve fare la mossa lui
	* turno = 1 significa che è il turno del nero, deve fare la mossa lui
	* 
	* viene inizializzato con valore 0, in quanto per regolamento il primo a fare la mossa è il bianco
	
	*/
	bool turno;


	//valore booleano per capire se si è arrivati allo scacco matto
	//inizializzato a false, diventa true se si verifica la situazione di scacco matto
	bool scaccoMatto;



public:
	ChessBoard();	//costruttore




	void sceltaPartita();


	//gestione della partita giocatore - pc
	//viene lanciato quando si vuole cominciare la partita
	//e termina con il termine di essa
	void partita_0(); 

	//gestione della partita pc - pc
	void partita_1();


	//metodo stampa
	void stampa();




	
	
	
};



#endif