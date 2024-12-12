#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long> v(n);
    // index->elt
    vector<long> ind(n+1);
    for(int i=0;i<n;i++){
        cin>>v[i];
        // elt-> index
        ind[v[i]]=i;
    }
    int ans=1; // atleast 1 round
    for(int e=1;e<n;e++){
//if e+1 occurs before e, both are taken in different rounds. Hence round+1
        if(ind[e+1]<ind[e]){
            ans++;
        }
// no increment means that we are still in the same round,collecting numbers
    }
    cout<<ans;
    return 0;
}