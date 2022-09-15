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
  vector<ll> a(n), cost(n + 3);
  vector<int> id(n);
  auto add = [&](int l, int r, ll s, ll q) {
    // cout << "add " << l << " " << r << " " << s << " " << q << endl;
    if (l > r) return;
    cost[l] += s;
    cost[l + 1] += q - s;
    cost[r + 1] -= s + (r - l + 1) * q;
    cost[r + 2] += s + (r - l) * q;
  };
  for (int i = 0; i < n; i++) cin >> a[i], id[a[i]] = i;
  for (int i = 0; i < n; i++) {
    int mini = (i - id[i] + n) % n;
    int maxi = (mini + n / 2) % n;
    if (maxi < mini) {
      add(0, maxi, n - mini, 1);
      add(maxi + 1, mini, mini - (maxi + 1), -1);
      add(mini + 1, n - 1, 1, 1);
    } else {
      add(0, mini, mini, -1);
      add(mini + 1, maxi, 1, 1);
      add(maxi + 1, n - 1, (n + 1) / 2 - 1, -1);
    }
  }
  for (int i = 0; i <= n; i++) cost[i + 1] += cost[i];
  for (int i = 0; i <= n; i++) cost[i + 1] += cost[i];
  cout << *min_element(cost.begin(), cost.begin() + n) << "\n";
}
