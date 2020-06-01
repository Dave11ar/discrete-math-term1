#include<bits/stdc++.h>

using namespace std;

int n, k;
long long m;
vector<int> ans;
long long C[40][40];

void sol(int first) {
  if (k == 0) {
    return;
  }

  int lastGood = first;
  long long lost = 0;
  for (int i = first; i <= n; i++) {
    long long cur = C[n - i][k - 1];
    if (lost + cur  <= m) {
      lost += cur;
    } else {
      lastGood = i;
      break;
    }
  }

  ans.push_back(lastGood);
  m -= lost;
  k--;
  sol(lastGood + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  freopen("num2choose.in", "r", stdin);
  freopen("num2choose.out", "w", stdout);

  cin >> n >> k >> m;
  C[0][0]= 1;

  for (int i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }

  sol(1);

  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i] << ' ';
  }

  return 0;
}
