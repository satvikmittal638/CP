#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,s;cin>>n>>s;
       vector<int> a(n);
       for(int i=0;i<n;i++){
        cin>>a[i];
       }
    int start = 0, current_sum = 0, max_size = 0;

    for (int end = 0; end < n; ++end) {
        current_sum += a[end];
        
        while (current_sum > s) {
            current_sum -= a[start];
            start++;
        }

        if (current_sum == s) {
            max_size = max(max_size, end - start + 1);
        }
    }
        if(max_size>0){
            cout<<n-max_size<<"\n";
        }else{
            cout<<"-1\n";
        }
       
    }
    return 0;
}