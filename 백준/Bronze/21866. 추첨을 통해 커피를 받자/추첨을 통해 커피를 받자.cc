#include <bits/stdc++.h>
using namespace std;

int score[9];
int maxScore[9] = { 100,100,200,200,300,300,400,400,500 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;
	bool hacked = false;
	for (int i = 0; i < 9; i++) {
		cin >> score[i];

		if (score[i] > maxScore[i]) {
			hacked = true;
			break;
		}
		
		sum += score[i];
	}

	if (hacked) cout << "hacker\n";
	else if (sum >= 100) cout << "draw\n";
	else cout << "none\n";

	return 0;
}