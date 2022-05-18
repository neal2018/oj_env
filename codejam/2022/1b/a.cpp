#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; case_num++) {
    cout << "Case #" << case_num << ": ";
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    deque<ll> dq(a.begin(), a.end());
    ll maxi = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (*dq.begin() < *dq.rbegin()) {
        if (*dq.begin() >= maxi) cnt++;
        maxi = max(maxi, *dq.begin());
        dq.pop_front();
      } else {
        if (*dq.rbegin() >= maxi) cnt++;
        maxi = max(maxi, *dq.rbegin());
        dq.pop_back();
      }
    }
    cout << cnt << "\n";
  }
}
