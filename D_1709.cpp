#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

void bubbleSort(vector<int>& arr,vector<pair<int,int>>& ans,int token) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = 0;

        for (int j = 0; j < n - i - 1; ++j) {
            // Swap if the current element is greater than the next
            if (arr[j] > arr[j + 1]) {
                ans.emplace_back(token,j+1);
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }

        // If no two elements were swapped in the inner loop, array is sorted
        if (!swapped)
            break;
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n),b(n);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
       vector<pair<int,int>> ans;
       // now a has [1,..,n]
       // b has [n+1,..,2n]
       // bubble sort a
       bubbleSort(a,ans,1);
       bubbleSort(b,ans,2);
       for(int i=0;i<n;i++){
        if(a[i]>=b[i]) {
            ans.emplace_back(3,i+1);
            swap(a[i],b[i]);
        }
       }

       cout<<ans.size()<<"\n";
       for(auto [x,y]:ans)cout<<x<<" "<<y<<"\n";
       
    }
    return 0;
}