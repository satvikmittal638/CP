#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        int dirn=1,curTurn=1;
        for(char c:s){
            if(c=='U'){
                curTurn+=dirn;
            }
            else if(c=='S'){
                curTurn+=dirn*2;
            }
            else if(c=='R'){
                dirn*=-1;
                curTurn+=dirn;
            }
            curTurn%=n; // 1,2...n-1,0 (0 is same as n)
            curTurn=(curTurn+n)%n; // handle -ve cases
        }
        cout<<(curTurn==0?n:curTurn)<<"\n";
    }
    return 0;
}