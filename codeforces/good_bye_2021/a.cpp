#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
using ll = long long;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  auto f = [&]() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> mp;
    int cnt = 0;
    for (auto& x : a) cin >> x;
    for (auto& x : a) {
      if (mp.count(x)) {
        if (!mp.count(-x)) {
          mp.insert(-x), cnt++;
        }
      } else {
        mp.insert(x), cnt++;
      }
    }
    cout << cnt << "\n";
  };
  for (; T--;) f();
}