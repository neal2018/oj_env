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
    int total_cases_number;
    cin >> total_cases_number;
    for (int case_num = 1; case_num <= total_cases_number; case_num++) {
        ll N, K, t;
        double res = 0;
        cin >> N >> K;
        vector<ll> P;
        unordered_set<ll> nums;
        for (int i = 0; i < N; i++) {
            cin >> t;
            t--;
            if (nums.find(t) == nums.end()) {
                nums.insert(t);
                P.push_back(t);
            }
        }
        sort(P.begin(), P.end());
        int n = P.size();
        auto calc = [&](int pi, int i) -> ll {
            // i: left index of pi
            if (pi < 0 || pi > K - 1) {
                return 0;
            }
            if (i == -1) {
                return pi + 1;
            } else if (i == n - 1) {
                return K - 1 - P[i];
            } else {
                return (P[i + 1] - P[i]) / 2;
            }
        };
        ll maxi = 0;
        ll temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                temp = calc(P[i] - 1, i - 1);
                if (P[i] - 1 != P[j] - 1) {
                    temp += calc(P[j] - 1, j - 1);
                }
                maxi = max(maxi, temp);

                temp = calc(P[i] + 1, i);
                if (P[i] + 1 != P[j] - 1) {
                    temp += calc(P[j] - 1, j - 1);
                    if (i == j - 1 && (P[i + 1] - P[i]) % 2 == 0) {
                        temp -= 1;
                    }
                }
                maxi = max(maxi, temp);

                temp = calc(P[i] - 1, i - 1);
                if (P[i] - 1 != P[j] + 1) {
                    temp += calc(P[j] + 1, j);
                    if (i - 1 == j && (P[i] - P[i - 1]) % 2 == 0) {
                        temp -= 1;
                    }
                }
                maxi = max(maxi, temp);

                temp = calc(P[i] + 1, i);
                if (P[i] + 1 != P[j] + 1) {
                    temp += calc(P[j] + 1, j);
                }
                maxi = max(maxi, temp);
            }
        }
        res = 1.0 * maxi / K;

        cout << "Case #" << case_num << ": " << setprecision(9) << res << endl;
    }
    return 0;
}