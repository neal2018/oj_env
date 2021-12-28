#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string x;
  cin >> x;
  reverse(x.begin(), x.end());
  ll sum = 0;
  for (auto& c : x) sum += c - '0';
  vector<ll> res(x.size() + 1);
  for (int i = 0; i < x.size(); i++) {
    res[i] = sum, sum -= x[i] - '0';
  }
  for (int i = 0; i < x.size(); i++) {
    res[i + 1] += res[i] / 10;
    res[i] %= 10;
  }
  while (res.back() == 0) res.pop_back();
  reverse(res.begin(), res.end());
  for (auto& c : res) cout << c;
  cout << "\n";
}