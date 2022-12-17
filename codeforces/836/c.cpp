#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> res(n);
    iota(res.begin(), res.end(), 1);
    if (n % k != 0) {
      cout << "-1\n";
      continue;
    }
    if (k == n) {
      swap(res[0], res.back());
    } else {
      res[n - 1] = 1;
      res[0] = k;
      int last = k - 1;
      set<int> poss;
      for (int i = last + 1; i < n - 1; i++) {
        if (n % (i + 1) == 0) poss.insert(i);
      }
      while (poss.size()) {
        auto t = *poss.begin();
        poss.erase(poss.begin());
        if (res[t] % (last + 1) == 0) res[last] = res[t], last = t;
      }
      res[last] = n;
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
