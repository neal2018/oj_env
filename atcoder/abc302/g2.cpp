#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto get_freq(const vector<int>& a) {
  auto n = a.size();
  auto b = a;
  sort(b.begin(), b.end());
  array<array<int, 4>, 4> freq{};

  for (int i = 0; i < n; i++) {
    freq[b[i]][a[i]]++;
  }
  return freq;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x, x--;
  auto freq = get_freq(a);
  ll res = 0;
  vector<vector<int>> pers = {{2, 1},       {3, 1},       {4, 1},       {3, 2},       {4, 2},
                              {4, 3},       {2, 3, 1},    {3, 1, 2},    {2, 4, 1},    {4, 1, 2},
                              {3, 4, 2},    {4, 2, 3},    {3, 4, 1},    {4, 1, 3},    {2, 3, 4, 1},
                              {4, 1, 2, 3}, {4, 3, 1, 2}, {2, 4, 1, 3}, {3, 4, 2, 1}, {3, 1, 4, 2}};
  for (auto& per : pers) {
    for (auto& x : per) x--;
    auto cur_freq = get_freq(per);
    int mini = 1e9;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (cur_freq[i][j]) {
          mini = min(mini, freq[i][j]);
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (cur_freq[i][j]) {
          freq[i][j] -= mini;
        }
      }
    }
    res += 1ll * mini * (int(per.size()) - 1);
  }
  cout << res << "\n";
}
