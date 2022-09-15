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
  vector<ll> a(n), cost(2 * n + 3);
  vector<int> id(n);
  auto add = [&](int l, int r, ll s, ll q) {
    // add arithmetic array
    if (l > r) return;
    cost[l] += s;
    cost[l + 1] += q - s;
    cost[r + 1] -= s + (r - l + 1) * q;
    cost[r + 2] += s + (r - l) * q;
  };
  for (int i = 0; i < n; i++) cin >> a[i], id[a[i]] = i;
  for (int i = 0; i < n; i++) {
    int mini = (i - id[i] + n) % n;
    if (mini < n / 2) mini += n;
    add(mini, mini + n / 2, 0, 1);
    add(mini - (n - 1) / 2, mini, (n - 1) / 2, -1);
  }
  for (int i = 0; i < 2 * n; i++) cost[i + 1] += cost[i];
  for (int i = 0; i < 2 * n; i++) cost[i + 1] += cost[i];
  for (int i = 0; i < n; i++) cost[i] += cost[i + n];
  cout << *min_element(cost.begin(), cost.begin() + n) << "\n";
}
