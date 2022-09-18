#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto& x : a) cin >> x, replace(x.begin(), x.end(), '.', '0');
  sort(a.begin(), a.end());
  // for (auto& x : a) cout << x << "\n";

  int res = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1 || !(a[i + 1].substr(0, a[i].size()) == a[i] && a[i + 1].size() > a[i].size() &&
                        a[i + 1][a[i].size()] == '/')) {
      if (a[i].size() >= 4 && a[i].substr(int(a[i].size()) - 4) == "0eoj") {
        res++;
      }
    }
  }
  cout << res << "\n";
}
