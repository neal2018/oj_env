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
    int t = 0;
    for (auto& x : a) t ^= x;
    if (t == 0) {
      cout << "0\n";
    } else if (n % 2 == 1) {
      cout << t << "\n";
    } else {
      cout << "-1\n";
    }
  }
}
