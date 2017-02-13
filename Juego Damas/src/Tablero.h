#pragma once

#include <iostream>
#include "glut.h"
#include"ETSIDI.h"
#include "piece.h"


using namespace std;

class Tablero {
protected:
			//NxN board
	Piece ** board;
private:
	//logica
	static const int DAMAS_ERROR = -1;
	static const int DAMAS_OK = 0;

public:
	//logica
	Tablero(int N);		//empty table
	~Tablero();
	void reset();
	const int N;
	//Codigo de dibujo
	void Dibuja();
	void Inicio();
	void SituarDamas();
	int getSize(){return N;}
	Piece** getTab(){return board;}
};
