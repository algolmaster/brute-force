//
//  zeroSum.cpp
//  brute-force
//
//  Created by 신예지 on 09/04/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int n;  //1-4000
    cin >> n;
    
    //vector<pair<int, int>, pair<int, int>> zeroPair;
    vector<int> sumAB; //sum, index
    vector<int> sumCD;
    
    int zeroPair = 0;
    
    int* A = new int[n];
    int* B = new int[n];
    int* C = new int[n];
    int* D = new int[n];
    
    for(int i=0; i<n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    int idx = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            sumAB.push_back(A[i]+B[j]);
    }
    
    idx = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            sumCD.push_back(-(C[i]+D[j]));
        }
    }
    
    for(int i=0; i<n*n; i++) {
        if(find(sumCD.begin(), sumCD.end(), sumAB[i]) != sumCD.end()) {
            zeroPair++;
        }
    }
    cout << zeroPair;
}
