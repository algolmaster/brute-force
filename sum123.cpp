#include <iostream>
#include <queue>
using namespace std;

int t;
int n;

int getResult() {
    int count = 0;

    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for (int i = 1; i <= 3; i++) {
            int temp = front + i;

            if (temp == n) count++;
            else if (temp < n) {
                q.push(temp);
            }
        }
    }

    return count;
}

int main() {
    cin >> t;

    int *results = new int[t];

    for (int i = 0; i < t; i++) {
        cin >> n;
        results[i] = getResult();
    }

    for (int i = 0; i < t; i++) cout << results[i] << endl;
}
