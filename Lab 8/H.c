#include <stdio.h>


int main() {

	int n;
	scanf("%d",&n);

	int a[n];
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += a[j];
			if(sum == 0) {
				int len = j-i+1;
				if(len > ans) 
					ans = len;
			}
		}
	}
	printf("%d",ans);
}