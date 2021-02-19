#include <stdio.h>

void fun(int cnt, int check, char c,int i,int n) {
    char ch;
    scanf("%c",&ch);
    i++;
    if(i == n+1) {
        if(check == 0) printf("NO");
        return;
    }
    if(ch == 'b') {
        if(cnt == 3 && c == 'a') {
            if(check == 0) {
                printf("YES %d ",i-3,n);
                check = 1;
            }
            else printf("%d ", i-3); 
            fun(1,check,'b',i,n);
        } else {
           fun(1,check,'b',i,n);
        }
    } else if(ch == 'a') {
        if(cnt == 1 && c == 'b') {
           fun(2,check,'a',i,n);
        } else if(cnt == 2 && c == 'a') {
            fun(3,check,'a',i,n);
        } else {
            fun(0,check,'a',i,n);
        }
    }
        
}

int main() {
    int n;
    scanf("%d\n", &n);
    int cnt = 0, check = 0;
    fun(cnt,check,'!',0,n);
}