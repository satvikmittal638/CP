#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin>>N)) return 0;
    vector<pair<double,double>> p(N);
    for(int i=0;i<N;i++) cin>>p[i].first>>p[i].second;

    // build segments (i -> i+1 mod N)
    struct Seg { double L, ux, uy, theta; };
    vector<Seg> segs;
    segs.reserve(N);
    for(int i=0;i<N;i++){
        int j=(i+1)%N;
        double dx = p[j].first - p[i].first;
        double dy = p[j].second - p[i].second;
        double L = hypot(dx,dy);
        if(L==0) continue;
        double ux = dx / L;
        double uy = dy / L;
        // theta such that cos(phi - theta) = ux*cos(phi) - uy*sin(phi)
        // i.e. theta = atan2(-uy, ux)
        double theta = atan2(-uy, ux);
        segs.push_back({L, ux, uy, theta});
    }

    const double PI = acos(-1.0);
    const double TWO = 2*PI;

    // events: pair(angle, pair(deltaA, deltaB))
    // An interval is (theta - pi/2, theta + pi/2) (active). We'll model as [start, end) and
    // if it wraps, split into [start, 2pi) and [0, end).
    struct Event { double ang; double dA, dB; };
    vector<Event> events;
    events.reserve(segs.size()*4);

    for(auto &s: segs){
        double start = s.theta - PI/2.0;
        double end   = s.theta + PI/2.0;
        // normalize to [0,2pi)
        while(start < 0) { start += TWO; end += TWO; }
        while(start >= TWO) { start -= TWO; end -= TWO; }
        // now end may be >= 2pi (wrap)
        double contribA = s.L * s.ux;     // cos theta_i = ux
        double contribB = s.L * s.uy * -1; // sin theta_i = -uy, so L * sin theta_i = -L*uy
        if(end < TWO){
            // normal interval [start, end)
            events.push_back({start, contribA, contribB}); // enter
            events.push_back({end,  -contribA, -contribB}); // leave
        } else {
            // wrap: [start, 2pi) and [0, end-2pi)
            events.push_back({start, contribA, contribB});
            events.push_back({TWO,  -contribA, -contribB});
            events.push_back({0.0, contribA, contribB});
            events.push_back({end - TWO, -contribA, -contribB});
        }
    }

    // sort events by angle
    sort(events.begin(), events.end(), [](const Event &a, const Event &b){
        if (a.ang == b.ang) {
            // apply removals before additions? Not necessary here because we treat region (prev, ang) first,
            // then apply all events at ang. Keep stable ordering.
            return a.dA < b.dA;
        }
        return a.ang < b.ang;
    });

    // sweep from angle = 0 to 2pi
    double curA = 0.0, curB = 0.0;
    double prevAng = 0.0;
    double ans = 1e300;

    auto eval_val = [&](double A, double B, double phi)->double{
        return A * cos(phi) + B * sin(phi);
    };

    // process grouped events: for each group at angle 'ang', first handle region (prevAng, ang) with current A,B
    int m = events.size();
    int idx = 0;
    while(idx < m){
        double ang = events[idx].ang;
        // handle region (prevAng, ang)
        if(ang > prevAng + 1e-15) { // non-empty region
            double A = curA, B = curB;
            double R = hypot(A,B);
            if(R < 1e-18){
                // E(phi) = 0 on this region
                ans = min(ans, 0.0);
            } else {
                double phi0 = atan2(B, A);       // A*cos + B*sin = R*cos(phi - phi0)
                double cand = phi0 + PI;        // minimum is at phi0 + pi
                // normalize cand into [prevAng, ang]
                while(cand < prevAng) cand += TWO;
                while(cand > ang) cand -= TWO;
                // but cand may be outside after +/- 2pi adjustments; check both shifts
                if(cand >= prevAng - 1e-12 && cand <= ang + 1e-12) {
                    ans = min(ans, eval_val(A,B,cand));
                }
                // also evaluate at endpoints prevAng and ang (use midpoint values in region safe)
                // exact endpoint may coincide with event where set changes, but the function is continuous and
                // checking values at prevAng+eps and ang-eps is equivalent; we'll evaluate directly at prevAng and
                // ang with current A,B (which correspond to (prevAng,ang) open interval).
                ans = min(ans, eval_val(A,B, prevAng));
                ans = min(ans, eval_val(A,B, ang));
            }
        }

        // apply all events at angle 'ang'
        while(idx < m && fabs(events[idx].ang - ang) < 1e-15){
            curA += events[idx].dA;
            curB += events[idx].dB;
            idx++;
        }
        prevAng = ang;
    }

    // final region (prevAng, 2pi)
    if(prevAng < TWO - 1e-15){
        double A = curA, B = curB;
        double R = hypot(A,B);
        if(R < 1e-18) ans = min(ans, 0.0);
        else {
            double phi0 = atan2(B,A);
            double cand = phi0 + PI;
            // normalize into [prevAng, 2pi]
            while(cand < prevAng) cand += TWO;
            while(cand > TWO) cand -= TWO;
            if(cand >= prevAng - 1e-12 && cand <= TWO + 1e-12) ans = min(ans, eval_val(A,B,cand));
            ans = min(ans, eval_val(A,B, prevAng));
            ans = min(ans, eval_val(A,B, TWO));
        }
    }

    // numerical tiny negative guard
    if(ans < 0 && ans > -1e-12) ans = 0.0;
    // print with 2 decimals
    cout.setf(std::ios::fixed); cout<<setprecision(2)<<ans<<"\n";
    return 0;
}
