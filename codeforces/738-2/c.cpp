#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    if (a[n - 1] == 0) {
      for (int i = 0; i < n + 1; i++) {
        cout << i + 1 << " ";
      }
      cout << endl;
      continue;
    }
    if (a[0] == 1) {
      cout << n + 1 << " ";
      for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
      }
      cout << endl;
      continue;
    }
    int go = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
        go = i;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i == go) {
        cout << n + 1 << " ";
      }
      cout << i + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
