#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    string op;cin>>op;
    if(op=="first"){
        int n;cin>>n;
        string s="z"; // start with a z
        for(int i=0;i<n;i++){
            int x;cin>>x;
            string num;
            // convert to base 25 and use a-y as digits and z as delimeter
            while(x){
                int d=x%25;
                num.push_back('a'+d);
                x/=25;
            }
            reverse(all(num));
            s=s+num;
            s.push_back('z'); // mark the ending of the no.
        }
        s.pop_back(); // remove the last z

        cout<<s<<endl;
    }
    else{
        string s;cin>>s;
        reverse(all(s));
        vector<int> a;
        int cur=0,place=1;
        for(auto e:s){
            if(e=='z'){
                a.push_back(cur);
                // reset for next no.
                cur=0; place=1;

            }
            else{
                int d=e-'a';
                cur+=place*d;
                place*=25;
            }
        }
        reverse(all(a));
        cout<<a.size()<<' ';
        for(auto e:a) cout<<e<<' ';
        cout<<endl;
    }
    return 0;
}