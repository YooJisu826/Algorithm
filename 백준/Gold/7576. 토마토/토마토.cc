#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n, m;
int box[1001][1001];
int dist[1001][1001];
queue<pair<int, int>> Q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs() {
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (dist[nx][ny] >= 0 || box[nx][ny] != 0) continue;
			Q.push({ nx, ny });
			box[nx][ny] = 1;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	int result = 0;
	int tomatoCount = 0;

	// 1은 익은 토마토, 0은 익지 않은 토마토, -1은 토마토 없음
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			// 안익었으면 dist -1로 초기화
			if (box[i][j] == 0) {
				tomatoCount++;
				dist[i][j] = -1;
			} // 익었으면 큐에 넣고 dist 0으로 초기화
			else if (box[i][j] == 1) {
				Q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}

	// 모든 토마토가 익어있었다면 0 출력하고 끝
	if (tomatoCount == 0) {
		cout << 0; return 0;
	}

	bfs();

	// 안 익은 토마토가 있다면 -1로 초기화
	// 가장 먼 거리 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				cout << -1; return 0;
			}
			else {
				result = max(result, dist[i][j]);
			}
		}
	}

	cout << result;
	
	return 0;
}