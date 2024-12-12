#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long> a(n+1),prefix(n+1),countOcc(n,0);
    prefix[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        long long toMod=(prefix[i-1]+a[i]);
        // may have issues with -ve number modding
        prefix[i] = ((toMod % n) + n) % n; // to handle toMod<0 cases
    }
    long long cnt=0;
    countOcc[0]=1; // 0 already present at prefix[0]
    for(int i=1;i<=n;i++){
            if(countOcc[prefix[i]]>0){
                cnt+=countOcc[prefix[i]];
            }
            countOcc[prefix[i]]++;
    }
    cout<<cnt;
    return 0;
}