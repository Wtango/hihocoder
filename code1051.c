#include <stdio.h>

int main(int argc,char *argv[])
{
	int t,n,m;
	int i;
	int arr[100];
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		for(i = 0; i < n; i++)
			scanf("%d",arr + i);
		int ans = 0;
		if(n <= m)
			ans = 100;
		else {
			ans = arr[m] - 1;
			for(i = 0; i < n - m - 1; i++) {
				int days = arr[m + i + 1] - arr[i] - 1;
				ans = days > ans ? days : ans;
			}
			int days = 100 - arr[n - m];
			ans = days > ans? days : ans;
		}
		printf("%d\n",ans);
	}
}
