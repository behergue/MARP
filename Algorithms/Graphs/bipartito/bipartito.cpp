//Beatriz Herguedas Pinedo

#include "Grafo.h"

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

void bipartito(Grafo const &g, vector<char> &marcado, int ini, char color, bool & ok) {

	if (ok) {

		marcado[ini] = color;

		for (int i : g.adj(ini)) {

			if (marcado[i] == 'n') {
				if (color == 'a')
					bipartito(g, marcado, i, 'r', ok);

				else
					bipartito(g, marcado, i, 'a', ok);
			}

			else if (marcado[i] == color)
				ok = false;
		}
	}
}

bool resuelveCaso() {
	int V, A, v1, v2;

	cin >> V >> A;

	if (!std::cin)
		return false;

	Grafo g(V);
	vector<char> marcado(V, 'n');

	for (int i = 0; i < A; i++) {
		cin >> v1 >> v2;
		g.ponArista(v1, v2);
	}

	bool ok = true;
	int i = 0;

	while (ok && i < V) {

		if (marcado[i] == 'n')
			bipartito(g, marcado, i, 'a', ok);
		
		i++;
	}

	if (ok)
		cout << "SI\n";

	else
		cout << "NO\n";

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