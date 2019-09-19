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

using namespace std;

int pilas(deque<int> & cola, int V) {

	sort(cola.begin(), cola.end());

	int cont = 0;


	while (!cola.empty() ) {

		if(cola.back() + cola.front() < V)
			cola.pop_front();

		else {
			cola.pop_front();
			if (!cola.empty()) {
				cola.pop_back();
				cont++;
			}
		}
	}

	return cont;
}


void resuelveCaso() {
	int N, V, valor;
	deque<int> cola;

	cin >> N >> V;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		cola.push_back(valor);
	}

	cout << pilas(cola, V) << '\n';
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