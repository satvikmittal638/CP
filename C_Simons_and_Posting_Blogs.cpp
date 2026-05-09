#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif
int main()
{
    fastio;
    int tt;
    if (cin >> tt)
    {
        while (tt--)
        {
            int n;
            cin >> n;
            multiset<vector<int>> ms;

            for (int i = 0; i < n; i++)
            {
                int l;
                cin >> l;
                vector<int> b(l);
                for (auto &j : b)
                    cin >> j;

                vector<int> b_rev;
                set<int> appeared;
                // contributes to Q in reverse
                for (int j = l - 1; j >= 0; j--)
                {
                    if (!appeared.count(b[j]))
                    {
                        b_rev.push_back(b[j]);
                        appeared.insert(b[j]);
                    }
                }
                ms.insert(b_rev);
            }

            set<int> appeared;
            vector<int> q;

            while (!ms.empty())
            {
                auto it = ms.begin();
                vector<int> cur = *it;
                ms.erase(it);

                for (int tgt : cur)
                {
                    if (!appeared.count(tgt))
                    {
                        q.push_back(tgt);
                        appeared.insert(tgt);
                    }
                }

                // update all other blogs in the ms by peeling off the now-seen elts
                vector<vector<int>> tmp;
                while (!ms.empty())
                {
                    auto it2 = ms.begin();
                    vector<int> v = *it2;
                    ms.erase(it2);

                    vector<int> new_v;
                    for (int x : v)
                    {
                        if (!appeared.count(x))
                        {
                            new_v.push_back(x);
                        }
                    }
                    tmp.push_back(new_v);
                }
                // put updated layers back
                for (auto &v : tmp)
                {
                    ms.insert(v);
                }
            }

            for (int i = 0; i < q.size(); i++)
            {
                cout << q[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}