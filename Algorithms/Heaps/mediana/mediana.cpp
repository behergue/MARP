//Beatriz Herguedas Pinedo

#include "PriorityQueue.h"

using namespace std;

int mediana(PriorityQueue<int, greater<int>> const &cola1, PriorityQueue<int> const &cola2) {

	int sol;

	if (cola1.size() == cola2.size()) {
		sol = cola1.top() + cola2.top();
	}

	else {
		sol = 2 * cola1.top();
	}

	return sol;
}

bool resuelveCaso() {
	int N, valor;
	vector<int> v;
	PriorityQueue<int> cola2;
	PriorityQueue<int, greater<int>> cola1;

	cin >> N;

	if (N == 0)
		return false;

	cin >> valor;
	cola1.push(valor);
	v.push_back(mediana(cola1, cola2));

	if (N > 1) {
		cin >> valor;

		if (valor < cola1.top()) {
			cola2.push(cola1.top());
			cola1.pop();
			cola1.push(valor);
		}

		else {
			cola2.push(valor);
		}

		v.push_back(mediana(cola1, cola2));

		for (int i = 2; i < N; i++) {
			cin >> valor;

			if (valor > cola2.top()) {
				cola2.push(valor);

				if (cola2.size() > cola1.size()) {
					cola1.push(cola2.top());
					cola2.pop();
				}
			}

			else {
				cola1.push(valor);

				if (cola1.size() - cola2.size() > 1) {
					cola2.push(cola1.top());
					cola1.pop();
				}
			}

			v.push_back(mediana(cola1, cola2));
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];

		if (i < v.size() - 1)
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