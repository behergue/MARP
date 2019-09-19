//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>

#include "bintree_eda.h"

using namespace std;

bool AVL(bintree<int> const & arbol, int & altura, int & maxim, int & minim) {

	if (arbol.empty()) {
		altura = 0;
		return true;
	}

	else if (arbol.left().empty() && arbol.right().empty()) {
		altura = 1;
		maxim = arbol.root();
		minim = arbol.root();
		return true;
	}

	else if (arbol.right().empty()) {

		int alturaIzq, maxIzq, minIzq;
		bool AVLIzq;

		AVLIzq = AVL(arbol.left(), alturaIzq, maxIzq, minIzq);

		altura = alturaIzq + 1;
		minim = min(minIzq, arbol.root());
		maxim = max(maxIzq, arbol.root());

		if (AVLIzq && alturaIzq < 2 && arbol.root() > maxIzq)
			return true;

		else
			return false;
	}

	else if (arbol.left().empty()) {

		int alturaDcha, maxDcha, minDcha;
		bool AVLDcha;

		AVLDcha = AVL(arbol.right(), alturaDcha, maxDcha, minDcha);

		altura = alturaDcha + 1;
		minim = min(maxDcha, arbol.root());
		maxim = max(maxDcha, arbol.root());

		if (AVLDcha && alturaDcha < 2 && arbol.root() < minDcha)
			return true;

		else
			return false;
	}

	else {
		int alturaIzq, alturaDcha;
		int maxIzq, maxDcha;
		int minIzq, minDcha;
		bool AVLIzq, AVLDcha;

		AVLIzq = AVL(arbol.left(), alturaIzq, maxIzq, minIzq);
		AVLDcha = AVL(arbol.right(), alturaDcha, maxDcha, minDcha);

		altura = max(alturaIzq, alturaDcha) + 1;
		minim= min(min(minIzq, minDcha), arbol.root());
		maxim = max(max(maxIzq, maxDcha), arbol.root());


		if (AVLIzq && AVLDcha && abs(alturaIzq - alturaDcha) < 2
			&& arbol.root() > maxIzq && arbol.root() < minDcha)
			return true;

		else
			return false;
	}
}


void resuelveCaso() {
	bintree<int> arbol;
	int altura, maxim, minim;

	arbol = leerArbol(-1);

	if (AVL(arbol, altura, maxim, minim))
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
