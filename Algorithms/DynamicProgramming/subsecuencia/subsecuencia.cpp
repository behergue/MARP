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

bool resuelveCaso() {
	string palabra1, palabra2;

	cin >> palabra1;

	if (!std::cin)
		return false;

	cin >> palabra2;

	int n = palabra1.size();
	int m = palabra2.size();


	//casos base rellenados con ceros
	vector<int> v(m + 1);

	int aux;
	int maximo;

	for (int i = 1; i < n + 1; i++) {
		aux = 0;
		for (int j = 1; j < m + 1; j++) {
			if (palabra1[i - 1] == palabra2[j - 1])
				maximo = max(v[j - 1], max(v[j], aux + 1));

			else
				maximo = max(v[j - 1], max(v[j], aux));

			//en aux voy a guardar el valor antiguo de v[j], es decir, M[i - 1][j - 1]
			aux = v[j];

			//y ahora actualizamos M[i][j]
			v[j] = maximo;
		}
	}

	cout << v[m] << '\n';

	//casos base rellenados con ceros
	//Matriz<int> M(n + 1, m + 1);


	/*for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {

			//los vectores van siempre de 0 a n y estamos empezando a leer en 1!!!
			if (palabra1[i - 1] == palabra2[j - 1])
				M[i][j] = max(M[i][j - 1], max(M[i - 1][j], M[i - 1][j - 1] + 1));

			else
				M[i][j] = max(M[i][j - 1], max(M[i - 1][j], M[i - 1][j - 1]));

		}
	}

	cout << M[n][m] << '\n';*/

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