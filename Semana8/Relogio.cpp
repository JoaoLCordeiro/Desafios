#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll h, m, s;
	cin >> h >> m >> s;

	ll cont = 0;
	for (int i = 0 ; i < h ; i++){
		if (((i*m) % h) == 0)//se o ponteiro dos minutos parar em cima do ponteiro de horas
			if (((i*s) % h) == 0)//se o ponteiro dos segundos parar em cima do ponteiro de horas
				cont++;
	}

	cout << cont << endl;
	for (int i = 0 ; i < h ; i++){
		if (((i*m) % h) == 0)//se o ponteiro dos minutos parar em cima do ponteiro de horas
			if (((i*s) % h) == 0)//se o ponteiro dos segundos parar em cima do ponteiro de horas
				cout << i << " " << i*m/h << " " << i*s/h << endl; 
	}
}