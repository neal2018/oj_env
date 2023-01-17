#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  cout << ([&] {
    vector<int> inside(26);
    vector<char> stk;
    for (auto& c : s) {
      if (c == '(') {
        stk.push_back('(');
      } else if (c == ')') {
        while (stk.back() != '(') {
          inside[stk.back() - 'a'] = 0, stk.pop_back();
        }
        stk.pop_back();
      } else {
        if (inside[c - 'a'] == 1) return false;
        inside[c - 'a'] = 1, stk.push_back(c);
      }
    }
    return true;
  }()
               ? "Yes\n"
               : "No\n");
}
