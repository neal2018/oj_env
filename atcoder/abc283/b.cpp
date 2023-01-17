#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int k, x;
      cin >> k >> x, k--;
      a[k] = x;
    } else {
      int k;
      cin >> k, k--;
      cout << a[k] << "\n";
    }
  }
}
