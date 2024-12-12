#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        string s;
        cin >> x >> s;
        int l = 0, sz = s.size(),end=s.size()-1;
        while (l != x)
        {
            l++; // move operation
            sz+=(end-l+1)*(s[l-1]-'1');
        }
    }
    return 0;
}