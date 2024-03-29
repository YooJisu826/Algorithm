#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n, m;
string board[102];
int dist[102][102];
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 시작점 임력 받기
void bfs(int x, int y) {
	Q.push({ x, y });
	dist[x][y] = 0;

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
			Q.push({ nx, ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	// 행렬 입력 받기
	// 방문하지 않은 노드는 dist가 -1이다.
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = -1;
		}
	}

	bfs(0, 0);

	cout << dist[n - 1][m - 1] + 1;
	
	return 0;
}