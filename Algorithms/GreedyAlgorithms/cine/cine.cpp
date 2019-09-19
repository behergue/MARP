//Beatriz Herguedas Pinedo

#include "horas.h"

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

int peliculas(vector<pair<hora, hora>> & v) {

	sort(v.begin(), v.end());

	int cont = 1;
	hora fin = v[0].second;
	hora descanso = hora(10);

	for (int i = 1; i < v.size(); i++) {

		if (v[i].first < fin) {
			if (v[i].second < fin)
				fin = v[i].second;
		}

		else if(fin + descanso< v[i].first || fin + descanso == v[i].first) {
			cont++;
			fin = v[i].second;
		}
	}

	return cont;
}

bool resuelveCaso() {
	int N, duracion;
	hora empieza, dur, termina;
	vector<pair<hora, hora>> v;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> empieza >> duracion;
		dur = hora(duracion);
		termina = empieza + dur;
		v.push_back({ empieza, termina });
	}

	cout << peliculas(v) << '\n';

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