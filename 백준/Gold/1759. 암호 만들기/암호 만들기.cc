#include <iostream>
#include <algorithm>
using namespace std;

int n, m;		  // n개 중 m개 선택
char arr[16];	  // 가능성 있는 알파벳
char result[16];  // 출력할 결과
bool isVowel[16]; // 모음 위치 기록
int isUsed[16];   // 집합이 사용됐는지
char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };

// 완성된 집합이 조건에 맞는지 확인
bool checkOption() {
	int vowelCount = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 5; j++) {
			if (result[i] == vowel[j])
				vowelCount++;
		}
	}
	if (vowelCount == 0) return false;
	if (m - vowelCount < 2) return false;
	return true;
}

void checkIsVowel() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i] == vowel[j]) {
				isVowel[i] = true;  
				break;
			}
		}
	}
}

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
	if (cur == m && checkOption()) {
		for (int i = 0; i < m; i++) {
			cout << result[i];
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isUsed[i] == 0) {
			result[cur] = arr[i];
			checkIsUsed(i);
			func(cur + 1);
			returnIsUsed(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// 알파벳 순 정렬
	sort(arr, arr + n);
	// 모음 위치 확인
	checkIsVowel();
	// 백트래킹 시작
	func(0);

	return 0;
}
