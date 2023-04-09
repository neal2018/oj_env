#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  auto get_pos = [&](char c) {
    vector<int> res;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == c) {
        res.push_back(i);
      }
    }
    return res;
  };
  auto pos_b = get_pos('B');
  if (pos_b[0] % 2 == pos_b[1] % 2) {
    cout << "No\n";
    return 0;
  }
  auto pos_r = get_pos('R');
  auto pos_k = get_pos('K');
  if (!(pos_r[0] < pos_k[0] && pos_k[0] < pos_r[1])) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
}
