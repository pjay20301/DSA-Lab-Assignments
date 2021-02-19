#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int a[], int low, int high) {
	int pivot = a[high];
	int i = low - 1;
	for(int j = low; j <= high - 1; j++) {
		if(a[j] < pivot) {
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return (i+1);
}
void quicksort(int a[], int low, int high) {
	if(low < high) {
		int pivot = partition(a,low,high);
		quicksort(a,low,pivot-1);
		quicksort(a,pivot+1,high);
	}
	return;
}

int binary_search(int a[], int l, int r, int x) {
	if(r >= l) {
	  int mid = l + (r-l)/2;
	  
	  if(a[mid] == x) 
	    return mid;

	  if(a[mid] > x) 
	    return binary_search(a,l,mid-1,x);
	  else if(a[mid] < x)
	  	return binary_search(a,mid+1,r,x);
	}
	
	return l;


}
int main() {
	int n,m,l;
	scanf("%d %d %d",&n,&m,&l);
	int u,v,a,b,k;
	scanf("%d %d %d %d %d",&u,&v,&a,&b,&k);
	int cities[m];
	for(int i = 0; i < m; i++) {
		scanf("%d",&cities[i]);
	}
    int gas[l];
	for(int i = 0; i < l; i++) {
        scanf("%d",&gas[i]);  
	}
	quicksort(cities,0,m-1);
	quicksort(gas,0,l-1);
	
	int ans = 0;
	for(int i = 0; i < m; i++) {
		if(cities[i] < u) 
			continue;
		else if(cities[i] >= v)
			break;
		int x;
		if((cities[i+1]-cities[i]-b)%a) {
			x = (cities[i+1]-cities[i]-b)/a + (cities[i+1]-cities[i]-b)%a;
		} else x = (cities[i+1]-cities[i]-b)/a;
		int j = binary_search(gas,0,l-1,x);
		ans += gas[j]*k;
		
	}
printf("%d",ans);
	
}