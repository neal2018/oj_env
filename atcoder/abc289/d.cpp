#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  int bad = 0;
  string a = s.substr(s.size() - t.size());
  for (int i = 0; i < t.size(); i++) {
    if (a[i] != '?' && t[i] != '?' && a[i] != t[i]) bad++;
  }
  auto print = [&] { cout << (bad ? "No\n" : "Yes\n"); };
  print();
  for (int i = 0; i < t.size(); i++) {
    if (a[i] != '?' && t[i] != '?' && a[i] != t[i]) bad--;
    a[i] = s[i];
    if (a[i] != '?' && t[i] != '?' && a[i] != t[i]) bad++;
    print();
  }
}