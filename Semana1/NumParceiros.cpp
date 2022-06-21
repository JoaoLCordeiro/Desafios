#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int linhas;
    cin >> linhas;

    while (linhas--){
        string s1,s2;
        cin >> s1 >> s2;
		int n1 = s1[s1.size()-1] - 48;
		int n2 = s2[s2.size()-1] - 48;
        if (((n1+n2) % 2) == 0)
            cout << "PARCEIROS\n";
        else
            cout << "NAO PARCEIROS\n";
    }
}
