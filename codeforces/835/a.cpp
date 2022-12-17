#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    vector<int> a(3);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    cout << a[1] << "\n";
  }
}
