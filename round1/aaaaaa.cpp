#include <algorithm>
#include <cstring>
#include <iostream>

#define MAXN 500
#define MAXM 500

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
        if(grid[i][j] == '#' || to[i][j] <= 0) continue;
        if(i < n - 1) to[i + 1][j] = max(to[i + 1][j], to[i][j] + 1);
        if(j < m - 1) to[i][j + 1] = max(to[i][j + 1], to[i][j] + 1);
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

    memset(from, 0, sizeof(from));

    for(int i = n - 1; i >= 0; i--) {
      for(int j = m - 1; j >= 0; j--) {
        if(grid[i][j] == '#') continue;
        if(!from[i][j]) from[i][j] = 1;

        if(i > 0) from[i - 1][j] = max(from[i - 1][j], from[i][j] + 1);
        if(j > 0) from[i][j - 1] = max(from[i][j - 1], from[i][j] + 1);
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

        if(j < m - 2) {
          // queue up from (i, j + 1) to (i - k, j + 1)
          for(int k = 0; k <= i && grid[i - k][j + 1] != '#'; k++) {
            maxQueue = max(maxQueue,
              to[i][j] + k + 1 +
              (grid[i - k][j + 2] == '#' ? 0 : from[i - k][j + 2]));
          }
        }
        if(i < n - 2) {
          // queue left from (i + 1, j) to (i + 1, j - k)
          for(int k = 0; k <= j && grid[i + 1][j - k] != '#'; k++) {
            maxQueue = max(maxQueue,
              to[i][j] + k + 1 +
              (grid[i + 2][j - k] == '#'? 0 : from[i + 2][j - k]));
          }
        }
      }
    }

    cout << "Case #" << tc << ": " << maxQueue << endl;
  }
  return 0;
}
