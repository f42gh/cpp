#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v = {4, 5, 6};

  do {
    cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
  } while (next_permutation(v.begin(), v.end()));
}
