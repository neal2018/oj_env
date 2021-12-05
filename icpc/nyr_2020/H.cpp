#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
typedef long long ll;
typedef pair<int, int> ii;

void pr(int a) {
  string s = to_string(a);
  cout << s;
  FOR(j, 4 - s.length()) cout << ' ';
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int solved[105][25];
  int penalty[105][25];
  int totalPenalty[105];
  int problemsSolved[105];
  vector<int> solveOrder[105];
  memset(solved, 0, sizeof solved);
  memset(penalty, 0, sizeof penalty);
  memset(totalPenalty, 0, sizeof totalPenalty);
  memset(problemsSolved, 0, sizeof problemsSolved);

  map<vector<int>, vector<int>> data;

  int nt, np, ns, nr;
  cin >> nt >> np >> ns >> nr;

  FOR(i, ns) {
    int team, problem, time, ac;
    cin >> team >> problem >> time >> ac;
    if (solved[team][problem]) continue;
    if (time >= 300) continue;
    if (ac) {
      solved[team][problem] = 1;
      penalty[team][problem] += time;
      problemsSolved[team]++;
      totalPenalty[team] += penalty[team][problem];
      solveOrder[team].push_back(problem);
    } else {
      penalty[team][problem] += 20;
    }
  }

  for (int i = 1; i <= nt; i++) {
    vector<int> create = {problemsSolved[i], -totalPenalty[i]};
    while (!solveOrder[i].empty()) {
      int problem = solveOrder[i].back();
      create.push_back(-penalty[i][problem]);
      solveOrder[i].pop_back();
    }
    data[create].push_back(i);
  }

  int place = 1;
  for (auto it = data.rbegin(); it != data.rend(); it++) {
    vector<int> key = it->first;
    vector<int> teams = it->second;
    if (place <= nr) {
      for (int team : teams) {
        pr(place);
        pr(team);
        printf("%3d", key[0]);
        printf("%5d\n", key[1]);
      }
    }
    place += teams.size();
  }
}
