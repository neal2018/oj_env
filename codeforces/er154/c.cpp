#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int cnt = 0;
    vector<int> bad, good;
    if ([&] {
          for (auto& c : s) {
            if (c == '+') {
              cnt++;
            } else if (c == '-') {
              cnt--;
              while (bad.size() && bad.back() > cnt) bad.pop_back();
              bool is_good = false;
              while (good.size() && good.back() > cnt) good.pop_back(), is_good = true;
              if (is_good) good.push_back(cnt);
            } else if (c == '1') {
              if (bad.size()) return false;
              good.push_back(cnt);
            } else {
              if (cnt < 2) return false;
              if (good.size() && good.back() == cnt) return false;
              bad.push_back(cnt);
            }
          }
          return true;
        }()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
