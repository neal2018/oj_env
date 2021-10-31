#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 998244353;

int n, m;
int l[maxn], r[maxn];
int f[maxn], sum[maxn];

int cal(int d) {
  int M = m / d;
  f[0] = 1;
  for (int i = 1; i <= M; i++) {
    f[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    int L = (l[i] + d - 1) / d, R = r[i] / d;
    if (L > R) {
      return 0;
    }
    for (int j = 0; j <= M; j++) {
      sum[j] = (f[j] + (j ? sum[j - 1] : 0)) % p;
    }
    for (int j = 0; j <= M; j++) {
      f[j] = ((j - L >= 0 ? sum[j - L] : 0) + p - (j - R - 1 >= 0 ? sum[j - R - 1] : 0)) % p;
    }
  }
  int ans = 0;
  for (int i = 1; i <= M; i++) {
    ans = (ans + f[i]) % p;
  }
  return ans;
}

int prm[maxn], cnt, mu[maxn];
bool tag[maxn];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
  mu[1] = 1;
  for (int i = 2; i <= m; i++) {
    if (!tag[i]) {
      prm[++cnt] = i, mu[i] = p - 1;
    }
    for (int j = 1; j <= cnt && prm[j] * i <= m; j++) {
      tag[i * prm[j]] = true;
      if (i % prm[j]) {
        mu[i * prm[j]] = (p - mu[i]) % p;
      } else {
        break;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = (ans + 1ll * mu[i] * cal(i)) % p;
  }
  cout << ans;
}