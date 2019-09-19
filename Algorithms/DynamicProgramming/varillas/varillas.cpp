//Beatriz Herguedas Pinedo

#include <algorithm>
#include <assert.h>
#include <climits>
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

using namespace std;

struct tvarilla {
	int longitud, coste;
};

struct sol {
	int numformas, minvarillas, mincoste;
};

bool resuelveCaso() {
	int	N, L;
	tvarilla t;
	vector<tvarilla> v;

	cin >> N >> L;

	if (!std::cin)
		return false;

	vector<sol> s(L + 1);

	for (int i = 0; i < N; i++) {
		cin >> t.longitud >> t.coste;
		v.push_back(t);
	}

	s[0] = { 1, 0, 0 };

	for (int j = 1; j < L + 1; j++) {
		if(j == v[0].longitud)
			s[j] = { 1, 1, v[0].coste };
		else
			s[j] = { 0, 0, 0 };
	}

	for (int i = 2; i < N + 1; i++) {
		for (int j = L; j >= 0; j--) {
			if (j >= v[i - 1].longitud) {
				if (s[j].numformas > 0 && s[j - v[i - 1].longitud].numformas > 0) {
					s[j].numformas = s[j].numformas + s[j - v[i - 1].longitud].numformas;
					s[j].minvarillas = min(s[j].minvarillas, s[j - v[i - 1].longitud].minvarillas + 1);
					s[j].mincoste = min(s[j].mincoste, s[j - v[i - 1].longitud].mincoste + v[i - 1].coste);
				}

				else if (s[j - v[i - 1].longitud].numformas > 0) {
					s[j].numformas = s[j - v[i - 1].longitud].numformas;
					s[j].minvarillas = s[j - v[i - 1].longitud].minvarillas + 1;
					s[j].mincoste = s[j - v[i - 1].longitud].mincoste + v[i - 1].coste;
				}
			}
		}
	}

	if (s[L].numformas > 0)
		cout << "SI " << s[L].numformas << ' ' << s[L].minvarillas << ' ' << s[L].mincoste << '\n';

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