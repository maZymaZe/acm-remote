#include <cmath>
#include <cstdio>

#define N 4
#define O 6
#define A 14
#define S 100005

bool p[2][A][A][A][A];
int s[N][S], n, m;

inline int sgn(double x) {
    return (x > 1e-10) - (x < -1e-10);
}

double op(double a, double b, int x) {
    switch (x) {
        case 0:
            return a + b;
        case 1:
            return a - b;
        case 2:
            return b - a;
        case 3:
            return a * b;
        case 4:
            return a / b;
        case 5:
            return b / a;
        default:
            puts("FUCK YOU!");
            return -1;
    }
}

inline void swap(int& a, int& b) {
    a ^= b ^= a ^= b;
}

void insert(bool g, int a, int b, int c, int d, double v) {
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (c > d)
        swap(c, d);
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);

    if (!sgn(v - m))
        p[g][a][b][c][d] = true;
}

void update2(int a, int b, int x) {
    bool g = false;
    if ((x == 4 && a % b) || (x == 5 && b % a))
        g = true;
    insert(g, 0, 0, a, b, op(a, b, x));
}

void update3(int a, int b, int c, int x, int y) {
    bool g = false;
    if ((x == 4 && a % b) || (x == 5 && b % a))
        g = true;

    double e = op(a, b, x);
    if (y == 5 && !sgn(e))
        return;

    if (!sgn(e - round(e))) {
        int ee = round(e);
        if ((y == 4 && ee % c) || (y == 5 && c % ee))
            g = true;
    }

    insert(g, 0, a, b, c, op(e, c, y));
}

void update4(int a, int b, int c, int d, int x, int y, int z, bool w) {
    bool g = false;

    if (w) {
        if ((x == 4 && a % b) || (x == 5 && b % a) || (y == 4 && c % d) ||
            (y == 5 && d % c))
            g = true;

        double e = op(a, b, x), f = op(c, d, y);
        if ((z == 4 && !sgn(f)) || (z == 5 && !sgn(e)))
            return;

        if (!sgn(e - round(e)) && !sgn(f - round(f))) {
            int ee = round(e), ff = round(f);
            if ((z == 4 && ee % ff) || (z == 5 && ff % ee))
                g = true;
        }

        insert(g, a, b, c, d, op(e, f, z));
    } else {
        if ((x == 4 && a % b) || (x == 5 && b % a))
            g = true;

        double e = op(a, b, x);
        if (y == 5 && !sgn(e))
            return;

        if (!sgn(e - round(e))) {
            int ee = round(e);
            if ((y == 4 && ee % c) || (y == 5 && c % ee))
                g = true;
        }

        double f = op(e, c, y);
        if (z == 5 && !sgn(f))
            return;

        if (!sgn(f - round(f))) {
            int ff = round(f);
            if ((z == 4 && ff % d) || (z == 5 && d % ff))
                g = true;
        }

        insert(g, a, b, c, d, op(f, d, z));
    }
}

void addans(int a, int b, int c, int d) {
    s[0][++s[0][0]] = a;
    s[1][s[0][0]] = b;
    s[2][s[0][0]] = c;
    s[3][s[0][0]] = d;
}

int main() {
    scanf("%d%d", &n, &m);

    if (n == 1) {
        puts("0");
        return 0;
    } else if (n == 2) {
        for (int i = 1; i < A; i++)
            for (int j = 1; j < A; j++)
                for (int x = 0; x < O; x++)
                    update2(i, j, x);

        for (int i = 1; i < A; i++)
            for (int j = i; j < A; j++)
                if (p[1][0][0][i][j] && !p[0][0][0][i][j])
                    addans(i, j, 0, 0);
    } else if (n == 3) {
        for (int i = 1; i < A; i++)
            for (int j = 1; j < A; j++)
                for (int k = 1; k < A; k++)
                    for (int x = 0; x < O; x++)
                        for (int y = 0; y < O; y++)
                            update3(i, j, k, x, y);

        for (int i = 1; i < A; i++)
            for (int j = i; j < A; j++)
                for (int k = j; k < A; k++)
                    if (p[1][0][i][j][k] && !p[0][0][i][j][k])
                        addans(i, j, k, 0);
    } else {
        for (int i = 1; i < A; i++)
            for (int j = 1; j < A; j++)
                for (int k = 1; k < A; k++)
                    for (int l = 1; l < A; l++)
                        for (int x = 0; x < O; x++)
                            for (int y = 0; y < O; y++)
                                for (int z = 0; z < O; z++)
                                    for (int w = 0; w < 2; w++)
                                        update4(i, j, k, l, x, y, z, w);

        for (int i = 1; i < A; i++)
            for (int j = i; j < A; j++)
                for (int k = j; k < A; k++)
                    for (int l = k; l < A; l++)
                        if (p[1][i][j][k][l] && !p[0][i][j][k][l])
                            addans(i, j, k, l);
    }

    printf("%d\n", s[0][0]);

    for (int i = 1; i <= s[0][0]; i++)
        for (int j = 0; j < n; j++)
            printf("%d%c", s[j][i], j == n - 1 ? '\n' : ' ');

    return 0;
}
