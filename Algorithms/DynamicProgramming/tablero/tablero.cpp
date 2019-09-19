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

using namespace std;

bool resuelveCaso() {
	int N;

	cin >> N;

	if (!std::cin)
		return false;

	Matriz<int> tablero(N, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tablero[i][j];
		}
	}

	// cada pos contiene el maximo que puedo obtener para llegar a ella siguiendo las normas
	Matriz<int> M(N, N);

	// Casos base
	for (int j = 0; j < N; j++) {
		M[0][j] = tablero[0][j];
	}

	// Recursion
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j != 0 && j != N - 1)
				M[i][j] = max(max(M[i - 1][j - 1], M[i - 1][j]), M[i - 1][j + 1]) + tablero[i][j];
			else if (j != 0)
				M[i][j] = max(M[i - 1][j - 1], M[i - 1][j]) + tablero[i][j];
			else
				M[i][j] = max(M[i - 1][j], M[i - 1][j + 1]) + tablero[i][j];
		}
	}

	int maximo = 0;
	int pos = 0;
	for (int j = 0; j < N; j++) {
		if (M[N - 1][j] > maximo) {
			maximo = M[N - 1][j];
			pos = j + 1;
		}
	}

	cout << maximo << " " << pos << '\n';

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