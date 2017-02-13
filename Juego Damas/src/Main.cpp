#include "glut.h"
#include <cstdio>
#include<math.h>
#include"Mundo.h"
#include "Coordinador.h"

Coordinador coordinador;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);

int main(int argc, char* argv[])
{
	ETSIDI::playMusica("sonidos/chopin.mp3", true);
	
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 750);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0); //le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMainLoop(); 
	return 0;
}

void OnDraw(void)
{
	coordinador.dibuja();
	glutSwapBuffers(); //no borrar esta linea ni poner nada despues
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	coordinador.tecla(key);
	glutPostRedisplay();
}

void OnTimer(int value)
{
	
	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

