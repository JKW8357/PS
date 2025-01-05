#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> p;

/*
Path Compression을 통해 Find 연산 최적화
루트 노드로 이동하며 거쳐간 노드들(x)의 부모 노드(p[x])를 모두 루트 노드(find(p[x])로 변경
곧바로 루트 노드를 반환하도록 최적화
*/

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]); // 루트 노드 find(p[x])를 x에 대입 후 반환
}

/*
Union by Rank를 통해 Union 연산 최적화
두 노드가 속한 트리들의 높이(rank)를 비교 후
높이가 더 낮은 트리의 루트를 높이가 더 높은 트리의 루트의 자식 노드로 연결해 트리의 깊이 최소화
(p[root] = -N: 루트 노드가 x인 트리의 높이(rank) = N)
*/

void unionSets(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (p[x] < p[y]) swap(x, y); // x의 rank가 더 큰 경우 x, y swap (rank(x) ≥ rank(y))
	if (p[x] == p[y]) p[y]--; // rank가 같을 경우 아무거나 선택해 나머지 노드의 자식 노드로 연결
	p[y] = x;
}

/*
Path Compression + Union by Rank 최적화를 거치면 상수 시간복잡도 O(α(N))에 연산 가능
(α(N): 역아커만 함수. N ≤ 2^2^2^65536-3일 때 α(n) ≤ 4이므로 사실상 상수 시간 내에 동작)
Path Compression 최적화만 수행해도 충분히 빠른 시간 내에 동작
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	p.resize(n + 1);
	fill(p.begin(), p.end(), -1);

	while (m--) {
		int q, a, b;
		cin >> q >> a >> b;
		if (q) cout << (find(a) == find(b) ? "YES" : "NO") << '\n';
		else unionSets(a, b);
	}

	return 0;
}