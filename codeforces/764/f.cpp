#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, t, pre = 0, sum = 0;
  cin >> n;
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    int ask = (mid - sum + 100 * n) % n;
    cout << "+ " << ask << endl;
    cin >> t;
    if (t == pre) {
      l = mid + 1;
    } else {
      r = mid;
    }
    pre = t, sum += ask;
  }
  cout << "! " << n - l + sum << endl;
}
