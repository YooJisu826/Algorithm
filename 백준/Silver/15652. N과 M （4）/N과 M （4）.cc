#include <iostream>
#include <deque>
using namespace std;

// 1부터 n까지 자연 수 중 길이가 m인 수열
int n, m;
int arr[10];
bool isUsed[10]; // 중복 방지

// k번째 수를 결정
void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		//if (!isUsed[i]) {
			if (k > 0 && i < arr[k - 1])
				continue;

			arr[k] = i;
			//isUsed[i] = true;
			// 다음 자리 숫자 찾으러 고고
			func(k + 1);
			// 다시 돌아오기
			//isUsed[i] = false;
			
		//}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	func(0);
}