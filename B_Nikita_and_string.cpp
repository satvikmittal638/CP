#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;cin>>s;
    int n=s.length();
    vector<int> prefa(n,0),prefb(n,0);
    prefa[0]=s[0]=='a';
    prefb[0]=s[0]=='b';
    for(int i=1;i<n;i++){
        // s[i-1] for 0 based indexing
        prefa[i]=prefa[i-1]+(s[i]=='a');
        prefb[i]=prefb[i-1]+(s[i]=='b');
    }
    int mxLen=0;
    // cut at position i means a cut after s[i]
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            // a..a b..b a..a
            int left_a = prefa[i];
            int middle_b = prefb[j] - (i > 0 ? prefb[i - 1] : 0);
            int right_a = prefa[n - 1] - prefa[j];
            int curLen = left_a + middle_b + right_a;
            mxLen = max(mxLen, curLen);
        }
    }
    cout<<mxLen;
    return 0;
}