#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N{ 0 }, K{ 0 }, numerator{ 0 }, denominator{ 0 };
    cin >> N >> K;
    numerator = denominator = N;

    for (int i = 0; i < K; ++i) {
        numerator *= (N - i);
        denominator *= (i + 1);
    }

    cout << numerator / denominator;

    return 0;
}