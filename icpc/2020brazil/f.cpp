#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int game[2] = {}, score[2] = {};
  int send = 0, winner = -1;
  string s;
  cin >> s;
  for (auto& c : s) {
    if (c == 'S') {
      score[send]++;
    } else if (c == 'R') {
      score[!send]++, send = !send;
    } else {
      if (winner != -1) {
        if (winner == 0) {
          cout << game[0] << " (winner) - " << game[1] << "\n";
        } else {
          cout << game[0] << " - " << game[1] << " (winner)\n";
        }
      } else {
        if (send == 0) {
          cout << game[0] << " (" << score[0] << "*) - " << game[1] << " (" << score[1] << ")\n";
        } else {
          cout << game[0] << " (" << score[0] << ") - " << game[1] << " (" << score[1] << "*)\n";
        }
      }
    }
    if (score[send] >= 10 || (score[send] >= 5 && (score[send] - score[!send]) >= 2)) {
      game[send]++;
      score[0] = 0, score[1] = 0;
    }
    if (game[send] >= 2) {
      winner = send;
    }
  }
}
