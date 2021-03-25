#include <stdio.h>
#include <stdlib.h>

#define ll long long 

typedef struct {
    int idx;
    int x, y;
    float m;
} Pair;

Pair hero;

int cmpfunc(const void* a, const void* b) {
    Pair p = *(Pair*)a, q = *(Pair*)b;

    return (q.m - p.m) > 0 ? 1 : -1; 
}

int main() {
    int n;
    scanf("%d", &n);

    n = n - 1;

    Pair points[n];

    int minY = 1e6, minYIdx = -1;

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &points[i].idx, &points[i].x, &points[i].y);

        if (points[i].y < minY) {
            minYIdx = i;
            minY = points[i].y;
        }
    }

    scanf("%d %d %d", &hero.idx, &hero.x, &hero.y);

    if (hero.y > minY) {
        Pair temp = hero;
        hero = points[minYIdx];
        points[minYIdx] = temp;
    }

    for (int i = 0; i < n; i++) {
        points[i].x -= hero.x;
        points[i].y -= hero.y;
        points[i].m = (float)points[i].x / (float)points[i].y;
    }

    qsort(points, n, sizeof(Pair), cmpfunc);

    for (int i = 0; i < n; i++) {
        printf("%d ", points[i].idx);
    }

    return 0;
}