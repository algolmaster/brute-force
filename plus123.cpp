//
//  plus123.cpp
//  brute-force
//
//  Created by 신예지 on 09/04/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int factorial(int n){
    return (n==1||n==0)? 1:n*factorial(n-1);
}

int calculate(vector<int> line) {
    int way = 0;
    
    int numOf1 = 0;
    int numOf2 = 0;
    int numOf3 = 0;
    
    for(int i=0; i<line.size(); i++){
        if(line[i]==1) numOf1++;
        else if(line[i]==2) numOf2++;
        else if(line[i]==3) numOf3++;
    }
    
    //한 종류의 숫자로만 이루어진 경우
    if(numOf1==line.size() || numOf2==line.size() || numOf3==line.size()) way++;
    
    else way = factorial(line.size())/(factorial(numOf1)*factorial(numOf2)*factorial(numOf3));
    return way;
}

int main() {
    int N;  //# of testcase
    cin >> N;
    int* n = new int[N];
    for(int i=0; i<N; i++) cin>>n[i];
    
    for(int j=0; j<N; j++){
        int max2 = n[j]/2;
        int numOfWay = 0;
        
        vector<vector<int>> way;
        vector<int> temp;
        for(int i=0; i<n[j]; i++) {
            temp.push_back(1);
        }
        way.push_back(temp);
        
        for(int i=0; i<max2; i++) {
            temp.erase(temp.begin());
            temp.erase(temp.begin());
            temp.push_back(2);
            way.push_back(temp);
        }
        int tempSize = way.size();
        for(int i=0; i<tempSize; i++) {
            temp = way[i];
            if(temp[2]==1){
                temp.erase(temp.begin());
                temp.erase(temp.begin());
                temp.erase(temp.begin());
                temp.push_back(3);
                way.push_back(temp);
            }
        }
        for(int i=tempSize; i<way.size(); i++) {
            temp = way[i];
            if(temp[2]==1) {
                temp.erase(temp.begin());
                temp.erase(temp.begin());
                temp.erase(temp.begin());
                temp.push_back(3);
                way.push_back(temp);
            }
        }
        
        for(int i=0; i<way.size(); i++) {
            numOfWay += calculate(way[i]);
        }
        cout << numOfWay << endl;
    }
}
