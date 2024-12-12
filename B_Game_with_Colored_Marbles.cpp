#include<bits/stdc++.h>
using namespace std;

int ceildiv(int a,int b){
    return (a+b-1)/b;
}

int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> freq(n+1,0);
       for(int i=0;i<n;i++){
        int c;cin>>c;
        freq[c]++;
       }
       // count-1 marbles have the most impact of 2 points
       int cnt_1=count(freq.begin(),freq.end(),1);
       // alice starts first, so gets more count-1 marbles
       int alice=ceildiv(cnt_1,2)*2;
       for(int i=1;i<=n;i++) alice+=freq[i]>=2;
        cout<<alice<<"\n";
        
        
    }
    return 0;
}