    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        string s;cin>>s;
        int cnt_lower=0,ans=0;
        for(int i=0;i<s.length();i++){
            if(islower(s[i])) cnt_lower++;
    //If the current character is uppercase and there are already lowercase letters before it 
    // change upper case to lower case
            else if(cnt_lower>0){
                cnt_lower--;ans++;
            }
        }
        cout<<ans;
        return 0;
    }