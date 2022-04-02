#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> strs(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    // cout << s << "\n";
    stringstream ss(s);
    string tt;
    string res;
    while (getline(ss, tt, '.')) {
      // cout<<tt<<"\n";
      int num = stoi(tt);
      bitset<8> b(num);
      res += b.to_string();
    }
    strs[i] = res;
  }
  string lcp = strs[0];
  int nn = int(strs.size()), res = int(lcp.size());
  for (int i = 1; i < nn; i++) {
    int m = int(strs[i].size());
    res = min(res, m);
    for (int j = 0; j < res; j++) {
      if (strs[i][j] != lcp[j]) {
        res = min(res, j);
        break;
      }
    }
  }
  if (res == 0) res = 32;
  cout << res << "\n";
}