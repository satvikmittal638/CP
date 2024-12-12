#include<iostream>
#include<map>
#include<set>
using namespace std;


bool solve(string s,string t){
    //character->set of index 
    map<char,set<int> > mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]].insert(i);
    }
    for(int i=0;i<t.size()-1;i++){
        bool exists1=mp.find(t[i])!=mp.end(),
            exists2=mp.find(t[i+1])!=mp.end();

        if(exists1 && exists2){
            set<int> s1=mp[t[i]],s2=mp[t[i+1]];
        // check for existence of consecutive indexes in s1 and s2
            auto it1=s1.begin(),it2=s2.begin();
            bool found=0;
            while(it1!=s1.end() && it2!=s2.end()){
                if(abs(*it1-*it2)==1){
                    found=1;
                    break; // consecutive indices found
                }
                else{
                    if(*it1>*it2){
                        it2++;
                    }
                    // *it1<=*it2 (equality is also possible when characters become same)
                    else{
                        it1++;
                    }
                }
            }
            if(!found) return 0;
        }
        else{
            return 0;
        }
        }
    return 1;
    }


int main()
{
    int q;
    cin>>q;
    while(q--){
        string s,t;
        cin>>s>>t;
        if(solve(s,t)){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}