#pragma once
#include <time.h>
#include "Jugador.h"
#include "Bacterias.h"
#include "Enemigo.h"
#include "Bala.h"
#include"FormDefeat.h"
#include"FormVictory.h"
using namespace System::Windows::Forms;
ref class Juego {
private:
	Jugador* jugador;
	Bacterias* bacterias;
	Enemigos* enemigos2;
	Balas* balas;

	Bitmap^ player;
	Bitmap^ enemy;
	Bitmap^ enemy2;
	Bitmap^ potion;

	bool juegoTerminado = false;
	int cooldown_atk;
	int time;
public:
	Juego(int v, int e, int t, int e2) {
		player = gcnew Bitmap("img/pj.png");
		enemy = gcnew Bitmap("img/enemy.png");
		enemy2 = gcnew Bitmap("img/enemy2.png");
		potion = gcnew Bitmap("img/potion.png");

		jugador = new Jugador(player, v);
		bacterias = new Bacterias(e, enemy);
		enemigos2 = new Enemigos(enemy2, e2);
		balas = new Balas();

		cooldown_atk = 0;
		time = t * 1000;
	}
	~Juego() {
		delete jugador;
		delete bacterias;
		delete balas;
		delete player;
		delete enemy;
		delete enemy2;
	}
	void Disparar() {
		int v = 10;
		if (jugador->GetAccion() == Arriba) {
			balas->Agregar(new Bala(jugador->GetX() + jugador->GetAncho() / 2, jugador->GetY() + jugador->GetAlto() / 2, 0, -v));
		}
		else if (jugador->GetAccion() == Abajo) {
			balas->Agregar(new Bala(jugador->GetX() + jugador->GetAncho() / 2, jugador->GetY() + jugador->GetAlto() / 2, 0, v));
		}
		else if (jugador->GetAccion() == Izquierda) {
			balas->Agregar(new Bala(jugador->GetX() + jugador->GetAncho() / 2, jugador->GetY() + jugador->GetAlto() / 2, -v, 0));
		}
		else if (jugador->GetAccion() == Derecha) {
			balas->Agregar(new Bala(jugador->GetX() + jugador->GetAncho() / 2, jugador->GetY() + jugador->GetAlto() / 2, v, 0));
		}
	}
	void MovimientoJugador(bool accion, Keys tecla) {
		int v = 4;
		if (accion) {
			if (tecla == Keys::Up) { jugador->SetDy(-v); jugador->SetAccion(Arriba); }
			else if (tecla == Keys::Down) { jugador->SetDy(v); jugador->SetAccion(Abajo); }
			else if (tecla == Keys::Left) { jugador->SetDx(-v); jugador->SetAccion(Izquierda); }
			else if (tecla == Keys::Right) { jugador->SetDx(v); jugador->SetAccion(Derecha); }
		}
		else {
			if (tecla == Keys::Up) { jugador->SetDy(0); }
			else if (tecla == Keys::Down) { jugador->SetDy(0); }
			else if (tecla == Keys::Left) { jugador->SetDx(0); }
			else if (tecla == Keys::Right) { jugador->SetDx(0); }
		}
		if (accion && tecla == Keys::A) {
			Disparar();
		}
	}
	
	bool Mover(Graphics^ g) {
		for (int i = 0; i < balas->Size(); i++) {
			Bala* B = balas->get(i);
			jugador->SetPuntos(bacterias->Eliminar(B->Area()));
		}
		if (bacterias->Colision(jugador->Hitbox()) && clock() - cooldown_atk >= 4000) {
			jugador->SetVidas(-1);
			cooldown_atk = clock();
		}
		if (bacterias->getNumeroBacterias() == 0 && !juegoTerminado) {
			juegoTerminado = true;
			TF::FormVictory^ victoryScreen = gcnew TF::FormVictory();
			victoryScreen->ShowDialog(); // Esto mostrará la forma como un diálogo modal
			return false; // Indica que el juego ha terminado.
		}
		// Aquí es donde comprobamos si el jugador ha perdido.
		if (jugador->GetVidas() == 0 || clock() >= time) {
			if (!juegoTerminado) {
				juegoTerminado = true;
				TF::FormDefeat^ gameOverScreen = gcnew TF::FormDefeat();
				gameOverScreen->ShowDialog(); // Esto mostrará la forma como un diálogo modal
			}
			return false;  // Indica que el juego ha terminado.
		}
		// En caso de que el jugador no haya perdido, continuamos con el movimiento.
		if (bacterias->Colision(jugador->Hitbox()) == false) {
			jugador->Mover(g);
		}
		bacterias->bMover(g);
		balas->Mover(g);
		return true;  // Indica que el juego sigue en marcha.
	}
	bool Mover2(Graphics^ g) {
		for (int i = 0; i < balas->Size(); i++) {
			Bala* B = balas->get(i);
			jugador->SetPuntos(enemigos2->Eliminar2(B->Area()));
		}
		if (enemigos2->Colision2(jugador->Hitbox()) && clock() - cooldown_atk >= 2000) {
			jugador->SetVidas(-1);
			cooldown_atk = clock();
		}
		if (enemigos2->getNumeroEnemigos() == 0 && !juegoTerminado) {
			juegoTerminado = true;
			TF::FormVictory^ victoryScreen = gcnew TF::FormVictory();
			victoryScreen->ShowDialog(); // Esto mostrará la forma como un diálogo modal
			return false; // Indica que el juego ha terminado.
		}
		if (jugador->GetVidas() == 0 || clock() >= time) {
			if (!juegoTerminado) {
				juegoTerminado = true;
				TF::FormDefeat^ gameOverScreen = gcnew TF::FormDefeat();
				gameOverScreen->ShowDialog(); // Esto mostrará la forma como un diálogo modal
			}
			return false;  // Indica que el juego ha terminado.
		}
		if (clock() >= time)
			return false;

		if (enemigos2->Colision2(jugador->NextHitbox()) == false) {
			jugador->Mover(g);
		}

		enemigos2->Mover2(g);
		balas->Mover(g);
		return true;
	}
	void Mostrar(Graphics^ g) {
		g->DrawString("\nTiempo: " + ((time - clock()) / 1000) + " s", gcnew Font("Arial", 14), Brushes::White, 0, 0);
		bacterias->bMostrar(g, enemy);
		balas->Mostrar(g, potion);
		jugador->Mostrar(g, player);
	}
	void Mostrar2(Graphics^ g) {
		g->DrawString("\nTiempo: " + ((time - clock()) / 1000) + " s", gcnew Font("Arial", 14), Brushes::White, 0, 0);
		//bacterias->bMostrar(g, enemy);
		enemigos2->Mostrar2(g, enemy2);
		balas->Mostrar(g, potion);
		jugador->Mostrar2(g, player);
	}


};
