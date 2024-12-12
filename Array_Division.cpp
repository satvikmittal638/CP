#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

/*
 checks if it is possible to paritition the array 
 such that maximum sum of all the k subarrays<=maxSum
*/
bool isParitionPos(long long maxSum,long long k,vector<long long> v){
    long long curSum=0,countPart=1; // atleast 1 partition(the whole array) exists
    for(auto e:v){
        curSum+=e;
        if(curSum>maxSum){
            countPart++;
            curSum=e; // start summing a new partition
        }
    }
    /*
    if we can achieve a maximum sum in <k subarrays, 
    then we can achieve the sum in k subarrays as well 
    since further division of subarrays will only
    decrease the individual sum of the subarrays
    and hence the maximum sum of all th subarrays won't be affected
     */
    return countPart<=k; 
}

int main()
{
    long long n,k;
    cin>>n>>k;
    vector<long long> v(n);
    for (long long &i : v) { cin >> i; }
    long long low=*max_element(v.begin(),v.end()),
        high=accumulate(v.begin(),v.end(),0LL),mid;
    /*
    binary search the "minimized" maximum sum of all the subarrays
    in [maxElt,maxElt+1...sum_of_all_elts]
    */
    while (low<high)
    {
        mid=(low+high)/2;
        if(isParitionPos(mid,k,v)){
            high=mid; // search in the 1st half
        }else{
            // TODO:figure out "off by 1" issue while updating low and high, 
            //TODO:and also while calculating mid
            low=mid+1;// search in the 2nd half
        }
    }
    cout<<low; // low==high now
    

    return 0;
}