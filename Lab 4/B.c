#include<stdio.h>
#include<stdbool.h>



int main() {
	int n, A, B;
	scanf("%d %d %d",&n,&A,&B);

	int a[n+1], idx,mx=0;
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
		if(a[i] > mx) {
			mx = a[i];
			idx = i+1;
		}
	}
		a[n] = -1;
		int k = n;
	while(true) {
		int l = 0;
		for(int i = 0; i < k; i+=2) {
			if(a[i] == -1)
				break;
			else if(a[i+1] == -1) {
				a[l] = a[i] + B;
				l++;
				break;
			}
			if(a[i] > a[i+1]) {
				a[l] = a[i]-A*(a[i]-a[i+1]);
				if(a[l] < 0) a[l] = -a[l];
				l++;
			} else if(a[i] < a[i+1]) {
				a[l] = a[i+1]-A*(a[i+1]-a[i]);
				if(a[l] < 0) a[l] = -a[l];
				l++;
			}
		}

		k = l;
		if(l == 0) {
			printf("-1 -1");
			break;
		} else if(l == 1) {
			printf("%d %d",idx,a[0]);
			break;
		}
	}
	return 0;
}