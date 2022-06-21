#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string materia;
	int horas, minutos;
	while (cin >> materia){
		cin >> horas >> minutos;
		if ((horas < 10) || (horas == 10 && minutos == 0))
			cout << "Abel deve cursar " << materia << "\n";
		else
			cout << "Abel deve cancelar " << materia << "\n";
	}
}
