#include <stdio.h>
#include <malloc.h>    
int main()    
{    
	int n,m,t;    
	scanf("%d",&t);    

	int *array;    
	int ans;
	int tt,i;
	for(tt=0; tt<t; tt++)
	{
		scanf("%d%d",&n,&m);
		ans=0;
		array = (int*)malloc(n*sizeof(int));    
		for(i=0; i<n; i++)
			scanf("%d",&array[i]);
		if(n<=m)
			ans=100;
		else
		{
			ans=array[m]-1;    
			for(i=0; i<n-m-1; i++)    
				if(array[i + m + 1] - array[i] > ans)
					ans = array[i + m + 1] - array[i] - 1;    
			if(100 - array[n-m] > ans)
				ans = 100 - array[n-m];
		}
		printf("%d\n",ans);
		free(array);      
	}
	return 0;    
}
