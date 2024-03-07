#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int counts = 0; // 연결 요소의 개수
vector<int> g[1001];
bool check[1001];

void dfs(int start) {
	check[start] = true;
	for (int i = 0; i < g[start].size(); i++){
		int next = g[start][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	fill(check, check + 1001, false);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
        // 방문하지 않은 노드를 처음 방문할 때
		if (check[i] == false) {
			dfs(i);
            // 연결 요소의 개수 추가
			counts++;
		}
	}
	cout << counts << '\n';

	return 0;
}
