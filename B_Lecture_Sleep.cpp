#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,k;cin>>n>>k;
    vector<int> a(n+1),t(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }

//calculate contribution of 1s for whole array
    int offset=0;
    for(int i=1;i<=n;i++){
        offset+=a[i]*t[i];
    }

    int i=1,j=1,curSum=0;
    // process the first window
    while(j<=k){
        curSum+=a[j]*(t[j]==0); // awake only if reqd
        j++;
    }
    curSum+=offset;
    int mxSum=curSum;
    // process subsequent windows
    while(j<=n){
        curSum+=a[j]*(t[j]==0); // awake only if required
        //undo calcn for i
        curSum-=a[i]*(t[i]==0); // remove only if reqd
        mxSum=max(mxSum,curSum);
        i++;j++;
    } 
    cout<<mxSum;       
    return 0;
}