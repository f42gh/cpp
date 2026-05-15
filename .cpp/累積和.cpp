#include<bits/stdc++.h>
using namespace std;

int N, Q, a[10009], s[10009], l[10009], r[10009];

void me(){
  cin >>N >>Q;
  for (int i=0; )
}


int main() {
  cin >>N, Q;
  for (int i=1; i<=N; i++) cin >> a[i];
  for (int j=1; j<=Q; j++) cin >>l[j] >>r[j];
  s[0] =0;
  for (int i=0; i <=N; i++) s[i] =s[i-1] +a[i];

  for (int j=0; j<=1; j++) {
    cout <<s[r[j] -s[l[j]] -1] <<endl;
  }
}
