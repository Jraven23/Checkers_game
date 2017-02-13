#include "Logica_Hombre.h"



Logica_Hombre::~Logica_Hombre(void)
{
}


int Logica_Hombre::Get_Better_Option(Piece** board, int N) 
{
	for (int i = 0; i < N; i++) // RECORREMOS LA MATRIZ DEL TABLERO
	{             
		for (int j = 0; j < N; j++)
		{
			int dif = board[i][j].diferencia;
			int n = 0;
			while (n<2)
			{
				if (board[i][j].getType() == type) // QUÉ PASA SI DETECTA UNA DAMA DE SU COLOR
				{    
					if (((i + dif) >(-1)) && ((i + dif) < N) && ((j - dif) > (-1)) && ((j - dif) < N))
					{
						//DCHA
						if (board[i + dif][j - dif].getType() == Piece::EMPTY) // si delante tiene un vacio (se puede mover)
						{
							board[i][j].setAccion(Piece::MOVER, Piece::DCHA);
							if (Piece::MOVER > get_Mejor_Opcion_DCHA())
								{
									set_Mejor_Opcion_DCHA(Piece::MOVER);
									set_Pos(i, j);
									mejor_dcha.clear();
									mejor_dcha.push_back(pos);
									if(board[i][j].getmejorOpt()<Piece::MOVER)
										board[i][j].setMejor(Piece::MOVER, Piece::DCHA, dif);
								}
							else if (Piece::MOVER == get_Mejor_Opcion_DCHA())
								{
									set_Pos(i, j);
									mejor_dcha.push_back(pos);
									if(board[i][j].getmejorOpt()<Piece::MOVER)
										board[i][j].setMejor(Piece::MOVER, Piece::DCHA, dif);
								}
						}

						else if (board[i + dif][j - dif].getType() != Piece::EMPTY && board[i + dif][j - dif].getType() != type) // si delante tiene color contrario
						{
							if (((i + 2 * dif) > (-1)) && ((i + 2 * dif) < N) && ((j - 2 * dif) > (-1)) && ((j - 2 * dif) < N))
							{
								if (board[i + 2 * dif][j - 2 * dif].getType() == Piece::EMPTY) // si dos delante tiene un vacio (puede comer)
								{
									board[i][j].setAccion(Piece::COMER, Piece::DCHA);
									if (Piece::COMER > get_Mejor_Opcion_DCHA())
									{
										set_Mejor_Opcion_DCHA(Piece::COMER);
										set_Pos(i, j);
										mejor_dcha.clear();
										mejor_dcha.push_back(pos);
										if(board[i][j].getmejorOpt()<Piece::COMER)
											board[i][j].setMejor(Piece::COMER, Piece::DCHA, dif);
									}
									else if (Piece::COMER == get_Mejor_Opcion_DCHA())
									{
										set_Pos(i, j);
										mejor_dcha.push_back(pos);
										if(board[i][j].getmejorOpt()<Piece::COMER)
											board[i][j].setMejor(Piece::COMER, Piece::DCHA, dif);
									}
								}
								else
									board[i][j].setAccion(Piece::QUIETO, Piece::DCHA);
							}
							else
								board[i][j].setAccion(Piece::QUIETO, Piece::DCHA); //No se puede mover a la dcha
						}
					}
					else
						board[i][j].setAccion(Piece::QUIETO, Piece::DCHA); //No hay tablero


					if (((i - dif) > (-1)) && ((i - dif) < N) && ((j - dif) > (-1)) && ((j - dif) < N))
					{
						//IZQ
						if (board[i - dif][j - dif].getType() == Piece::EMPTY) // si delante tiene un vacio (se puede mover)
						{
							board[i][j].setAccion(Piece::MOVER, Piece::IZQ);
							if (Piece::MOVER > get_Mejor_Opcion_IZQ())
							{
								set_Mejor_Opcion_IZQ(Piece::MOVER);
								set_Pos(i, j);
								mejor_izq.clear();
								mejor_izq.push_back(pos);
								if(board[i][j].getmejorOpt()<Piece::MOVER)
									board[i][j].setMejor(Piece::MOVER, Piece::IZQ, dif);
							}
							else if (Piece::MOVER == get_Mejor_Opcion_IZQ())
							{
								set_Pos(i, j);
								mejor_izq.push_back(pos);
								if(board[i][j].getmejorOpt()<Piece::MOVER)
									board[i][j].setMejor(Piece::MOVER, Piece::IZQ, dif);
							}
						}

						else if (board[i - dif][j - dif].getType() != Piece::EMPTY && board[i - dif][j - dif].getType() != type) // si delante tiene una negra
						{
							if (((i - 2 * dif) > (-1)) && ((i - 2 * dif) < N) && ((j - 2 * dif) > (-1)) && ((j - 2 * dif) < N))
							{
								if (board[i - 2 * dif][j - 2 * dif].getType() == Piece::EMPTY) // si dos delante tiene un vacio (puede comer)
								{
									board[i][j].setAccion(Piece::COMER, Piece::IZQ);
									if (Piece::COMER > get_Mejor_Opcion_IZQ())
									{
										set_Mejor_Opcion_IZQ(Piece::COMER);
										set_Pos(i, j);
										mejor_izq.clear();
										mejor_izq.push_back(pos);
										if(board[i][j].getmejorOpt()<Piece::COMER)
											board[i][j].setMejor(Piece::COMER, Piece::IZQ, dif);
									}
									else if (Piece::COMER == get_Mejor_Opcion_IZQ())
									{
										set_Pos(i, j);
										mejor_izq.push_back(pos);
										if(board[i][j].getmejorOpt()<Piece::COMER)
											board[i][j].setMejor(Piece::COMER, Piece::IZQ, dif);
									}
								}
								else
									board[i][j].setAccion(Piece::QUIETO, Piece::IZQ);

							}

							else board[i][j].setAccion(Piece::QUIETO, Piece::IZQ); //No se puede mover a la izq

						}

					}
					else board[i][j].setAccion(Piece::QUIETO, Piece::IZQ); //No hay tablero
				}
				if (board[i][j].getTypeDQ() == Piece::QUEEN) { n++; dif = -dif;}
				else n+=2;
			}
		}
	}
	for(int i=0; i<N;i++)
	{
		for(int j=0; j<N;j++)
		{
			if (get_Mejor_Opcion_IZQ()==board[i][j].getmejorOpt() || get_Mejor_Opcion_DCHA()==board[i][j].getmejorOpt())
				board[i][j].posible=true;
			else
				board[i][j].posible=false;
		}
	}

	if (get_Mejor_Opcion_IZQ() > Piece::QUIETO || get_Mejor_Opcion_DCHA() > Piece::QUIETO)
		return 1;
	else if (get_Mejor_Opcion_IZQ() == Piece::QUIETO || get_Mejor_Opcion_DCHA() == Piece::QUIETO)
		return 0;
	else
		return -1;

}

int Logica_Hombre::mueve(Piece** board, int N, Vector2D presente, Vector2D futuro)
{
	int i, j, n,m;

	j=static_cast<int>(presente.x);
	i=static_cast<int>(presente.y);
	m=static_cast<int>(futuro.x);
	n=static_cast<int>(futuro.y);


	if((i!=n && j!=m) && (board[i][j].getType()==type))
	{
		if((mejor_opcion_dcha==Piece::COMER || mejor_opcion_izq==Piece::COMER) && (n==(i+2) || n==(i-2)) && (j==(m+2) || j==(m-2)))
			if((board[((n-i)/2)+i][((m-j)/2)+j].getType()!=Piece::EMPTY && board[((n-i)/2)+i][((m-j)/2)+j].getType()!=type) && board[i][j].posible && board[n][m].getType()==Piece::EMPTY)
			{
				if ((m == 0) || (m == (N-1)))
					board[n][m].setCell(type, Piece::QUEEN);
				else
					board[n][m] = board[i][j];
				board[((n-i)/2)+i][((m-j)/2)+j].setCell(Piece::EMPTY, Piece::DAMA);
				board[i][j].setCell(Piece::EMPTY, Piece::DAMA);
				return 2;
			}
			else
				return 1;

		else if ((mejor_opcion_dcha==Piece::MOVER || mejor_opcion_izq==Piece::MOVER) && (n==(i+1) || n==(i-1)) && (j==(m+1) || j==(m-1)))
		{
			if(board[i][j].posible && board[n][m].getType()==Piece::EMPTY)
			{
				if ((m == 0) || (m == (N-1)))
					board[n][m].setCell(type, Piece::QUEEN);
				else
					board[n][m] = board[i][j];
				board[i][j].setCell(Piece::EMPTY, Piece::DAMA);
				return 2;
			}
			else
				return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

