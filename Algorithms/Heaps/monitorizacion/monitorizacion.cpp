//Beatriz Herguedas Pinedo

#include "PriorityQueue.h"

using namespace std;

void KprimerosEnvios(PriorityQueue<pair<int, pair<int, int>>> &cola, int K, vector<int> &v) {

	pair<int, pair<int, int>> aux;
	int i = 0;

	while (!cola.empty() && i < K) {
		aux = cola.top();
		v.push_back(aux.second.first);
		cola.pop();
		aux.first += aux.second.second;
		cola.push(aux);

		i++;
	}
}

bool resuelveCaso() {
	int N, K, usuario, periodicidad;
	PriorityQueue<pair<int, pair<int, int>>> cola;
	vector<int> v;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> usuario >> periodicidad;
		cola.push({ periodicidad, { usuario, periodicidad } });
	}

	cin >> K;

	KprimerosEnvios(cola, K, v);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	cout << "----\n";

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