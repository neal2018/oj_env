#include <bits/stdc++.h>
using namespace std;

int main() {
  int nt, np, ns, nr;
  cin >> nt >> np >> ns >> nr;
  vector<vector<int>> penalty(nt, vector<int>(np));
  vector<vector<int>> real_penalty(nt, vector<int>(np));
  vector<int> solved(nt);
  vector<vector<int>> solved_list(nt);
  for (int i = 0; i < ns; i++) {
    int T, p, t, ac;
    cin >> T >> p >> t >> ac;
    T--, p--;
    if (t >= 300) continue;
    if (ac) {
      if (penalty[T][p] == -1) continue;
      solved[T]++;
      solved_list[T].push_back(p);
      real_penalty[T][p] = t + penalty[T][p];
      penalty[T][p] = -1;
    } else {
      penalty[T][p] += 20;
    }
  }
  map<vector<int>, vector<int>> rank;
  for (int i = 0; i < nt; i++) {
    int total = accumulate(real_penalty.begin(), real_penalty.end(), 0);
    vector<int> v{};
    reverse(solved_list[i].begin(), solved_list[i].end());
  }
}