#pragma once
#include <ctime>
using namespace System::Drawing;
enum Direccion { Abajo, Izquierda, Derecha, Arriba, Aleatoria};
class Entidad {
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int IDx;
	Direccion direccion;
public:
	Entidad() {
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
		IDx = 0;
	}
	
	void SetDx(int n) { dx = n; }
	void SetDy(int n) { dy = n; }
	int GetX() { return x; }
	int GetY() { return y; }
	int GetAncho() { return ancho; }
	int GetAlto() { return alto; }
	Rectangle Area() {
		return Rectangle(x, y, ancho, alto);
	}
	Rectangle NextArea() {
		return Rectangle(x+dx, y+dy, ancho, alto);
	}
	Rectangle Hitbox() {
		return Rectangle(x + ancho / 4, y + alto / 3 - 5, ancho / 2, alto * 2 / 3);
	}
	Rectangle NextHitbox() {
		return Rectangle(x + ancho / 4 + dx, y + alto / 3 - 5 + dy, ancho / 2, alto * 2 / 3);
	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img) {
		x += dx;
		y += dy;
	}
	virtual void Mover(Graphics^ g) {
		g->FillRectangle(Brushes::Red, Area());
	}
	
};