//Beatriz Herguedas Pinedo

#include "PriorityQueue.h"

using namespace std;

bool resuelveCaso() {
	int N, gravedad;
	char evento;
	string nombre;
	vector<string> v;
	PriorityQueue<pair<int, pair<int, string>>, greater<pair<int, pair<int, string>>>> cola;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> evento;

		if (evento == 'I') {
			cin >> nombre >> gravedad;
			cola.push({ gravedad, {N - i, nombre} });
		}

		else if (evento == 'A') {
			v.push_back(cola.top().second.second);
			cola.pop();
		}
	}

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