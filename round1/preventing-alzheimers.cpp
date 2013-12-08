#include <algorithm>
#include <ctime>
#include <iostream>

#define ll long long

#define MAXN 20

using namespace std;

int n, k, A[MAXN];
int minFact[MAXN], tailFactSum[MAXN + 1];

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}

int it;

bool existsSolAux(int i, ll currProd, ll currProd2, int lastFact, int currSum, int maxSum) {
  if(i == n) return true;
  it++;

  int startFact = max(minFact[i], lastFact);
  int maxFact = maxSum - currSum - tailFactSum[i + 1];
  if(startFact <= 1) maxFact = min(maxFact, 1);

  for(int fact = startFact; fact <= maxFact; fact++) {
    if(gcd(currProd, fact) != 1 || gcd(currProd2, fact) != 1) continue;
    if(existsSolAux(i + 1,
      i < MAXN / 2 ? currProd * fact : currProd,
      i >= MAXN / 2 ? currProd2 * fact : currProd2,
      fact,
      currSum + fact,
      maxSum)) { cerr << fact << " "; return true; }
  }
  return false;
}

inline bool existsSol(int maxSum) {
  it = 0;
  bool res = existsSolAux(0, 1, 1, 0, 0, maxSum);
  // cerr << it << " iterations for maxSum " << (maxSum * k) << endl;
  return res;
}

int existsSolGreedyAux(int i, ll currProd, ll currProd2, int lastFact, int currSum) {
  if(i == n) return currSum;
  it++;

  int startFact = max(minFact[i], lastFact);
  int maxFact = 0x3f3f3f3f;
  if(startFact <= 1) maxFact = min(maxFact, 1);

  for(int fact = startFact; fact <= maxFact; fact++) {
    if(gcd(currProd, fact) != 1 || gcd(currProd2, fact) != 1) continue;
    int res = existsSolGreedyAux(i + 1,
      i < MAXN / 2 ? currProd * fact : currProd,
      i >= MAXN / 2 ? currProd2 * fact : currProd2,
      fact,
      currSum + fact);
    if(res >= 0) { cerr << fact << " "; return res; }
  }
  return -1;
}

inline int existsSolGreedy() {
  it = 0;
  int res = existsSolGreedyAux(0, 1, 1, 0, 0);
  cerr << endl;
  return res;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
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

    cerr << "Case " << tc << " -- GREEDY" << endl;
    int newFactSumGr = existsSolGreedy();
    cerr << "-- cost: " << (newFactSumGr * k) << endl;

    int fs;
    cerr << "Case " << tc << " -- BACKTRACKING" << endl;
    ll timeout = time(NULL) + 20;
    for(fs = tailFactSum[0]; time(NULL) < timeout; fs++) {
      if(existsSol(fs)) { cerr << endl; timeout = 0; break; }
    }
    int newFactSum = timeout != 0 ? -1 : fs;
    cerr << "-- cost: " << (newFactSum * k) << endl;

    int diff = (newFactSum < 0 ? newFactSumGr : newFactSum) * k - sum;
    cout << "Case #" << tc << ": " << diff << endl;
  }
  return 0;
}
