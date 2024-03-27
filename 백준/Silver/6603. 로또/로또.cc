#include <iostream>
using namespace std;

int k;			 // 주어진 정수의 개수, 7~12
int arr[13];	 // 집합
int lotto[13];	 // 로또 번호
int isUsed[13];  // 집합이 사용됐는지

void checkIsUsed(int a) {
	for (int i = 0; i < a; i++) {
		if (isUsed[i] == 0) {
			isUsed[i] = 2; // 임시 사용
		}
	}
	isUsed[a] = 1;
}

void returnIsUsed(int a) {
	for (int i = 0; i < a; i++) {
		if (isUsed[i] == 2) {
			isUsed[i] = 0; // 임시 사용
		}
	}
	isUsed[a] = 0;
}

// cur는 현재 index를 의미
void func(int cur) {
	// base condition
	if (cur == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < k; i++) {
		int temp;
		if (cur == 0) temp = 0;
		else temp = cur - 1;
		if (isUsed[i] == 0) {
			lotto[cur] = arr[i];
			checkIsUsed(i);
			func(cur + 1);
			returnIsUsed(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		func(0);
		cout << "\n";
	}

	return 0;
}
