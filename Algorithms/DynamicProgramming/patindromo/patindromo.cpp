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
	string palabra;

	cin >> palabra;

	if (!std::cin)
		return false;

	// Enfrentamos una palabra consigo misma y en la pos [i][j] consideramos el palíndromo más largo desde i hasta j
	Matriz<string> M(palabra.size() + 1, palabra.size() + 1, "");

	// Casos base
	for (int i = 1; i < palabra.size() + 1; i++) {
		M[i][i] = palabra[i - 1];
	}

	for (int d = 1; d < palabra.size(); d++) {
		for (int i = 1; i <= palabra.size() - d; i++) {
			int j = i + d;

			if (palabra[i - 1] == palabra[j - 1])
				M[i][j] = palabra[i - 1] + M[i + 1][j - 1] + palabra[j - 1];
			else if (M[i + 1][j].size() >= M[i][j - 1].size())
				M[i][j] = M[i + 1][j];
			else
				M[i][j] = M[i][j - 1];
		}
	}

	cout << M[1][palabra.size()] << '\n';

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