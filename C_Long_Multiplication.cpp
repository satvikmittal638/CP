#include<bits/stdc++.h>
using namespace std;


int main()
{
    int tt;cin>>tt;
    while(tt--){
       string x,y;cin>>x>>y;
       int n=x.size();
       // minimize the difference b/w x and y to maximise their product
        int i;
        for(i=0;i<n;i++){
            if(x[i]!=y[i]){
                // give the maxm most significant digit to x
                int mxDig=max(x[i]-'0',y[i]-'0'),minDig=min(x[i]-'0',y[i]-'0');
                x[i]='0'+mxDig;
                y[i]='0'+minDig;
                break;
            }
        }
        i++;
        // now give all the other(less significant) maxm digits to y
        for(;i<n;i++){
            if((x[i]-'0')>(y[i]-'0')){
                swap(x[i],y[i]);
            }
        }
        cout<<x<<"\n"<<y<<"\n";
    }
    return 0;
}