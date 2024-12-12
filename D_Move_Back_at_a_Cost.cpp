#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,curIdx=0;cin>>n;
       multiset<pair<int,int>> ms; //like a min-heap sorting by first elt of pair by default
        for(int i=0;i<n;i++){
            int a;cin>>a;
            ms.insert({a,i});
        }
        while(ms.size()){
            auto [value,index]=*ms.begin();
            ms.extract(*ms.begin());
            // if the elt occurs at the end or it occurs after the prvs elt printed
            if(index==n || index>=curIdx){
                cout<<value<<" ";
                curIdx=index;
            }else{
                ms.insert({value+1,n}); // increment the value and move to the end
                // seqeunce of elts occuring before the elts printed doesn't matter
            }
        }
        cout<<"\n";
    }
    return 0;
}