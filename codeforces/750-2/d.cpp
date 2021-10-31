#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n & 1) {
      vector<int> order(n);
      iota(order.begin(), order.end(), 0);
      sort(order.begin(), order.end(), [&](int x, int y) {
        return (abs(a[x]) == abs(a[y])) ? (a[x] < a[y]) : (abs(a[x]) < abs(a[y]));
      });
      for (int i = 0; i < n - 1;) {
        if (i == order[0] || i == order[1] || i == order[2] || b[i] != 0) {
          i++;
          continue;
        }
        int j = i + 1;
        while (j == order[0] || j == order[1] || j == order[2]) {
          j++;
        }
        b[i] = a[j], b[j] = -a[i];
      }
      if (abs(a[order[0]]) == abs(a[order[1]]) && abs(a[order[2]]) == abs(a[order[1]])) {
        b[order[0]] = -2, b[order[1]] = 1, b[order[2]] = 1;
        if (a[order[1]] < 0) b[order[1]] = -b[order[1]];
        if (a[order[0]] < 0) b[order[0]] = -b[order[0]];
        if (a[order[2]] < 0) b[order[2]] = -b[order[2]];
      } else {
        swap(order[2], order[0]);
        if (abs(a[order[0]]) == abs(a[order[1]])) swap(order[0], order[2]);
        if (abs(a[order[0]]) == abs(a[order[1]])) swap(order[0], order[1]);
        b[order[2]] = abs(a[order[0]]) - abs(a[order[1]]);
        b[order[1]] = a[order[2]];
        if (a[order[1]] < 0) b[order[1]] = -b[order[1]];
        b[order[0]] = -a[order[2]];
        if (a[order[0]] < 0) b[order[0]] = -b[order[0]];
      }
    } else {
      for (int i = 0; i < n - 1; i += 2) {
        b[i] = a[i + 1], b[i + 1] = a[i];
        b[i + 1] = -b[i + 1];
      }
    }
    for (auto& x : b) cout << x << " ";
    // int sum = 0;
    // for (int i = 0; i < n; i++) {
    //   sum += a[i] * b[i];
    // }
    // cout << endl << sum << endl;
    cout << endl;
  }
}