#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k, c;
  cin >> n >> k >> c;
  vector<array<int, 2>> res;
  vector<array<int, 2>> remain;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int id, school;
    cin >> id >> school;
    if (cnt[school] < c && k) {
      res.push_back({i, id});
      cnt[school]++;
      k--;
    } else {
      remain.push_back({i, id});
    }
  }
  reverse(remain.begin(), remain.end());
  while (k && remain.size()) {
    res.push_back(remain.back());
    remain.pop_back();
    k--;
  }
  sort(res.begin(), res.end());
  for (auto& [rank, id] : res) cout << id << "\n";
}
