//Beatriz Herguedas Pinedo

#include "PriorityQueue.h"

using namespace std;

bool conflictos(PriorityQueue<pair<pair<int, int>, int>> &cola, int T) {

	int i = 0;
	int z = 0;
	bool conflicto = false;
	pair<pair<int, int>, int> aux1, aux2;

	while (cola.size() > 1 && !conflicto && z < T) {

		aux1 = cola.top();
		cola.pop();
		aux2 = cola.top();

		if (aux1.first.second > T)
			aux1.first.second = T;

		z = aux1.first.second;

		if (aux1.first.second > aux2.first.first)
			conflicto = true;

		else {
			if (aux1.second > 0) {
				aux1.first.first += aux1.second;
				aux1.first.second += aux1.second;
				cola.push(aux1);
			}
		}
	}

	return conflicto;
}

bool resuelveCaso() {
	int N, M, T, ini, fin, periodo;
	PriorityQueue<pair<pair<int, int>, int>> cola;

	cin >> N;

	if (!std::cin)
		return false;

	cin >> M >> T;

	for (int i = 0; i < N; i++) {
		cin >> ini >> fin;
		cola.push({ {ini, fin}, 0 });
	}

	for (int i = 0; i < M; i++) {
		cin >> ini >> fin >> periodo;
		cola.push({ {ini, fin}, periodo });
	}

	if (conflictos(cola, T))
		cout << "SI\n";

	else
		cout << "NO\n";

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