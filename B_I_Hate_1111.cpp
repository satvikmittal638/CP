#include<bits/stdc++.h>
using namespace std;

int lenNum(int n){
    int cnt = 0;
    while(n){
        n /= 10;
        cnt++;
    }
    return cnt;
}

int main() {
    int tt; 
    cin >> tt;
    while(tt--) {
        int x; 
        cin >> x;
        /*
        1111=11⋅100+11
        11111=111⋅100+11
        this means that we can construct 1111,11111.. and all bigger
        numbers by just using 11 and 111
        therfore the number will be of the form
        X=A.11+B.111
        */
    }
    return 0;
}