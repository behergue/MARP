//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>

#include "bintree_eda.h"

using namespace std;

bool equilibrado(bintree<char> const & arbol, int & altura) {
	 
	if (arbol.empty()) {
		altura = 0;
		return true;
	}

	else {
		int alturaIzq, alturaDcha;
		bool equilibIzq, equilibDcha;

		equilibIzq = equilibrado(arbol.left(), alturaIzq);
		equilibDcha = equilibrado(arbol.right(), alturaDcha);

		altura = max(alturaIzq, alturaDcha) + 1;

		if (equilibIzq && equilibDcha && abs(alturaIzq - alturaDcha) < 2)
			return true;

		else
			return false;
	}
}


void resuelveCaso() {
	bintree<char> arbol;
	int altura;

	arbol = leerArbol('.');

	if (equilibrado(arbol, altura))
		cout << "SI\n";

	else
		cout << "NO\n";
}

int main() {

#ifndef DOMJUDGE

	std::ifstream in("archivo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif 
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE 

	std::cin.rdbuf(cinbuf);
	system("PAUSE");

#endif

	return 0;
}
