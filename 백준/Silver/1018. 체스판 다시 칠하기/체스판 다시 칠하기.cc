#include <iostream>
#include <algorithm>
using namespace std;

string board[50];

string startW[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
};
string startB[8] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
};

int CheckBoard(int x, int y) {
	int countW = 0;
	int countB = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[x + i][y + j] != startW[i][j])
				countW++;
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[x + i][y + j] != startB[i][j])
				countB++;
		}
	}
	return min(countW, countB);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;

	int min = 99999999;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
			cin >> board[i];
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int temp = CheckBoard(i, j);
			if (min > temp) {
				min = temp;
			}
		}
	}

	cout << min << "\n";

	return 0;
}


