#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, h, c, l;

	while (cin >> n){
		cin >> h >> c >> l;

		double mult = c * c + h * h;
		mult = sqrt(mult);
		double area = mult * n * l;
		area = area/10000;
		cout << setprecision (4) << fixed << area << endl;
	}
}