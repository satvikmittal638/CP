#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canMakeTProd(long long time,long long t,vector<long long> v){
    long long prodMade=0;
    for(auto e:v){
        prodMade+=time/e;
        if(prodMade>=t){
            return 1; // no need to calculate further if all products already made
        }
    }
    return prodMade>=t;
}

int main()
{
    long long n,t;
    cin>>n>>t;
    vector<long long> v(n); // stores efficiency of each machine
    for(auto &i:v){
        cin>>i;
    }
    // maxm time is when the least efficient machine makes all the products
    long long lo=1,hi=(*max_element(v.begin(),v.end()))*t;
    while (lo<hi)
    {
        long long mid=lo+(hi-lo)/2; // mid=(lo+hi)/2 would cause "off by 1 logical error"
        /*
        if prods can be made in time=mid, 
        then they can be made in any time>mid.
        So search for any time<=mid
        */ 
        // cout<<lo<<" "<<hi<<" ";
    //    cout<<mid<<endl;
        if(canMakeTProd(mid,t,v)){
            hi=mid;
        }else{
            lo=mid+1;
        }
    }
    cout<<lo; // lo==hi now
    
    return 0;
}