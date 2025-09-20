#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

bool gameOver(int L, int R)
{
    if ((L >= 5 || R >= 5) && abs(L - R) >= 2)
        return 1;
    if (L == 10 || R == 10)
        return 1;
    return 0;
}

int main()
{
    fastio;
    string s;
    cin >> s;
    int GL = 0, GR = 0; // games won
    int PL = 0, PR = 0; // current pts
    int srvr = 0;     // 0 = left, 1 = right (left starts)

    for (char c : s)
    {
        if (c == 'S' || c == 'R')
        {
            bool ptTosrvr = (c == 'S');
            if (ptTosrvr)
            {
                if (srvr == 0)
                    PL++;
                else
                    PR++;
            }
            else
            {
                if (srvr == 0)
                    PR++;
                else
                    PL++;
            }
            srvr = ptTosrvr ? srvr : 1 - srvr;

            if (gameOver(PL, PR))
            {
                if (PL > PR)
                    GL++;
                else
                    GR++;
                PL = PR = 0;
                srvr = (PL > PR ? 0 : 1);
                srvr = (GL > GR ? 0 : 1);
                if (GL == 2 || GR == 2)
                {
                }
            }
        }
        else if (c == 'Q')
        {
            if (GL == 2 || GR == 2)
            {
                if (GL == 2)
                    cout << GL << " (winner) - " << GR << "\n";
                else
                    cout << GL << " - " << GR << " (winner)\n";
            }
            else
            {
                cout << GL << " (" << PL;
                if (srvr == 0)
                    cout << "*";
                cout << ") - " << GR << " (" << PR;
                if (srvr == 1)
                    cout << "*";
                cout << ")\n";
            }
        }
    }

    return 0;
}