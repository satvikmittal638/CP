#include<iostream>
#include<vector>
using namespace std;


long long cost(pair<long long,long long> p1,pair<long long,long long> p2){
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

// pos and minPos follows 1-based indexing
long long nearestMajorTo(long long pos,vector<pair<long long,long long> > &coords,long long k){
    pair<long long,long long> p=coords[pos-1];
    long long minCost=1e18,minPos=1;// taking minCost=INT_MAX may cause issues when input size>INT_MAX
    for(long long i=0;i<k;i++){
        long long curCost=cost(p,coords[i]);
        if(curCost<minCost){
            minCost=curCost;
            minPos=i+1;
        }
    }
    return minPos;
}

// a,b,k obey 1-based indexing
long long solve(vector<pair<long long,long long> > &coords,long long k,long long a,long long b){
    if(k<2){
        auto p1=coords[a-1],p2=coords[b-1];
        return cost(p1,p2);
    }
    else{
        // src and dest are major
        if(a<=k && b<=k){
            return 0;
        }
        // src is major, dest isn't
        // a->nearestMajor(b)->b
        else if(a<=k){
            auto nearestB=coords[nearestMajorTo(b,coords,k)-1];
            return cost(nearestB,coords[b-1]);//cost(coords[a-1],nearestB)=0
        }
        // src is not major, dest is
        // a->nearestMajor(a)->b
        else if(b<=k){
            auto nearestA=coords[nearestMajorTo(a,coords,k)-1];
            return cost(nearestA,coords[a-1]);//cost(coords[b-1],nearestB)=0
        }
        // src and dest both are not major
        // a->nearestMajor(a)->nearestMajor(b)->b
        else {
            auto nearestA=coords[nearestMajorTo(a,coords,k)-1],
                                        nearestB=coords[nearestMajorTo(b,coords,k)-1];
            return cost(coords[a-1],nearestA) +cost(nearestB,coords[b-1]); // cost(nearestA,nearestB)=0
        }
    }
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        long long n,k,a,b;
        cin>>n>>k>>a>>b;
        vector<pair<long long,long long> > coords(n);
        for(auto &coord:coords){
            cin>>coord.first>>coord.second;
        }
        // use major cities or not and get the minimum
        cout<<min(solve(coords,0,a,b),solve(coords,k,a,b))<<endl;
    }
    return 0;
}