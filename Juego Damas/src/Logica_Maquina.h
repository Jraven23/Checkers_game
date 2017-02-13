#pragma once
#include "Logica.h"


using namespace std;

class Logica_Maquina:public Logica
{
protected:
	Piece::Accion mejor_opcion_dcha;
	Piece::Accion mejor_opcion_izq;
	const Piece::type_t type;
	Vector2D pos;
	vector <Vector2D> mejor_dcha;
	vector <Vector2D> mejor_izq;
public:
	
	Logica_Maquina(Piece::type_t type):type(type),pos(-1,-1), mejor_opcion_dcha(Piece::NADA), mejor_opcion_izq(Piece::NADA) {}
	Logica_Maquina(const Logica_Maquina& logica):type(logica.type),mejor_opcion_dcha(logica.mejor_opcion_dcha), mejor_opcion_izq(logica.mejor_opcion_izq),mejor_dcha(logica.mejor_dcha), mejor_izq(logica.mejor_izq) {}

	virtual int Get_Better_Option(Piece** board, int N);
	void set_Mejor_Opcion_DCHA(Piece::Accion m) { this->mejor_opcion_dcha = m; }
	void set_Mejor_Opcion_IZQ(Piece::Accion m) { this->mejor_opcion_izq = m; }
	void set_Pos(int x, int y) { this->pos.x = x; this->pos.y = y; }
	int mueve(Piece** board, int N, Vector2D, Vector2D);
	void reset() { mejor_opcion_dcha = Piece::NADA; mejor_dcha.clear(); mejor_opcion_izq = Piece::NADA; mejor_izq.clear(); };
	Piece::Accion get_Mejor_Opcion_DCHA() { return this->mejor_opcion_dcha; }
	Piece::Accion get_Mejor_Opcion_IZQ() { return this->mejor_opcion_izq; }

	~Logica_Maquina(void);
};

