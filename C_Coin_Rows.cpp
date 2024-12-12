#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int m;cin>>m;
       vector<int> row1(m,0),row2(m,0),pref1(m,0),pref2(m,0);

        for(int i=0;i<m;i++){
            cin>>row1[i];
            pref1[i]+=(i>=1?pref1[i-1]:0)+row1[i];
        }
        for(int i=0;i<m;i++){
            cin>>row2[i];
            pref2[i]+=(i>=1?pref2[i-1]:0)+row2[i];
        }

        int sumA=INT_MAX,sumB=INT_MIN;
        for(int i=0;i<m;i++){
            int curA=pref1[i]+pref2[m-1]-(i>=1?pref2[i-1]:0);
            if(curA<sumA){
                sumA=curA;
                sumB=max(pref1[m-1]-pref1[i],pref2[i]);
            }
        }
        cout<<sumA+sumB<<"\n";
       
      
    }
    return 0;
}