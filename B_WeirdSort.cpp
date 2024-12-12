#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       vector<int> a(n),p(m);
       for(auto &i:a) cin>>i;
       for(auto &i:p) cin>>i;
       sort(p.begin(),p.end());
       for(int i=0;i<m;i++){
        int start=p[i]-1;// make 0 indexed
        // get a connected component
        while(i+1<m && (p[i+1]-p[i])==1) i++;
        int end=p[i];//p[i]+1 in 0 indexed same as p[i] in 1-indexed
        // sort the connected component
        sort(a.begin()+start,a.begin()+end+1);
       }
    //    for(auto e:a) cout<<e<<" ";
    //    cout<<"\n";
       if(is_sorted(a.begin(),a.end())) cout<<"YES";
       else cout<<"NO";
       cout<<"\n";
    }
    return 0;
}