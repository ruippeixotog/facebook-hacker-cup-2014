#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <utility>

#define MAXN 30

#define Player pair<int, pair<int, string> >

using namespace std;

Player players[MAXN];

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

    queue<int> in[2], out[2];
    for(int i = 2 * p - 1; i >= 0; i--) in[i % 2].push(i);
    for(int i = 2 * p; i < n; i++) out[i % 2].push(i);

    for(int i = 0; i < m; i++) {
      out[0].push(in[0].front()); in[0].pop();
      in[0].push(out[0].front()); out[0].pop();
      out[1].push(in[1].front()); in[1].pop();
      in[1].push(out[1].front()); out[1].pop();
    }

    set<string> names;
    while(!in[0].empty()) { names.insert(players[in[0].front()].second.second); in[0].pop(); }
    while(!in[1].empty()) { names.insert(players[in[1].front()].second.second); in[1].pop(); }

    cout << "Case #" << tc << ":";
    for(set<string>::iterator it = names.begin(); it != names.end(); it++)
      cout << " " << *it;
    cout << endl;
  }
  return 0;
}
