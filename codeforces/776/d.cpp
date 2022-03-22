#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x, x--;
    vector<ll> res;
    for (int i = n - 1; i >= 0; i--) {
      auto it = find(a.begin(), a.end(), i);
      if (it != --a.end()) {
        res.push_back(it - a.begin() + 1);
        rotate(a.begin(), ++it, a.end());
      } else {
        res.push_back(0);
      }
      a.pop_back();
    }
    reverse(res.begin(), res.end());
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
