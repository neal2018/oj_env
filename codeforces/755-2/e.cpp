#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    ll val = 0, ans = 0;
    map<ll, int> mp{{0, 1}};
    for (int i = 0, x, f = 1; i < n; i++, f = -f) {
      cin >> x;
      val = x - val, ans += mp[f * val]++;
      if (f == 1)
        while (mp.size() && mp.rbegin()->first > val) mp.erase(--mp.end());
      else
        while (mp.size() && -mp.begin()->first > val) mp.erase(mp.begin());
    }
    cout << ans << '\n';
  }
}
