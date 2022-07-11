#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    vector<string> res(n, string(n, '='));
    for (int i = 0; i < n; i++) res[i][i] = 'X';
    vector<int> win;
    for (int i = 0; i < n; i++) {
      if (s[i] == '2') win.push_back(i);
    }
    if (win.size() == 1 || win.size() == 2) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0; i < win.size(); i++) {
      int nex = (i + 1) % int(win.size());
      res[win[i]][win[nex]] = '+', res[win[nex]][win[i]] = '-';
    }

    for (auto& x : res) cout << x << "\n";
  }
}
