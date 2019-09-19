//Beatriz Herguedas Pinedo

#include "PriorityQueue.h"

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

int informatica(PriorityQueue<int> & cola1, PriorityQueue<int> & cola2) {

	int necesarios = -1;
	int cont = 0;

	while (!cola1.empty()) {

		if (cola1.top() < cola2.top()) {
			necesarios++;
			cola1.pop();
		}

		else {
			necesarios--;
			cola2.pop();
		}

		cont = max(cont, necesarios);
	}

	return cont;
}

bool resuelveCaso() {
	int N, ini, fin;
	PriorityQueue<int> cola1, cola2;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> ini >> fin;
		cola1.push(ini);
		cola2.push(fin);
	}

	cout << informatica(cola1, cola2) << '\n';

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