#include <iostream>
using namespace std;

int cnt;

void solve(int n,int plus) {
	if (plus == 4) {
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (i + plus <= n) cnt++;
		else break;
	}
	solve(n, ++plus);
}
int main() {
	int k = 0;//test case수
	int *n; //입력숫자 배열
	cin >> k;

	n = new int[k];
	for (int i = 0; i < k; i++)
		cin >> n[i];
	
	for (int i = 0; i < k; i++) {
		cnt = 1;
		solve(n[i],1);
		cout << cnt<<endl;
	}
		
	return 0;
}