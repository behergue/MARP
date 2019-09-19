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

int partidos(vector<int> & a, vector<int> & b) {

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<int> aux;
	int N = b.size();

	for (int i = N - 1; i >= 0; i--) {
		aux.push_back(b[i]);
	}

	int suma = 0;

	for (int i = 0; i < a.size(); i++) {
		if(aux[i] > a[i])
			suma += aux[i] - a[i];
	}

	return suma;
}

bool resuelveCaso() {
	int N, valor;
	vector<int> a, b;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		a.push_back(valor);
	}

	for (int i = 0; i < N; i++) {
		cin >> valor;
		b.push_back(valor);
	}

	cout << partidos(a, b) << '\n';

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