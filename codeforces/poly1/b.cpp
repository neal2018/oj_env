#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (auto& x : a) cin >> x;
    int up = n % k;
    int avail = n / k + 1;
    cout << ([&] {
      for (auto& x : a) {
        if (x > avail) return false;
        if (x == avail) up--;
        if (up < 0) return false;
      }
      return true;
    }()
                 ? "YES\n"
                 : "NO\n");
  }
}
