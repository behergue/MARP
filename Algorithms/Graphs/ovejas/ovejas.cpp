//Beatriz Herguedas Pinedo

#include "Grafo.h"
#include "Matriz.h"

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

void profundidad(Grafo const &g, vector<bool> & marcado, Matriz<char> const &m, int ini, int ancho) {

	marcado[ini] = true;

	for (int i : g.adj(ini)) {

		if (m[i / ancho][i - (i / ancho) * ancho] == '.' && !marcado[i]) {
			profundidad(g, marcado, m, i, ancho);
		}
	}
}

int ovejas(Grafo const &g, int ancho, int alto, Matriz<char> const &m) {
	vector<bool> marcado(ancho * alto, false);
	int cont = 0;
	
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {

			if (!marcado[i * ancho + j] && m[i][j] == '.') {
				profundidad(g, marcado, m, i * ancho + j, ancho);
				cont++;
			}
		}
	}

	return cont;
}

bool resuelveCaso() {
	int ancho, alto;
	char valor;

	cin >> ancho >> alto;

	if (!std::cin)
		return false;

	Grafo g(ancho * alto);
	Matriz<char> m(alto, ancho);

	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			cin >> valor;
			m[i][j] = valor;

			if (m.posCorrecta(i - 1, j))
				g.ponArista(i * ancho + j, (i - 1) * ancho + j);

			if (m.posCorrecta(i + 1, j))
				g.ponArista(i * ancho + j, (i + 1) * ancho + j);

			if (m.posCorrecta(i, j + 1))
				g.ponArista(i * ancho + j, i * ancho + j + 1);

			if (m.posCorrecta(i, j - 1))
				g.ponArista(i * ancho + j, i * ancho + j - 1);
		}
	}

	cout << ovejas(g, ancho, alto, m) - 1 << '\n';

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