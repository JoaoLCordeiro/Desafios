#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	int contAIndo = 0;
	int contAVindo = 0;
	int endIni = -1;
	int endFim = -1;

	for (int i=0 ; i<n ; i++){
		if (str[i] == 'A')
			contAIndo++;
		else
			contAIndo = 0;

		if (str[n-i-1] == 'A')
			contAVindo++;
		else
			contAVindo = 0;

		if ((contAIndo == 7) && (endIni < 0))
			endIni = i - 6;

		if ((contAVindo == 7) && (endFim < 0))
			endFim = n - i + 6;
	}

	cout << (endFim - endIni) << "\n";
}
