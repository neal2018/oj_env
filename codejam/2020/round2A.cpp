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
        ll C, D;
        cin >> C >> D;
        vector<int> X(C);
        for (int i = 1; i < C; i++) {
            cin >> X[i];
        }
        vector<vector<int>> G(C);
        for (int i = 0; i < D; i++) {
            int U, V;
            cin >> U >> V;
            G[U - 1].push_back(V - 1);
            G[V - 1].push_back(U - 1);
        }

        cout << "Case #" << case_num << ": " << endl;
    }
    return 0;
}