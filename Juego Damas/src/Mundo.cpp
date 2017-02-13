#include"Mundo.h"


using namespace std;


void Mundo::Dibuja()
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(x*tab.N/8, y, z,  // posicion del ojo
		(5 * tab.N / 2), (5*tab.N/2), 0,      // hacia que punto mira  (0,0,0) 
		0, 0, 1);      // definimos hacia arriba (eje Y)
	
	//dibujar tablero
	tab.SituarDamas();
	tab.Dibuja();
	

	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	if(Espera==2)
		glColor3ub(0, 255, 0);
	if(Espera==1)
		glColor3ub(255, 0, 0);
	if(Espera==0)
		glColor3ub(255, 255, 0);
	glVertex3f(0 + 5 * j, (tab.N-1)*5 - 5 * i, 0.1);
	glVertex3f(0 + 5 * j, tab.N*5 - 5 * i, 0.1);
	glVertex3f(5 + 5 * j, tab.N*5 - 5 * i, 0.1);
	glVertex3f(5 + 5 * j, (tab.N-1)*5 - 5 * i, 0.1);
	glEnd();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);


}


void Mundo::RotarOjo()
{
	if (state==1) {
			float distancia = sqrt(((x - (5 * tab.N / 2))*(x - (5 * tab.N / 2))) + ((y - (5 * tab.N / 2))*(y - (5 * tab.N / 2))));
			float angulo = atan2((y - (5 * tab.N / 2)), (x - (5 * tab.N / 2)));
			angulo += 0.03f;

			x = (5 * tab.N / 2) + distancia*cos(angulo);
			y = (5 * tab.N / 2) + distancia*sin(angulo);
			
			cout << angulo*ConvRadDeg << endl;
			if (((angulo*ConvRadDeg) > 89.0) && ((angulo*ConvRadDeg) < 91.0)) { state = 0; }

	}
	if (state==2) {
		float distancia = sqrt(((x - (5 * tab.N / 2))*(x - (5 * tab.N / 2))) + ((y - (5 * tab.N / 2))*(y - (5 * tab.N / 2))));
		float angulo = atan2((y - (5 * tab.N / 2)), (x - (5 * tab.N / 2)));
		angulo += 0.03f;

		x = (5 * tab.N / 2) + distancia*cos(angulo);
		y = (5 * tab.N / 2) + distancia*sin(angulo);

		if (((angulo*ConvRadDeg) < -89.0) && ((angulo*ConvRadDeg) > -91.0)) { state = 0; }
	}
}

void Mundo::Teclado(unsigned char key)
{
	if (key == 'r') {
		state = 1;
	}
	if (key == 't') {
		state = 2;
	}

	if (key == 'w')
		i--;
	if (key == 's')
		i++;
	if (key == 'a')
		j--;
	if (key == 'd')
		j++;
	if (key == 'x') {
		if (Espera == 2)
		{
			Espera = 1;
			presente.x = i;
			presente.y = j;
		}
		else if (Espera == 1)
		{
			Espera = 0;
			futuro.x = i;
			futuro.y = j;
		}
		else
			Espera=2;
	}

}

void Mundo::teclaEspecial(unsigned char key)
{

}

void Mundo::Inicializa()
{
	i = -1;
	j = -1;
	Espera = 2;
	tab.Inicio();
	tab.SituarDamas();
	ETSIDI::stopMusica();
	ETSIDI::playMusica("sonidos/valkirias.mp3",true);
}


void Mundo::mueve(Logica* logica)
{
	juego = logica->Get_Better_Option(tab.getTab(), tab.N);
	if (juego == 1) 
	{
		Espera = logica->mueve(tab.getTab(), tab.N, presente, futuro);
		if(Espera==2)
		{
			tab.reset();
			logica->reset();
		}
	}
}

