#include <iostream>
using namespace std;

int diff(int a, int b)
{
	return a - b;
}
int solve(int input)
{
	int num1 = 0, num10 = 0, num100 = 0, num1000 = 0;
	int cnt = 0;

	for (int i = 1; i <= input; ++i)
	{
		if (i < 100) { //둘째 자리 까지는 
			cnt++;
			continue;
		}
		num1000 = (i / 1000) % 10;
		num100 = (i / 100) % 10;
		num10 = (i / 10) % 10;
		num1 = (i / 1) % 10;

		if (num1000 != 0
			&& diff(num1000, num100) == diff(num100, num10)
			&& diff(num100, num10) == diff(num10, num1)) //넷째자리 일때
		{
			cnt++;
		}
		else if (num100 != 0
			&& diff(num100, num10) == diff(num10, num1)) //셋째자리 일때
		{
			cnt++;
		}
	}
	return cnt;
}
int main() {
	int k = 0;//

	cin >> k;
	cout << solve(k);
	
	return 0;
}