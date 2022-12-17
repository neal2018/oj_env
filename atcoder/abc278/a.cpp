#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  if (k < n) {
    for (int i = k; i < n; i++) {
      cout << a[i] << " ";
    }
    for (int i = 0; i < k; i++) {
      cout << "0 ";
    }
    cout << "\n";
  } else {
    for (int i = 0; i < n; i++) {
      cout << "0 ";
    }
    cout << "\n";
  }
}
