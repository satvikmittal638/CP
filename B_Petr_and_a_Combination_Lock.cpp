#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> a,int i,int sum){
    if(i==a.size()){
        return sum%360==0;
    }
    // take CW(+)
    return solve(a,i+1,sum+a[i])
    // take ACW(-)
        || solve(a,i+1,sum-a[i]);

}


int main()
{
    int n;cin>>n;
    vector<int> a(n);for(auto &i:a) cin>>i;
    cout<<(solve(a,1,a[0]) || solve(a,1,-a[0])?"YES":"NO");
    return 0;
}