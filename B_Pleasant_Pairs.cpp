#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n+1);
       for(int i=1;i<=n;i++) cin>>a[i];
       long long cnt=0;
       // brute-force all the pairs 
       /*
ai*aj=i+j --> for a fixed i, j=a[j]*a[i]-i or j=k*a[i]-i
now try all values of k from 1..n
       */
       for(int i=1;i<=n;i++){
        // use a[i]-(i%a[i]) to omit -ve j
        for(int j=a[i]-(i%a[i]);j<=n;j+=a[i]){
            if(i!=j && a[i]*a[j]==i+j){
                cnt++;
            }
        }
       }
       cout<<cnt/2<<"\n";
       

    }
    return 0;
}