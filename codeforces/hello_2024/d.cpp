#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    if (count(a.begin(), a.end(), 0) != 1) {
      cout << "NO\n";
      continue;
    }

    vector<int> prev(n), nex(n);
    for (int i = 0; i < n; i++) prev[i] = i - 1;
    for (int i = 0; i < n; i++) nex[i] = i + 1;

    auto is_good = [&](int i) {
      if (prev[i] >= 0 && a[prev[i]] == a[i] - 1) return true;
      if (nex[i] < n && a[nex[i]] == a[i] - 1) return true;
      return false;
    };

    set<array<int, 2>> st;

    for (int i = 0; i < n; i++) {
      if (is_good(i)) {
        st.insert({-a[i], i});
      }
    }

    auto erase = [&](int i) {
      if (prev[i] >= 0) {
        nex[prev[i]] = nex[i];
        if (is_good(prev[i])) {
          st.insert({-a[prev[i]], prev[i]});
        }
      }
      if (nex[i] < n) {
        prev[nex[i]] = prev[i];
        if (is_good(nex[i])) {
          st.insert({-a[nex[i]], nex[i]});
        }
      }
    };

    int erased = 0;
    while (st.size()) {
      auto [_, i] = *st.begin();
      st.erase(st.begin());
      erase(i);
      erased++;
    }

    if (erased == n - 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
