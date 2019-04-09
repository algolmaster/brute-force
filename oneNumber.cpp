//
//  oneNumber.cpp
//  brute-force
//
//  Created by 신예지 on 09/04/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int numOfHan = 0;
    
    if(n<100) numOfHan=n;
    else {
        if(n==1000) n-=1;
        
        numOfHan += 99;
        
        int num;
        for(int i=1; i<=n/100; i++) {
            //오름차순 등차
            for(int j=0; j<=(9-i)/2; j++) {
                num = 100*i + 10*(i+j) + 1*(i+2*j);
                if(num<=n) numOfHan++;
            }
            //내림차순 등차
            for(int j=1; j<=(i-0)/2; j++) {
                num = 100*i + 10*(i-j) + 1*(i-2*j);
                if(num<=n) numOfHan++;
            }
        }
    }
    cout << numOfHan;
}
