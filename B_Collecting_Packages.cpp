#include<bits/stdc++.h>
using namespace std;

int d(pair<int,int> p){
    return p.first*p.first+p.second*p.second;
}

int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<pair<int,int>> crd(n);
       for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        crd[i]={x,y};
       }
       // sort acc to increasing distances from origin
       sort(crd.begin(),crd.end(),[](auto p1,auto p2){
        return d(p1)<d(p2);
       });
       // check if all points x,y are non dec
       bool ok=1;
       for(int i=0;i<n-1;i++){
        if(crd[i+1].first-crd[i].first<0 || crd[i+1].second-crd[i].second<0){
            ok=0;break;
        }
       }
       
       if(ok){
        string path;
        path.append(crd[0].first,'R');
        path.append(crd[0].second,'U');
        for(int i=1;i<n;i++){
            path.append(crd[i].first-crd[i-1].first,'R');
            path.append(crd[i].second-crd[i-1].second,'U');
        }
        cout<<"YES\n"<<path<<"\n";
       }else{
        cout<<"NO\n";
       }
    }
    return 0;
}