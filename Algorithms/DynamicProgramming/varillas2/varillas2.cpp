//Beatriz Herguedas Pinedo

#include "Matriz.h"

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

	// filas = i = varillas consideradas
	// columnas = j = longitud que suman
	Matriz<sol> M(N + 1, L + 1);

	for (int i = 0; i < N; i++) {
		cin >> t.longitud >> t.coste;
		v.push_back(t);
	}

	for (int i = 0; i < N + 1; i++) {
		M[i][0] = { 1, 0, 0 };
	}

	for (int j = 1; j < L + 1; j++) {
		if (j == v[0].longitud)
			M[1][j] = { 1, 1, v[0].coste };
		else
			M[1][j] = { 0, 0, 0 };
	}

	for (int i = 2; i < N + 1; i++) {
		for (int j = 1; j < L + 1; j++) {
			if (j >= v[i - 1].longitud) {
				if (M[i - 1][j].numformas > 0 && M[i - 1][j - v[i - 1].longitud].numformas > 0) {
					M[i][j].numformas = M[i - 1][j].numformas + M[i - 1][j - v[i - 1].longitud].numformas;
					M[i][j].minvarillas = min(M[i - 1][j].minvarillas, M[i - 1][j - v[i - 1].longitud].minvarillas + 1);
					M[i][j].mincoste = min(M[i - 1][j].mincoste, M[i - 1][j - v[i - 1].longitud].mincoste + v[i - 1].coste);
				}

				else if (M[i - 1][j - v[i - 1].longitud].numformas > 0) {
					M[i][j].numformas = M[i - 1][j - v[i - 1].longitud].numformas;
					M[i][j].minvarillas = M[i - 1][j - v[i - 1].longitud].minvarillas + 1;
					M[i][j].mincoste = M[i - 1][j - v[i - 1].longitud].mincoste + v[i - 1].coste;
				}

				else {
					M[i][j].numformas = M[i - 1][j].numformas;
					M[i][j].minvarillas = M[i - 1][j].minvarillas;
					M[i][j].mincoste = M[i - 1][j].mincoste;
				}
			}
			else {
				M[i][j].numformas = M[i - 1][j].numformas;
				M[i][j].minvarillas = M[i - 1][j].minvarillas;
				M[i][j].mincoste = M[i - 1][j].mincoste;
			}
		}
	}

	if (M[N][L].numformas > 0)
		cout << "SI " << M[N][L].numformas << ' ' << M[N][L].minvarillas << ' ' << M[N][L].mincoste << '\n';

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