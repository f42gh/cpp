#include<iostream>
using namespace std;
int main(){
    int tmp =0;
    if (tmp ==0) {
        cout <<"tmp is zero" <<endl;
    }
    else if (!(tmp ==0) || tmp ==1) {
        cout <<"tmp is one or something without zero" <<endl;
    }
    else {
        cout <<"tmp is not zero and two" <<endl;
    }

    // --- break: ループを即抜ける ---
    for (int i = 0; i < 10; i++) {
        if (i == 5) break;   // i==5 でループ終了
        cout << i << " ";
    }
    cout << endl;  // 0 1 2 3 4

    // --- continue: 残りをスキップして次のイテレーションへ ---
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) continue;  // 偶数はスキップ
        cout << i << " ";
    }
    cout << endl;  // 1 3 5 7 9

    // --- goto: 指定ラベルへジャンプ（基本的に非推奨） ---
    int x = 0;
    loop:
        if (x < 3) {
            cout << x++ << " ";
            goto loop;
        }
    cout << endl;  // 0 1 2

    // --- switch: 整数・char の多分岐 ---
    int val = 2;
    switch (val) {
        case 1:
            cout << "one" << endl;
            break;         // break がないと次の case にフォールスルーする
        case 2:
            cout << "two" << endl;
            break;
        case 3:
            [[fallthrough]];   // C++17: 意図的なフォールスルーを明示
        case 4:
            cout << "three or four" << endl;
            break;
        default:
            cout << "other" << endl;
    }

    // --- 多重ループの break はラベルではなくフラグかgoto ---
    bool done = false;
    for (int i = 0; i < 3 && !done; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) { done = true; break; }
            cout << i << j << " ";
        }
    }
    cout << endl;  // 00 01 02 10
}
