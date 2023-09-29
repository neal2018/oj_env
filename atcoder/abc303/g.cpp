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
  vector<int> per = {0, 1, 2, 3};
  // vector<vector<int>> pers;
  vector<array<array<int, 4>, 4>> freqs;
  vector<int> cnts;

  do {
    auto cur_freq = get_freq(per);
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (i == j) continue;
        if (cur_freq[i][j]) cnt++;
      }
    }
    freqs.push_back(cur_freq);
    cnts.push_back(cnt);
  } while (next_permutation(per.begin(), per.end()));

  vector<int> order(freqs.size());
  iota(order.begin(), order.end(), 0ll);
  sort(order.begin(), order.end(), [&](int i, int j) { return cnts[i] < cnts[j]; });

  for (auto& ii : order) {
    auto cur_freq = freqs[ii];
    auto cnt = cnts[ii];
    if (cnt == 0) continue;
    int mini = 1e9;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (i == j) continue;
        if (cur_freq[i][j]) {
          mini = min(mini, freq[i][j]);
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (i == j) continue;
        if (cur_freq[i][j]) {
          freq[i][j] -= mini;
        }
      }
    }
    res += mini * (cnt - 1);
  }
  cout << res << "\n";
}
