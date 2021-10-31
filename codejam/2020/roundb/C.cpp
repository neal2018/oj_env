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
    ll N, B, P;
    int D;
    cin >> N >> B >> P;
    for (int case_num = 1; case_num <= total_cases_number; case_num++) {
        vector<ll> tower(N);
        vector<vector<ll>> number(N);
        number.push_back({1});
        for (int i = 0; i < N * B; i++) {
            cin >> D;
            if (D == -1) {
                return 0;
            }
            ll p = -1;
            if (D >= 9) {
                for (int j = 0; j < N; j++) {
                    if (tower[j] < B && (p == -1 | tower[j] > tower[p])) {
                        p = j;
                    }
                }
            } else if (D >= 8) {
                for (int j = 0; j < N; j++) {
                    if (tower[j] < B - 1 && (p == -1 | tower[j] > tower[p])) {
                        p = j;
                    }
                }
            } else {
                for (int j = 0; j < N; j++) {
                    if (tower[j] < B - 2 && (p == -1 | tower[j] > tower[p])) {
                        p = j;
                    }
                }
            }
            if (p == -1) {
                for (int j = 0; j < N; j++) {
                    if (tower[j] < B && (p == -1 | tower[j] < tower[p])) {
                        p = j;
                    }
                }
            }
            tower[p] += 1;
            number[p].push_back(D);
            cout << p + 1 << endl;
        }
    }
    cin >> D;
    if (D == -1) {
        return 0;
    }
    return 0;
}