#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int cnt = 0;

	vector<bool> vec(N + 1, true);

	for (int i = 2; i <= N; i++) {
		if (vec[i]) {
			for (int j = i; j <= N; j += i) {
				if (vec[j]) {
					vec[j] = false;
					cnt++;
				}
				if (cnt == K) {
					cout << j;
					return 0;
				}
			}
		}
	}
}
