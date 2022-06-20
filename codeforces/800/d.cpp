#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    int n;
    cin >> s >> n;
    int dh = n / 60, dm = n % 60;
    int h = stoi(s.substr(0, 2)), m = stoi(s.substr(3));
    int hh = h, mm = m;
    auto start = s;
    set<pair<int, int>> st;
    if (h / 10 == m % 10 && h % 10 == m / 10) {
      st.insert({h, m});
    }
    while (true) {
      h += dh, m += dm;
      if (m >= 60) m -= 60, h += 1;
      h = h % 24;
      if (h / 10 == m % 10 && h % 10 == m / 10) {
        st.insert({h, m});
      }
      if (h == hh && m == mm) break;
    }
    cout << st.size() << "\n";
  }
}
