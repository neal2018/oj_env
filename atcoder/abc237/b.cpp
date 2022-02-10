#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> b(w, vector<int>(h));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> b[j][i];
    }
  }
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      cout << b[i][j] << " \n"[j == h - 1];
    }
  }
}
