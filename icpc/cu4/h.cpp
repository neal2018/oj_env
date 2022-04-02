#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    string pre = s.substr(0, x), remain = s.substr(x);
    reverse(pre.begin(), pre.end());
    reverse(remain.begin(), remain.end());
    s = pre + remain;
    cout << s << "\n";
  }
}