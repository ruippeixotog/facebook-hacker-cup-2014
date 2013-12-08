#include <iostream>

#define ll long long

#define MAXN 20

using namespace std;

int n, k, A[MAXN];
int minFact[MAXN];

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

bool existsSol(int i, ll currProd, int currSum, int maxSum) {
  if(currSum > maxSum) return false;
  if(i == n) return true;

  int fact = minFact[i];
  for(fact = minFact[i]; currSum + fact <= maxSum; fact++) {
    if(gcd(currProd, fact) != 1) continue;
    if(existsSol(i + 1, currProd * fact, currSum + fact, maxSum))
      return true;
  }
  return false;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> n >> k;

    int sum = 0, factSum = 0;
    for(int i = 0; i < n; i++) {
      cin >> A[i];
      sum += A[i];
      minFact[i] = (A[i] + k - 1) / k; // ceil(A[i] / k)
      factSum += minFact[i];
      cerr << "min value of " << A[i] << " is " << (minFact[i] * k) << endl;
    }

    cerr << "--" << endl;

    int s = 0;
    while(true) {
      cerr << "Trying sum of " << ((factSum + s) * k) << endl;
      if(existsSol(0, 1, 0, factSum + s)) break;
      s++;
    }
    cerr << "--" << endl;

    int diff = (factSum + s) * k - sum;
    cout << "Case #" << tc << ": " << diff << endl;
  }
  return 0;
}
