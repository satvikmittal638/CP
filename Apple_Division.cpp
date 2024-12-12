#include<iostream>
#include<vector>
using namespace std;

// complete search the solution 
long long search(vector<long long> v, long long sum1,long long sum2,long long k){
    
    // a possible solution has been generated,so return it
    if(k==v.size()) return abs(sum1-sum2);

    // give item to grp-1
    long long ans1=search(v,sum1+v[k],sum2,k+1),
    // give item to grp-2
        ans2=search(v,sum1,sum2+v[k],k+1);
    return min(ans1,ans2);
}

int main()
{
    long long n;
    cin>>n;
    vector<long long> v(n);
    for(auto &i:v) cin>>i;
    cout<<search(v,0,0,0);
    return 0;
}