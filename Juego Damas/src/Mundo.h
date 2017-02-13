#pragma once
#include<math.h>
#include<cstdio>
#include<iostream>
#include"glut.h"
#include"ETSIDI.h"
#include "Tablero.h"
#include "Logica_Maquina.h"
#include "Logica_Hombre.h"


using namespace std;

class Mundo {
	double x;
	double y;
	double z;
	const double ConvRadDeg;
	Tablero tab;
	int juego;
	int i, j;
	Vector2D presente;
	Vector2D futuro;

public:
	unsigned int state;
	unsigned int Espera;
	Mundo(double x, double y, double z) : x(x), y(y), z(z), ConvRadDeg(180 / 3.14159265359), juego(1),tab(8), i(-1), j(-1){ tab.SituarDamas(); Espera=2; state=0;};
	void Dibuja();
	void RotarOjo();
	void Teclado(unsigned char key);
	void teclaEspecial(unsigned char key);
	void mueve(Logica* logica);
	void Inicializa();
	int getJuego() { return juego; };
	
};

