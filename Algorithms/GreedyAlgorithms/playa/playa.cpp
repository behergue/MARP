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

int pasarelas(vector<pair<int, int>> & v) {

	sort(v.begin(), v.end());

	int cont = 1;
	int ini = v[0].first;
	int fin = v[0].second;

	for (int i = 1; i < v.size(); i++) {

		if (fin > v[i].first) {
			ini = v[i].first;
			fin = min(fin, v[i].second);
		}
		else {
			cont++;
			ini = v[i].first;
			fin = v[i].second;
		}
	}

	return cont;
}

bool resuelveCaso() {
	int N, W, E;
	vector<pair<int, int>> v;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> W >> E;
		v.push_back({ W, E });
	}

	cout << pasarelas(v) << '\n';

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