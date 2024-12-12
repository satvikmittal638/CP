#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        // false init by default
        vector<bool> to0(n+1,0);

        // find the last non-dec segment
        int last=-1;
        for(int i=n-2;i>=0;i--){
            if(v[i]>v[i+1]){
                last=i;break;
            }
        }
        if(last==-1) {cout<<0<<endl;continue;} // array is already non decreasing
        
        // now all elts from 0 to last are to be set to 0
        // track how many distinct ai's are to be set to 0
        for(int i=0;i<=last;i++){
            to0[v[i]]=1;
        }

        // when elts from 0 to last are set 0, 
        //some elts from last to n-1 are also set to 0, 
        //thereby requiring the updation of the last variable
        for(int i=last+1;i<n;i++){
            if(to0[v[i]]){
                last=i;
            }
        }
        // now update the to0 counter to include any new elements 
        //appeared via setting of elts to 0 from index 0 to last(before updating last)
        for(int i=last;i>=0;i--){
            to0[v[i]]=1;
        }
        // count the number of distinct elts to be set to 0
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=to0[i];
        }
        cout<<ans<<endl;

    }
    return 0;
}