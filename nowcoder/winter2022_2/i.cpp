#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string good = "\"!\'*+-.08:=^_WTYUIOAHXVM|";
  vector<pair<char, char>> pp = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'\\', '/'}, {'<', '>'}};
  int gz = (int)good.size();
  int pz = (int)pp.size();
  int n, m;
  cin >> n >> m;
  int tt = m;
  if (m > min(n / 2, pz) * 2 + min(gz, max(0, (n - min(n / 2, pz) * 2 + 1) / 2))) {
    cout << "-1\n";
    return 0;
  }
  if (n % 2 == 0) {
    string s(n, '?');
    int left = 0, right = n - 1, ppp = 0;
    for (; ppp < pz; ppp++) {
      if (m <= 1) break;
      s[left++] = pp[ppp].first;
      s[right--] = pp[ppp].second;
      m -= 2;
    }
    if (m == 0) {
      ppp--;
      while (left < right) {
        s[left++] = pp[ppp].first;
        s[right--] = pp[ppp].second;
      }
    } else {
      int cur = 0;
      for (; cur < gz; cur++) {
        if (m == 0) break;
        s[left++] = good[cur];
        s[right--] = good[cur];
        m--;
      }
      if (cur) cur--;
      for (int i = left; i <= right; i++) s[i] = good[cur];
    }
    cout << s << "\n";
  } else {
    string s(n, '?');
    int left = 0, right = n - 1, ppp = 0;
    for (; ppp < pz; ppp++) {
      if (m <= 2) break;
      s[left++] = pp[ppp].first;
      s[right--] = pp[ppp].second;
      m -= 2;
    }
    if (m == 0) {
    } else {
      int cur = 0;
      for (; cur < gz; cur++) {
        if (m == 0) break;
        s[left++] = good[cur];
        s[right--] = good[cur];
        m--;
      }
      if (cur) cur--;
      for (int i = left; i <= right; i++) s[i] = good[cur];
    }
    cout << s << "\n";
  }
}