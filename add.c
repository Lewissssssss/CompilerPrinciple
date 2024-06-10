// Input: 5 3 0 6 7 8 9 1 2 6 7 2 1 9 5 3 4 8 1 9 8 3 4 2 5 6 7 8 5 9 7 6 1 0 2 3 4 2 6 8 5 3 7 9 1 7 1 3 9 2 4 8 5 6 9 6 1 5 3 7 2 8 4 2 8 7 4 1 0 6 3 5 3 4 5 2 8 6 1 7 9
// Output: 5 3 4 6 7 8 9 1 2 6 7 2 1 9 5 3 4 8 1 9 8 3 4 2 5 6 7 8 5 9 7 6 1 4 2 3 4 2 6 8 5 3 7 9 1 7 1 3 9 2 4 8 5 6 9 6 1 5 3 7 2 8 4 2 8 7 4 1 9 6 3 5 3 4 5 2 8 6 1 7 9

int a[9][9];

int check_sudoku(int a[][9]) {
    int i, j, k;
    int b[9];
    // check rows
    i = 0;
    while (i < 9) {
        j = 0;
        while (j < 9) {
            b[j] = 0;
            j = j + 1;
        }
        j = 0;
        while (j < 9) {
            if (a[i][j]) {
                if (!b[a[i][j] - 1]) {
                    b[a[i][j] - 1] = 1;
                } else {
                    return 0;
                }
            }
            j = j + 1;
        }
        i = i + 1;
    }

    // check columns
    i = 0;
    while (i < 9) {
        j = 0;
        while (j < 9) {
            b[j] = 0;
            j = j + 1;
        }
        j = 0;
        while (j < 9) {
            if (a[j][i]) {
                if (!b[a[j][i] - 1]) {
                    b[a[j][i] - 1] = 1;
                } else {
                    return 0;
                }
            }
            j = j + 1;
        }
        i = i + 1;
    }

    // check 3x3 squares
    i = 0;
    while (i < 3) {
        j = 0;
        while (j < 3) {
            k = 0;
            while (k < 9) {
                b[k] = 0;
                k = k + 1;
            }
            k = 0;
            while (k < 3) {
                int l;
                l = 0;
                while (l < 3) {
                    int m;
                    m = a[i * 3 + k][j * 3 + l];
                    if (m) {
                        if (!b[m - 1]) {
                            b[m - 1] = 1;
                        } else {
                            return 0;
                        }
                    }
                    l = l + 1;
                }
                k = k + 1;
            }
            j = j + 1;
        }
        i = i + 1;
    }

    return 1;

}

int solve_sudoku() {
    int i, j, solve_i, solve_j, done = 1;
    i = 0;
    while (i < 9 && done) {
        j = 0;
        while (j < 9 && done) {
            if (a[i][j] == 0) {
                done = 0;
                solve_i = i;
                solve_j = j;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    if (done) {
        return check_sudoku(a);
    }
    i = 1;
    while (i <= 9) {
        a[solve_i][solve_j] = i;
        if (check_sudoku(a)) {
            if (solve_sudoku()) {
                return 1;
            }
        }
        i = i + 1;
    }
    a[solve_i][solve_j] = 0;
    return 0;
}

int main() {

    int i = 0, j = 0;
    int solve = 0;
    while (i < 9) {
        j = 0;
        while (j < 9) {
            a[i][j] = getint();
            if (a[i][j] < 0 || a[i][j] > 9) {
                putint(0);
                putch(32);
                return 0;
            } else if (a[i][j] == 0) {
                solve = 1;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    
    if (solve) {
        if (solve_sudoku()) {
            i = 0;
            while (i < 9) {
                j = 0;
                while (j < 9) {
                    putint(a[i][j]);
                    putch(32);
                    j = j + 1;
                }
                i = i + 1;
            }
        } else {
            putint(0);
            putch(32);
        }
    } else if (check_sudoku(a)) {
        putint(1);
        putch(32);
    } else {
        putint(0);
        putch(32);
    }

    return 0;
}