#pragma once
#include "math.h"

class Vector2D
{
private:
public:
	float x;
	float y;
public:	
	Vector2D(float xv=0.0f, float yv=0.0f);
	~Vector2D(void);
	
	float modulo();      // (2) modulo del vector 
	float argumento();     // (3) argumento del vector
	Vector2D Unitario();     // (4) devuelve un vector unitario 
	Vector2D operator - (Vector2D &v); // (5) resta de vectores  
	Vector2D operator + (Vector2D &v); // (6) suma de vectores
	float operator *(Vector2D &v);   // (7) producto escalar 
	Vector2D operator *(float k);  // (8) producto por un escalar
	Vector2D operator /(float k); // division por un escalar
};

