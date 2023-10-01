#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> aa(n - 1);
  for (auto& x : aa) cin >> x;
  sort(aa.begin(), aa.end());
  if (aa[0] < a || aa.back() > b) {
    cout << "-1\n";
    return 0;
  }
  if (aa[0] != a && aa.back() != b) {
    cout << "-1\n";
    return 0;
  }
  if (aa[0] != a) {
    cout << a << "\n";
    return 0;
  }
  if (aa.back() != b) {
    cout << b << "\n";
    return 0;
  }
  for (int i = a; i <= b; i++) cout << i << "\n";
}
