//Beatriz Herguedas Pinedo

#include "GrafoValorado.h"

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

void recorrido(int v1, int v2, GrafoValorado<int> const& g, int anchuraCamion, vector<bool> & marcado, bool & encontrado) {

	if (!encontrado) {
		for (Arista<int> i : g.adj(v1)) {
			if (i.valor() >= anchuraCamion) {

				if (i.otro(v1) == v2) {
					encontrado = true;
				}
				
				else if (!marcado[i.otro(v1)]) {
					marcado[i.otro(v1)] = true;
					recorrido(i.otro(v1), v2, g, anchuraCamion, marcado, encontrado);
				}
			}
		}
	}
}

bool resuelveCaso() {
	int V, E, v1, v2, anchura, N;
	bool encontrado = false;

	cin >> V >> E;

	if (!std::cin)
		return false;

	GrafoValorado<int> g(V + 1);
	vector<bool> marcado(V + 1);

	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2 >> anchura;
		g.ponArista(Arista<int>(v1, v2, anchura));
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> v1 >> v2 >> anchura;

		if (v1 == v2)
			cout << "SI\n";

		else {
			recorrido(v1, v2, g, anchura, marcado, encontrado);

			if (encontrado)
				cout << "SI\n";

			else
				cout << "NO\n";
		}

		encontrado = false;
		marcado.assign(V + 1, false);
	}

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