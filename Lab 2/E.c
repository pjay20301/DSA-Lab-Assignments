#include <stdio.h>
#include <math.h>

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    char ch[n+1];
    scanf("%s",ch);
    long long m = round(pow(n,k)), c = m;
    printf("%lld\n",m);
    char a[m][k];
    for(int j = 0; j < k; j++) {
        long long  x = 0, cnt = 0;
        c /= n;
        for(int i = 0; i < m; i++) {
            a[i][j] = ch[x];
            cnt++;
            if(cnt == c) {
                x++; 
                cnt = 0;
                if(x == n) x = 0;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    
}