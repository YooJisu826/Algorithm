#include <iostream>
using namespace std;

int n; // 정수의 개수
int s; // 정수들의 합
int cnt; // 합이 S가 되는 부분 수열의 개수
int arr[21]; // 정수들

// cur는 현재 index를 의미
void func(int cur, int total) {
	// base condition
	if (cur == n) {
		if (s == total) cnt++;
		return;
	}

	// 더하지 않은 경우
	func(cur + 1, total);
	// 더했을 경우
	func(cur + 1, total+arr[cur]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	func(0, 0);
	// s가 0일 때는 공집합도 포함되므로 공집합 제외
	if (s == 0) cnt--; 
	cout << cnt << "\n";
}
