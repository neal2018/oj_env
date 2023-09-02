#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1] - 1) cout << a[i] + 1 << "\n";
  }
}
