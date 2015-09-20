#include <stdio.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(m > (n + 1)) {
		printf("NO\n");
		return 0;
	}
	if(m == (n + 1)) {
		putchar('1');
		while(--m) {
			putchar('0');
			putchar('1');
		}
		putchar('\n');
		return 0;
	}

	int nz = n - m;
	while(m--) {
		putchar('0');
		putchar('1');
	}
	while(nz--) {
		putchar('0');
	}
	putchar('\n');
	return 0;
}
