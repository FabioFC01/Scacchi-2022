#ifndef CHESS_H
#define CHESS_H

#include <iostream>
#include "Pezzo.h"
#include "Pedone.h"
using namespace std;

class Chess {
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



	//valore booleano per capire di chi ? il turno
	/*
	* turno = 0 significa che ? il turno del bianco, deve fare la mossa lui
	* turno = 1 significa che ? il turno del nero, deve fare la mossa lui
	* 
	* viene inizializzato con valore 0, in quanto per regolamento il primo a fare la mossa ? il bianco
	
	*/
	bool turno;

public:
	Chess();	//costruttore


	//gestione della partita
	//viene lanciato quando si vuole cominciare la partita
	//e termina con il termine di essa
	void partita(); 


	//metodo stampa
	void stampa();






};



#endif