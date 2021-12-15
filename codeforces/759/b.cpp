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
    int maxi = a[n - 1], cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] > maxi) maxi = a[i], cnt++;
    }
    cout << cnt << '\n';
  }
}