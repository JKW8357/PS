#include <bits/stdc++.h>
using namespace std;

string toBinary(int num) {
	string bin;
	if (num == 0) return "0";
	int highestBit = 31;
	while (highestBit >= 0 && !(num & (1 << highestBit))) { highestBit--; }
	for (int i = highestBit; i >= 0; i--) bin += (num & (1 << i) ? "1" : "0");
	return bin;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	string game;
	for (int i = 0; i < 100; i++) game += toBinary(i);
	for (int i = 0; i < 5; i++) cout << game[k - 1 + (n * i)] << ' ';

	return 0;
}