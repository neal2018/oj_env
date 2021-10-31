#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
bool is_prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int sum = accumulate(a.begin(), a.end(), 0);
    int ans = 0;
    if (!is_prime(sum)) {
      ans = sum;
      cout << n << '\n';
      for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
      }
      cout << '\n';
      continue;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
      if (!is_prime(sum - a[i])) {
        ans = max(ans, sum);
        index = i;
      }
    }
    cout << n - 1 << '\n';
    for (int i = 0; i < n; i++) {
      if (i != index) cout << i + 1 << " ";
    }
    cout << '\n';
  }
}