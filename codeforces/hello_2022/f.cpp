#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    ll n, a, b, c, res = 0;
    cin >> n >> a >> b >> c >> s;
    vector<int> adj(2), steps;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) adj[s[i] - '0']++;
    }
    for (int i = 0, j; i < n; i = j) {
      j = i;
      while (j < n && s[i] == s[j]) j++;
      if (s[i] == '0' && i != 0 && j != n) steps.push_back(j - i);
    }
    int k = (int)steps.size();
    ranges::sort(steps);
    vector<int> pre(k + 1);
    for (int i = 0; i < k; i++) pre[i + 1] = pre[i] + steps[i];
    ll cnt0 = count(s.begin(), s.end(), '0');
    for (ll cnt = 0; cnt <= adj[1] + k; cnt++) {
      if (cnt >= pre[max(0ll, cnt - adj[1])]) {
        for (auto x : {cnt - 1, cnt, cnt + 1}) {
          if (0 <= x && x <= cnt0) {
            ll t = max({0ll, cnt - adj[1], x - adj[0]});
            res = max(res, (x - t) * a + cnt * b - t * c);
          }
        }
      }
    }
    cout << res << "\n";
  }
}
