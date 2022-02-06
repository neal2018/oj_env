#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<int> power10(8, 1);
  for (int i = 0; i < 7; i++) power10[i + 1] = 10 * power10[i];
  int n, m, d;
  cin >> n >> m >> d;
  auto cnt = [&](int x) {
    int val = 0;
    while (x) val += (x % 10 > 0), x /= 10;
    return val;
  };
  auto reorder = [&](int x) {
    array<int, 5> temp = {};
    for (int i = 0; i < 5; i++) temp[i] = (x / power10[i]) % 10;
    sort(temp.begin(), temp.end());
    int res = 0;
    for (int i = 0; i < 5; i++) res *= 10, res += temp[i];
    return res;
  };
  int total = 0;
  array<int, 5> my = {}, eny = {};
  for (int i = 0; i < n; i++) cin >> my[i], total += my[i];
  for (int i = 0; i < m; i++) cin >> eny[i], total += eny[i];
  map<array<int, 3>, ld> mp;
  function<ld(int, int, int)> dfs = [&](int mine, int ene, int remain) {
    int my_cnt = cnt(mine), ene_cnt = cnt(ene);
    if (ene_cnt == 0) return (ld)1.0;
    if (my_cnt == 0) return total > d ? (ld)0.0 : (ld)1.0;
    if (remain == 0) return (ld)0.0;
    mine = reorder(mine), ene = reorder(ene);
    if (mp.count({mine, ene, remain})) return mp[{mine, ene, remain}];
    ld res = 0;
    for (int i = 0; i < 5; i++) {
      if ((ene / power10[i]) % 10 != 0) {
        res += dfs(mine, ene - power10[i], remain - 1);
      }
      if ((mine / power10[i]) % 10 != 0) {
        res += dfs(mine - power10[i], ene, remain - 1);
      }
    }
    res /= (my_cnt + ene_cnt);
    return mp[{mine, ene, remain}] = res;
  };
  cout << fixed << setprecision(15);
  int mine = 0, ene = 0;
  sort(my.begin(), my.end());
  sort(eny.begin(), eny.end());
  for (int i = 0; i < 5; i++) mine *= 10, mine += my[i];
  for (int i = 0; i < 5; i++) ene *= 10, ene += eny[i];
  cout << dfs(mine, ene, d) << "\n";
}
