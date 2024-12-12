#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> x(n);
       vector<int> excess(n);
       for(auto &i:x) cin>>i;
       for(int i=0;i<n;i++) {
        int y;cin>>y;
        excess[i]=y-x[i];
       }
       // sort in descn based on excess amount(y-x)
       sort(excess.rbegin(),excess.rend());
       int i=0,j=n-1,cnt=0;
       while(i<j){
        if(excess[i]+excess[j]>=0){
            cnt++;
            i++;j--;
        }else{
            j--; // try increasing the excess
        }
       }
       cout<<cnt<<"\n";


    }
    return 0;
}