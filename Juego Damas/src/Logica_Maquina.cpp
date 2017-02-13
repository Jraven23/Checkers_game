#include "Logica_Maquina.h"

Logica_Maquina::~Logica_Maquina(void)
{
}

int Logica_Maquina::Get_Better_Option(Piece** board, int N)
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
	if (get_Mejor_Opcion_IZQ() > Piece::QUIETO || get_Mejor_Opcion_DCHA() > Piece::QUIETO)
		return 1;
	else if (get_Mejor_Opcion_IZQ() == Piece::QUIETO || get_Mejor_Opcion_DCHA() == Piece::QUIETO)
		return 0;
	else
		return -1;
}

int Logica_Maquina::mueve(Piece** board, int N, Vector2D presente, Vector2D futuro)
{

	int k, dif, i, j;
	bool izq=false;
	bool dcha=false;

	srand(time(NULL));

	if (get_Mejor_Opcion_IZQ() > get_Mejor_Opcion_DCHA())
	{
			k = rand() % mejor_izq.size();
			i = static_cast<int>(mejor_izq[k].x);
			j = static_cast<int>(mejor_izq[k].y);
			izq=true;
	}
	else if (get_Mejor_Opcion_IZQ() < get_Mejor_Opcion_DCHA())
	{
			k = rand() % mejor_dcha.size();
			i = static_cast<int>(mejor_dcha[k].x);
			j = static_cast<int>(mejor_dcha[k].y);
			dcha=true;
	}
	else
	{
		if (rand()%2)
		{
			k = rand() % mejor_izq.size();
			i = static_cast<int>(mejor_izq[k].x);
			j = static_cast<int>(mejor_izq[k].y);
			izq=true;
		}
		else
		{
			k = rand() % mejor_dcha.size();
			i = static_cast<int>(mejor_dcha[k].x);
			j = static_cast<int>(mejor_dcha[k].y);
			dcha=true;
		}
	}

	dif = board[i][j].mejor_dif;

	if (izq)
	{
		if (board[i][j].getmejorOpt() == Piece::MOVER)
		{
			if (((j - dif) == 0) || ((j - dif) == (N-1)))
				board[i - dif][j - dif].setCell(type, Piece::QUEEN);
			else
				board[i - dif][j - dif] = board[i][j];
		}
		else if (board[i][j].getmejorOpt() == Piece::COMER)
		{
			if (((j - 2*dif) == 0) || ((j - 2*dif) == (N-1)))
				board[i - 2*dif][j - 2*dif].setCell(type, Piece::QUEEN);
			else
				board[i - 2*dif][j - 2*dif] = board[i][j];
			board[i - dif][j - dif].setCell(Piece::EMPTY, Piece::DAMA);
		}
	}

	else if (dcha)
	{
		if (board[i][j].getmejorOpt() == Piece::MOVER)
		{
			if (((j - dif) == 0) || ((j - dif) == (N-1)))
				board[i + dif][j - dif].setCell(type, Piece::QUEEN);
			else
				board[i + dif][j - dif]= board[i][j];
		}
		else if (board[i][j].getmejorOpt() == Piece::COMER)
		{
			if (((j - 2*dif) == 0) || ((j - 2*dif) == (N-1)))
				board[i + 2*dif][j - 2*dif].setCell(type, Piece::QUEEN);
			else
				board[i + 2*dif][j - 2*dif] = board[i][j];
			board[i + dif][j - dif].setCell(Piece::EMPTY, Piece::DAMA);
		}
	}

	board[i][j].setCell(Piece::EMPTY, Piece::DAMA);
	return 2;
}

