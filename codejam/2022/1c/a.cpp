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
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    vector<ll> left(n, -1), right(n, -1);
    ll nice = 1;
    auto check = [&](ll& val, ll t) {
      if (val != -1) nice = 0;
      val = t;
    };
    for (int i = 0; i < 26; i++) {
      vector<ll> mid;
      ll end = -1, start = -1, only = 0;
      for (int j = 0; j < n; j++) {
        if (ll cnt = count(a[j].begin(), a[j].end(), i + 'A')) {
          if (a[j].size() == cnt) {
            mid.push_back(j);
          } else {
            auto t = a[j];
            t.erase(unique(t.begin(), t.end()), t.end());
            if (count(t.begin(), t.end(), 'A' + i) > 1) nice = 0;
            if (a[j].back() == 'A' + i) {
              check(start, j);
            } else if (a[j][0] == 'A' + i) {
              check(end, j);
            } else {
              only++;
              if (only > 1) nice = 0;
            }
          }
        }
      }
      if (start != -1) mid.insert(mid.begin(), start);
      if (end != -1) mid.push_back(end);
      if (mid.size() && only) nice = 0;
      for (int ii = 1; ii < (int)mid.size(); ii++) {
        check(right[mid[ii - 1]], mid[ii]);
        check(left[mid[ii]], mid[ii - 1]);
      }
    }
    vector<ll> order, seen(n);
    for (int i = 0; i < n; i++) {
      if (left[i] == -1) {
        ll cur = i;
        while (cur != -1 && seen[cur] == 0) {
          seen[cur] = 1;
          order.push_back(cur);
          cur = right[cur];
        }
        if (cur != -1) {
          nice = 0;
        }
      }
    }
    if (!nice || order.size() != n) {
      cout << "IMPOSSIBLE\n";
    } else {
      for (auto& x : order) cout << a[x];
      cout << "\n";
    }
  }
}
