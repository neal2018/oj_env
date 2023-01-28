#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll sum = accumulate(a.begin(), a.end(), 0ll);
  set<int> st;
  for (int i = 0; i < n; i++) st.insert(i);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, k;
      cin >> l >> r >> k, l--;
      auto it = st.lower_bound(l);
      while (it != st.end() && *it < r) {
        auto cur = a[*it];
        sum -= cur;
        if ([&] {
              for (int i = 0; i < k; i++) {
                ll nex = ll(round(10 * sqrt(cur)));
                if (nex == cur) return true;
                cur = nex;
              }
              return false;
            }()) {
          a[*it] = cur;
          it = st.erase(it);
        } else {
          a[*it] = cur;
          it++;
        }
        sum += cur;
      }
    } else {
      cout << sum << "\n";
    }
  }
}