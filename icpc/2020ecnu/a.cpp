#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n1, n2;
  cin >> n1;
  vector<string> v1(n1);
  for (auto& x : v1) cin >> x;
  cin >> n2;
  vector<string> v2(n2);
  for (auto& x : v2) cin >> x;
  if (n1 > n2) {
    cout << "Cuber QQ\n";
  } else {
    cout << "Quber CC\n";
  }
}
