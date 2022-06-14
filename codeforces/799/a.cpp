#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    vector<int> a(4);
    for (auto& x : a) cin >> x;
    int t = a[0];
    sort(a.begin(), a.end());
    cout << 3 - (find(a.begin(), a.end(), t) - a.begin()) << "\n";
  }
}
