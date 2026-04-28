# 浮動小数点の精度付き出力（printf）

`printf` のフォーマット指定子で小数点以下の桁数を制御する。

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    double d; cin >> d;
    printf("%.16f\n", d);      // 小数点以下 16 桁
    printf("%.16f\n", M_PI);   // π を 16 桁で出力
}
```

> **コードの誤り**: 元ファイルでは `cin <<d`（誤）、`printf("%16", M_PI)`（書式不完全）。
> 正しくは `cin >> d` と `printf("%.16f\n", M_PI)`。

## printf の書式指定

| 書式 | 意味 | 例 |
|---|---|---|
| `%f` | 浮動小数点（デフォルト 6 桁） | `3.141593` |
| `%.nf` | 小数点以下 n 桁 | `%.3f` → `3.142` |
| `%e` | 指数表記 | `3.141593e+00` |
| `%g` | 短い方を自動選択 | |

## cout で精度を指定する方法

```cpp
#include <iomanip>
cout << fixed << setprecision(16) << M_PI << endl;
// 3.1415926535897931
```

競技プログラミングでは `cout << fixed << setprecision(15)` がよく使われる。
