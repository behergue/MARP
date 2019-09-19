//Beatriz Herguedas Pinedo

#include <algorithm>
#include <assert.h>
#include <climits>
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

#include "Matriz.h"

using namespace std;

bool resuelveCaso() {
	int P, R;
	string nombre1, nombre2;
	unordered_map<string, int> mapa;

	cin >> P;

	if (!std::cin)
		return false;

	cin >> R;
	
	Matriz<int> M(P, P, INT_MAX);

	for (int i = 0; i < P; i++) {
		M[i][i] = 0;
	}

	int cont = 0;
	for (int i = 0; i < R; i++) {
		cin >> nombre1 >> nombre2;

		auto it1 = mapa.find(nombre1);
		auto it2 = mapa.find(nombre2);

		if (it1 == mapa.end()) {
			mapa.insert({ nombre1, cont });
			cont++;
		}

		if (it2 == mapa.end()) {
			mapa.insert({ nombre2, cont });
			cont++;
		}

		M[mapa[nombre1]][mapa[nombre2]] = 1;
		M[mapa[nombre2]][mapa[nombre1]] = 1;
	}

	for (int k = 0; k < P; k++) {
		for (int i = 0; i < P; i++) {
			for (int j = 0; j < P; j++) {
				if (M[i][k] != INT_MAX && M[k][j] != INT_MAX)
					M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
			}
		}
	}

	int maximo = 0;
	for (int i = 0; i < P; i++) {
		for (int j = 0; j < P; j++) {
			maximo = max(maximo, M[i][j]);
		}
	}

	if (maximo == INT_MAX)
		cout << "DESCONECTADA\n";

	else
		cout << maximo << '\n';

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