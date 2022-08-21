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
    cout << ([&] {
      for (int i = 1, j; i < n - 1; i = j) {
        for (j = i; j < n - 1 && a[i] == a[j];) j++;
        if (a[i] < a[i - 1] && a[i] < a[j]) return false;
      }
      return true;
    }()
                 ? "YES\n"
                 : "NO\n");
  }
}
