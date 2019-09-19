//Beatriz Herguedas Pinedo

#include "ConjuntosDisjuntos.h"
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

void expandir(Matriz<char> const & matris, ConjuntosDisjuntos & mancha, int i, int j, int C) {

	if (matris.posCorrecta(i - 1, j - 1) && matris[i - 1][j - 1] == '#')
		mancha.unir(i * C + j, (i - 1) * C + j - 1);

	if (matris.posCorrecta(i - 1, j) && matris[i - 1][j] == '#')
		mancha.unir(i * C + j, (i - 1) * C + j);

	if (matris.posCorrecta(i - 1, j + 1) && matris[i - 1][j + 1] == '#')
		mancha.unir(i * C + j, (i - 1) * C + j + 1);

	if (matris.posCorrecta(i, j - 1) && matris[i][j - 1] == '#')
		mancha.unir(i * C + j, i * C + j - 1);

	if (matris.posCorrecta(i, j + 1) && matris[i][j + 1] == '#')
		mancha.unir(i * C + j, i * C + j + 1);

	if (matris.posCorrecta(i + 1, j - 1) && matris[i + 1][j - 1] == '#')
		mancha.unir(i * C + j, (i + 1) * C + j - 1);

	if (matris.posCorrecta(i + 1, j) && matris[i + 1][j] == '#')
		mancha.unir(i * C + j, (i + 1) * C + j);

	if (matris.posCorrecta(i + 1, j + 1) && matris[i + 1][j + 1] == '#')
		mancha.unir(i * C + j, (i + 1) * C + j + 1);
}

bool resuelveCaso() {
	int F, C, N, fila, col;
	char valor;
	string linea;
	bool petroleo = false;

	cin >> F >> C;

	if (!std::cin)
		return false;

	cin.ignore(1);
	
	Matriz<char> matris(F, C);
	ConjuntosDisjuntos mancha(F * C);

	for (int i = 0; i < F; i++) {

		getline(cin, linea);
		
		for (int j = 0; j < C; j++) {

			matris[i][j] = linea[j];

			if (linea[j] == '#') {
				petroleo = true;
				expandir(matris, mancha, i, j, C);
			}
		}
	}

	if (petroleo) 
		cout << mancha.conjuntoMax();

	else
		cout << "0";

	cin >> N;

	if (N > 0)
		cout << ' ';

	for (int i = 0; i < N; ++i) {

		cin >> fila >> col;
		fila--;
		col--;

		matris[fila][col] = '#';

		expandir(matris, mancha, fila, col, C);

		cout << mancha.conjuntoMax();

		if (i < N - 1)
			cout << ' ';
	}

	cout << '\n';

	return true;
}

int main() {

#ifndef DOMJUDGE

	std::ifstream in("archivo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE 

	std::cin.rdbuf(cinbuf);
	system("PAUSE");

#endif

	return 0;
}