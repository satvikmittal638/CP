#include<bits/stdc++.h>
using namespace std;
int main()
{
    const int long long MOD=1000000007;
    long long n;cin>>n;
    /*
    zD-> number of ways to reach D after a certain number of steps
    zABC-> number of ways to reach D after a certain number of steps

    nzD-> next value of zD
    nzABC->next value of zABC
    */
    long long zD,zABC,nzD,nzABC;
    // for 0 steps, we have a base case
    zD=1;// initially at D, hence 1 way to reach D
    zABC=0;// not at any of A/B/C 
    for(int i=0;i<n;i++){
// to reach A/B/C start at D or start from either of the other 2 vertices
        nzABC=(zD+zABC*2)%MOD; 
// to reach D, start at any of A/B/C
        nzD=(zABC*3)%MOD;
        // store the next step values in current to compute the next values
        zD=nzD;
        zABC=nzABC;
    }
    cout<<zD;
    return 0;
}