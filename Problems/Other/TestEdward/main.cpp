#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int a[1024][1024], board[1024][1024], n; //0 = empty, 1 = red, 2 = blue;
bool locked[1024][1024], show_coord = 0;
stack<pii> moves;

bool undo() {
    if (moves.empty()) return false;
    pii p = moves.top(); moves.pop();
    board[p.f][p.s] += 2; board[p.f][p.s] %= 3;
    return true;
}

bool full() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) return false;
        }
    }
    return true;
}

int opp(int x) {
    return x == 1 ? 2 : 1;
}

bool solved() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != board[i][j]) return false;
        }
    }
    return true;
}

void print_board() {
    if (show_coord) {
        printf("    ");
        for (int i = 1; i <= n; i++) printf("%d ", i % 10);
        printf("\n  +");
        for (int i = 1; i <= 2 * n; i++) printf("-");
        printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        if (show_coord) {
            if (i < 10) printf("%d | ", i);
            else printf("%d| ", i);
        }
        for (int j = 1; j <= n; j++) {
            if (!a[i][j]) printf("_ ");
            else printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void print_playing_board() {
    if (show_coord) {
        printf("    ");
        for (int i = 1; i <= n; i++) printf("%d ", i % 10);
        printf("\n  +");
        for (int i = 1; i <= 2 * n; i++) printf("-");
        printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        if (show_coord) {
            if (i < 10) printf("%d | ", i);
            else printf("%d| ", i);
        }
        for (int j = 1; j <= n; j++) {
            if (!board[i][j]) printf("_ ");
            else printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void print_locked() {
    if (show_coord) {
        printf("    ");
        for (int i = 1; i <= n; i++) printf("%d ", i % 10);
        printf("\n  +");
        for (int i = 1; i <= 2 * n; i++) printf("-");
        printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        if (show_coord) {
            if (i < 10) printf("%d | ", i);
            else printf("%d| ", i);
        }
        for (int j = 1; j <= n; j++) {
            if (!locked[i][j]) printf("_ ");
            else printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool valid() {
    set<string> s1, s2;
    for (int i = 1; i <= n; i++) {
        int cnt1 = 0, cnt2 = 0;
        string str = "";
        for (int j = 1; j <= n; j++) {
            if (!a[i][j]) continue;
            if (a[i][j] == a[i][j + 1] && a[i][j + 1] == a[i][j + 2]) return false;
            if (a[i][j] == a[i + 1][j] && a[i + 1][j] == a[i + 2][j]) return false;
            if (a[i][j] == 1) cnt1++; if (a[i][j] == 2) cnt2++;
            str += to_string(a[i][j]);
        }
        if (cnt1 > n / 2 || cnt2 > n / 2) return false;
        if (cnt1 + cnt2 == n && s1.count(str)) return false;
        else s1.insert(str);
    }
    for (int j = 1; j <= n; j++) {
        int cnt1 = 0, cnt2 = 0;
        string str = "";
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == 1) cnt1++; if (a[i][j] == 2) cnt2++;
            str += to_string(a[i][j]);
        }
        if (cnt1 > n / 2 || cnt2 > n / 2) return false;
        if (cnt1 + cnt2 == n && s2.count(str)) return false;
        else s2.insert(str);
    }
    return true;
}

bool valid_player() {
    set<string> s1, s2;
    for (int i = 1; i <= n; i++) {
        int cnt1 = 0, cnt2 = 0;
        string str = "";
        for (int j = 1; j <= n; j++) {
            if (!board[i][j]) continue;
            if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2]) return false;
            if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j]) return false;
            if (board[i][j] == 1) cnt1++; if (board[i][j] == 2) cnt2++;
            str += to_string(board[i][j]);
        }
        if (cnt1 > n / 2 || cnt2 > n / 2) return false;
        if (cnt1 + cnt2 == n && s1.count(str)) return false;
        else s1.insert(str);
    }
    for (int j = 1; j <= n; j++) {
        int cnt1 = 0, cnt2 = 0;
        string str = "";
        for (int i = 1; i <= n; i++) {
            if (board[i][j] == 1) cnt1++; if (board[i][j] == 2) cnt2++;
            str += to_string(board[i][j]);
        }
        if (cnt1 > n / 2 || cnt2 > n / 2) return false;
        if (cnt1 + cnt2 == n && s2.count(str)) return false;
        else s2.insert(str);
    }
    return true;
}

void generate_valid_row(int r, int c, int len, int prev, int cnt1, int cnt2, string str, vector<string> &v, set<string> &s) {
    if (cnt1 > n / 2 || cnt2 > n / 2 || len >= 3) return;
    if (c == n + 1) {if (!s.count(str)) v.push_back(str); return;}
    if (a[r][c] == 0) {
        generate_valid_row(r, c + 1, prev == 1 ? len + 1 : 1, 1, cnt1 + 1, cnt2, str + "1", v, s); //choose 1
        generate_valid_row(r, c + 1, prev == 2 ? len + 1 : 1, 2, cnt1, cnt2 + 1, str + "2", v, s); //choose 2
    }
    if (a[r][c] == 1) generate_valid_row(r, c + 1, prev == 1 ? len + 1 : 1, 1, cnt1 + 1, cnt2, str + "1", v, s); //choose 1
    if (a[r][c] == 2) generate_valid_row(r, c + 1, prev == 2 ? len + 1 : 1, 2, cnt1, cnt2 + 1, str + "2", v, s); //choose 2
}

void generate_valid_col(int r, int c, int len, int prev, int cnt1, int cnt2, string str, vector<string> &v, set<string> &s) {
    if (cnt1 > n / 2 || cnt2 > n / 2 || len >= 3) return;
    if (r == n + 1) {if (!s.count(str)) v.push_back(str); return;}
    if (a[r][c] == 0) {
        generate_valid_col(r + 1, c, prev == 1 ? len + 1 : 1, 1, cnt1 + 1, cnt2, str + "1", v, s); //choose 1
        generate_valid_col(r + 1, c, prev == 2 ? len + 1 : 1, 2, cnt1, cnt2 + 1, str + "2", v, s); //choose 2
    }
    if (a[r][c] == 1) generate_valid_col(r + 1, c, prev == 1 ? len + 1 : 1, 1, cnt1 + 1, cnt2, str + "1", v, s); //choose 1
    if (a[r][c] == 2) generate_valid_col(r + 1, c, prev == 2 ? len + 1 : 1, 2, cnt1, cnt2 + 1, str + "2", v, s); //choose 2
}

void generate_valid_row_player(int r, int c, int len, int prev, int cnt1, int cnt2, string str, vector<string> &v, set<string> &s) {
    if (cnt1 > n / 2 || cnt2 > n / 2 || len >= 3) return;
    if (c == n + 1) {if (!s.count(str)) v.push_back(str); return;}
    if (board[r][c] == 0) {
        generate_valid_row_player(r, c + 1, prev == 1 ? len + 1 : 1, 1, cnt1 + 1, cnt2, str + "1", v, s); //choose 1
        generate_valid_row_player(r, c + 1, prev == 2 ? len + 1 : 1, 2, cnt1, cnt2 + 1, str + "2", v, s); //choose 2
    }
    if (board[r][c] == 1) generate_valid_row_player(r, c + 1, prev == 1 ? len + 1 : 1, 1, cnt1 + 1, cnt2, str + "1", v, s); //choose 1
    if (board[r][c] == 2) generate_valid_row_player(r, c + 1, prev == 2 ? len + 1 : 1, 2, cnt1, cnt2 + 1, str + "2", v, s); //choose 2
}

void generate_valid_col_player(int r, int c, int len, int prev, int cnt1, int cnt2, string str, vector<string> &v, set<string> &s) {
    if (cnt1 > n / 2 || cnt2 > n / 2 || len >= 3) return;
    if (r == n + 1) {if (!s.count(str)) v.push_back(str); return;}
    if (board[r][c] == 0) {
        generate_valid_col_player(r + 1, c, prev == 1 ? len + 1 : 1, 1, cnt1 + 1, cnt2, str + "1", v, s); //choose 1
        generate_valid_col_player(r + 1, c, prev == 2 ? len + 1 : 1, 2, cnt1, cnt2 + 1, str + "2", v, s); //choose 2
    }
    if (board[r][c] == 1) generate_valid_col_player(r + 1, c, prev == 1 ? len + 1 : 1, 1, cnt1 + 1, cnt2, str + "1", v, s); //choose 1
    if (board[r][c] == 2) generate_valid_col_player(r + 1, c, prev == 2 ? len + 1 : 1, 2, cnt1, cnt2 + 1, str + "2", v, s); //choose 2
}

bool place() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!a[i][j]) continue;
            if (a[i][j] == a[i][j + 1]) { //horizontal adjacent case
                if (!a[i][j - 1]) {a[i][j - 1] = opp(a[i][j]); return true;}
                if (!a[i][j + 2]) {a[i][j + 2] = opp(a[i][j]); return true;}
            }
            if (a[i][j] == a[i + 1][j]) { //vertical adjacent case
                if (!a[i - 1][j]) {a[i - 1][j] = opp(a[i][j]); return true;}
                if (!a[i + 2][j]) {a[i + 2][j] = opp(a[i][j]); return true;}
            }
            if (a[i][j] == a[i][j + 2]) { //horizontal gap case
                if (!a[i][j + 1]) {a[i][j + 1] = opp(a[i][j]); return true;}
            }
            if (a[i][j] == a[i + 2][j]) {
                if (!a[i + 1][j]) {a[i + 1][j] = opp(a[i][j]); return true;}
            }
        }
    }
    for (int i = 1; i <= n; i++) { //horizontal row checker
        int cnt1 = 0, cnt2 = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) cnt1++;
            if (a[i][j] == 2) cnt2++;
        }
        if (cnt1 + cnt2 == n) continue;
        if (cnt1 == n / 2) {
            for (int j = 1; j <= n; j++) if (!a[i][j]) a[i][j] = 2;
            return true;
        }
        if (cnt2 == n / 2) {
            for (int j = 1; j <= n; j++) if (!a[i][j]) a[i][j] = 1;
            return true;
        }
        if (cnt1 + cnt2 != n - 2) continue;
        //no two identical case
        int ref = 0;
        for (int ii = 1; ii <= n; ii++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) if (a[ii][j] == 1 || a[ii][j] == 2) cnt++;
            if (cnt < n) continue;
            bool same = 1;
            for (int j = 1; j <= n; j++) {
                if (!a[i][j]) continue;
                if (a[i][j] != a[ii][j]) same = 0;
            }
            if (same) ref = ii;
        }
        if (!ref) continue;
        for (int j = 1; j <= n; j++) if (!a[i][j]) a[i][j] = opp(a[ref][j]);
        return true;
    }
    for (int j = 1; j <= n; j++) { //vertical row checker
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == 1) cnt1++;
            if (a[i][j] == 2) cnt2++;
        }
        if (cnt1 + cnt2 == n) continue;
        if (cnt1 == n / 2) {
            for (int i = 1; i <= n; i++) if (!a[i][j]) a[i][j] = 2;
            return true;
        }
        if (cnt2 == n / 2) {
            for (int i = 1; i <= n; i++) if (!a[i][j]) a[i][j] = 1;
            return true;
        }
        if (cnt1 + cnt2 != n - 2) continue;
        //no two identical case
        int ref = 0;
        for (int jj = 1; jj <= n; jj++) {
            int cnt = 0;
            for (int i = 1; i <= n; i++) if (a[i][jj] == 1 || a[i][jj] == 2) cnt++;
            if (cnt < n) continue;
            bool same = 1;
            for (int i = 1; i <= n; i++) {
                if (!a[i][j]) continue;
                if (a[i][j] != a[i][jj]) same = 0;
            }
            if (same) ref = jj;
        }
        if (!ref) continue;
        for (int i = 1; i <= n; i++) if (!a[i][j]) a[i][j] = opp(a[i][ref]);
        return true;
    }
    set<string> s1, s2; //last resort logic checking (handles hard cases like 1 1 2 _ _ _)
    for (int i = 1; i <= n; i++) {
        string str = "", str1 = "";
        int cnt = 0, cnt1 = 0;
        for (int j = 1; j <= n; j++) {
            str += to_string(a[i][j]);
            str1 += to_string(a[j][i]);
            if (a[i][j]) cnt++;
            if (a[j][i]) cnt1++;
        }
        if (cnt == n) s1.insert(str);
        if (cnt1 == n) s2.insert(str1);
    }
    for (int i = 1; i <= n; i++) { //checks whether a row can be logically deduced
        vector<string> perms;
        generate_valid_row(i, 1, 0, 0, 0, 0, "", perms, s1);
        if (perms.empty()) continue;
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) continue;
            bool same = 1;
            for (int k = 1; k < perms.size(); k++) if (perms[k][j - 1] != perms[k - 1][j - 1]) {same = 0; break;}
            if (same) {a[i][j] = perms[0][j - 1] - '0'; return true;}
        }
    }
    for (int j = 1; j <= n; j++) { //checks whether a column can be logically deduced
        vector<string> perms;
        generate_valid_col(1, j, 0, 0, 0, 0, "", perms, s2);
        if (perms.empty()) continue;
        for (int i = 1; i <= n; i++) {
            if (a[i][j]) continue;
            bool same = 1;
            for (int k = 1; k < perms.size(); k++) if (perms[k][i - 1] != perms[k - 1][i - 1]) {same = 0; break;}
            if (same) {a[i][j] = perms[0][i - 1] - '0'; return true;}
        }
    }
    return false; //no valid move found, board is incorrect
}

string hint() {
    if (!valid_player()) return "Hmm... Your board looks wrong.\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!board[i][j]) continue;
            if (board[i][j] == board[i][j + 1]) { //horizontal adjacent case
                if (!board[i][j - 1]) {
                    int r = i, c = j - 1;
                    return "Perhaps you have enough information to fill out cell (" + to_string(r) + " " + to_string(c) + ").\n";
                }
                if (!board[i][j + 2]) {
                    int r = i, c = j + 2;
                    return "Perhaps you have enough information to fill out cell (" + to_string(r) + " " + to_string(c) + ").\n";
                }
            }
            if (board[i][j] == board[i + 1][j]) { //vertical adjacent case
                if (!board[i - 1][j]) {
                    int r = i - 1, c = j;
                    return "Perhaps you have enough information to fill out cell (" + to_string(r) + " " + to_string(c) + ").\n";
                }
                if (!board[i + 2][j]) {
                    int r = i + 2, c = j;
                    return "Perhaps you have enough information to fill out cell (" + to_string(r) + " " + to_string(c) + ").\n";
                }
            }
            if (board[i][j] == board[i][j + 2]) { //horizontal gap case
                if (!board[i][j + 1]) {
                    int r = i, c = j + 1;
                    return "Perhaps you have enough information to fill out cell (" + to_string(r) + " " + to_string(c) + ").\n";
                }
            }
            if (board[i][j] == board[i + 2][j]) { //vertical gap case
                if (!board[i + 1][j]) {
                    int r = i + 1, c = j;
                    return "Perhaps you have enough information to fill out cell (" + to_string(r) + " " + to_string(c) + ").\n";
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) { //horizontal row checker
        int cnt1 = 0, cnt2 = 0;
        for (int j = 1; j <= n; j++) {
            if (board[i][j] == 1) cnt1++;
            if (board[i][j] == 2) cnt2++;
        }
        if (cnt1 + cnt2 == n) continue;
        if (cnt1 == n / 2 || cnt2 == n / 2) {
            int r = i;
            return "Perhaps you have enough information to fill out row " + to_string(r) + ".\n";
        }
        if (cnt1 + cnt2 != n - 2) continue;
        //no two identical case
        int ref = 0;
        for (int ii = 1; ii <= n; ii++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) if (board[ii][j] == 1 || board[ii][j] == 2) cnt++;
            if (cnt < n) continue;
            bool same = 1;
            for (int j = 1; j <= n; j++) {
                if (!board[i][j]) continue;
                if (board[i][j] != board[ii][j]) same = 0;
            }
            if (same) ref = ii;
        }
        if (!ref) continue;
        return "Remember that no two rows can be the same.\n";
    }
    for (int j = 1; j <= n; j++) { //vertical row checker
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++) {
            if (board[i][j] == 1) cnt1++;
            if (board[i][j] == 2) cnt2++;
        }
        if (cnt1 + cnt2 == n) continue;
        if (cnt1 == n / 2 || cnt2 == n / 2) {
            int c = j;
            return "Perhaps you have enough information to fill out column " + to_string(c) + ".\n";
        }
        if (cnt1 + cnt2 != n - 2) continue;
        //no two identical case
        int ref = 0;
        for (int jj = 1; jj <= n; jj++) {
            int cnt = 0;
            for (int i = 1; i <= n; i++) if (board[i][jj] == 1 || board[i][jj] == 2) cnt++;
            if (cnt < n) continue;
            bool same = 1;
            for (int i = 1; i <= n; i++) {
                if (!board[i][j]) continue;
                if (board[i][j] != board[i][jj]) same = 0;
            }
            if (same) ref = jj;
        }
        if (!ref) continue;
        return "Remember that no two columns can be the same.\n";
    }
    set<string> s1, s2; //last resort logic checking (handles hard cases like 1 1 2 _ _ _)
    for (int i = 1; i <= n; i++) {
        string str = "", str1 = "";
        int cnt = 0, cnt1 = 0;
        for (int j = 1; j <= n; j++) {
            str += to_string(board[i][j]);
            str1 += to_string(board[j][i]);
            if (board[i][j]) cnt++;
            if (board[j][i]) cnt1++;
        }
        if (cnt == n) s1.insert(str);
        if (cnt1 == n) s2.insert(str1);
    }
    for (int i = 1; i <= n; i++) { //checks whether a row can be logically deduced
        vector<string> perms;
        generate_valid_row_player(i, 1, 0, 0, 0, 0, "", perms, s1);
        if (perms.empty()) continue;
        for (int j = 1; j <= n; j++) {
            if (board[i][j]) continue;
            bool same = 1;
            for (int k = 1; k < perms.size(); k++) if (perms[k][j - 1] != perms[k - 1][j - 1]) {same = 0; break;}
            if (same) return "It is possible to determine cell (" + to_string(i) + " " + to_string(j) + ") with logical deduction.\n";
        }
    }
    for (int j = 1; j <= n; j++) { //checks whether a row can be logically deduced
        vector<string> perms;
        generate_valid_col_player(1, j, 0, 0, 0, 0, "", perms, s2);
        if (perms.empty()) continue;
        for (int i = 1; i <= n; i++) {
            if (board[i][j]) continue;
            bool same = 1;
            for (int k = 1; k < perms.size(); k++) if (perms[k][i - 1] != perms[k - 1][i - 1]) {same = 0; break;}
            if (same) return "It is possible to determine cell (" + to_string(i) + " " + to_string(j) + ") with logical deduction.\n";
        }
    }
    return "Your board is invalid because it forces illegal moves to be made at later stages.\n";
}

void solve() { //solves given board
    memset(a, 0x3f, sizeof(a));
    memset(board, 0x3f, sizeof(board));
    memset(locked, 0, sizeof(locked));
    printf("Please enter the dimensions of the board: ");
    cin >> n;
    int show = 0;
    printf("Show steps? (0/1): ");
    cin >> show;
    printf("Show coordinates? (0/1): ");
    cin >> show_coord;
    printf("Please enter the format of the board below:\n");
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            if (c == '_') a[i][j] = 0;
            else a[i][j] = c - '0';
        }
    }
    printf("\n");
    int steps = 0;
    while (!full()) {
        steps++;
        if (!place()) break;
        if (show) printf("Step %d:\n", steps), print_board();
    }
    if (!valid() || !full()) printf("Sorry, no valid solution found.\n");
    else if (!show) printf("Final result:\n"), print_board();
}

void generate_board() {
    memset(a, 0x3f, sizeof(a));
    memset(board, 0x3f, sizeof(board));
    memset(locked, 0, sizeof(locked));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = board[i][j] = 0;
        }
    }
    while (!full()) {
        if (place()) continue;
        int r = rand() % n + 1, c = rand() % n + 1, col = rand() % 2 + 1;
        while (a[r][c] != 0) r = rand() % n + 1, c = rand() % n + 1;
        a[r][c] = board[r][c] = col;
        locked[r][c] = 1;
    }
}

void play() {
    printf("Welcome! This is a game where you fill out a board with 1s and 2s according to a few rules:\n\n"
           "1. No three 1s or 2s can be adjacent in the same column or row.\n"
           "2. Every row and column must have the same number of 1s and 2s.\n"
           "3. No two rows or columns can be identical.\n\n"
           "To make a move, simply enter the row number and then column number of the square you would like to change.\n"
           "If you are stuck and need a hint, enter \"0 0\".\n"
           "If you would like to undo your previous move, enter \"-1 0\".\n"
           "If you want the initial board to be displayed, enter \"1 0\".\n\n"
           "To start playing, please enter the dimensions of the board you would like to solve: ");
    cin >> n;
    while (n % 2 == 1 || n <= 0) {
        printf("Dimensions must be a positive even number: ");
        cin >> n;
    }
    printf("Show coordinates? (0/1): ");
    cin >> show_coord;
    do generate_board();
    while (!valid());
    printf("Board:\n"); print_playing_board();
    while (!solved()) {
        int r, c;
        printf("Enter the row and column number which you would like to change (e.g: 1 1): ");
        cin >> r >> c;
        if (r == 0 && c == 0) {printf("%s", hint().c_str()); continue;}
        if (r == -1 && c == 0) {
            if (undo()) printf("Your last move has been reverted.\n");
            else printf("Sorry, you cannot undo without making a move.\n");
            goto print;
        }
        if (r == 1 && c == 0) {
            printf("Initial board:\n"); print_locked();
            continue;
        }
        while (r < 1 || r > n || c < 1 || c > n || locked[r][c]) {
            printf("Sorry, that square cannot be changed. Try another: ");
            cin >> r >> c;
        }
        board[r][c]++;
        board[r][c] %= 3;
        moves.push({r, c});
        print:
        printf("Board:\n"); print_playing_board();
    }
    printf("Congrats! You solved it!\n");
}

int main() {
    srand(time(NULL));

    int choice;
    printf("Welcome to Tazuku! Type 0 to play, or 1 for the board solver: ");
    cin >> choice;
    if (choice) solve();
    else play();

    return 0;
}