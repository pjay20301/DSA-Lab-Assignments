#include <stdio.h>

int main() {
    int n,m;
    scanf("%d %d\n",&n,&m);
    int freq[36] = {};
    for(int i = 0; i < n; i++) {
        char tag[21];
        scanf("%[^\n]%*c",tag);
        if(tag[0] <= '9') 
            freq[tag[0]-'0']++;
        else freq[tag[0]-'A'+10]++;
        
    }

    int ans = 0;
    for(int i = 0; i < 36; i++) {
        if(freq[i] <= m) continue;
        int a = freq[i]/m, b = freq[i]%m;
        ans += ((m-b)*(a)*(a-1)/2 + (b)*(a+1)*(a)/2);
    }
    printf("%d",ans);

    return 0;
}
