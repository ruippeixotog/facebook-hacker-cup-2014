#include <algorithm>
#include <iostream>
#include <vector>

#define MAXN 30

using namespace std;

pair<int, pair<int, string> > players[MAXN];

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n, m, p; cin >> n >> m >> p;

    for(int i = 0; i < n; i++) {
      cin >> players[i].second.second >>
        players[i].first >> players[i].second.first;
      players[i].first = -players[i].first;
      players[i].second.first = -players[i].second.first;
    }
    sort(players, players + n);
    for(int i = 0; i < p / 2; i++) {
      swap(players[i * 2], players[(p - i - 1) * 2]);
      swap(players[i * 2 + 1], players[(p - i - 1) * 2 + 1]);
    }

    int rotA = (2 * m) % (n % 2 == 0 ? n : n + 1);
    int rotB = (2 * m + 1) % (n % 2 == 0 ? n : n - 1);

    vector<string> names;
    while(p--) {
      names.push_back(players[rotA].second.second);
      names.push_back(players[rotB].second.second);
      rotA = (rotA + 2) % (n % 2 == 0 ? n : n + 1);
      rotB = (rotB + 2) % (n % 2 == 0 ? n : n - 1);
    }
    sort(names.begin(), names.end());

    cout << "Case #" << tc << ":";
    for(int i = 0; i < (int) names.size(); i++)
      cout << " " << names[i];
    cout << endl;
  }
  return 0;
}
