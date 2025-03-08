#include <bits/stdc++.h>
using namespace std;

void fwt_xor(vector<long long>& a, bool invert) {
  int n = int(a.size());
  for (int len = 1; len < n; len <<= 1) {
    for (int i = 0; i < n; i += 2 * len) {
      for (int j = 0; j < len; ++j) {
        long long u = a[i + j], v = a[i + j + len];
        a[i + j] = u + v;
        a[i + j + len] = u - v;
      }
    }
  }
  if (invert) {
    for (int i = 0; i < n; ++i) {
      a[i] /= n;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int H, W;
  cin >> H >> W;
  vector<long long> count(1 << W, 0);

  for (int i = 0; i < H; ++i) {
    string s;
    cin >> s;
    int x = 0;
    for (char c : s) {
      x = (x << 1) | (c == '1');
    }
    count[x]++;
  }

  vector<long long> f(1 << W);
  for (int x = 0; x < (1 << W); ++x) {
    int cnt = __builtin_popcount(x);
    f[x] = min(cnt, W - cnt);
  }

  fwt_xor(count, false);
  fwt_xor(f, false);

  for (int i = 0; i < (1 << W); ++i) {
    count[i] *= f[i];
  }

  fwt_xor(count, true);

  long long ans = numeric_limits<long long>::max();
  for (int i = 0; i < (1 << W); ++i) {
    ans = min(ans, count[i]);
  }

  cout << ans << '\n';
  return 0;
}
