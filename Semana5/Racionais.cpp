#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B, C;

int main() {
	cin >> A >> B >> C;

	ll termo = B*B - 4 * A * C;

	ll i = sqrt (termo);

	if (i*i == termo)
		cout << "Y" << endl;
	else
		cout << "N" << endl;
}