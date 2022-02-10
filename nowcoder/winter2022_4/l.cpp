#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  string s;
  cin >> n >> q >> s;
  // abc, [l, r)
  // sum cnt(a, l, i) * cnt(c, i+1, r) * [s[i]==b]
  // sum (cnt(a, i) - cnt(a, l)) * (cnt(c, r) - cnt(c, i+1)) * [s[i]==b]
  // sum (cnt(a, i) * cnt(c, r) - cnt(a, i) * cnt(c, i+1)
  // - cnt(a, l) * cnt(c, r) + cnt(a, l) * cnt(c, i+1)) * [s[i]==b]
  // 1:   sum (cnt(a, i) * [s[i]==b]) * cnt(c, r)
  // 2: - sum (cnt(a, i) * cnt(c, i+1) * [s[i]==b])
  // 3: - sum ([s[i]==b]) * cnt(c, r) * cnt(a, l)
  // 4:   sum (cnt(c, i+1) * [s[i]==b]) * cnt(a, l)
  vector<vector<ll>> cnt(26, vector<ll>(n + 1));
  for (int c = 0; c < 26; c++) {
    for (int i = 0; i < n; i++) {
      cnt[c][i + 1] = cnt[c][i] + (s[i] - 'a' == c);
    }
  }
  vector<vector<vector<ll>>> cnt2d(26, vector<vector<ll>>(26, vector<ll>(n + 1)));
  for (int c1 = 0; c1 < 26; c1++) {
    for (int c2 = 0; c2 < 26; c2++) {
      for (int i = 0; i < n; i++) {
        cnt2d[c1][c2][i] = cnt[c1][i] * cnt[c2][i + 1];
      }
    }
  }
  vector<vector<ll>> pos(26);
  for (int i = 0; i < n; i++) pos[s[i] - 'a'].push_back(i);
  vector<ll> pre[26][26], pre_shift[26][26], pre2d[26][26][26];
  for (int b = 0; b < 26; b++) {
    for (int c = 0; c < 26; c++) {
      pre[b][c].resize(pos[b].size() + 1);
      for (int i = 0; i < pos[b].size(); i++) {
        pre[b][c][i + 1] = pre[b][c][i] + cnt[c][pos[b][i]];
      }
    }
  }
  for (int b = 0; b < 26; b++) {
    for (int c = 0; c < 26; c++) {
      pre_shift[b][c].resize(pos[b].size() + 1);
      for (int i = 0; i < pos[b].size(); i++) {
        pre_shift[b][c][i + 1] = pre_shift[b][c][i] + cnt[c][pos[b][i] + 1];
      }
    }
  }
  for (int b = 0; b < 26; b++) {
    for (int c1 = 0; c1 < 26; c1++) {
      for (int c2 = 0; c2 < 26; c2++) {
        pre2d[b][c1][c2].resize(pos[b].size() + 1);
        for (int i = 0; i < pos[b].size(); i++) {
          pre2d[b][c1][c2][i + 1] = pre2d[b][c1][c2][i] + cnt2d[c1][c2][pos[b][i]];
        }
      }
    }
  }
  while (q--) {
    int l, r;
    string t;
    cin >> l >> r >> t, l--;
    ll a = t[0] - 'a', b = t[1] - 'a', c = t[2] - 'a';
    ll left = lower_bound(pos[b].begin(), pos[b].end(), l) - pos[b].begin();
    ll right = lower_bound(pos[b].begin(), pos[b].end(), r) - pos[b].begin();
    ll part1 = (pre[b][a][right] - pre[b][a][left]) * cnt[c][r];
    ll part2 = -(pre2d[b][a][c][right] - pre2d[b][a][c][left]);
    ll part3 = -(right - left) * cnt[c][r] * cnt[a][l];
    ll part4 = (pre_shift[b][c][right] - pre_shift[b][c][left]) * cnt[a][l];
    ll res = part1 + part2 + part3 + part4;
    cout << res << "\n";
  }
}
