# 三項演算子（条件演算子）

`if / else` を一式で書ける演算子。

## 構文

```
条件 ? 真のときの値 : 偽のときの値
```

## 例

```cpp
#include <iostream>
using namespace std;
int main(){
    int n = 1;
    cout << (n == 0 ? "yes" : "no") << endl;  // no

    n = 0;
    cout << (n == 0 ? "yes" : "no") << endl;  // yes
}
```

## Python との対比

| 言語 | 書き方 |
|---|---|
| C++ | `n == 0 ? "yes" : "no"` |
| Python | `"yes" if n == 0 else "no"` |

## 注意点

- `cout` と一緒に使うときは `(条件 ? A : B)` と括弧で囲む（演算子優先順位のため）
- ネストは可読性が落ちるので避ける。複雑な分岐には `if / else` を使う
