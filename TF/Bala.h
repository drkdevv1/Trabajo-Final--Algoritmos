#pragma once
#include <vector>
#include "Entidad.h"
class Bala :public Entidad {
public:
	Bala(int x, int y, int dx, int dy) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		ancho = alto = 10;
	}

};
class Balas{
private:
	std::vector <Bala*> balas;
public:
	~Balas() {
		for (int i = 0; i < balas.size(); i++) {
			delete balas.at(i);
		}
	}
	void Eliminar(int pos) {
		balas.erase(balas.begin() + pos);
	}
	void Agregar(Bala* bala) {
		balas.push_back(bala);
	}
	int Size() {
		return balas.size();
	}

	Bala* get(int pos) {
		return balas[pos];
	}
	bool Colision(Rectangle obj) {
		for each (Bala * b in balas) {
			if (b->Area().IntersectsWith(obj)) {
				return true;
			}
		}
		return false;
	}
	void Mover(Graphics^ g) {
		for (Bala* b : balas) {
			b->Mover(g);
		}
		Rectangle pantalla = Rectangle(0, 0, (int)g->VisibleClipBounds.Width, (int)g->VisibleClipBounds.Height);
		for (int i = 0; i < Size(); i++) {
			if (balas[i]->Area().IntersectsWith(pantalla) == false) {
				Eliminar(i--);
			}
		}
	}
	void Mostrar(Graphics^ g, Bitmap^ img) {
		for (Bala* b : balas) {
			b->Mostrar(g, img);
		}
	}

};