//Beatriz Herguedas Pinedo

//#include "GrafoDirigido.h"
#include "PriorityQueue.h"

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
	int N, K, S, E, ini, fin;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comparador> casillasNoVisitadas;

	cin >> N >> K >> S >> E;

	if (N == 0 && K == 0 && S == 0 && E == 0)
		return false;

	vector<bool> tablero(N * N);
	vector<int> serpientes(N * N, -1);
	vector<int> escaleras(N * N, -1);

	for (int i = 0; i < S; i++) {
		cin >> ini >> fin;
		serpientes[ini - 1] = fin - 1;
	}

	for (int i = 0; i < E; i++) {
		cin >> ini >> fin;
		escaleras[ini - 1] = fin - 1;
	}

	int sol = INT_MAX;
	bool ok = true;

	casillasNoVisitadas.push({ 0,0 });

	while (!casillasNoVisitadas.empty() && ok) {

		auto casillaActual = casillasNoVisitadas.top();
		casillasNoVisitadas.pop();

		tablero[casillaActual.first] = true;

		if (casillaActual.second >= sol)
			ok = false;

		else if (casillaActual.first == N * N - 1)
			sol = casillaActual.second;

		for (int i = 1; i <= K && casillaActual.first + i < N * N; i++) {

			if (!tablero[casillaActual.first + i]) {

				if (escaleras[casillaActual.first + i] != -1)
					casillasNoVisitadas.push({ escaleras[casillaActual.first + i], casillaActual.second + 1 });

				else if (serpientes[casillaActual.first + i] != -1)
					casillasNoVisitadas.push({ serpientes[casillaActual.first + i], casillaActual.second + 1 });

				else
					casillasNoVisitadas.push({ casillaActual.first + i, casillaActual.second + 1 });
			}

			tablero[casillaActual.first + i] = true;
		}
	}

	cout << sol << '\n';

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