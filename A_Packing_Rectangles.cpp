#include<iostream>
using namespace std;

bool canAccomodate(long long s,long long w,long long h,long long n){
    long long count_w=s/w, count_h=s/h;
    return count_w*count_h>=n;
}

int main()
{
    long long w,h,n;
    cin>>w>>h>>n;
    long long lo=max(w,h), hi=1;

    /*
    using hi=max(w, h) * n is a potentially excessive and 
    overflow-prone value.This would work fine for small inputs only

    The "hi*=2" approach would just find a square large enough
    to fit all the rectangles and thus would give a smaller upper bound 
    for the binary search, thereby preventing any overflow
    */
    //Dynamically find a valid upper bound.
    while(!canAccomodate(hi,w,h,n)){
		hi*=2;
	}
    // binary search the ans
    while(lo<hi){
        long long mid=lo+(hi-lo)/2;
        if(canAccomodate(mid,w,h,n)){
            hi=mid;
        }else{
            lo=mid+1;
        }
    }
    cout<<lo;
    return 0;
}