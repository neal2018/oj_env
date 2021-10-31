#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

int main() {
#ifdef LOCAL
  ifstream cin("/Users/neallai/Projects/oj_env/input.txt");
  ofstream cout("/Users/neallai/Projects/oj_env/output.txt");
#endif  // LOCAL
  int T, a, b;
  cin >> T;
  while (T--) {
    cin >> a >> b;
    int m = (a + b) / 2;
    vector<int> res;
    if ((a + b) % 2 == 0) {
      for (int i = m - min(a, b); i <= m + min(a, b); i += 2) {
        res.push_back(i);
      }
    } else {
      for (int i = m - min(a, b); i <= m + min(a, b) + 1; i++) {
        res.push_back(i);
      }
    }
    cout << res.size() << endl;
    for (auto& x : res) cout << x << " ";
    cout << endl;
  }
}
