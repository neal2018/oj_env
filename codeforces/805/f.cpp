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
    auto get = [&] {
      vector<int> a(n);
      for (auto& x : a) {
        cin >> x;
        while (x % 2 == 0) x /= 2;
      }
      return multiset<int>(a.begin(), a.end());
    };
    auto st_a = get();
    auto st_b = get();
    while (st_a.size()) {
      if (*st_a.rbegin() == *st_b.rbegin()) {
        st_a.erase(--st_a.end());
        st_b.erase(--st_b.end());
      } else {
        auto last = *st_b.rbegin();
        if (last == 1) break;
        st_b.erase(--st_b.end());
        st_b.insert(last / 2);
      }
    }
    cout << (st_a.size() == 0 ? "YES\n" : "NO\n");
  }
}
