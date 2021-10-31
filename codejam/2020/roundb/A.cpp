#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define IO
ll INF = 1e18;
ll M = 360 * 12 * 1e10;
ll MINUTE_MAX = 12;
ll SECOND_MAX = 12 * 60;

ll solve(ll A, ll B, ll C) {
    int i, j;
    ll res;
    auto check = [&](ll d1, ll d2) -> ll {
        if ((d1 + i * M) % 11 == 0 && (d2 + j * M) % 719 == 0) {
            ll x = (d1 + i * M) / 11;
            if (x == (d2 + j * M) / 719) {
                return x;
            }
        }
        return -1;
    };
    for (i = 0; i < MINUTE_MAX; i++) {
        for (j = 0; j < SECOND_MAX; j++) {
            // A is hour
            // B is minute
            if ((res = check(B - A, C - A)) != -1) {
                return res;
            }
            // A is hour
            // C is minute
            if ((res = check(C - A, B - A)) != -1) {
                return res;
            }
            // B is hour
            // A is minute
            if ((res = check(A - B, C - B)) != -1) {
                return res;
            }
            // B is hour
            // C is minute
            if ((res = check(C - B, A - B)) != -1) {
                return res;
            }
            // C is hour
            // A is minute
            if ((res = check(A - C, B - C)) != -1) {
                return res;
            }
            // C is hour
            // B is minute
            if ((res = check(B - C, A - C)) != -1) {
                return res;
            }
        }
    }
    return -1;
}

int main(int, char**) {
#ifdef IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    __int128_t a=0;
    int total_cases_number;
    cin >> total_cases_number;
    for (int case_num = 1; case_num <= total_cases_number; case_num++) {
        ll A, B, C;
        cin >> A >> B >> C;
        ll x = solve(A, B, C);
        ll n = x % (int)1e9;
        x /= (int)1e9;
        ll s = x % 60;
        x /= 60;
        ll m = x % 60;
        x /= 60;
        ll h = x;
        cout << "Case #" << case_num << ": " << h << " " << m << " " << s << " "
             << n << endl;
    }
    return 0;
}