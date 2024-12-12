#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> a(n);for(auto &i:a) cin>>i;
    vector<int> tmp(a);
    sort(tmp.begin(),tmp.end());
    int l=-1,r=-1; // start and end of the segment
    for(int i=0;i<n;i++){
        if(tmp[i]!=a[i]) {
            l=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(tmp[i]!=a[i]) {
            r=i;
            break;
        }
    }
    if(l!=-1 && r!=-1){
        reverse(a.begin()+l,a.begin()+r+1);
        if(is_sorted(a.begin(),a.end())) cout<<"yes\n"<<l+1<<" "<<r+1;
        else cout<<"no";
    }
    // no segment was found so the array is already sorted
    else{
        cout<<"yes\n1 1";
    }
    return 0;
}