#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int KetvircioNustatymas(int x, int y) {
	if (x > 0 && y > 0) return 1;
	else if (x < 0 && y > 0) return 2;
	else if (x < 0 && y < 0) return 3;
	else if (x > 0 && y < 0) return 4;
}

int ArKertaAsi(int x1, int y1, int x2, int y2) {
	if ((x1 < 0 && x2 > 0) || (x1 > 0 && x2 < 0)) cout << "Kerta x aðá" << endl;
	if ((y1 < 0 && y2 > 0) || (y1 > 0 && y2 < 0)) cout << "Kerta y aðá" << endl;
}

int TrikampioPlotas(int x1, int y1, int x2, int y2, int x3, int y3) {
	return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

bool ArStaciakampis(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	return (y1 == y2 && y3 == y4 && y1 != y3 && y2 != y4);
}

bool ArKvadratas(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	double d1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	double d2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	double d3 = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
	double d4 = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));

	return (d1 == d2 && d2 == d3 && d3 == d4);
}

void FailoNuskaitymas() {
	int x1, y1, x2, y2, x3, y3, x4, y4, a;
	a = 0;
	ifstream fin("duomenys.txt");


	while (!fin.eof()) {
		int n;
		fin >> n;
		switch (n)
		{
		case 1:
			int x1, y1;
			fin >> x1 >> y1;
			cout << "Taðkas yra " << KetvircioNustatymas(x1, y1) << " ketvirtyje" << endl;
			break;
		case 2:
			fin >> x1 >> x2 >> y1 >> y2;
			ArKertaAsi(x1, y1, x2, y2);
			break;
		case 3:
			fin >> x1 >> x2 >> y1 >> y2 >> x3 >> y3;
			cout << "Trikampio plotas yra " << TrikampioPlotas(x1, y1, x2, y2, x3, y3) << endl;
			break;
		case 4:
			fin >> x1 >> x2 >> y1 >> y2 >> x3 >> y3 >> x4 >> y4;
			if (ArStaciakampis(x1, y1, x2, y2, x3, y3, x4, y4)) {
				cout << "Trikampis yra staèiakampis" << endl;
				if (ArKvadratas(x1, y1, x2, y2, x3, y3, x4, y4)) a++;
			}
			else {
				cout << "Trikampis nëra staèiakampis" << endl;
			}
			break;
		}
		cout << a << " staèiakampiø yra kvadratai.";
	}
}


int main() {
	setlocale(LC_ALL, "lithuanian");
	FailoNuskaitymas();
}