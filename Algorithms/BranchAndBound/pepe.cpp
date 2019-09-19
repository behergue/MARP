//Beatriz Herguedas Pinedo

#include <algorithm>
#include <assert.h>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct nodo {
	int k;
	float tcaraA, tcaraB;
	float puntuacion;
	float puntOptimista;
};

struct cancion {
	float puntuacion, duracion;
};

bool operator<(nodo const& n1, nodo const& n2) {
	return n1.puntOptimista < n2.puntOptimista;
}

bool operator>(nodo const& n1, nodo const& n2) {
	return n1.puntOptimista > n2.puntOptimista;
}

bool operator<(cancion const & c1, cancion const & c2) {
	return (c1.puntuacion / c1.duracion) < (c2.puntuacion / c2.duracion);
}

bool operator>(cancion const& c1, cancion const& c2) {
	return (c1.puntuacion / c1.duracion) > (c2.puntuacion / c2.duracion);
}

float optimista(vector<cancion> const & v, float t, int k, float beneficio, float tcaraA, float tcaraB, int n) {
	float hueco = 2 * t - tcaraA - tcaraB;
	float opt = beneficio;
	int j = k + 1;

	while (j <= n && v[j].duracion <= hueco) {
		hueco -= v[j].duracion;
		opt += v[j].puntuacion;
		j++;
	}

	if (j <= n) {
		opt += (hueco / v[j].duracion) * v[j].puntuacion;
	}
	return opt;
}

float pesimista(vector<cancion> const& v, float t, int k, float beneficio, float tcaraA, float tcaraB, int n) {
	float ocupadoAaux = tcaraA;
	float ocupadoBaux = tcaraB;
	float pes = beneficio;
	int j = k + 1;

	while (j <= n && (ocupadoAaux <= t || ocupadoBaux <= t)) {

		if (ocupadoAaux + v[j].duracion <= t) {
			ocupadoAaux += v[j].duracion;
			pes += v[j].puntuacion;
		}

		else if (ocupadoBaux + v[j].duracion <= t) {
			ocupadoBaux += v[j].duracion;
			pes += v[j].puntuacion;
		}

		j++;
	}

	return pes;
}

bool resuelveCaso() {
	int n, t;
	cancion c;
	vector <cancion> v;

	cin >> n;

	if (n == 0)
		return false;

	cin >> t;
	v.push_back({ 0, 0 });

	for (int i = 0; i < n; i++) {
		cin >> c.duracion >> c.puntuacion;
		v.push_back(c);
	}

	sort(v.begin() + 1, v.end(), greater<cancion>());

	priority_queue<nodo> pq;
	nodo X, Y;

	Y.k = 0;
	Y.puntuacion = 0;
	Y.tcaraA = 0;
	Y.tcaraB = 0;
	Y.puntOptimista = optimista(v, t, Y.k, Y.puntuacion, Y.tcaraA, Y.tcaraB, n);
	float puntMejor = pesimista(v, t, Y.k, Y.puntuacion, Y.tcaraA, Y.tcaraB, n);

	pq.push(Y);

	while (!pq.empty() && pq.top().puntOptimista >= puntMejor) {

		Y = pq.top();
		pq.pop();

		X.k = Y.k + 1;

		//rama1: la metemos en la cara A
		if (Y.tcaraA + v[X.k].duracion <= t) {
			X.puntuacion = Y.puntuacion + v[X.k].puntuacion;
			X.tcaraA = Y.tcaraA + v[X.k].duracion;
			X.tcaraB = Y.tcaraB;
			X.puntOptimista = Y.puntOptimista;

			if (X.k == n)
				puntMejor = X.puntuacion;

			else
				pq.push(X);
		}

		//rama2: la metemos en la cara B
		if (Y.tcaraB + v[X.k].duracion <= t && Y.tcaraA != Y.tcaraB) {
			X.puntuacion = Y.puntuacion + v[X.k].puntuacion;
			X.tcaraB = Y.tcaraB + v[X.k].duracion;
			X.tcaraA = Y.tcaraA;
			X.puntOptimista = Y.puntOptimista;

			if (X.k == n)
				puntMejor = X.puntuacion;

			else {
				pq.push(X);
				puntMejor = max(pesimista(v, t, X.k, X.puntuacion, X.tcaraA, X.tcaraB, n), puntMejor);
			}
		}

		//rama3: no la cogemos
		X.puntuacion = Y.puntuacion;
		X.tcaraA = Y.tcaraA;
		X.tcaraB = Y.tcaraB;
		X.puntOptimista = optimista(v, t, X.k, X.puntuacion, X.tcaraA, X.tcaraB, n);

		if (X.puntOptimista >= puntMejor) {

			if (X.k == n)
				puntMejor = X.puntuacion;

			else {
				pq.push(X);
				puntMejor = max(pesimista(v, t, X.k, X.puntuacion, X.tcaraA, X.tcaraB, n), puntMejor);
			}
		}
	}

	cout << puntMejor << '\n';

	return true;
}

int main() {

#ifndef DOMJUDGE

	std::ifstream in("archivo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif 
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

#ifndef DOMJUDGE 

	std::cin.rdbuf(cinbuf);
	system("PAUSE");

#endif

	return 0;
}