#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long> v(n);
    for(auto &i:v) cin>>i;
    long long curSum=0,maxSum=LLONG_MIN;
    for(auto e:v){
        curSum+=e;
        maxSum=max(curSum,maxSum);
        if(curSum<0) curSum=0; // prevent adding large -ves to form a max Sum
        /*
        resetting of curSum is done after updating maxSum to handle the edge
        case when all elts of the array are -ve
        */
    }
    cout<<maxSum;
    return 0;
}