#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int input[4000][4];
int n;
queue<long long> q;

void getCases(int time) {
    int size = q.size();

    for (int i = 0; i < size; i++) {
        int front = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            q.push(front + input[i][time]);
        }
    }

    if (time == 0) return;
    else getCases(time - 1);
}

long long getResult() {
    long long count = 0;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        if (front == 0) count++;
    }

    return count;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) cin >> input[i][j];
    }

    q.push({});
    getCases(4 - 1);

    cout << getResult();
}
