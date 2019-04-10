#include <iostream>
using namespace std;
int *A;
int *B;
int *C;
int *D;

int cnt = 0;
int n;
int solve(int i1,int i2, int i3, int i4) {
	if (A[i1] + B[i2] + C[i3] + D[i4] == 0) cnt++;
	cout << i1 << i2 << i3 << i4 << endl;
	if (i4 < n) solve(i1, i2, i3, ++i4);

	int i4_1 = i4 - n;
	if (i3 < n) solve(i1, i2, ++i3, i4_1++);

	int i3_1 = i3 - n-1;
	int i4_1 = i4 - n-1;
	if (i2 < n) solve(i1, ++i2, ++i3_1, ++i4_1);
	cout << "asdf" << endl;
	return 0;
}
int main() {
	cin >> n;

	A = new int[n];
	B = new int[n];
	C = new int[n];
	D = new int[n];

	for (int i = 0; i < 4 * n; i++) {
		if (i%4 == 0)
			cin >> A[i];
		else if (i%4 == 1)
			cin >> B[i];
		if (i%4 == 2)
			cin >> C[i];
		if (i%4 == 3)
			cin >> D[i];
	}
	for (int i = 0; i < n; i++) {
		solve(i, 0, 0, 0);
	}
	cout << cnt;
	return 0;
}