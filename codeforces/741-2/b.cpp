#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool kmp(string txt, string pat) {
  int n = txt.size(), m = pat.size();
  vector<vector<int> > dp(n + 1, vector<int>(m + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (txt[i] == pat[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }
  return dp[n][m] == m;
}

int main() {
  ll T, k;
  vector<int> a{1};
  auto prime = [](int x) {
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        return false;
      }
    }
    return true;
  };
  for (int i = 2; i < 1e5; i++) {
    if (!prime(i)) {
      a.push_back(i);
    }
  }
  string s;
  cin >> T;
  while (T--) {
    cin >> k >> s;
    for (auto& x : a) {
      string t = to_string(x);
      if (kmp(s, t)) {
        cout << t.size() << endl;
        cout << t << endl;
        break;
      }
    }
  }
}