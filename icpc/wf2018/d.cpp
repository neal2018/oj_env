#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int one = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      zero = i;
    else
      one = i;
  }
  swap(s[one], s[zero]);
  cout << s << "\n";
}