#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T >> n;
  ll res_mini = 0, res_maxi = 0;
  while (T--) {
    string s;
    cin >> s;
    {
      int remain_two = n / 4;
      int mini = 0;
      for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && s[i] == s[j];) j++;
        if (s[i] == '0') continue;
        int minus = min(remain_two, (j - i) / 2);
        remain_two -= minus;
        mini += j - i - minus;
      }
      res_mini += mini;
    }
    {
      int remain_two = n / 4;
      vector<int> used(n);
      for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && s[i] == s[j];) j++;
        if (s[i] == '1') continue;
        int len = j - i;
        if (len % 2 == 0) {
          int minus = min(remain_two, (j - i) / 2);
          if (remain_two > minus && i > 0 && used[i - 1] == 0 && j < n && used[j] == 0) {
            used[i - 1] = 1, used[j] = 1, minus++;
          }
          remain_two -= minus;
        } else {
          int minus = min(remain_two, (j - i) / 2);
          if (remain_two > minus && i > 0 && used[i - 1] == 0) {
            used[i - 1] = 1, minus++;
          } else if (remain_two > minus && j < n && used[j] == 0) {
            used[j] = 1, minus++;
          }
          remain_two -= minus;
        }
      }
      res_maxi += count(s.begin(), s.end(), '1') - remain_two;
    }
  }
  cout << res_mini << " " << res_maxi << "\n";
}
