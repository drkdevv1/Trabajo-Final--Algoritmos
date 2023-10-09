#pragma once
#include "Entidad.h"
#include <iostream>
#include <vector>
using namespace std;
enum e1Direccion{eAbajo,eIzquierda,eDerecha,eArriba};
class Enemigo : public Entidad {
	e1Direccion direccion;
public:
	Enemigo(Bitmap^ img) {
		//srand(time(0));
		x = rand() % 800;
		y = rand() % 500;

		if (rand() % 2 == 0) {
			dx = (rand() % 30) + 10;
			if (dx == 0)dx = 12;
		}
		else {
			dy = (rand() % 30) + 10;
			if (dy == 0)dy = 12;
		}
		ancho = img->Width/4;
		alto = img->Height/4;

		direccion = eAbajo;
	}
	void e1Mostrar(Graphics^ g, Bitmap^ img) {
		Rectangle frame = Rectangle(IDx * ancho, direccion * alto, alto, ancho);
		g->DrawImage(img, Area(), frame, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, Area());
		//g->DrawRectangle(Pens::Blue, Hitbox());
		if (direccion >= eArriba && direccion <= eDerecha) {
			IDx = (IDx + 1) % 4;
		}
	}
	void e1Mover(Graphics^ g) {
		if (!(x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)) {
			dx *= -1;
		}
		if (!(y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)) {
			dy *= -1;
		}
		if (dx < 0)direccion = eIzquierda;
		else if (dx > 0)direccion = eDerecha;
		else if (dy < 0)direccion = eArriba;
		else if (dy > 0)direccion = eAbajo;
		x += dx;
		y += dy;
	}
};

class Enemigos {
private:
	vector <Enemigo*> enemigos;
public:
	Enemigos(Bitmap^ img, int n) {
		for (int i = 0; i < n; i++) {
				enemigos.push_back(new Enemigo(img));
		}
	}
	~Enemigos() {
		for each(Enemigo* ene in enemigos) {
			delete ene;
		}
	}
	int Eliminar2(Rectangle rect) {
		int cant = 0;
		for (int i = 0; i < enemigos.size(); i++) {
			if (enemigos[i]->Hitbox().IntersectsWith(rect)) {
				enemigos.erase(enemigos.begin() + i--);
				cant++;
			}
		}
		return cant;
	}
	bool Colision2(Rectangle obj) {
		for each(Enemigo* ene in enemigos) 
			if (ene->Hitbox().IntersectsWith(obj)) 
				return true;
			return false;
	}
	int getNumeroEnemigos() {
		return enemigos.size();
	}
	void Mover2(Graphics^ g) {
		for each(Enemigo * ene in enemigos) {
			ene->e1Mover(g);
		}
	}
	void Mostrar2(Graphics^ g,Bitmap^ img) {
		for each(Enemigo* ene in enemigos) {
			ene->e1Mostrar(g,img);
		}
	}

};