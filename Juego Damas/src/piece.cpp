#include "piece.h"

void Piece::SetColor(unsigned char rojo, unsigned char verde, unsigned char azul)
{
	this->rojo=rojo;
	this->verde=verde;
	this->azul=azul;
}
void Piece::setCell(type_t t,type_t2 k)
{
	this->type2 = k;
	this->type = t;
	if (k == DAMA)
	{
		if (t == PIECE_BLACK)
		{
			diferencia = -1;
			SetColor(50, 50, 50);
		}
		else if (t == PIECE_WHITE)
		{
			diferencia = 1;
			SetColor(230, 230, 230);
		}
		else diferencia = 0;
	}
	else if (k==QUEEN)
	{
		if (t == PIECE_BLACK)
		{
			SetColor(50, 50, 50);
			diferencia = 1;
		}
		else if (t == PIECE_WHITE)
		{
			SetColor(230, 230, 230);
			diferencia = -1;
		}
		
	}
}

void Piece::operator=(Piece& piece)
{
	this->type = piece.type;
	this->type2= piece.type2;
	this->diferencia= piece.diferencia;
	setCell(type, type2);
}

void Piece::Dibuja() 
{ 
	if(type!=EMPTY)
	{
		glDisable(GL_TEXTURE_2D);
		glTranslatef(posicion.x,posicion.y, 0.4); 
		glColor3ub(rojo,verde,azul);
		glutSolidTorus( 0.35,1.75, 50, 50); 
		glColor3ub(rojo, verde, azul);
		glutSolidCone(1.75, 0.3, 20, 20);
		glTranslatef(-posicion.x,-posicion.y, -0.4);
		glTranslatef(posicion.x, posicion.y, 0.6);
		glColor3ub(rojo, verde, azul);
		glutSolidTorus(0.35, 0.75, 50, 50);
		glTranslatef(-posicion.x, -posicion.y, -0.6);

	
		if(type2==QUEEN)
		{	
			//Segundo piso
			glTranslatef(posicion.x, posicion.y, 1.5);
			glColor3ub(rojo, verde, azul);
			glutSolidTorus(0.35, 1.75, 50, 50);
			glColor3ub(rojo, verde, azul);
			glutSolidCone(1.75, 0.3, 20, 20);
			glTranslatef(-posicion.x, -posicion.y, -1.5);
			glTranslatef(posicion.x, posicion.y, 1.7);
			glColor3ub(rojo, verde, azul);
			glutSolidTorus(0.35, 0.75, 50, 50);
			glTranslatef(-posicion.x, -posicion.y, -1.7);
		}
		glEnable(GL_TEXTURE_2D);
	}
}

void Piece::SetPos(float x, float y)
{
	posicion.x=x;
	posicion.y=y;
}

void Piece::SetRadio(float radio)
{
	this->radio=radio;
}

