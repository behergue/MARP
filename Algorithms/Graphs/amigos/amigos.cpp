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

void amigos(Grafo const &g, vector<bool> &marcado, int &cont, int ini) {

	cont++;
	marcado[ini] = true;

	for (int i : g.adj(ini)) {

		if (!marcado[i])
			amigos(g, marcado, cont, i);
	}
}

void resuelveCaso() {
	int N, M, A, B;
	int maxim = 0;
	int cont = 0;

	cin >> N >> M;

	Grafo g(N + 1);
	vector<bool> marcado(N + 1, false);

	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		g.ponArista(A, B);
	}

	for (int i = 1; i < N + 1; i++) {
		cont = 0;

		if(!marcado[i])
			amigos(g, marcado, cont, i);

		maxim = max(maxim, cont);
	}

	cout << maxim << '\n';
}

int main() {

#ifndef DOMJUDGE

	std::ifstream in("archivo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif 
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE 

	std::cin.rdbuf(cinbuf);
	system("PAUSE");

#endif

	return 0;
}