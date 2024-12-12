#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(auto &i:a) cin>>i;
        int minDis=0;
        for(int i=1;i<n/2;i++){
            int dis1=(a[i]==a[i-1]) + (a[n-i-1]==a[n-i]);
            int dis2=(a[n-i-1]==a[i-1]) + (a[i]==a[n-i]);
            // if disturbance decreases on swapping
            if(dis1>dis2){
                minDis+=dis2;
                swap(a[i],a[n-i-1]);
            }else{
                minDis+=dis1;
            }
            // cout<<dis1<<" "<<dis2<<"  ";
        }
        if(n%2!=0){
            minDis+=(a[n/2]==a[n/2-1]) + (a[n/2]==a[n/2+1]);
        }else{
            minDis+=a[n/2]==a[n/2-1];
        }
        cout<<minDis<<"\n";
    }
    return 0;
}