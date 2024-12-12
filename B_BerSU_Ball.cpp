#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> a(n);for(auto &i:a) cin>>i;
    int m;cin>>m;
    vector<int> b(m);for(auto &i:b) cin>>i;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0,j=0;
    int cnt_pair=0;
    while(i<n && j<m){
        if(abs(a[i]-b[j])<=1){
            cnt_pair++;
            i++;j++;
        }else{
            if(a[i]>b[j]){
                j++;
            }else{
                i++;
            }
        }
    }
    cout<<cnt_pair;
    return 0;
}