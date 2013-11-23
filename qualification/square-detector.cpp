#include <iostream>

#define MAXN 20

using namespace std;

char img[MAXN][MAXN];

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++)
        cin >> img[i][j];
    }

    int i0 = -1, j0, i1, j1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(img[i][j] == '#') {
          if(i0 == -1) { i0 = i; j0 = j; }
          i1 = i; j1 = j;
        }
      }
    }

    bool fail = (i1 - i0 != j1 - j0);

    for(int i = 0; i < n && !fail; i++) {
      for(int j = 0; j < n; j++) {
        char expected = i >= i0 && i <= i1 &&
          j >= j0 && j <= j1 ? '#' : '.';

        if(img[i][j] != expected) {
          fail = true; break;
        }
      }
    }
    cout << "Case #" << tc << (fail ? ": NO" : ": YES") << endl;
  }
  return 0;
}
