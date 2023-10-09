#pragma once
#include "Entidad.h"
#include <iostream>
#include <vector>
using namespace std;
class Bacteria : public Entidad {
public:
	Bacteria(Bitmap^ img) {

		x = rand() % 500;
		y = rand() % 500;
		if (rand() % 2 == 0) {
			dx = rand() % 10 - 5;
			if (dx == 0)dx = 5;
		}
		else {
			dy = rand() % 10 - 5;
			if (dy == 0)dy = 5;
		}
		ancho = img->Width;
		alto = img->Height;
		direccion = Abajo;
	}
	void eMostrar(Graphics^ g, Bitmap^ img) {
		Rectangle zoom = Rectangle(IDx * ancho, direccion * alto, alto, ancho);
		g->DrawImage(img, Area(), zoom, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, Area());

	}
	void eMover(Graphics^ g) {
		if (!(x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)) {
			dx *= -1;
		}
		if (!(y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)) {
			dy *= -1;
		}
		x += dx;
		y += dy;
	}
};

class Bacterias {
private:
	vector <Bacteria*> bacterias;
public:
	Bacterias(int n, Bitmap^ img) {
		for (int i = 0; i < n; i++) {
			bacterias.push_back(new Bacteria(img));
		}
	}
	~Bacterias() {
		for each (Bacteria * enem in bacterias) {
			delete enem;
		}
	}
	
	int Eliminar(Rectangle rect) {
		int cant = 0;
		for (int i = 0; i < bacterias.size(); i++) {
			if (bacterias[i]->Hitbox().IntersectsWith(rect)) {
				bacterias.erase(bacterias.begin() + i--);
				cant++;
			}
		}
		return cant;
	}
	
	bool Colision(Rectangle obj) {
		for each (Bacteria * enem in bacterias)
			if (enem->Area().IntersectsWith(obj))
				return true;
		return false;

	}
	int getNumeroBacterias() {
		return bacterias.size();
	}
	void bMover(Graphics^ g) {
		for each (Bacteria * enem in bacterias) {
			enem->eMover(g);
		}
	}
	void bMostrar(Graphics^ g, Bitmap^ img) {
		for each (Bacteria * enem in bacterias) {
			enem->eMostrar(g, img);
		}
	}

};
