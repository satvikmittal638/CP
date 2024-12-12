#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> b(n);for(auto &i:b) cin>>i;
    int large=*max_element(b.begin(),b.end()),
        small=*min_element(b.begin(),b.end());
    long long freq_large=count(b.begin(),b.end(),large),
        freq_small=count(b.begin(),b.end(),small);
    long long diff=large-small,cnt=0;
    if(diff!=0){
        cnt=freq_large*freq_small; // nC1 * mC1
    }else{
        cnt=freq_large*(freq_large-1)/2; // nC2
    }
    cout<<diff<<" "<<cnt;
    return 0;
}