//Beatriz Herguedas Pinedo

#include "Matriz.h"
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
	int N, M, K, n, x, y, fila, col;
	stack<pair<int, int>> pila;
	bool hecho = false;

	cin >> N >> M >> K >> n;

	if (!std::cin)
		return false;

	M++;
	N++;

	ConjuntosDisjuntos espana(N * M);
	Matriz<bool> matris(N, M);

	matris[0][0] = true;
	matris[N - 1][M - 1] = true;

	
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		pila.push({ x, y });
	}

	while (!pila.empty() && !hecho) {

		fila = pila.top().first;
		col = pila.top().second;

		if (!hecho) {
			for (int j = -K; j < K + 1; j++) {
				if (!hecho) {
					for (int l = -K; l < K + 1; l++) {

						if (sqrt(j*j + l * l) <= K && matris.posCorrecta(fila + j, col + l) && matris[fila + j][col + l])
							espana.unir(fila * M + col, (fila + j) * M + col + l);

						if (espana.unidos(0, N * M - 1))
							hecho = true;
					}
				}
			}
		}

		matris[fila][col] = true;
		pila.pop();
	}
	if (!hecho)
		cout << "NUNCA SE PUDO\n";

	else
		cout << fila << " " << col << '\n';

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