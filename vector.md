# vector チートシート

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int>    a;              // 空の vector
vector<double> b(5, 0);       // {0,0,0,0,0}: サイズ 5、全て 0 で初期化
vector<int>    c = {1, 2, 3}; // 直接初期化
```

## アクセス

```cpp
a[0];           // 先頭要素（インデックスアクセス）
a.front();      // 先頭要素
a[a.size()-1];  // 末尾要素
a.back();       // 末尾要素
```

## 追加・削除

```cpp
a.push_back(1); // 末尾に追加
a.pop_back();   // 末尾を削除（戻り値なし）
a.size();       // 要素数
```

> `pop_back()` は削除するだけで値を返さない。末尾の値が必要なら `a.back()` で先に取得する。

## ループ

```cpp
// インデックス for（size_t との比較に注意して (int) キャスト）
for (int i = 0; i < (int)a.size(); i++) {
    cout << a[i] << endl;
}

// 範囲 for（読み取りのみ）
for (int x : a) {
    cout << x << endl;
}

// 範囲 for（変更あり）
for (int& x : a) {
    x *= 2;
}
```

## よく使うその他の操作

```cpp
a.empty();              // 空かどうか
a.clear();              // 全要素削除
sort(a.begin(), a.end());   // 昇順ソート
reverse(a.begin(), a.end()); // 逆順
```
