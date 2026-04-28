# 配列の入力（vector + cin）

n 個の整数を cin で読み込んで vector に格納するパターン。競技プログラミングで最頻出。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);       // サイズ n の vector を確保（初期値 0）
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
```

> **誤字メモ**: 元ファイルに `vecvor<int>` という typo がある。正しくは `vector<int>`。

## ワンライナー入力（競プロ頻出）

```cpp
int n; cin >> n;
vector<int> a(n);
for (auto& x : a) cin >> x;  // 範囲 for + 参照で簡潔に書ける
```

## サイズ指定の初期化パターン

```cpp
vector<int> a(n);      // n 個、全て 0
vector<int> b(n, -1);  // n 個、全て -1
vector<int> c = {1, 2, 3};  // 直接初期化
```
