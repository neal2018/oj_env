#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<int> a(n), cnt(n), id(n);
  for (int i = 0; i < n; i++) cin >> a[i], id[a[i]] = i;
  for (int i = 0; i < n; i++) {
    for (auto& t : {(i - 1 + n) % n, i, (i + 1) % n}) {
      int need = (t - id[i] + n) % n;
      cnt[need]++;
    }
  }
  cout << *max_element(cnt.begin(), cnt.end()) << "\n";
}
