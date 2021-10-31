#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> solve(const string& s) {
  vector<int> res(26);
  int n = s.size();
  int prev = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      int cnt = 0;
      for (i++; s[i] != ')'; i++) {
        cnt = cnt * 10 + (s[i] - '0');
      }
      res[prev] += cnt - 1;
    } else {
      if (i < n - 2 && s[i + 2] == '#') {
        prev = 10 * (s[i] - '0') + (s[i + 1] - '0');
        res[--prev]++;  // offset to 0 index
        i += 2;
      } else {
        prev = (s[i] - '0');
        res[--prev]++;
      }
    }
  }
  return res;
}

int main() {
  string s = "1226#24#(1000)";
  auto res = solve(s);
  for (auto& x : res) cout << x << " ";
  cout << endl;
}