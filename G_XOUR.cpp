#include<iostream>
#include<algorithm>
#include<map>
using namespace std;



int main()
{
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        // mp[a[i]] --> vector(indices at which a[i] is present in a)
        map<int,vector<int> > mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]].push_back(i);
        }

        for(int i=0;i<n;i++){
            // 3 possibilities for a swap
            int b[]={a[i]^1,a[i]^2,a[i]^3};
            sort(b,b+3);
            
            for(int j=0;j<3;j++){
                // if b[j]<a[i] and b[j exists in array
                if(b[j]<a[i] && mp[b[j]].size()>0){
                    int ind=mp[b[j]][0];
                    // swap the indexing
                    
                    // swap the values
                    swap(a[i],a[ind]);

                }
            }
        }
        
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}