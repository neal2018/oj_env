#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    multiset sa(a.begin(), a.end()), sb(b.begin(), b.end());
    while (k && sb.size() && *sa.begin() < *sb.rbegin()) {
      k--, sa.erase(sa.begin()), sa.insert(*sb.rbegin()), sb.erase(--sb.end());
    }
    cout << accumulate(sa.begin(), sa.end(), 0ll) << "\n";
  }
}
