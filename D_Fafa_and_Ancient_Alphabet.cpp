#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
long long fast_pow(long long base, long long n,long long M)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
long long MMI(long long n,long long M)
{
    return fast_pow(n,M-2,M);
}

long long probab(vector<int> &s1,vector<int> &s2,int n,int m){
    int i=0,count_unset=0;
    long long p=0,mmi_m=MMI(m,MOD),mmi_denom=1;
    while(i<n){
        // both are set
        if(s1[i]!=0 && s2[i]!=0){
            if(s1[i]>s2[i]){
                // cout<<s1[i]<<" "<<s2[i]<<endl;
                // can have s1==s2 at a prvs unset position(if it exists)
                if(count_unset>=1){
                    p+=mmi_m;
                    p%=MOD;
                }
                else{
                    p=1;
                }
                return p;
            }
            else if(s1[i]<s2[i]){
                // cannot have s1==s2 at a prvs unset position
                return p;
            }
        }
        // atleast one is clear
        else{
            count_unset++;
            mmi_denom=(mmi_denom*mmi_m)%MOD;
            if(s1[i]==0 && s2[i]!=0){
                // s1[i] can take vals from s2[i]...m if i!=n-1
                //  OW it takes val from s2[i]+1...m
                p+=((m - s2[i])*mmi_denom)%MOD;
                p%=MOD;
            }
            else if(s2[i]==0 && s1[i]!=0){
                // s2[i] can take vals from 1..s1[i] if i!=n-1
                // OW it takes val from 1...s1[i]-1
                p+=((s1[i]-1)*mmi_denom)%MOD;
                p%=MOD;
            }
            // both s1[i] and s2[i] are cleared
            else{
                p+=(((m-1)*MMI(2,MOD))%MOD)*mmi_denom;
                p%=MOD;
            }

        }
        i++;// if s1[i]==s2[i] was taken
    }
    return p;
}

int main()
{
    int n,m; // total m alphabets available
    cin>>n>>m;
    vector<int> s1(n),s2(n);
    for(auto &i:s1) cin>>i;
    for(auto &i:s2) cin>>i;
    cout<<probab(s1,s2,n,m);
    
    return 0;
}