#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string s;cin>>s;
    int n=s.length();
    vector<int> prefixq(n,0);
    prefixq[0]=(s[0]=='Q');
    for(int i=1;i<n;i++){
        prefixq[i]=prefixq[i-1]+(s[i]=='Q');
    }
    long long cnt=0;
    for(int i=1;i<n;i++){
        if(s[i]=='A'){
            // convert to 1-based indexing
            cnt+=prefixq[i-1]*(prefixq[n-1]-prefixq[i]);
        }
    }
    cout<<cnt;
    return 0;
}