#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
    // for submission to USACO only
     freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin>>n;
    vector<long long> ids(n+1),prefix(n+1);
    for(int i=1;i<=n;i++) cin>>ids[i];
    prefix[0]=0;
    for(int i=1;i<=n;i++){
        prefix[i]=(prefix[i-1]+ids[i])%7;
    }

    int mxlen=0;
    // if any 2 indices give same value, a valid range is found
    // or any elt is 0, then a vlid range is found from start till that index
    /*
    only first occurence of a rpted elt would give maximum length of subarray
    */
    map<int,int> mp;  // elt->index of first occurence of elt in prefix
    for(int i=0;i<=n;i++){
        if(mp[prefix[i]]==0) mp[prefix[i]]=i;
        else{
            mxlen=max(mxlen,i-mp[prefix[i]]);
        }
        if(prefix[i]==0) mxlen=max(mxlen,i); // start to i also becomes a valid range
    }
    cout<<mxlen;
    return 0;
}