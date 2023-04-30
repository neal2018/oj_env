#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  auto good_cnt = count(s.begin(), s.end(), 'o');
  auto poor_cnt = count(s.begin(), s.end(), 'x');
  cout << ((good_cnt > 0 && poor_cnt == 0) ? "Yes\n" : "No\n");
}
