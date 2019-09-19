//Beatriz Herguedas Pinedo

#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

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
	int N, M, v1, v2, tcarga, tenlace;
	vector<int> v;

	cin >> N;

	if (N == 0)
		return false;

	v.push_back(0);

	for (int i = 1; i < N + 1; i++) {
		cin >> tcarga;
		v.push_back(tcarga);
	}

	GrafoDirigidoValorado<int> g(N + 1);
	vector<bool> marcado(N + 1);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> tenlace;
		g.ponArista(AristaDirigida<int>(v1, v2, tenlace));
	}


	vector<int> distTo(N + 1, INT_MAX);
	IndexPQ<int> pq(N + 1);

	pq.push(1, v[1]);
	distTo[1] = v[1];

	while (!pq.empty()) {
		int b = pq.top().elem;
		pq.pop();

		for (AristaDirigida<int> a : g.adj(b)) {
			int x = a.from();
			int w = a.to();

			if (distTo[w] > distTo[x] + a.valor() + v[w]) {
				distTo[w] = distTo[x] + a.valor() + v[w];
				pq.update(w, distTo[w]);
			}
		}
	}

	if (distTo[N] < INT_MAX)
		cout << distTo[N] << '\n';

	else
		cout << "IMPOSIBLE\n";

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