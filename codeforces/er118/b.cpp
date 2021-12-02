#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    ranges::sort(a);
    for (int i = n - 1; i >= (n + 1) / 2; i--) {
      cout << a[i] << " " << a[0] << '\n';
    }
  }
}