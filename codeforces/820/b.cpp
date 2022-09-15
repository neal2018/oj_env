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
    string res;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') {
        res += char((s[i - 2] - '0') * 10 + (s[i - 1] - '0') - 1 + 'a');
        i -= 2;
      } else {
        res += s[i] - '1' + 'a';
      }
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
  }
}
