#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;double l;cin>>n>>l;
    vector<double> a(n);for(auto &i:a) cin>>i;
    sort(a.begin(),a.end());
    double d=max(a[0],(l-a[n-1]));
    for(int i=0;i<n-1;i++){
        d=max(d,(a[i+1]-a[i])/(double)2);
    }
    printf("%.10f",d);
    return 0;
}