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
    if (accumulate(a.begin(), a.end(), 0) % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
