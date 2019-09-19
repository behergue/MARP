//Beatriz Herguedas Pinedo

#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

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

bool resuelveCaso() {
	int I, P, v1, v2, coste;
	int cont = 0;

	cin >> I >> P;

	if (!std::cin)
		return false;

	GrafoValorado<int> g(I + 1);
	vector<bool> marcado(I + 1);

	queue<Arista<int>> mst;
	PriorityQueue<Arista<int>> pq;
	ConjuntosDisjuntos uf(I + 1);

	for (int i = 0; i < P; i++) {
		cin >> v1 >> v2 >> coste;
		g.ponArista(Arista<int>(v1, v2, coste));
		pq.push(Arista<int>(v1, v2, coste));
	}

	while (!pq.empty() && mst.size() < g.V() - 1) {
		Arista<int> a = pq.top();
		pq.pop();
		int v = a.uno();
		int w = a.otro(v);

		if (!uf.unidos(v, w)) {
			uf.unir(v, w);
			mst.push(a);
			cont += a.valor();
		}
	}

	// Mayor que 2 porque el conjunto del 0 siempre va a estar
	if (uf.num_cjtos() > 2)
		cout << "No hay puentes suficientes\n";

	else
		cout << cont << '\n';


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