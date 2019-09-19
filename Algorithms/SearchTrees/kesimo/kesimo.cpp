//Beatriz Herguedas Pinedo

#include "TreeMap_AVL.h"

using namespace std;

bool resuelveCaso() {
	int N, M, valor, k;
	map<int, int> claves;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		claves.insert({ valor, 1 });
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> k;

		if (k < 1 || k > claves.size()) {
			cout << "??";
		}
		else{
			cout << claves.kpeque(k);
		}
		

		cout << '\n';
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
