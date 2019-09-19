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
	int N, valor;
	vector<int> v;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	// La pos [i][j] representa lo max que puedo comer considerando los cubos del i al j
	Matriz<int> M(N , N);

	// Casos base
	for (int i = 0; i < N; i++) {
		M[i][i] = v[i];
	}

	// Recursion
	// La diagnoal empieza en 1 porque la 0 es la principal que ya la hemos rellenado con casos base
	for (int d = 1; d < N; d++) {
		for (int i = 0; i < N - d; i++) {
			int j = i + d;
			int a, b;

			if (j == i + 1)
				a = v[i];

			// yo me he comido el i y devoradora se come el i + 1
			else if (v[i + 1] >= v[j])
				a = v[i] + M[i + 2][j];

			// yo me he comido el i y devoradora el j
			else
				a = v[i] + M[i + 1][j - 1];

			if (j == i + 1)
				b = v[j];

			// yo me he comido el j y devoradora se come el j - 1
			else if (v[i] <= v[j - 1])
				b = v[j] + M[i][j - 2];

			// yo me he comido el j y devoradora el i
			else
				b = v[j] + M[i + 1][j - 1];

			M[i][j] = max(a, b);
		}
	}

	cout << M[0][N - 1] << '\n';

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