#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int ask(const string& s) {
  cout << s << endl;
  int res;
  cin >> res;
  if (res == 0) exit(0);
  return res;
}

constexpr ll MAX = 300;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int ask_a = ask(string(MAX, 'a'));  // 300 - #a
  int ask_b = ask(string(MAX, 'b'));  // 300 - #b
  int num_a = MAX - ask_a, num_b = MAX - ask_b, len = num_a + num_b;
  string s = string(len, 'a');
  int cur = num_b;
  for (int i = len - 1; i > 0; i--) {
    s[i] = 'b';
    int tmp = ask(s);
    if (tmp < cur) {
      cur = tmp;
    } else {
      s[i] = 'a';
    }
  }
  if (count(s.begin(), s.end(), 'a') != num_a) s[0] = 'b';
  cout << s << endl;
}
