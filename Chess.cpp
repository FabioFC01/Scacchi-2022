#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

//chess.cpp
/*
    matrice char [8] [8] --- per stampare a schermo

    pezzi contraddistinti da classi per gestire le loro caratteristiche

    riga---numero
    colonna --- lettera


    //es. torrre in A1 all'inizio
    int riga = 1;
    char colonna = A;

    riga++;


    --
    es.
    classe pedone, ed � l'oggetto pedone che si muove
    riga++;

    classe pedone, per� � la classe scacchiera che lo muove
    pedone.setRiga(ecc...)






*/


/*
//gestione file

scacchiera.cpp --- main    --- gestisce argomenti da riga di comando

chess.cpp --- gestisce scacchiera e inizializza pezzi vari

pedone.cpp
torre.cpp
cavaliere.cpp
alfiere.cpp
regina.cpp
re.cpp

pedone.h
torre.h
cavaliere.h
alfiere.h
regina.h
re.h






*/

/*
    in ogni classe di un pezzo

    dati sulla posizione
        riga
        colonna

    metodi per ottenere e modificare posizione


    //es alfiere
    bool metodo move(int riga, char colonna) {
        
        //controlla che la posizione data sia in diagonale 
        //e non occupata da uno dei suoi pezzi

        //se ci� � rispettato si pu� muovere e ritorna true
        //se non pu� farlo ritorna false




    }


    //chiamata del metodo move

    while (! pedone.move(posizione dove deve andare)) {
        //ritenta
    }

    //� riuscito a fare una mossa




*/


/*
replay.cpp

e sotto file


ogni mossa che facciamo la scriviamo nel log 

es
pedone da A2 a A3

A2 A3
A3 A4
A4 A5


xx



*/