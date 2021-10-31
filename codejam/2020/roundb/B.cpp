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
        ll N, A, B;
        cin >> N >> A >> B;
        map<int, int> U;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            if (x > 0) {
                U[i] = x;
            }
        }
        auto check = [&](ll m) -> bool {
            auto T = U;
            map<int, int> H;
            if (T.find(m) != T.end()) {
                T[m]--;
                return T.empty();
            }
            H[m] = 1;
            while ((!H.empty()) && (!T.empty())) {
                int metal = (H.rbegin())->first;
                int count = (H.rbegin())->second;
                H.erase(metal);
                for (int x : {A, B}) {
                    if (metal >= x) {
                        if (T.find(metal - x) != T.end()) {
                            if (T[metal - x] > count) {
                                T[metal - x] -= count;
                            } else if (T[metal - x] == count) {
                                T.erase(metal - x);
                            } else {
                                H[metal - x] = count - T[metal - x];
                                T.erase(metal - x);
                            }
                        } else {
                            H[metal - x] += count;
                        }
                    }
                }
            }
            return T.empty();
        };
        int res = -1;
        for (int m = 0; m < 403; m++) {
            if (check(m)) {
                res = m + 1;
                break;
            }
        }
        if (res == -1) {
            cout << "Case #" << case_num << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << case_num << ": " << res << endl;
        }
    }
    return 0;
}