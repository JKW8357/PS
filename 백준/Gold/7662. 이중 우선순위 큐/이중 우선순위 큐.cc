#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int k;
		cin >> k;
		multiset<int> ms;

		while (k--) {
			char cmd1;
			cin >> cmd1;
			if (cmd1 == 'D') {
				int cmd2;
				cin >> cmd2;
				if (ms.empty()) continue;
				if (cmd2 == 1) ms.erase(prev(ms.end()));
				else ms.erase(ms.begin());
			}

			else {
				int num;
				cin >> num;
				ms.insert(num);
			}
		}

		if (ms.empty()) cout << "EMPTY" << '\n';
		else cout << *prev(ms.end()) << ' ' << * ms.begin() << '\n';
	}

	return 0;
}

/*
이진 검색 트리 set을 사용하면 삽입, 삭제, 탐색 모두 O(logN)에 처리 가능
중복되는 원소까지 고려해야 하는 경우 set이 아닌 multiset을 사용해야 함에 유의
또한 ms.erase(ms.begin());으로 코드를 작성한다면 최솟값이 여러 개일 때 그 중 1개만 삭제하지만
ms.erase(*ms.begin());과 같이 작성한다면 최솟값이 여러 개일 때 모든 최솟값을 삭제하게 되므로 유의해야 함

또한 임의 접근 가능 stl(array, vector, deque 등)은 반복자 간의 산술 연산이 가능하지만(it + n, it - n 등)
그 외의 stl(list, forward_list, stack, queue, priority_queue, unordered_(multi)set/map, (multi)set/map 등)은
<iterator> 헤더의 advance, prev, next 등 반복자 조작 함수들을 이용해 반복자를 조작해야 함
*/
