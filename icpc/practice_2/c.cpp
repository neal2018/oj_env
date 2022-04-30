#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using vi = vector<int>;

ll productSum[110][110];
constexpr ll MOD = 1e9 + 7;

ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD) {
    if (b & 1) (res *= a) %= MOD;
  }
  return res;
}

int main() {

  int n; cin >> n;
  memset(productSum, 0, sizeof(productSum));
  for(int i = 0; i < 101; i++) productSum[i][0] = 1;

  cout << "1 1 1" << endl;
  ll a, b; cin >> a >> b;
  productSum[1][1] = b;

  vector<ll> ans(n);
  ans[0] = b;

  for(int i = 2; i <= n; i++) {
    cout << 1 << ' ' << 1 << ' ' << i << endl;
    cin >> a >> b;

    b -= productSum[i-1][a];
    b = (b+MOD) % MOD;
    ll inv = power(productSum[i-1][a-1], MOD-2);
    b *= inv;
    b %= MOD;
    ans[i-1] = b;

    for(int j = 0; j < 101; j++) {
      productSum[i][j] = productSum[i-1][j];
    }
    for(int j = 0; j < 101; j++) {
      ll add = productSum[i-1][j-1] * ans[i-1];
      add %= MOD;
      productSum[i][j] += add;
      productSum[i][j] %= MOD;
    }

  }   

  cout << "2 ";
  for(ll z : ans) cout << z << ' ';
  cout << endl;
  
}