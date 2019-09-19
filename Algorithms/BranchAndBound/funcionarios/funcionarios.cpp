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

#include "Matriz.h"
#include "PriorityQueue.h"

using namespace std;

struct nodo {
	int k;
	int tiempo;
	int topt;
	vector<bool> asignado;
};

bool operator<(nodo const& a, nodo const& b) {
	return a.topt < b.topt;
}

bool resuelveCaso() {
	int N;

	cin >> N;

	if (N == 0)
		return false;

	Matriz<int> M(N + 1, N + 1);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cin >> M[i][j];
		}
	}

	vector<int> rapido(N + 1), lento(N + 1), opt(N + 1), pes(N + 1);

	for (int i = 1; i < N + 1; i++) {
		rapido[i] = M[i][1];
		lento[i] = M[i][1];

		for (int j = 2; j < N + 1; j++) {
			rapido[i] = min(rapido[i], M[i][j]);
			lento[i] = max(lento[i], M[i][j]);
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		opt[i] = opt[i + 1] + rapido[i + 1];
		pes[i] = pes[i + 1] + lento[i + 1];
	}

	nodo X, Y;
	PriorityQueue<nodo> C;

	Y = {0, 0, opt[0], vector<bool> (N + 1, false)};
	C.push(Y);

	int tiempomejor = pes[0];

	while (!C.empty() && C.top().topt <= tiempomejor) {
		Y = C.top();
		C.pop();
		X.k = Y.k + 1;
		X.asignado = Y.asignado;

		for (int t = 1; t < N + 1; t++) {
			if (!X.asignado[t]) {
				X.asignado[t] = true;
				X.tiempo = Y.tiempo + M[X.k][t];
				X.topt = X.tiempo + opt[X.k];

				if (X.topt <= tiempomejor) {

					if (X.k == N) {
						tiempomejor = X.tiempo;
					}

					else {
						C.push(X);
						tiempomejor = min(tiempomejor, X.tiempo + pes[X.k]);
					}
				}

				X.asignado[t] = false;
			}
		}
	}

	cout << tiempomejor << '\n';

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