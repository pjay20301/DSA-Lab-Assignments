#include <stdio.h>
#include <string.h>

#define N 10001
char s[N], t[N];
void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
void reverseString(int i , int j) {
	while(i < j) {
		swap(&t[i++], &t[j--]);
	}
}

void increaseString(int i, int j) {
	for(int k = i; k <= j; k++) {
		if(t[k] == 'z')
			t[k] = 'a';
		else 
			t[k]++;
	}
}
int main() {

	scanf("%s%*c",s);
	int pStack[N], bStack[N];
	int pTop = -1, bTop = -1;

	int n = strlen(s), k = 0;

	for(int i = 0; i < n; i++) {

		if(s[i] == '(') {

			pStack[++pTop] = k;

		} else if(s[i] == ')') {

			int j = pStack[pTop--];
			reverseString(j,k-1);

		} else if(s[i] == '[') {

			bStack[++bTop] = k;

		} else if(s[i] == ']') {

			int j = bStack[bTop--];
			increaseString(j,k-1);

		} else {
			t[k++] = s[i];
		}
	}

	printf("%s",t);
}