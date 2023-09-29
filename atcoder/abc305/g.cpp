#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
int power(int, ll) = delete;
template <typename T>
T power(T a, ll b, int _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  int x;
  Z(int _x = 0) : x(norm(_x)) {}
  Z(long long _x) : x(norm((_x % MOD + MOD) % MOD)) {}
  static int norm(int x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
    return x;
  }
  // auto operator<=>(const Z &) const = default;  // need c++ 20
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2, MOD); }
  Z &operator*=(const Z &rhs) { return x = int(ll(x) * rhs.x % MOD), *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const int &rhs) { return x %= rhs, *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const int &rhs) { return lhs %= rhs; }
  friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};

struct ACAM {
  static constexpr int SZ = 2;
  vector<vector<int>> e = {vector<int>(SZ)};
  vector<int> fail = {0}, end = {0}, fast = {0};  // closest end

  int insert(string &s) {
    int p = 0;
    for (auto c : s) {
      c -= 'a';
      if (!e[p][c]) {
        e.emplace_back(SZ), fail.emplace_back();
        end.emplace_back(), fast.emplace_back();
        e[p][c] = int(e.size()) - 1;
      }
      p = e[p][c];
    }
    end[p]++;
    return p;
  }

  void build() {
    queue<int> q;
    for (int i = 0; i < SZ; i++) {
      if (e[0][i]) q.push(e[0][i]);
    }
    while (!q.empty()) {
      int p = q.front();
      q.pop();
      fast[p] = end[p] ? p : fast[fail[p]];
      for (int i = 0; i < SZ; i++) {
        if (e[p][i]) {
          fail[e[p][i]] = e[fail[p]][i];
          end[e[p][i]] += end[fail[e[p][i]]];
          q.push(e[p][i]);
        } else {
          e[p][i] = e[fail[p]][i];
        }
      }
    }
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  ACAM acam;
  vector<string> a(m);
  for (auto &x : a) cin >> x, acam.insert(x);
  acam.build();
  int k = int(acam.e.size());
  vector<int> good(k, 1);
  for (int i = 0; i < k; i++) {
    if (acam.end[i]) good[i] = 0;
  }
  for (int i = 0; i < k; i++) {
    auto x = i;
    while (x != 0) {
      good[i] &= good[x];
      x = acam.fail[x];
    }
  }
  vector<vector<Z>> trans(k, vector<Z>(k));
  for (int i = 0; i < k; i++) {
    if (!good[i]) continue;
    trans[acam.e[i][0]][i] = 1;
    trans[acam.e[i][1]][i] = 1;
  }

  auto mul = [&](const vector<vector<Z>> &x, const vector<vector<Z>> &y) {
    vector<vector<Z>> res(k, vector<Z>(k));
    for (int i = 0; i < k; i++) {
      for (int kk = 0; kk < k; kk++) {
        for (int j = 0; j < k; j++) {
          res[i][j] += x[i][kk] * y[kk][j];
        }
      }
    }
    return res;
  };

  vector<vector<Z>> res(k, vector<Z>(k));
  for (int i = 0; i < k; i++) res[i][i] = 1;

  for (; n; n /= 2, trans = mul(trans, trans)) {
    if (n & 1) res = mul(res, trans);
  }

  Z out = 0;
  for (int i = 0; i < k; i++) {
    if (good[i]) out += res[i][0];
  }
  cout << out << "\n";
  
  using IntRef = int &;
  int sb = 0;
  const IntRef ccc = sb;
  ccc++;
}
