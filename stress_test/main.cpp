#include <stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Compares b to a for descending order
}

int main() {
int t;
scanf("%d",&t);
while(t--){
    int n,j,k;
    scanf("%d %d %d",&n,&j,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int x=a[j-1];
     qsort(a, n, sizeof(a[0]), compare);
     if(k==1 && a[0]!=x)
     printf("NO\n");
     else
     printf("YES\n");
}
    return 0;
}