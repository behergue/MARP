//Beatriz Herguedas Pinedo

#include "Matriz.h"

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

struct cofre {
	int oros, profundidad;
	bool cogido;
};


bool resuelveCaso() {
	int T, N;
	cofre c;

	cin >> T;

	if (!std::cin)
		return false;

	cin >> N;
	vector<cofre> v;

	for (int i = 0; i < N; i++) {
		cin >> c.profundidad >> c.oros;
		c.cogido = false;
		v.push_back(c);
	}

	Matriz<int> M(N + 1, T + 1);

	//casos base
	for (int i = 0; i < N + 1; i++) {
		M[i][0] = 0;
	}

	for (int j = 0; j < T + 1; j++) {
		M[0][j] = 0;
	}

	//recursion
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < T + 1; j++) {

			if (j < 3 * v[i - 1].profundidad) {
				M[i][j] = M[i - 1][j];
			}

			else {
				M[i][j] = max(M[i - 1][j], M[i - 1][j - 3 * v[i - 1].profundidad] + v[i - 1].oros);
			}
		}
	}

	//reconstruimos la matriz
	int j = T;
	int numcofres = 0;

	for (int i = N; i > 0; i--) {
		if (M[i][j] != M[i - 1][j]) {
			v[i - 1].cogido = true;
			j -= 3 * v[i - 1].profundidad;
			numcofres++;
		}
	}

	cout << M[N][T] << '\n';
	cout << numcofres << '\n';

	for (int i = 0; i < N; i++) {
		if (v[i].cogido)
			cout << v[i].profundidad << " " << v[i].oros << '\n';
	}

	cout << "----\n";

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