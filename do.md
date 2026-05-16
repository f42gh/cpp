# do-while 文まとめ（C++）

## 1. 基本形

`do-while` 文は、**先に処理を1回実行してから** 条件を判定するループ。

```cpp
do {
    // 繰り返したい処理
} while (条件式);
```

- `while` と違って、条件が最初から `false` でも **最低1回は実行される**
- 末尾の `while (条件式)` のあとに **`;` が必要**

---

## 2. `while` との違い

```cpp
int x = 0;

while (x > 0) {
    cout << "while" << endl;
}

do {
    cout << "do-while" << endl;
} while (x > 0);
```

この場合:

- `while` は 1 回も実行されない
- `do-while` は 1 回だけ実行される

---

## 3. 典型例

### 1回は必ず入力を受けたい場合

```cpp
int n;

do {
    cin >> n;
} while (n < 0);
```

負の数が来たら再入力させる例。

### メニューを1回は表示したい場合

```cpp
int cmd;

do {
    cout << "1: add, 2: delete, 0: exit" << endl;
    cin >> cmd;
} while (cmd != 0);
```

最初に必ずメニューを表示したいときに向いている。

---

## 4. `break` と `continue`

`do-while` でも `break` と `continue` は使える。

```cpp
int x = 0;

do {
    x++;

    if (x == 2) continue;
    if (x == 5) break;

    cout << x << endl;
} while (x < 10);
```

- `continue` はその回の残りを飛ばして、末尾の条件判定へ進む
- `break` はループ全体を終了する

---

## 5. 競プロでの出番

競技プログラミングでは、`for` や `while` の方が使う頻度は高い。
`do-while` は次のような場面なら使える:

- 1回は必ず処理したい
- 入力チェックを繰り返したい
- メニュー処理や再試行処理を書きたい

ただし、競プロ本番では可読性のために `while (true)` + `break` で書くことも多い。

```cpp
while (true) {
    int n;
    cin >> n;
    if (n >= 0) break;
}
```

---

## 6. 注意点

- `while (...)` のあとに `;` を忘れやすい
- 「最低1回は実行される」ことを忘れるとバグになる
- ループ回数が先に分かっているなら `for` の方が自然

---

## チェックリスト

- [ ] `do { ... } while (条件);` の形で書く
- [ ] 末尾の `;` を忘れない
- [ ] 条件が最初から `false` でも 1 回は動く
- [ ] 1回は必ず処理したい場面で使う
- [ ] 競プロでは `for` / `while` の方が基本
