#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
checks if a given value x is a possible median value
which can be achieved by atmost k operations
*/
//isMedianPossible
bool isMedPos(vector<long long> v, long long x,long long k){
    long long numOfOpn=0;
    /*
    we need to increment all values from v[(n-1)/2] to v[n-1]
    to x for it to become the median
     */
    for(int i=(v.size()-1)/2;i<v.size();i++){
        numOfOpn+=max(0ll,x-v[i]);
    }
    return numOfOpn<=k;
}


int main()
{
    long long n,k;
    cin>>n>>k;
    vector<long long> v(n);
    for(long i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    /*
        maximum median is achieved when k=10^9 
        and v has only n=1 elt equal to 10^9
     */
    long long low=v[(n-1)/2],high=2e9,mid;
    /*
    m->lowest median value(equal to the median of the current array w/o 
                performing any operations)
    M->maxm median value possible according to the given constraints
    perform binary search on [m,m+1,m+2...M]
    to find the maximum median
    */ 
   // keeps searching until there are atleast 2 elements to search
    while(low<high){
        mid=low+(high-low+1)/2; // TODO:why not (low+high)/2 ?
        if(isMedPos(v,mid,k)){
            // try to maximize the median
            low=mid;
        }else{
            high=mid-1; //why not high=mid ?
            /*When isMedPos(v, mid, k) returns false,
             it means mid cannot be a valid median, nor can any value larger than mid. 
             Thus, we exclude mid from the search space by setting high = mid - 1.
            If you used high = mid, the current mid could be included in the next search iteration,
             potentially leading to incorrect results or an infinite loop.*/
        }
    }
    if(isMedPos(v,high,k))
        cout<<high;
    else
        cout<<low; // low==high now
   
    return 0;
}