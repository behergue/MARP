//Beatriz Herguedas Pinedo

#include "GrafoDirigidoValorado.h"
#include  "IndexPQ.h"

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

using namespace std;


bool resuelveCaso() {
	int N, C, origen, destino, esfuerzo, O, P, casa;
	bool imposible = false;

	cin >> N >> C;

	if (!std::cin)
		return false;

	GrafoDirigidoValorado<int> gIda(N + 1);
	GrafoDirigidoValorado<int> gVuelta(N + 1);
	vector<int> marcado(N + 1);

	for (int i = 0; i < C; i++) {
		cin >> origen >> destino >> esfuerzo;
		gIda.ponArista(AristaDirigida<int>(origen, destino, esfuerzo));
		gVuelta.ponArista(AristaDirigida<int>(destino, origen, esfuerzo));
	}

	cin >> O >> P;

	vector<int> distTo1(N + 1, INT_MAX);
	IndexPQ<int> pq1(N + 1);

	pq1.push(O, 0);
	distTo1[O] = 0;

	while (!pq1.empty()) {
		int b = pq1.top().elem;
		pq1.pop();

		for (AristaDirigida<int> a : gIda.adj(b)) {
			int x = a.from();
			int w = a.to();

			if (distTo1[w] > distTo1[x] + a.valor()) {
				distTo1[w] = distTo1[x] + a.valor();
				pq1.update(w, distTo1[w]);
			}
		}
	}

	vector<int> distTo2(N + 1, INT_MAX);
	IndexPQ<int> pq2(N + 1);

	pq2.push(O, 0);
	distTo2[O] = 0;

	while (!pq2.empty()) {
		int b = pq2.top().elem;
		pq2.pop();

		for (AristaDirigida<int> a : gVuelta.adj(b)) {
			int x = a.from();
			int w = a.to();

			if (distTo2[w] > distTo2[x] + a.valor()) {
				distTo2[w] = distTo2[x] + a.valor();
				pq2.update(w, distTo2[w]);
			}
		}
	}

	int cont = 0;

	for (int i = 0; i < P; i++) {

		cin >> casa;

		if (!imposible) {

			if (distTo1[casa] == INT_MAX || distTo2[casa] == INT_MAX)
				imposible = true;

			else
				cont += distTo1[casa] + distTo2[casa];
		}
	}

	if (imposible)
		cout << "Imposible\n";

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