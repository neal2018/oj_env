#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int T, n;
  cin >> T;
  string enemy, mine;
  while (T--) {
    cin >> n >> enemy >> mine;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (mine[i] == '0') continue;
      if (enemy[i] == '0') {
        cnt++;
      } else {
        if (i > 0 && enemy[i - 1] == '1') {
          cnt++;
          enemy[i - 1] = '2';
        } else if (i < n - 1 && enemy[i + 1] == '1') {
          cnt++;
          enemy[i + 1] = '2';
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
