#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()


int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<vector<int>> crd_accX(n,vector<int>(3,0)),crd_accY(n,vector<int>(3,0));//{x,y,ind} and {y,x,ind}
       for(int i=0;i<n;i++){
        cin>>crd_accX[i][0]>>crd_accX[i][1];
        crd_accY[i][0] = crd_accX[i][1];
        crd_accY[i][1] = crd_accX[i][0];
        crd_accY[i][2] = i + 1;
        crd_accX[i][2]=i+1;
       }
       sort(all(crd_accX));sort(all(crd_accY));
       vector<int> Xl,Xr,Yl,Yr,Ill,Irr,Ilr,Irl;
       for(int i=0;i<n/2;i++){
        Xl.push_back(crd_accX[i][2]);
        Yl.push_back(crd_accY[i][2]);
       }
       for(int i=n/2;i<n;i++){
        Xr.push_back(crd_accX[i][2]);
        Yr.push_back(crd_accY[i][2]);
       }
       sort(all(Xl));
       sort(all(Yl));
       sort(all(Xr));
       sort(all(Yr));
       set_intersection(all(Xl),all(Yl),back_inserter(Ill));
       set_intersection(all(Xr),all(Yr),back_inserter(Irr));
       set_intersection(all(Xl),all(Yr),back_inserter(Ilr));
       set_intersection(all(Xr),all(Yl),back_inserter(Irl));
       for(int i=0;i<min(Ill.size(), Irr.size());i++){
        cout<<Ill[i]<<" "<<Irr[i]<<"\n";
       }
       for(int i=0;i<min(Ilr.size(), Irl.size());i++){
        cout<<Ilr[i]<<" "<<Irl[i]<<"\n";
       }
    //    cout<<"\n";

    }
    return 0;
}