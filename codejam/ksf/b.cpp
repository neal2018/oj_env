#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define IO
ll INF = 1e18;

int main(int, char**) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll total_cases_number, n;
  string s;
  cin >> total_cases_number;
  for (ll case_num = 1; case_num <= total_cases_number; case_num++) {
    cin >> n >> s;
    vector<ll> dis(n, INF);
    ll pre = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        pre = i;
      }
      if (pre != -1) {
        dis[i] = min(dis[i], abs(i - pre));
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '1') {
        pre = i;
      }
      if (pre != -1) {
        dis[i] = min(dis[i], abs(i - pre));
      }
    }
    ll res = 0;
    for (auto& x : dis) res += x;
    cout << "Case #" << case_num << ": " << res << '\n';
  }
  return 0;
}