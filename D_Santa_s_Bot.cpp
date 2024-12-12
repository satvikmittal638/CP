#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define MOD 998244353

long long fast_pow(long long base, long long n,long long M)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
long long MMI(long long n,long long M)
{
    return fast_pow(n,M-2,M);
}

int main()
{
    long long n,totalItems=0;
    cin>>n;
    vector<vector<long long> > list(n); // total n kids
    map<long long,long long> mp; // item -> count
    for(auto &kid:list){
        long long k; // no of items in list of ith kid
        cin>>k;
        totalItems+=k;
        // take the list of items(having ki no of items) as demanded by the ith kid
        for(long long i=0;i<k;i++){
            long long item;
            cin>>item;
            mp[item]++;
            kid.emplace_back(item);
        }
    }
    // for every kid, check all items of all the kids
    long long totalDec=(n*totalItems)%MOD;
    // make all possible decisions
    /*
    find total number of valid decisions mod M
    find MMI of total number of decisions 
    */
    long long countValidDec=0;
    // choose a kid x
    for(auto &x:list){
        // choose a item y from list of kid x
        for(auto &y:x){
            // valid decision is taken
            countValidDec=(countValidDec+mp[y])%MOD;
        }
    }
    long long totalDecMMI=MMI(totalDec,MOD),
        ans=(long long)(countValidDec*totalDecMMI)%MOD;
    cout<<ans;
    return 0;
}