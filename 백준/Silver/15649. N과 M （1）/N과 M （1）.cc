#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool isUsed[9];

// k는 arr의 index를 나타냄 (k번째 자리)
void func(int k) {
	// base condition
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		// i가 사용되지 않은 숫자라면
		if (!isUsed[i]) {
			arr[k] = i; // k번째에 대입
			isUsed[i] = true;
			func(k + 1);
			isUsed[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < 9; i++) {
		isUsed[i] = false;
		arr[i] = 0;
	}
	func(0);
}
