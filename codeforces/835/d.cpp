#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int cnt = 0;
    for (int i = 0, j = 0; i < n; i = j) {
      for (j = i; j < n && a[i] == a[j];) j++;
      if ((i == 0 || a[i - 1] > a[i]) && (j == n || a[j - 1] < a[j])) cnt++;
    }
    if (cnt == 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
