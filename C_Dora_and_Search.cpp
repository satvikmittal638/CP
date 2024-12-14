#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       set<int> st; //stores all elements in the current window
       vector<int> a(n);
       for(auto &i:a) {
        cin>>i;
        st.insert(i);
       }
       int l=0,r=n-1;
       while(l<=r){
        if(a[l]==*st.begin() || a[l]==*st.rbegin()){
            st.erase(st.find(a[l]));
            l++;
        }
        else if(a[r]==*st.begin() || a[r]==*st.rbegin()){
            st.erase(st.find(a[r]));
            r--;
        }else{
            break; // found the segment :)
        }
       }
       if(l<r){
        cout<<l+1<<" "<<r+1<<"\n";
       }else{
        cout<<"-1\n";
       }
    }
    return 0;
}