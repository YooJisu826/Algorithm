#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int counts = 0;

void dfs(int start, vector<int> g[], bool check[]) {
	check[start] = true;
	//cout << start << " ";
	counts++;

	for (int i = 0; i < g[start].size(); i++) {
		int next = g[start][i];
		if (check[next] == false) {
			dfs(next, g, check);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int>* g = new vector<int>[n + 1];
	bool* check = new bool[n + 1];

	fill(check, check + n + 1, false);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, g, check);
	cout << counts - 1 << '\n';

	return 0;
}

// 1번 컴퓨터와 연결되어 있는 정점의 개수를 구하면 됨 DFS!