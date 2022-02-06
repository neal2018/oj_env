#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  vector<int> cnt(10);
  for (auto& c : s) {
    if (c != '5') {
      cnt[c - '0']++;
      cnt[5]++;
    }
  }
  for (int i = 1; i < cnt.size(); i++) cout << cnt[i] << " ";
  cout << "\n";
}