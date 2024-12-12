#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;cin>>n>>k;
    vector<int> h(n);for(auto &i:h) cin>>i;
    int i=0,j=0,curSum=0,minSum=INT_MAX,minStart;
   
    // reach window size
    for(;j<k;j++){
        curSum+=h[j];
    }
    minSum = curSum;
    minStart = 0;

    // Slide the window
    while (j < n) {
        curSum -= h[i];
        curSum += h[j];
        i++;
        j++;
        if (curSum <= minSum) {
            minSum = curSum;
            minStart = i;
        }
    }
    cout<<minStart+1;

    return 0;
}