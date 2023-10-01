#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k, k *= 5;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  int cur = 0;
  int i = 0;
  while (i < n && cur + a[i] <= k) cur += a[i], i++;
  cout << i << "\n";
}
