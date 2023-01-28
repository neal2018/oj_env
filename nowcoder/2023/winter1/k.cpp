#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i += 3) {
    if (m) a[i] = 1, m--;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (m && a[i] == 0) a[i] = 1, m--;
  }
  int res = 0;
  for (int i = 2; i < n; i++) {
    if (a[i - 2] + a[i - 1] + a[i] >= 2) res++;
  }
  cout << res << "\n";
}