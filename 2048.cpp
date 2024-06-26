#include <bits/stdc++.h>

using namespace std;

struct Game2048 {
    int board[4][4];

    void score() {
        int score = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == 2048) score += 1280;
                if (board[i][j] == 1024) score += 640;
                if (board[i][j] == 512) score += 320;
                if (board[i][j] == 256) score += 160;
                if (board[i][j] == 128) score += 80;
                if (board[i][j] == 64) score += 40;
                if (board[i][j] == 32) score += 20;
                if (board[i][j] == 16) score += 10;
                if (board[i][j] == 8) score += 5;
            }
        }
        cout << "Your Score: " << score << '\n';
    }

    void random() {
        while (1) {
            int i = rand() % 4;
            int j = rand() % 4;
            if (board[i][j] == 0) {
                int value = rand() % 2;
                board[i][j] = value == 0 ? 2 : 4;
                return;
            }
        }
    }

    void init() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                board[i][j] = 0;
            }
        }
        random();
        random();
    }

    bool end() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == 0) return false;
                if (i > 0 && board[i][j] == board[i-1][j]) return false;
                if (i < 3 && board[i][j] == board[i+1][j]) return false;
                if (j > 0 && board[i][j] == board[i][j-1]) return false;
                if (j < 3 && board[i][j] == board[i][j+1]) return false;
            }
        }
        return true;
    }

    void push(int array[]) {
        int temp[4] = {0}, lastAdded = 0;
        bool merged = false;

        for (int i = 0; i < 4; i++) {
            if (array[i] != 0) {
                if (lastAdded > 0 && temp[lastAdded - 1] == array[i] && !merged) {
                    temp[lastAdded - 1] *= 2;
                    merged = true;
                } else {
                    temp[lastAdded++] = array[i];
                    merged = false;
                }
            }
        }
        for (int i = 0; i < 4; i++) array[i] = temp[i];
    }

    void print() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] != 0) cout << setw(4) << board[i][j];
                else cout << setw(4) << "-";
            }
            cout << '\n';
            cout << " ---------------\n";
        }
        score();
    }

    void move(int dir) {
        int flag = 0;
        for (int i = 0; i < 4; i++) {
            int array[4], arrayCheck[4];
            int count = 0;
            for (int j = 0; j < 4; j++) {
                switch(dir) {
                    case 0: // up
                        array[j] = board[3 - j][i];
                        arrayCheck[j] = array[j];
                        break;
                    case 1: // down
                        array[j] = board[j][i];
                        arrayCheck[j] = array[j];
                        break;
                    case 2: // left
                        array[j] = board[i][3 - j];
                        arrayCheck[j] = array[j];
                        break;
                    case 3: // right
                        array[j] = board[i][j];
                        arrayCheck[j] = array[j];
                        break;
                }
            }
            push(array);
            for (int j = 0; j < 4; j++) if (arrayCheck[j] == array[j]) count++;
            if (count == 4) flag++;
            for (int j = 0; j < 4; j++) {
                switch(dir) {
                    case 0:
                        board[3 - j][i] = array[j];
                        break;
                    case 1:
                        board[j][i] = array[j];
                        break;
                    case 2:
                        board[i][3 - j] = array[j];
                        break;
                    case 3:
                        board[i][j] = array[j];
                        break;
                }
            }
        }
        if (flag == 4) cout << "Input Not Allowed!\n";
        else random();
        print();
    }
};

int main() {
    srand(time(0));
    Game2048 mygame;
    mygame.init();
    mygame.print();

    while (!mygame.end()) {
        cout << "What Move? (U,D,L,R): ";
        char ch;
        cin >> ch;
        switch(ch) {
            case 'U':
                mygame.move(0);
                break;
            case 'D':
                mygame.move(1);
                break;
            case 'L':
                mygame.move(2);
                break;
            case 'R':
                mygame.move(3);
                break;
            default:
                cout << "Invalid Input\n";
        }
    }

    cout << "GAME OVER!\n";
    return 0;
}
