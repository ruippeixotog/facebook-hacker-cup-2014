#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

#define ll long long

#define MAXN 1000000
#define MAXM 1000000

using namespace std;

int n, m;
ll x1, a1, b1, c1, r1;
ll x2, a2, b2, c2, r2;

int board1[MAXN], board2[MAXM];

void gen() {
  set<int> seen1, seen2;
  vector<int> rep1, rep2;

  board1[0] = x1; seen1.insert(x1);
  board2[0] = x2; seen2.insert(x2);

  for(int i = 1; i < max(n, m); i++) {
    if(i < n) {
      board1[i] = (a1 * board1[(i - 1) % n] + b1 * board2[(i - 1) % m] + c1) % r1;
      if(seen1.count(board1[i])) rep1.push_back(i); 
      else { seen1.insert(board1[i]); }
    }
    if(i < m) {
      board2[i] = (a2 * board1[(i - 1) % n] + b2 * board2[(i - 1) % m] + c2) % r2;
      if(seen2.count(board2[i])) rep2.push_back(i);
      else { seen2.insert(board2[i]); }
    }
  }

  for(int i = 0; i < (int) rep1.size(); i++) board1[rep1[i]] = -1;
  for(int i = 0; i < (int) rep2.size(); i++) board2[rep2[i]] = -1;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> n >> m;
    cin >> x1 >> a1 >> b1 >> c1 >> r1;
    cin >> x2 >> a2 >> b2 >> c2 >> r2;

    gen();

    ll count = 0;
    int seenSize1 = 0;
    set<int> seen2;

    for(int i1 = 0, i2 = 0; i1 < n; i1++) {
      if(board1[i1] == -1) continue;

      int pairs = 0;

      seenSize1++;
      while(i2 < m && !seen2.count(board1[i1])) {
        int color = board2[i2++];
        if(color != -1) seen2.insert(color);
      }

      if(i2 == m && !seen2.count(board1[i1])) break;

      if(seenSize1 == (int) seen2.size()) {
        pairs++;
        while(i2 < m && board2[i2] == -1) { pairs++; i2++; }

        count += pairs;
        i1++;
        while(i1 < n && board1[i1] == -1) {
          count += pairs; i1++;
        }
        i1--;
      }
    }

    cout << "Case #" << tc << ": " << count << endl;
  }
  return 0;
}
