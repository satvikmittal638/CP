#include<iostream>
using namespace std;
bool isDiag(pair<int,int>& p1,pair<int,int>& p2){
    return p1.first!=p2.first && p1.second!=p2.second;
}

int main()
{
    int n,m;
    cin>>n>>m;
    char a[n][m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k=0;
    pair<int,int> cd[4];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='*')
                cd[k++]=make_pair(i,j);
        }
    }
    /**
     choose cd[0]
     check if its diagonally opposite to which of remaining 2. if it is to some, then we r done.
     if not, then the remaining i.e. cd[1] & cd[2] are diagonally opposite

     now equate the MP of the diagonally opposite cds to find the unknown cd
     */

    int i,j,l;
    if(isDiag(cd[0],cd[1])){
       i=0;j=1;l=2;
    }else if(isDiag(cd[1],cd[2])){
        i=1;j=2;l=0;
    }else{ // cd[0] and cd[2] are diagonally opp
        i=0;j=2;l=1;
    }
    cd[k]=make_pair(cd[i].first+cd[j].first-cd[l].first,
                cd[i].second+cd[j].second-cd[l].second);
    cout<<cd[k].first+1<<" "<<cd[k].second+1;
    return 0;
}