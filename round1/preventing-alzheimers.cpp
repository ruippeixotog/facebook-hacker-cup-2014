#include <algorithm>
#include <ctime>
#include <iostream>

#define ll long long

#define MAXN 20

#define INF 0x3f3f3f3f

using namespace std;

int n, k, A[MAXN];
int minFact[MAXN], tailFactSum[MAXN + 1];

int it; ll timeout;
int bestSum;

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}

void findSolAux(int i, ll currProd, ll currProd2, int lastFact, int currSum) {
  if(i == n) {
    bestSum = min(bestSum, currSum);
    return;
  }

  int startFact = max(minFact[i], lastFact);
  int maxFact = bestSum - currSum - tailFactSum[i + 1];
  if(startFact <= 1) maxFact = min(maxFact, 1);

  for(int fact = startFact; fact <= maxFact && time(NULL) < timeout; fact++) {
    if(gcd(currProd, fact) != 1 || gcd(currProd2, fact) != 1) continue;
    findSolAux(i + 1,
      i < MAXN / 2 ? currProd * fact : currProd,
      i >= MAXN / 2 ? currProd2 * fact : currProd2,
      fact,
      currSum + fact);
    maxFact = min(maxFact, bestSum - currSum - tailFactSum[i + 1]);
  }
}

inline void findSol() {
  bestSum = INF;
  timeout = time(NULL) + 15;
  findSolAux(0, 1, 1, 0, 0);
  if(time(NULL) >= timeout) cerr << "timeout!" << endl;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cerr << "Running test case " << tc << "..." << endl;

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> A[i];
    sort(A, A + n);

    int sum = 0;
    for(int i = 0; i < n; i++) {
      sum += A[i];
      minFact[i] = (A[i] + k - 1) / k; // ceil(A[i] / k)
    }

    tailFactSum[n] = 0;
    for(int i = n - 1; i >= 0; i--)
      tailFactSum[i] = minFact[i] + tailFactSum[i + 1];

    findSol();

    int diff = bestSum * k - sum;
    cout << "Case #" << tc << ": " << diff << endl;
  }
  return 0;
}
