#include"Tablero.h"


void Tablero::Dibuja()
{
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if ((j + i) % 2) {
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/blanca.png").id);
			}  //Casilla blanca
			else {
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/negra.png").id);
			}//Casilla negra
			
			//Forma casilla
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3ub(255, 255, 255);
			glTexCoord2d(0, 1); glVertex3f(0 + 5 * j, 5 + 5 * i, 0);
			glTexCoord2d(1, 1); glVertex3f(0 + 5 * j, 0 + 5 * i, 0);
			glTexCoord2d(1, 0); glVertex3f(5 + 5 * j, 0 + 5 * i, 0);
			glTexCoord2d(0, 0); glVertex3f(5 + 5 * j, 5 + 5 * i, 0);
			glEnd();
			glEnable(GL_LIGHTING);
		}
	}
}

Tablero::Tablero(int N):N(N)
{		
	board=new Piece*[N];
	for (int i=0; i<N; i++){
		board[i]=new Piece[N];			
	}
}


Tablero::~Tablero(void)
{
	for (int i = 0; i<N; i++)
		delete[] board[i];
	delete[] board;
}

void Tablero::reset() {
	for (int i = 0; i<Tablero::N; i++) {
		for (int j = 0; j<Tablero::N; j++) {
			board[i][j].accion = Piece::NADA;
			board[i][j].accion2 = Piece::NULO;
			board[i][j].mejor_lado = Piece::NULO;
			board[i][j].mejor_opt = Piece::NADA;
		}
	}
}


void Tablero::Inicio()
{
	//Initially empty
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j].setCell(Piece::EMPTY, Piece::DAMA);
		}
	}

	for(int i=0;i<((N/2)-1);i++)
		for(int j=0;j<N;j++)
			if((j+i)%2)
			{
				board[j][i].setCell(Piece::PIECE_BLACK,Piece::DAMA);
			}
	
	for(int i=(N-1);i>(N/2);i--)
		for(int j=0;j<N;j++)
			if((j+i)%2)
			{
				board[j][i].setCell(Piece::PIECE_WHITE, Piece::DAMA);
			}

}

void Tablero::SituarDamas()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j].SetPos((2.5 + 5 * i), ((N*5-2.5) - 5 * j));
			board[i][j].Dibuja();
		}
	}
}


