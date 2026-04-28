# 差の判定（if / else）

2つの整数を入力し、差がゼロかどうかを判定する。

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, y;
    cin >> x >> y;
    if (x - y == 0) cout << "diff zero" << endl;
    else             cout << "diff not zero" << endl;
}
```

## ポイント

- `cin >> x >> y` で複数の値を空白区切りで受け取る
- `x - y == 0` は `x == y` と同義。直感的なほうを選ぶと良い
- 単文の `if / else` は `{}` を省略できるが、複数行になる場合は必ず付ける
