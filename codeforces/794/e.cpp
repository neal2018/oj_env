#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    string s;
    cin >> n >> s;
    ll swp = 0, cnt_i = 0, cnt_j = 0;
    vector<pair<int, int>> res;
    char a = '(', b = ')';
    for (ll i = 0, j = 2 * n - 1; i < j;) {
      while (i < j && cnt_i >= 0) {
        cnt_i += (s[i] == a ? 1 : -1);
        i++;
      }
      while (i < j && cnt_j >= 0) {
        cnt_j += (s[j] == b ? 1 : -1);
        j--;
      }
      if (i != j) {
        swp ^= 1;
        res.push_back({i - 1, j + 1});
        cnt_i = 0, cnt_j = 0;
        swap(a, b);
      }
    }
    cout << res.size() << "\n";
    for (auto& [x, y] : res) {
      cout << x + 1 << " " << y + 1 << "\n";
    }
  }
}
