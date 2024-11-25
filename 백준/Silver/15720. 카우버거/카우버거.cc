#include <bits/stdc++.h>
using namespace std;

int burger[1005];
int sides[1005];
int drink[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int b, c, d;
	cin >> b >> c >> d;

	int beforeDiscount = 0;
	int afterDiscount = 0;

	for (int i = 0; i < b; i++) {
		cin >> burger[i]; 
		beforeDiscount += burger[i];
	}
	sort(burger, burger + b, greater<int>());
	for (int i = 0; i < c; i++) {
		cin >> sides[i];
		beforeDiscount += sides[i];
	}
	sort(sides, sides + c, greater<int>());
	for (int i = 0; i < d; i++) {
		cin >> drink[i];
		beforeDiscount += drink[i];
	}
	sort(drink, drink + d, greater<int>());

	for (int i = 0; i < min({ b, c, d }); i++)
		afterDiscount += burger[i] + sides[i] + drink[i];

	afterDiscount *= 0.9;

	for (int i = min({ b, c, d }); i < max({ b, c, d }); i++)
		afterDiscount += burger[i] + sides[i] + drink[i];

	cout << beforeDiscount << '\n' << afterDiscount << '\n';
	return 0;
}