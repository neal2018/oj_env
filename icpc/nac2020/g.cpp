#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
const char nl = '\n';

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  int n, p, q, s;
  cin >> n >> p >> q >> s;
  // s = p = q = n = 200000;
  vector<int> pa(p), qa(q);
  FOR(i,p) cin >> pa[i];
  FOR(i,q) cin >> qa[i];
  // FOR(i, p) pa[i] = 1000000;
  // FOR(i, q) qa[i] = 1000000;
  int lo = 0, hi = 1e9;
  multiset<int> pp;
  multiset<int> qq;
  for (int v : pa) pp.insert(v);
  for (int v : qa) qq.insert(v);
  auto check = [&](int d) {
    auto pvals = pp;
    auto qvals = qq;
    int ct = 0;
    while (!pvals.empty() && !qvals.empty()) {
      int x = *(pvals.rbegin()), y = *(qvals.rbegin());
      if (x > y) {
        auto it = qvals.upper_bound(s - x);
        if (it != qvals.begin()) {
          it--;
          if (abs(x - *it) <= d) {
            qvals.erase(it);
            ct++;
          }
        }
        pvals.erase(pvals.find(x));
      } else {
        auto it = pvals.upper_bound(s - y);
        if (it != pvals.begin()) {
          it--;
          if (abs(y - *it) <= d) {
            pvals.erase(it);
            ct++;
          }
        }
        qvals.erase(qvals.find(y));
      }
      if (ct == n) return true;
    }
    return false;
  };
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (check(mid))
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  if (lo > 1e9)
    cout << "-1\n";
  else
    cout << lo << '\n';
}
