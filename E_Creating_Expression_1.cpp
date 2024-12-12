#include<iostream>
#include<vector>
using namespace std;


bool solve(vector<long long> v,long long sum,long long k,long long x){
    // a combination is made
    if(k==v.size()){
        return sum==x;
    }
    else{
        // check if either path was succesfully
        return solve(v,sum+v[k],k+1,x) || solve(v,sum-v[k],k+1,x);
    }
}

int main()
{
    long long n,x;
    cin>>n>>x;
    vector<long long> v(n);
    for(auto &i:v) cin>>i;
    // doing solve(v,0,0,x) would also take sequences starting with -v[0]into account which can give wrong ans for some cases
    if(solve(v,v[0],1,x)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}