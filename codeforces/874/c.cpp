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
    vector<int> odd, even;
    for (auto& x : a) (x % 2 ? odd : even).push_back(x);
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    if (odd.size() == 0 || even.size() == 0) {
      cout << "YES\n";
      continue;
    }
    if (odd[0] < even[0]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
