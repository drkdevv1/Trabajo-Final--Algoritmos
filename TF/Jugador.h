#pragma once
#include "Entidad.h"
using namespace System::Drawing;

class Jugador : public Entidad {
private: 
	int vidas;
	int puntos;
public:
	Jugador(Bitmap^ img, int v) {
		x = 60;
		y = 60;
		dx = dy = 0;
		ancho = img->Width / 4;
		alto = img->Height / 4;
		direccion = Abajo;
		vidas = v;
		puntos = 0;
		
	}
	void SetVidas(int value) {
		vidas += value;
	}
	int GetVidas() {
		return vidas;
	}
	void SetPuntos(int value) {
		puntos += value;
	}
	int GetPuntos() {
		return puntos;
	}
	void SetAccion(Direccion n) {
		direccion = n;
	}
	Direccion GetAccion() {
		return direccion;
	}
	void Mostrar(Graphics^ g, Bitmap^ img) {
		g->DrawString("Vidas: " + vidas, gcnew Font("Arial", 14), Brushes::White, 0, 0);
		
		g->DrawString("\n\nPuntos: " + puntos, gcnew Font("Arial", 14), Brushes::White, 0, 0);
		Rectangle zoom = Rectangle(IDx * ancho, direccion * alto, alto, ancho);
		g->DrawImage(img, Area(), zoom, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, Area());
		//g->DrawRectangle(Pens::Blue, Hitbox());
		if (dx != 0 || dy != 0) {
			IDx = (IDx + 1) % 4;
		}
	}
	void Mostrar2(Graphics^ g, Bitmap^ img) {
		g->DrawString("Vidas: " + vidas, gcnew Font("Arial", 14), Brushes::White, 0, 0);

		g->DrawString("\n\nPuntos: " + puntos, gcnew Font("Arial", 14), Brushes::White, 0, 0);
		Rectangle zoom = Rectangle(IDx * ancho, direccion * alto, alto, ancho);
		g->DrawImage(img, Area(), zoom, GraphicsUnit::Pixel);
		//g->DrawRectangle(Pens::Black, Area());
		// g->DrawRectangle(Pens::Blue, Hitbox());
		if (dx != 0 || dy != 0) {
			IDx = (IDx + 1) % 4;
		}
	}
	void Mover(Graphics^ g) {
		if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width) {
			x += dx;
		}
		if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height) {
			y += dy;
		}
	}
};

