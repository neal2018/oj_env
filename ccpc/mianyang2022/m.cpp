#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  map<char, char> win{{'R', 'P'}, {'S', 'R'}, {'P', 'S'}};
  while (T--) {
    string s;
    cin >> s;
    vector<char> stk;
    for (auto& c : s) {
      while (stk.size() && win[stk.back()] == c) {
        stk.pop_back();
      }
      stk.push_back(c);
    }
    cout << stk[0] << "\n";
  }
}
