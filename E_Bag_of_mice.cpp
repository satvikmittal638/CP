#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

using namespace std;
// Following code is AI-generated after I successfully figured out the recurrence and state for the dp solution
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int W, B;
    cin >> W >> B;

    // dp[w][b] will store the probability of the princess winning
    // given w white and b black mice, with her to move.
    vector<vector<double>> dp(W + 1, vector<double>(B + 1, 0.0));

    // Iterate through all possible states (w, b) from smallest to largest.
    for (int w = 0; w <= W; ++w) {
        for (int b = 0; b <= B; ++b) {
            // --- Base Cases ---
            if (w == 0) {
                dp[w][b] = 0.0; // No white mice, princess can't win.
                continue;
            }
            if (b == 0) {
                dp[w][b] = 1.0; // No black mice, princess wins immediately.
                continue;
            }

\
            // 1. Probability the princess wins on her current turn.
            double prob_win_now = (double)w / (w + b);
            double total_prob = prob_win_now;

            // 2. Probability the princess wins on a future turn.
            // This path is only possible if the game continues. For the game to continue past the dragon's turn,
            // there must be at least 2 black mice initially (one for P, one for D).
            if (b >= 2) {
                // Probability that P draws black, then D draws black.
                double prob_path_continues = ((double)b / (w + b)) * ((double)(b - 1) / (w + b - 1));

                // After D draws black, there are w white and b-2 black mice. One panics.
                // This panic step is only possible if there are mice left to panic.
                if (w + b - 2 > 0) {
                    // Case A: A white mouse panics.
                    // The probability of this is w / (w + b - 2).
                    // The new state for the princess is (w-1, b-2). We look up the pre-computed value.
                    double prob_white_panics = (double)w / (w + b - 2);
                    total_prob += prob_path_continues * prob_white_panics * dp[w - 1][b - 2];

                    // Case B: A black mouse panics.
                    // This is only possible if there are black mice left to panic (b-2 > 0 => b >= 3).
                    if (b >= 3) {
                        // The probability of this is (b-2) / (w + b - 2).
                        // The new state for the princess is (w, b-3). We look up the pre-computed value.
                        double prob_black_panics = (double)(b - 2) / (w + b - 2);
                        total_prob += prob_path_continues * prob_black_panics * dp[w][b - 3];
                    }
                }
            }
            
            dp[w][b] = total_prob;
        }
    }

    // The final answer is the state with the initial number of mice.
    cout << fixed << setprecision(10) << dp[W][B] << endl;

    return 0;
}
