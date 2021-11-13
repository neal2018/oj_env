#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
const ll MOD = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  string s;
  cin >> T;
  while (T--) {
    cin >> n >> s;
    int res = 1e9;
    vector<int> a;
    for (int i = 0; i < n; i++)
      if (s[i] == 'a') a.push_back(i);
    for (int i = 0; i < (int)a.size() - 2; i++) {
      int cnt[3] = {0, 0, 0};
      for (int j = a[i]; j <= a[i + 2]; j++) cnt[s[j] - 'a']++;
      if (cnt[0] > cnt[1] && cnt[0] > cnt[2]) res = min(res, a[i + 2] - a[i] + 1);
    }
    for (int i = 0; i < n - 3; i++)
      if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 1] != s[i + 2]) res = 4;
    for (int i = 0; i < n - 2; i++)
      if (s[i] == 'a' && s[i + 2] == 'a') res = 3;
    for (int i = 0; i < n - 1; i++)
      if (s[i] == 'a' && s[i + 1] == 'a') res = 2;
    cout << (res == 1e9 ? -1 : res) << '\n';
  }
}