#include<bits/stdc++.h>
using namespace std;
int main()
{   
    const long long MAX=1e6;
    // precompute for all n if they can be summed by a GP 1,k,k^2,..k^m where m>=2
    bitset<MAX+1> canBeSumed;
    for(long long k=2;k<=sqrt(MAX);k++){
        // ceil(log(1e6)=20
        long long sum=1+k;
        long long kpowm=k*k;
        for(int m=2;m<=20;m++){
            sum+=kpowm;
            if(sum>MAX) break;
            canBeSumed[sum]=1;
            kpowm*=k;
        }
    }
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       cout<<(canBeSumed[n]?"YES":"NO")<<"\n";
    }
    return 0;
}