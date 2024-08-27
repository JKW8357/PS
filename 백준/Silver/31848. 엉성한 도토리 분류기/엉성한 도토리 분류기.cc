#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

vector<p> holes;
int acorns[100005];
int min_holes[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		holes.push_back({ num + i, i + 1 }); // { 해당 구멍에서 도토리가 떨어질 수 있는 최소 크기, 번호 }
	}
	sort(holes.begin(), holes.end()); // 이분 탐색을 위한 정렬

	min_holes[n - 1] = holes[n - 1].second;
	for (int i = n - 2; i >= 0; i--)
		min_holes[i] = min(holes[i].second, min_holes[i + 1]);
    // 최소 구멍 번호를 미리 저장
    
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> acorns[i];
		auto it = lower_bound(holes.begin(), holes.end(), acorns[i], [](p a, int b) { return a.first < b; }); // 명시적인 비교함수를 통해 이분 탐색 수행
		int idx = it - holes.begin();
		cout << min_holes[idx] << ' '; // 최소 구멍 번호를 미리 저장함으로써 O(1)에 최솟값 출력 가능
	}
    
    // 시간복잡도: O(Q * logN)

	return 0;
}
