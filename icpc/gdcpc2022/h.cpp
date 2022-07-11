#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<string> a = {"Zi", "Chou", "Yin",  "Mao", "Chen", "Si",
                      "Wu", "Wei",  "Shen", "You", "Xu",   "Hai"};
  auto get_digit = [&](const string& s) {
    for (int i = 0; i < a.size(); i++) {
      if (s == a[i]) return i + 1;
    }
    return -1;
  };
  vector<string> b = {"000", "100", "010", "110", "001", "101", "011", "111"};
  string y_s, h_s;
  int m, d;
  cin >> y_s >> m >> d >> h_s;
  int y = get_digit(y_s), h = get_digit(h_s);
  int up_digit = (y + m + d) % 8;
  if (up_digit == 0) up_digit = 8;
  auto up = b[up_digit - 1];
  int down_digit = (y + m + d + h) % 8;
  if (down_digit == 0) down_digit = 8;
  auto down = b[down_digit - 1];
  auto tran = [&](char c) { return c == '1' ? "- -\n" : "---\n"; };
  for (auto& s : up) cout << tran(s);
  for (auto& s : down) cout << tran(s);
  cout << '\n';
  int flip = (y + m + d + h) % 6;
  if (flip == 0) flip = 6;
  flip = 6 - flip;
  if (flip < 3) {
    up[flip] ^= ('0' ^ '1');
  } else {
    down[flip - 3] ^= ('0' ^ '1');
  }
  for (auto& s : up) cout << tran(s);
  for (auto& s : down) cout << tran(s);
}
