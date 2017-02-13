#pragma once

#include <iostream>
#include "glut.h"
#include "piece.h"
#include "Tablero.h"
#include <vector>
#include <time.h> 

using namespace std;

class Logica{
//interface class for all pieces
public:
	virtual int Get_Better_Option(Piece**,int)=0;
	virtual int mueve(Piece** , int, Vector2D, Vector2D)=0;
	virtual void reset() = 0;
};