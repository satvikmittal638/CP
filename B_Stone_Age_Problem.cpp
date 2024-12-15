#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,q;cin>>n>>q;
    vector<long long> a(n);
    long long sum=0ll;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    // track operation of type-2 since it's time consuming to update all elts
    long long last_time_changed_all=-1,lastVal=0;
    vector<long long> last_time_changed(n,0);
    for(long long j=0;j<q;j++){
        long long t;cin>>t;
        if(t==1){
            long long i,x;
            cin>>i>>x;
            i--;// make 0-indexed
    // a[i] is defined by the last operation of type-1
            if(last_time_changed[i]>last_time_changed_all){
                sum+=x-a[i];
            }
    //a[i] is defined by the last operation of type-2
            else{
                sum+=x-lastVal;
            }
            a[i]=x;
            last_time_changed[i]=j;
        }
        else if(t==2){
            long long x;
            cin>>x;
            sum=n*x;
            // set all elts to x   
            last_time_changed_all=j;
            lastVal=x;         
        }
        cout<<sum<<"\n";
    }
    return 0;
}