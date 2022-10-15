#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    ll n, e;
    cin >> n >> e;
    vector<array<ll, 3>> a(n);
    for (auto& [x, y, z] : a) cin >> x >> y >> z;
    vector<int> compress(2*n);
  }
}
