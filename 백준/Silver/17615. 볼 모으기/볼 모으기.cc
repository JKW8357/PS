#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; string balls;
    cin >> n >> balls;

    int rb = 0, bb = 0;
    for (char ball : balls) {
        if (ball == 'R') rb++;
        else bb++;
    }

    int c1 = rb - (int)balls.find_first_not_of('R');
    int c2 = rb - (int)(n - balls.find_last_not_of('R') - 1);
    int c3 = bb - (int)balls.find_first_not_of('B');
    int c4 = bb - (int)(n - balls.find_last_not_of('B') - 1);

    cout << min({ c1, c2, c3, c4 }) << '\n';    
    return 0;
}