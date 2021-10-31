#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define IO
ll INF = 1e18;

int main(int, char**) {
#ifdef IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    ll MAX = 1e18;
    set<ll> threes;
    for (ll i = 1; i <= 1e6; i++) {
        ll j = i;
        ll t = i;
        while (t < MAX && t > 0) {
            j++;
            t = stoll(to_string(t) + to_string(j));
            if (t < MAX && t > 0) {
                threes.insert(t);
            }
        }
    }

    int total_cases_number;
    cin >> total_cases_number;
    for (int case_num = 1; case_num <= total_cases_number; case_num++) {
        ll Y;
        cin >> Y;
        ll res = (*threes.upper_bound(Y));
        ll left = 1;
        ll right = 1e9;
        while (left < right) { // the minimal x that x(x+1) larger than Y
            ll mid = (left+right)/2;
            ll t=stoll(to_string(mid) + to_string(mid+1));
            if (t>=Y){
                right=mid;
            } else{
                left=mid+1;
            }
        }

        cout << "Case #" << case_num << ": " << endl;
    }
    return 0;
}