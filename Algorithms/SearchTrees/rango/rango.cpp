//MARP10, Beatriz Herguedas Pinedo

#include "TreeMap_AVL.h"

using namespace std;

bool resuelveCaso() {
	int N, k1, k2, valor;
	vector<int> claves;
	map<int, int> AVL;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> valor;
		AVL.insert({ valor, 1 });
	}

	cin >> k1 >> k2;

	vector<int> aux = AVL.intervalo(k1, k2);

	for (int i = 0; i < aux.size(); i++) {
		cout << aux[i];

		if (i < aux.size() - 1)
			cout << " ";
	}

	cout << '\n';

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