#include <bits/stdc++.h>

using namespace std;

#define N 4010
#define eps 1e-8
#define pdd pair<double, double>
#define pdi pair<double, int>
#define mp make_pair
#define pb push_back

int n;
double M;

double a[N], b[N], c[N];

pdd point(double a1, double b1, double c1, double a2, double b2, double c2) {
    double y = 1. * (c2 * a1 - c1 * a2) / (b1 * a2 - b2 * a1);
    double x = 1. * (c2 * b1 - c1 * b2) / (a1 * b2 - a2 * b1);
    return mp(x, y);
}

bool parallel(double a1, double b1, double a2, double b2) {
    return abs(a1 * b2 - a2 * b1) < eps;
}

bool inside(double x) {
    return x > -eps && x < M + eps;
}

vector<pdi> points;

void add(int x, double a2, double b2, double c2) {
    if (parallel(a[x], b[x], a2, b2))
        return;
    pdd p = point(a[x], b[x], c[x], a2, b2, c2);
    // printf("%.6f %.6f\n", p.first, p.second);
    if (inside(p.first) && inside(p.second)) {
        if (abs(c2) < eps && abs(a2) < eps)
            points.pb(mp(p.first, x));
        if (abs(c2 + M) < eps && abs(b2) < eps)
            points.pb(mp(M + p.second, x));
        if (abs(c2 + M) < eps && abs(a2) < eps)
            points.pb(mp(3 * M - p.first, x));
        if (abs(c2) < eps && abs(b2) < eps)
            points.pb(mp(4 * M - p.second, x));
    }
}

bool cmp(pdi a, pdi b) {
    if (a.first < b.first)
        return true;
    if (a.first > b.first)
        return false;

    return a.second < b.second;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%lf", &n, &M);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf", &a[i], &b[i], &c[i]);
        points.clear();
        points.pb(mp(0 * M, -1));
        points.pb(mp(1 * M, -2));
        points.pb(mp(2 * M, -3));
        points.pb(mp(3 * M, -4));
        points.pb(mp(4 * M, -1));
        if (n > 2) {
            puts("100.000000%");
            continue;
        }
        if (n == 2) {
            if (parallel(a[0], b[0], a[1], b[1])) {
                puts("100.000000%");
                continue;
            }
            pdd p = point(a[0], b[0], c[0], a[1], b[1], c[1]);
            // printf("%.6f %.6f\n", p.first, p.second);
            if (p.first < eps || p.first > M - eps || p.second < eps ||
                p.second > M - eps) {
                puts("100.000000%");
                continue;
            }
            for (int i = 0; i < 2; i++) {
                add(i, 0, 1, 0);
                add(i, 1, 0, -M);
                add(i, 0, 1, -M);
                add(i, 1, 0, 0);
            }
            sort(points.begin(), points.end(), cmp);
            double temp[4] = {0, 0, 0, 0};
            double h = p.second;
            double x = 0;
            int id = 0;
            int sz = points.size();
            for (int i = 1; i < sz; i++) {
                if (abs(points[i].first - points[i - 1].first) < eps &&
                    points[i].second == points[i - 1].second)
                    continue;
                // printf("%.6f %.6f %d %d %.6f\n", points[i].first, h,
                // points[i].second, id, temp[id]);
                temp[id] += h * (points[i].first - x) / 2;
                x = points[i].first;
                if (points[i].second >= 0)
                    id = (id + 1) % 4;
                else if (points[i].second == -1)
                    h = p.second;
                else if (points[i].second == -2)
                    h = M - p.first;
                else if (points[i].second == -3)
                    h = M - p.second;
                else if (points[i].second == -4)
                    h = p.first;
            }
            double mm = M * M;
            for (int i = 0; i < 4; i++) {
                mm = min(mm, temp[i]);
                // printf("%.6f\n", temp[i]);
            }
            printf("%.6f%\n", 100. * (1. - mm / (M * M)));
        } else {
            add(0, 0, 1, 0);
            add(0, 1, 0, -M);
            add(0, 0, 1, -M);
            add(0, 1, 0, 0);
            int sz = points.size();
            if (sz == 5) {
                puts("100.000000%");
                continue;
            }
            sort(points.begin(), points.end(), cmp);
            pdd p;
            for (int i = 0; i < sz; i++)
                if (points[i].second >= 0) {
                    if (points[i].first < M + eps)
                        p = mp(points[i].first, 0);
                    else if (points[i].first < 2 * M + eps)
                        p = mp(M, points[i].first - M);
                    else if (points[i].first < 3 * M + eps)
                        p = mp(3 * M - points[i].first, M);
                    else if (points[i].first < 4 * M + eps)
                        p = mp(0, 4 * M - points[i].first);
                    break;
                }
            double temp[2] = {0, 0};
            double h = p.second;
            double x = 0;
            int id = 0;
            for (int i = 1; i < sz; i++) {
                if (abs(points[i].first - points[i - 1].first) < eps &&
                    points[i].second == points[i - 1].second)
                    continue;
                temp[id] += h * (points[i].first - x) / 2;
                // printf("%.6f %.6f %d %d %.6f\n", points[i].first, h,
                // points[i].second, id, temp[id]);
                x = points[i].first;
                if (points[i].second >= 0)
                    id = (id + 1) % 2;
                else if (points[i].second == -1)
                    h = p.second;
                else if (points[i].second == -2)
                    h = M - p.first;
                else if (points[i].second == -3)
                    h = M - p.second;
                else if (points[i].second == -4)
                    h = p.first;
            }
            double mm = M * M;
            for (int i = 0; i < 2; i++) {
                mm = min(mm, temp[i]);
                // printf("%.6f\n", temp[i]);
            }
            printf("%.6f%\n", 100. * (1. - mm / (M * M)));
        }
    }
    return 0;
}