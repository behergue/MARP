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

#ifndef horas_h
#define horas_h

class hora {

private:
	int horas, minutos;

public:

	hora() {};

	hora(int m) {
		horas = m / 60;
		minutos = m % 60;
	}

	hora(int h, int m) {

		if (h < 0 || h > 23) {
			throw domain_error("ERROR");
		}
		else {
			this->horas = h;
		}

		if (m < 0 || m > 59) {
			throw domain_error("ERROR");
		}
		else {
			this->minutos = m;
		}
	}

	int getHoras() {
		return horas;
	}

	int getMinutos() {
		return minutos;
	}

	bool operator<(hora const & h) const{

		if (this->horas < h.horas) {
			return true;
		}

		else if (this->horas == h.horas && this->minutos < h.minutos) {
			return true;
		}

		else {
			return false;
		}
	}

	bool operator==(hora const & h) {
		return this->horas == h.horas && this->minutos == h.minutos;
	}

	hora operator+(hora const & h) {

		hora suma;

		int min = this->minutos + h.minutos;
		suma.minutos = min % 60;

		int hor = this->horas + h.horas + min / 60;

		suma.horas = hor;

		return suma;
	}
};

inline istream &operator>>(istream & in, hora &h) {
	int hh, mm;
	char aux;

	in >> hh >> aux >> mm;

	h = hora(hh, mm);

	return in;
}

inline ostream &operator<<(ostream & out, hora h) {

	out << setfill('0') << setw(2) << h.getHoras() << ":" << setfill('0') << setw(2)
		<< h.getMinutos();

	return out;
}
#endif