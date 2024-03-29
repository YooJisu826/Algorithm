#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n, m;
int board[500][500];
int vis[500][500];
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// bfs는 Q에 삽입할 때 방문 표시를 해야한다.
void visit(int x, int y) {
	Q.push({ x, y });
	vis[x][y] = 1;
}

// 시작점 임력 받기
int dfs(int x, int y) {
	int area = 1;
	visit(x, y);

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
			visit(nx, ny);
			area++;
		}
	}
	return area;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int count = 0;
	int result = 0;

	// 행렬 입력 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 방문하지 않은, 칠해진 칸을 만나면 bfs 시작
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == 0 && board[i][j] == 1) {
				result = max(dfs(i, j), result);
				count++;
			}
		}
	}

	cout << count << "\n" << result;
}