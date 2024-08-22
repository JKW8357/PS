#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int l;
	cin >> l;
	string Eevee[3] = { "Vaporeon", "Jolteon", "Flareon" };
	cout << Eevee[(++l) % 3] << '\n';

	return 0;
}