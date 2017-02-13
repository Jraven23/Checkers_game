#include "Coordinador.h"


Coordinador::~Coordinador(void)
{
	delete Logica1;
	delete Logica2;
}


void Coordinador::dibuja()
{  
	if(estado==INICIO)
	{
		//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS   
		//Borrado de la pantalla	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Para definir el punto de vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 7.5, 30,  // posicion del ojo  
			0.0, 7.5, 0.0,   // hacia que punto mira (0,7.5,0)  
			0.0, 1.0, 0.0);   // definimos hacia arriba (eje Y)   
		
		glDisable(GL_TEXTURE_2D);
		ETSIDI::setTextColor(255,255,0); 
		ETSIDI::setFont("fuentes/Bitwise.ttf",22);  
		ETSIDI::printxy("Damas 1.0", -7,8);  
		ETSIDI::setTextColor(255,255,255);  
		ETSIDI::setFont("fuentes/Bitwise.ttf",16);  
		ETSIDI::printxy("PULSE LA TECLA _E_ PARA EMPEZAR", -7,7); 
		ETSIDI::printxy("PULSE LA TECLA _S_ PARA SALIR", -7,6);
		ETSIDI::printxy("ORTEGA & RAVEN",2,1); 
		glEnable(GL_TEXTURE_2D);
		
	}
	else if(estado==MENU1) 
	{  
		//Borrado de la pantalla	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Para definir el punto de vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 7.5, 30,  // posicion del ojo  
			0.0, 7.5, 0.0,   // hacia que punto mira (0,7.5,0)  
			0.0, 1.0, 0.0);  // definimos hacia arriba (eje Y)
		
		glDisable(GL_TEXTURE_2D);
		ETSIDI::setTextColor(1.0f,0.0f,0.0f); 
		ETSIDI::setFont("fuentes/Bitwise.ttf",22); 
		ETSIDI::printxy("Seleccione MODO de juego",-5,10);
		ETSIDI::setTextColor(1.0f,1.0f,1.0f);  
		ETSIDI::setFont("fuentes/Bitwise.ttf",16);
		ETSIDI::printxy("1_ JUGADOR  vs  MAQUINA",-5,7);
		ETSIDI::printxy("2_ JUGADOR  vs  JUGADOR",-5,6);
		ETSIDI::printxy("3_ MAQUINA  vs  MAQUINA",-5,5);
		ETSIDI::printxy("ORTEGA & RAVEN",2,1);
		glEnable(GL_TEXTURE_2D);
	}
	else if(estado==MENU2) 
	{   
		//Borrado de la pantalla	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Para definir el punto de vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 7.5, 30,  // posicion del ojo  
			0.0, 7.5, 0.0,   // hacia que punto mira (0,7.5,0)  
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		
		glDisable(GL_TEXTURE_2D);
		ETSIDI::setTextColor(1.0f,0.0f,0.0f); 
		ETSIDI::setFont("fuentes/Bitwise.ttf",22); 
		ETSIDI::printxy("Elija COLOR de sus damas",-5,10);
		ETSIDI::setTextColor(1.0f,1.0f,1.0f);  
		ETSIDI::setFont("fuentes/Bitwise.ttf",16);
		ETSIDI::printxy("b_ Color BLANCO",-5,7);
		ETSIDI::printxy("n_ Color NEGRO",-5,6);
		ETSIDI::printxy("ORTEGA & RAVEN",2,1);
		glEnable(GL_TEXTURE_2D);
	}
	//else if(estado==MENU3) 
	//{   
	//	//Borrado de la pantalla	
	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//	//Para definir el punto de vista
	//	glMatrixMode(GL_MODELVIEW);
	//	glLoadIdentity();

	//	gluLookAt(0, 7.5, 30,  // posicion del ojo  
	//		0.0, 7.5, 0.0,   // hacia que punto mira (0,7.5,0)  
	//		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	//	
	//	glDisable(GL_TEXTURE_2D);
	//	ETSIDI::setTextColor(1.0f,0.0f,0.0f); 
	//	ETSIDI::setFont("fuentes/Bitwise.ttf",16); 
	//	ETSIDI::printxy("Elija TAMAÑO del tablero",-5,10);
	//	ETSIDI::setTextColor(1.0f,1.0f,1.0f);  
	//	ETSIDI::setFont("fuentes/Bitwise.ttf",12);
	//	ETSIDI::printxy("1_ 8x8",-5,7);
	//	ETSIDI::printxy("2_ 10x10",-5,6);
	//	ETSIDI::printxy("3_ 12x12",-5,5);
	//	ETSIDI::printxy("ORTEGA & RAVEN",2,1);
	//	glEnable(GL_TEXTURE_2D);
	//}
	else if (estado == JUEGO) {
		if (juego == 0) estado = TABLAS;
		if (juego == -1) {
			if (turno == NEGRAS)
				estado = FIN;
			if (turno == BLANCAS)
				estado = GAMEOVER;
		}
		if (juego == 1)
		{
			mueve();
			mundo.Dibuja();
			mundo.RotarOjo();
			if(turno==BLANCAS)
			{
				glDisable(GL_TEXTURE_2D);
				ETSIDI::setTextColor(0.0f,1.0f,0.0f); 
				ETSIDI::setFont("fuentes/Bitwise.ttf",15); 
				ETSIDI::printxy("Turno BLANCAS",14,-5); 
				glEnable(GL_TEXTURE_2D);
			}
			if(turno==NEGRAS)
			{
				glDisable(GL_TEXTURE_2D);
				ETSIDI::setTextColor(0.0f,1.0f,0.0f); 
				ETSIDI::setFont("fuentes/Bitwise.ttf",15); 
				ETSIDI::printxy("Turno NEGRAS",14,-5); 
				glEnable(GL_TEXTURE_2D);
			}
		}

	}
	else if(estado==PAUSA)
	{	
		//Borrado de la pantalla	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Para definir el punto de vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 7.5, 30,  // posicion del ojo  
			0.0, 7.5, 0.0,   // hacia que punto mira (0,7.5,0)  
			0.0, 1.0, 0.0);  // definimos hacia arriba (eje Y)
		
		
		glDisable(GL_TEXTURE_2D);
		ETSIDI::setTextColor(0.0f,1.0f,0.0f); 
		ETSIDI::setFont("fuentes/Bitwise.ttf",32); 
		ETSIDI::printxy("PAUSA",-5,10); 
		ETSIDI::setTextColor(0.0f,1.0f,1.0f);  
		ETSIDI::setFont("fuentes/Bitwise.ttf",14);
		ETSIDI::printxy("p- Continuar",-3,7);
		ETSIDI::printxy("c- Inicio",-3,6);
		ETSIDI::printxy("s- Salir",-3,5);
		ETSIDI::setTextColor(0.0f, 1.0f, 0.0f);
		ETSIDI::printxy("ORTEGA & RAVEN",0,2);
		glEnable(GL_TEXTURE_2D);
	}
	else if(estado==GAMEOVER) 
	{ 
		//Borrado de la pantalla	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Para definir el punto de vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 7.5, 30,  // posicion del ojo  
			0.0, 7.5, 0.0,   // hacia que punto mira (0,7.5,0)  
			0.0, 1.0, 0.0);  // definimos hacia arriba (eje Y)
		glDisable(GL_TEXTURE_2D); 
		ETSIDI::setTextColor(1.0f,0.0f,0.0f); 
		ETSIDI::setFont("fuentes/Bitwise.ttf",24); 
		ETSIDI::printxy("GAMEOVER: Has perdido",-5,10); 
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 8);
		ETSIDI::printxy("Pulsa -S- para salir", -5, 7);
		ETSIDI::printxy("ORTEGA & RAVEN",2,1);
		glEnable(GL_TEXTURE_2D);
	} 
	else if(estado==FIN) 
	{ 
		//Borrado de la pantalla	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Para definir el punto de vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 7.5, 30,  // posicion del ojo  
			0.0, 7.5, 0.0,   // hacia que punto mira (0,7.5,0)  
			0.0, 1.0, 0.0);  // definimos hacia arriba (eje Y)
		glDisable(GL_TEXTURE_2D);
		ETSIDI::setTextColor(0.0f,1.0f,0.0f);
		ETSIDI::setFont("fuentes/Bitwise.ttf",24); 
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!",-5,10); 
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 8);
		ETSIDI::printxy("Pulsa -S- para salir", -5, 7);
		ETSIDI::printxy("ORTEGA & RAVEN",2,1);
		glEnable(GL_TEXTURE_2D);
	} 
	else if (estado == TABLAS)
	{
		//Borrado de la pantalla	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Para definir el punto de vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 7.5, 30,  // posicion del ojo  
			0.0, 7.5, 0.0,   // hacia que punto mira (0,7.5,0)  
			0.0, 1.0, 0.0);  // definimos hacia arriba (eje Y)
		glDisable(GL_TEXTURE_2D);
		ETSIDI::setTextColor(0.0f, 0.0f, 1.0f);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
		ETSIDI::printxy("TABLAS, ¡Ay caramba!", -5, 10);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 8);
		ETSIDI::printxy("Pulsa -S- para salir", -5, 7);
		ETSIDI::printxy("ORTEGA & RAVEN",2,1);
		glEnable(GL_TEXTURE_2D);
	}
}

void Coordinador::tecla(unsigned char key) 
{ 
	if(estado==INICIO) 
	{   
		if(key=='e')  
		{     
			estado=MENU1;
			ETSIDI::play("sonidos/disparo.wav");
		}  
		if (key == 's') {
			exit(0);
			ETSIDI::play("sonidos/disparo.wav");
		}
	} 
	else if(estado==MENU1)
	{
		if(key=='1')
		{
			modo=JUGADOR_MAQUINA;
			estado=MENU2;
			ETSIDI::play("sonidos/disparo.wav");
		}
		if(key=='2')
		{
			modo=JUGADOR_JUGADOR;
			estado=MENU2;
			ETSIDI::play("sonidos/disparo.wav");
		}
		if(key=='3')
		{
			modo=MAQUINA_MAQUINA;
			DeleteLogica();
			Logica1 = new Logica_Maquina(Piece::PIECE_WHITE);
			Logica2 = new Logica_Maquina(Piece::PIECE_BLACK);
			mundo.Inicializa();
			estado=JUEGO;
			turno = BLANCAS;
			ETSIDI::play("sonidos/disparo.wav");
		}
	}
	else if(estado==MENU2)
	{
		if(modo==JUGADOR_MAQUINA)
		{
			if(key=='b')
			{
				DeleteLogica();
				Logica1 = new Logica_Hombre(Piece::PIECE_WHITE);
				Logica2 = new Logica_Maquina(Piece::PIECE_BLACK);
				mundo.Inicializa();
				estado=JUEGO;
				turno = BLANCAS;
				ETSIDI::play("sonidos/disparo.wav");
			}
			if(key=='n')
			{
				DeleteLogica();
				Logica1 = new Logica_Maquina(Piece::PIECE_WHITE);
				Logica2 = new Logica_Hombre(Piece::PIECE_BLACK);
				mundo.Inicializa();
				estado=JUEGO;
				turno = BLANCAS;
				ETSIDI::play("sonidos/disparo.wav");
			}
		}
		if(modo==JUGADOR_JUGADOR)
		{
			if(key=='b')
			{
				DeleteLogica();
				Logica1 = new Logica_Hombre(Piece::PIECE_WHITE);
				Logica2 = new Logica_Hombre(Piece::PIECE_BLACK);
				mundo.Inicializa();
				estado=JUEGO;
				turno = BLANCAS;
				ETSIDI::play("sonidos/disparo.wav");
			}
			if(key=='n')
			{
				DeleteLogica();
				Logica1 = new Logica_Hombre(Piece::PIECE_WHITE);
				Logica2 = new Logica_Hombre(Piece::PIECE_BLACK);
				mundo.Inicializa();
				estado=JUEGO;
				turno = BLANCAS;
				ETSIDI::play("sonidos/disparo.wav");
			}
		}
	}

	else if(estado==JUEGO) 
	{ 
		if (key == 'p') {
			estado = PAUSA;
			ETSIDI::stopMusica();
			ETSIDI::play("sonidos/disparo.wav");
		}
		else
			mundo.Teclado(key); 
	} 
	else if(estado==PAUSA)
	{
		if(key=='c')
			estado=INICIO;
		if(key=='s')
			exit(0);
		if (key == 'p') {
			estado = JUEGO;
			ETSIDI::play("sonidos/disparo.wav");
			ETSIDI::playMusica("sonidos/valkirias.mp3", true);
		}
	}
	else if(estado==GAMEOVER) 
	{  
		if (key == 'c')
		{
			estado = INICIO;
			turno = NINGUNO;
			juego = 1;
		}
		if (key == 's')
			exit(0);
	} 
	else if(estado==FIN)  
	{  
		if (key == 'c')
		{
			estado = INICIO;
			turno = NINGUNO;
			juego = 1;
		}
		if (key == 's')
			exit(0);

	}
	else if (estado == TABLAS)
	{
		if (key == 'c')
		{
			estado = INICIO;
			turno = NINGUNO;
			juego = 1;
		}
		if (key == 's')
			exit(0);

	}
}

void Coordinador::teclaEspecial(unsigned char key)
{ 
	if(estado==JUEGO)
		mundo.Teclado(key);
}

void Coordinador::mueve()
{ 
	if (estado == JUEGO)
		if (turno == BLANCAS)
		{
				mundo.Dibuja();
				if (mundo.Espera==0)
				{
					mundo.mueve(Logica1);
					juego = mundo.getJuego();
					if(mundo.Espera==2)
					{
						turno = NEGRAS;
						Sleep(500);
					}
				}
			}

		else if (turno==NEGRAS)
			{
				mundo.Dibuja();
				if (mundo.Espera==0)
				{
					mundo.mueve(Logica2);
					juego = mundo.getJuego();
					if(mundo.Espera==2)
					{
						turno = BLANCAS;
						Sleep(500);
					}
				}
			}
}

void Coordinador::DeleteLogica()
{
	if (Logica1!=NULL)
		delete Logica1;
	if (Logica2!=NULL)
		delete Logica2;	
}
