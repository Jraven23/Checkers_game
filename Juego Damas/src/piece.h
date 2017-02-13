//piece.h: interface for the Piece class Hierarchy and definitions

#pragma once
#include <iostream>
#include "glut.h"
#include "Vector2D.h"

using namespace std;

class Object{
//interface class for all pieces
public:
	enum type_t { EMPTY = 0, PIECE_BLACK, PIECE_WHITE};
	enum type_t2 { DAMA = 0, QUEEN };
	enum Accion { NADA = -1, QUIETO, MOVER, COMER, COMER2, COMER3, COMER4 };
	enum Accion2 { NULO = -1, IZQ, DCHA };
	enum Lado { LHS = 0, RHS };
	virtual type_t getType()=0;
	virtual type_t2 getTypeDQ() = 0;
	virtual void setCell(type_t t, type_t2 k)=0;
};


class Piece:public Object{
protected:
	type_t type;
	type_t2 type2;
	Accion accion;
	Accion2 accion2;
	Piece::Accion2 mejor_lado;
	Piece::Accion mejor_opt;
	int diferencia;
	int mejor_dif;
	bool posible;
	float radio;
	Vector2D posicion;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	friend class Logica_Maquina;
	friend class Logica_Hombre;
	friend class Tablero;
	Piece():type(EMPTY), type2(DAMA), posible(false),diferencia(0),accion(QUIETO), mejor_lado(Piece::NULO), mejor_opt(Piece::NADA){}
	void setCell(type_t t,type_t2 k);
	virtual type_t getType(){return type;}
	virtual type_t2 getTypeDQ() { return type2; }
	Accion getAccion(){return accion;}
	Accion2 getmejorLado(){ return mejor_lado; }
	Accion getmejorOpt() { return mejor_opt; }
	void setMejor(Accion best, Accion2 mejor,int dif) { this->mejor_opt = best;  this->mejor_lado = mejor; this->mejor_dif = dif; }
	void setAccion(Accion m,Accion2 n){ this->accion=m; this->accion2 = n;}
	void SetColor(unsigned char rojo, unsigned char verde, unsigned char azul);
	void SetPos(float x, float y);
	void SetRadio(float radio);
	void Dibuja();
	void operator=(Piece&);

};

