#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       int global_mxCnt2=0,global_L=-1,global_R=-1; // final ans is stored here
       int l=0,r=0;
       vector<int> cnt2(n,0),sign(n,1);
       while(l<n && r<n){
           // get a segment of non-0 elts
           while(l<n && a[l]==0) l++;
           r=l;
           while(r<n && a[r]!=0) r++;
           r--;
            // for(int i=l;i<=r;i++){
            //     cout<<a[i]<<" ";
            // }
            // ready for reuse
            for (int i = l; i <= r; ++i) {
                cnt2[i] = 0;
                sign[i] = 1;
            }           
            // compute its prefix of products(which is a power of 2+sign of the product)
            for(int i=l;i<=r;i++){
            cnt2[i]+=(abs(a[i])==2);
            sign[i]*=a[i]/abs(a[i]);
            if(i>l) {
                cnt2[i]+=cnt2[i-1];
                sign[i]*=sign[i-1];
            }
           }
           // if the product of segment is -ve, try removing a -ve elt
           // by removing its prefix or its suffix(whichever gives maxm product)
           int mxCnt2=cnt2[r],curL=l,curR=r;
           if(sign[r]<0){
            mxCnt2=0;
               for(int i=l;i<=r;i++){
                if(a[i]<0){
                    int cntLeft=(i>l?cnt2[i-1]:0), cntRight=cnt2[r]-cnt2[i];
                    int signLeft=(i>l?sign[i-1]:1), signRight=sign[r]*sign[i];
                    // keep the prefix
                    if(mxCnt2<cntLeft && signLeft==1){
                        mxCnt2=cntLeft;
                        curL=l;curR=i-1;
                    }
                    // keep the suffix
                    if(mxCnt2<cntRight && signRight==1){
                        mxCnt2=cntRight;
                        curL=i+1;curR=r;
                    }
                    // cout<<cntLeft<<" "<<cntRight<<" ";
                }
                // cout<<curL<<" "<<curR<<"\n";
               }
           }
           // check against global ans
           if(global_mxCnt2<mxCnt2){
            global_mxCnt2=mxCnt2;
            global_L=curL;
            global_R=curR;
           }
           
           l=r+1;//l now points to a 0
       }
       if(global_mxCnt2==0){
        cout<<"0 "<<n<<"\n";
        continue;
       }
    //    cout<<global_L<<" "<<global_R;
       cout<<global_L<<" "<<n-(global_R+1)<<"\n";


       }
    return 0;
}