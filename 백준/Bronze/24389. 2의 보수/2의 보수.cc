#include <bits/stdc++.h>
using namespace std;

int popCount(int num) {
    int count = 0;
    while (num) {
        num &= (num - 1);
        count++;
    }
    return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cout << popCount(n ^ (~n + 1)) << '\n';

	return 0;
}
