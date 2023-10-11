#include <iostream>
#include <string>
using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	
	getline(cin, str);
	
	int count = 0;
	bool semaphore = false;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			semaphore = true;
		}
		else if(str[i] == ' '){
			if (semaphore == true) {
				semaphore = false;
				count++;
			}
		}
	}
	if (semaphore == true) {
		count++;
	}
	
	cout << count << "\n";

	return 0;
}