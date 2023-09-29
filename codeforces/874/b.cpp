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
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    vector<int> order(n), id(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) { return a[i] < a[j]; });
    for (int i = 0; i < n; i++) id[order[i]] = i;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
      cout << b[id[i]] << " ";
    }
    cout << "\n";
  }
}
