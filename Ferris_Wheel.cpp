#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    long long x;
    cin>>n>>x;
    vector<long long> p(n);
    for(auto &i:p) cin>>i;
    sort(p.begin(),p.end());
    long long count=0;
    int i=0,j=n-1;
    while(i<=j){
        if(p[i]+p[j]<=x){
            count++; // place p[i] and p[j] in same box
            i++;j--;
        }else{
            count++; // place p[j] in seperate box
            j--;
        }
    }
    cout<<count;
    return 0;
}