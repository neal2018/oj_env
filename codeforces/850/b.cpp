#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  map<char, int> tran = {{'w', 0}, {'i', 1}, {'n', 2}};
  map<int, char> rev = {{0, 'w'}, {1, 'i'}, {2, 'n'}};
  while (T--) {
    int n;
    cin >> n;
    array<array<vector<int>, 3>, 3> need;

    for (int id = 0; id < n; id++) {
      string s;
      cin >> s;
      array<int, 3> freq{};
      for (auto& c : s) freq[tran[c]]++;
      for (int i = 0; i < 3; i++) {
        if (freq[i] == 3) {
          for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            need[i][j].push_back(id);
          }
          break;
        }
        if (freq[i] == 2) {
          for (int j = 0; j < 3; j++) {
            if (freq[j] != 0) continue;
            need[i][j].push_back(id);
          }
          break;
        }
      }
    }
    vector<tuple<int, char, int, char>> res;
    vector<array<int, 2>> poss = {{0, 1}, {0, 2}, {1, 2}};
    for (auto& [i, j] : poss) {
      while (need[i][j].size() > 0 && need[j][i].size() > 0) {
        res.push_back({need[i][j].back(), rev[i], need[j][i].back(), rev[j]});
        need[i][j].pop_back();
        need[j][i].pop_back();
      }
    }
    while (need[0][1].size()) {
      int x = need[0][1].back();  // wwn
      int y = need[1][2].back();  // iiw
      int z = need[2][0].back();  // nni
      res.push_back({x, 'w', y, 'i'});
      res.push_back({y, 'w', z, 'n'});
      need[0][1].pop_back();  // wwn
      need[1][2].pop_back();  // iiw
      need[2][0].pop_back();  // nni
    }
    while (need[1][0].size()) {
      int x = need[1][0].back();  // iin
      int y = need[2][1].back();  // nnw
      int z = need[0][2].back();  // wwi
      res.push_back({x, 'i', z, 'w'});
      res.push_back({z, 'i', y, 'n'});
      need[1][0].pop_back();  // iin
      need[2][1].pop_back();  // nnw
      need[0][2].pop_back();  // wwn
    }

    cout << res.size() << "\n";
    for (auto& [x, y, z, k] : res) {
      cout << x + 1 << " " << y << " " << z + 1 << " " << k << "\n";
    }
  }
}
