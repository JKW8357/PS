#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned int N{ 0 };
	cin >> N;

	while (N != 1) {
		for (int i = 2; i <= N;) {
			if (N % i == 0) {
				cout << i <<'\n';
				N /= i;
			}
			else {
				++i;
			}
		}
	}

	return 0;
}