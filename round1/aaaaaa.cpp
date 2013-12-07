#include <algorithm>
#include <cstring>
#include <iostream>

#define MAXN 500
#define MAXM 500

#define INF 0x3f3f3f3f

using namespace std;

char grid[MAXN][MAXM];

int to[MAXN][MAXM], from[MAXN][MAXM];

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++)
        cin >> grid[i][j];
    }

    memset(to, -0x3f, sizeof(to));
    to[0][0] = 1;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(grid[i][j] == '#' || to[i][j] > 0) continue;
        to[i][j] = max(
          i == 0 ? -INF : to[i - 1][j],
          j == 0 ? -INF : to[i][j - 1]) + 1;
      }
    }

    // cerr << "TO" << endl;
    // for(int i = 0; i < n; i++) {
    //   for(int j = 0; j < m; j++) {
    //     if(grid[i][j] == '#') cerr << "# ";
    //     else cerr << to[i][j] << " ";
    //   }
    //   cerr << endl;
    // }

    memset(from, -0x3f, sizeof(from));

    for(int i = n - 1; i >= 0; i--) {
      for(int j = m - 1; j >= 0; j--) {
        if(grid[i][j] == '#') continue;
        from[i][j] = max(1, max(
          i == n - 1 ? -INF : from[i + 1][j],
          j == m - 1 ? -INF : from[i][j + 1]) + 1);
      }
    }

    // cerr << "FROM" << endl;
    // for(int i = 0; i < n; i++) {
    //   for(int j = 0; j < m; j++) {
    //     if(grid[i][j] == '#') cerr << "# ";
    //     else cerr << from[i][j] << " ";
    //   }
    //   cerr << endl;
    // }

    int maxQueue = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(grid[i][j] == '#') continue;
        maxQueue = max(maxQueue, to[i][j]);

        // queue upwards from (i, j) to (i - k, j)
        for(int k = 0; k <= i && grid[i - k][j] != '#'; k++) {
          int before = (j == 0 ? -INF : to[i][j - 1]);
          int after = (j == m - 1 ? 0 : max(0, from[i - k][j + 1]));
          maxQueue = max(maxQueue, before + k + 1 + after);
        }

        // queue leftwards from (i, j) to (i, j - k)
        for(int k = 0; k <= j && grid[i][j - k] != '#'; k++) {
          int before = (i == 0 ? -INF : to[i - 1][j]);
          int after = (i == n - 1 ? 0 : max(0, from[i + 1][j - k]));
          maxQueue = max(maxQueue, before + k + 1 + after);
        }
      }
    }

    cout << "Case #" << tc << ": " << maxQueue << endl;
  }
  return 0;
}
