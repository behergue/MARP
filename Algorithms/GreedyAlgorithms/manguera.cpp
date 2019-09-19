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

int parches(vector<int> const& v, int L) {

	int cont = v.size();
	int ini = v[0];

	for (int i = 1; i < v.size(); i++) {
		if (v[i] - ini <= L)
			cont--;
		else
			ini = v[i];

	}

	return cont;
}

bool resuelveCaso() {
	int N, L, valor;
	vector<int> v;

	cin >> N >> L;

	if (!std::cin)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	cout << parches(v, L) << '\n';

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