#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> a(n+1);for(int i=1;i<=n;i++) cin>>a[i];
    /*
    Let f(i,j) denote the minm cost incurred by using the first i slimes
    and converting them to a total of j slimes
    Transn: f(i,j)=min(f(i-1,j),f(i-1,j-1)+a[i]+a[i-1])
    Base:f(2,1)=a[2]+a[1]

    now let f(i-1,j)-->prev_row((i-1)th row)
    f(i,j)-->cur_row(ith row)
    */
    vector<int> prev_row(n+1,INT_MAX),cur_row(n+1,INT_MAX);
    prev_row[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=n;j>=1;j--){
            if(i==j) 
                cur_row[j]=0; // no cost is incurred if no of slimes remain the same
            else if(i>j){
                int cost = (j > 1) ? prev_row[j - 1] + a[i] + a[i - 1] : INT_MAX;
                cur_row[j] = min(prev_row[j], cost);
            }
        }
        prev_row=cur_row;
        cur_row.clear();
        
    }
    cout<<cur_row[1];
    return 0;
}