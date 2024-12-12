#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
        int n;long long l,r;cin>>n>>l>>r;
        vector<long long> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        long long wins=0,curSum=0;
        int s=0,e=0;
        while(s<n){
            while(e<n && curSum<l){
                curSum+=a[e];
                e++;
            }

            if(l<=curSum && curSum<=r){
                wins++;
                s=e; // e is already 1 step ahead due to loop structure so we took all cards from [s->e-1]
                curSum=0;
            }else{
                curSum-=a[s];
                s++;
            }
        }

        cout<<wins<<"\n";

    }
    return 0;
}