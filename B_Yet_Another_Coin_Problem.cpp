#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       /*
        Optimal solution has
        <=2 ones
        <=1 threes
        <=4 sixes
        <=2 tens       
       */
      int minCnt=INT_MAX;
       for(int ones=0;ones<=2;ones++){
        for(int threes=0;threes<=1;threes++){
            for(int sixes=0;sixes<=4;sixes++){
                for(int tens=0;tens<=2;tens++){
                    int bruteSum=1*ones+3*threes+6*sixes+10*tens;
                    if(bruteSum<=n && (n-bruteSum)%15==0){
                        int cnt=ones+threes+sixes+tens+(n-bruteSum)/15;
                        minCnt=min(cnt,minCnt);
                    }
                }
            }
        }
       }
        cout<<minCnt<<"\n";
    }
    return 0;
}