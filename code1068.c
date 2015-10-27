/*
 * hihocode problem 1068
 * http://hihocoder.com/problemset/problem/1068
 */
#include <stdio.h>
int N;
int Q;
int Li,Ri;
int weight[1000010];
int lightnode[1000010] = {0};
int main()
{
	scanf("%d",&N);
	int i,j;
	for(i = 1; i <= N; i++) {
		scanf("%d",weight + i);
	}
	for(i = 1; i < N; i++) {
		for(j = i + 1; j < N; j++) {
			if(weight[i] > weight[j]) {
				lightnode[i] = j;
				break;
			}
		}
	}
	scanf("%d",&Q);
	for(i = 0; i < Q; i++) {
		scanf("%d%d",&Li,&Ri);
		int pos = Li;
		while((lightnode[pos] <= Ri) && (lightnode[pos] != 0))
			pos = lightnode[pos];
		printf("%d\n",weight[pos]);
	}
}
