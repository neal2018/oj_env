#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    long long val = 0, ans = 0;
    map<long long, int> mp;
    for (int i = 0, x, f = 1; i < n; i++, f = -f) {
      cin >> x;
      if (f == 1)
        while (!mp.empty() && mp.rbegin()->first > x - val) {
          mp.erase(--mp.end());
        }
      else
        while (!mp.empty() && -mp.begin()->first > x - val) {
          mp.erase(mp.begin());
        }
      mp[-f * val]++, val = x - val, ans += mp[f * val];
    }
    cout << ans << '\n';
  }
}
