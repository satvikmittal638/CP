#include<iostream>
#include<vector>
using namespace std;

bool solve(int sum,int k,vector<int> &bars){
    if(sum==0) return 1;
    if(k==bars.size()) return 0;
    return solve(sum-bars[k],k+1,bars) || solve(sum,k+1,bars) ;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        vector<int> bars(p);
        for(auto &i:bars) cin>>i;
        if(solve(n,0,bars)){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}