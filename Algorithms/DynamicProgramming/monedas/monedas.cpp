//Beatriz Herguedas Pinedo

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

#include "Matriz.h"

using namespace std;

bool resuelveCaso() {
	int N, valor, C;

	cin >> N;

	if (!std::cin)
		return false;

	vector<pair<int, int>> v;
	v.push_back({ 0, 0 });

	for (int i = 1; i < N + 1; i++) {
		cin >> valor;
		v.push_back({ valor, 0 });
	}

	for (int i = 1; i < N + 1; i++) {
		cin >> valor;
		v[i].second = valor;
	}

	cin >> C;

	// filas = tipos de monedas, columnas = cantidad que queremos sumar
	// en cada pos llevamos el mínimo de monedas necesarias
	//Matriz<int> M(N + 1, C + 1);

	vector<int> vector(C + 1);

	// Casos base
	/*for (int j = 1; j < C + 1; j++) {
		M[0][j] = INT_MAX;
	}*/


	for (int j = 1; j < C + 1; j++) {
		vector[j] = INT_MAX;
	}

	// Recursion
	/*for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			int aux = INT_MAX;
			// k es el numero de monedas que cojo
			for (int k = 0; k <= v[i].second && k * v[i].first <= j; k++) {
				if(M[i - 1][j - k * v[i].first] != INT_MAX)
					aux = min(aux, M[i - 1][j - k * v[i].first] + k);
			}
			M[i][j] = aux;
		}
	}*/

	for (int i = 1; i < N + 1; i++) {
		for (int j = C; j >= 0; j--) {
			int aux = INT_MAX;
			// k es el numero de monedas que cojo
			for (int k = 0; k <= v[i].second && k * v[i].first <= j; k++) {
				if (vector[j - k * v[i].first] != INT_MAX)
					aux = min(aux, vector[j - k * v[i].first] + k);
			}
			vector[j] = aux;
		}
	}

	if (vector[C] == INT_MAX)
		cout << "NO\n";

	else
		cout << "SI " << vector[C] << '\n';

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