#pragma once
#include "Mundo.h"
#include "ETSIDI.h"


class Coordinador 
{ 
 public: 
	Coordinador(): mundo(20,-33,55){ estado = INICIO; turno = NINGUNO; juego = 1; }
	virtual ~Coordinador();  
	void teclaEspecial(unsigned char key); 
	void tecla(unsigned char key);  
	void mueve(); 
	void dibuja(); 

 protected: 
	int juego;
	Logica* Logica1;
	Logica* Logica2;
	Mundo mundo;
	enum Estado {INICIO, MENU1, MENU2, MENU3, JUEGO, PAUSA, GAMEOVER, FIN, TABLAS};
	enum Modo {JUGADOR_MAQUINA,JUGADOR_JUGADOR, MAQUINA_MAQUINA};
	enum Turno { NINGUNO, BLANCAS, NEGRAS };
	Estado estado;
	Modo modo;
	Turno turno;
	void DeleteLogica();
};

