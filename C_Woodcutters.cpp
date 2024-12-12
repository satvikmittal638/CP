#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> x(n),h(n);
    for(int i=0;i<n;i++) cin>>x[i]>>h[i];
    /*
    left[i]->maxm number of trees cut till i if the ith tree falls left
    right[i]->maxm number of trees cut till i if the ith tree falls right
    stay[i]->maxm number of trees cut till i if the ith tree stays upright
    */
    vector<int> left(n,INT_MIN),stay(n,INT_MIN),right(n,INT_MIN);
    left[0]=1;// cut first tree and fell it to left(always possible)
    right[0]=(x[1]-x[0]>h[0]);//possible to fell tree to right with some conditions
    stay[0]=0; // first tree stays intact-->no tree cut
    for(int i=1;i<n;i++){
        // enough gap b/w i and i-1 tree to fell ith tree to left
        if (x[i] - x[i - 1] > h[i]) {
            left[i] = 1 + max(left[i - 1], stay[i - 1]);
        }
        // enough gap to accomodate both trees w/o overlap
        if (x[i] - x[i - 1] > h[i] + h[i - 1]) {
            left[i] = max(left[i], 1 + right[i - 1]);
        }

        // fell to right irrespective of prvs tree but check if it can be fell(till 2nd last tree)
        // last tree can be fell w/o any checks 
        if((i+1<n && x[i+1]-x[i]>h[i]) || i==n-1)
            right[i] = 1 + max({left[i - 1], stay[i - 1], right[i - 1]});

        /*
        the prvs tree will fell to the right only after considering the position
        of the next tree. hence stay[i] need not check any conditions on the prvs tree
        */
        stay[i] = max({left[i - 1], stay[i - 1], right[i - 1]});
    }

    cout<<max({left[n-1],stay[n-1],right[n-1]});
    return 0;
}