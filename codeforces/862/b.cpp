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
    int id = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] <= s[id]) id = i;
    }
    auto c = s[id];
    s.erase(s.begin() + id);
    cout << c << s << "\n";
  }
}
