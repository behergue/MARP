//Beatriz Herguedas Pinedo

#include "PriorityQueue.h"

using namespace std;

long long int esfuerzoMinimo(PriorityQueue<long long int> &cola) {
	
	long long int x, y;
	long long int z = 0;

	while (cola.size() > 1) {

		x = cola.top();
		cola.pop();

		y = cola.top();
		cola.pop();
		
		z += x + y;

		if (!cola.empty()) {
			cola.push(x + y); 
		}
	}

	return z;
}

bool resuelveCaso() {
	int N;
	long long int valor;
	PriorityQueue<long long int> cola;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		cola.push(valor);
	}

	cout << esfuerzoMinimo(cola) << '\n';

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