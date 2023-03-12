#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string a, b;
    cin >> n >> a >> b;
    auto it = find(a.begin(), a.end(), '1');
    auto it2 = find(b.begin(), b.end(), '1');
    if (it == a.end() || it2 == b.end()) {
      if (a == b) {
        cout << "0\n";
      } else {
        cout << "-1\n";
      }
      continue;
    }
    // int a_first_1 = int(it - a.begin());
    int b_first_1 = int(it2 - b.begin());
    vector<int> res;
    int a_last_1 = int(find(a.rbegin(), a.rend(), '1').base() - 1 - a.begin());

    auto apply = [&](int k) {
      res.push_back(k);
      auto t = a;
      for (int i = 0; i < n; i++) {
        char c = (i + k < 0 || i + k >= n) ? '0' : t[i + k];
        if (c == '1') a[i] = a[i] ^ '0' ^ '1';
      }
    };
    for (int i = b_first_1; i >= 0; i--) {
      if (a[i] != b[i]) {
        // i + k = a_last_1
        apply(a_last_1 - i);
      }
      a_last_1 = int(find(a.rbegin(), a.rend(), '1').base() - 1 - a.begin());
    }
    for (int i = b_first_1 + 1; i <= n; i++) {
      if (a[i] != b[i]) {
        // i + k = a_first_1
        apply(b_first_1 - i);
      }
    }
    cout << res.size() << "\n";
    if (res.size()) {
      for (auto& x : res) cout << x << " ";
      cout << "\n";
    }
  }
}
