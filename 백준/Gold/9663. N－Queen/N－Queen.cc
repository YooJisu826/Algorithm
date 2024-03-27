#include <iostream>
using namespace std;

int n;
int cnt = 0; // 배치한 퀸의 개수
int arr[15][15];
bool isUsed1[15], isUsed2[30], isUsed3[30];

void init() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			arr[i][i] = 0;
		}
	}
	for (int i = 0; i < 15; i++) {
		isUsed1[i] = false;
	}
	for (int i = 0; i < 30; i++) {
		isUsed2[i] = false;
		isUsed3[i] = false;
	}
}

void checkIsUsed(int cur, int x, bool flag) {
	isUsed1[x] = flag;
	isUsed2[cur + x] = flag;
	isUsed3[x - cur + n - 1] = flag;
}

// cur번째 행에 퀸을 배치할 예정
void func(int cur) {
	// base condition
	if (cur == n) { // 끝까지 내려왔다면 성공
		cnt++;
		return;
	}

	// (cur, x) 
	for (int x = 0; x < n; x++) {
		if (!isUsed1[x] && !isUsed2[cur + x] && !isUsed3[x - cur + n - 1]) {
			checkIsUsed(cur, x, true);
			func(cur + 1);
			checkIsUsed(cur, x, false);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n; // NxN의 체스판, N개의 퀸
	init();
	func(0);
	cout << cnt << "\n";
}
