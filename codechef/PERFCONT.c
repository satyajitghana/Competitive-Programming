#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		int N,P,cakewalk,hard;
		cakewalk = hard = 0;
		scanf("%d %d", &N, &P);
		while (N--) {
			int temp; 
			scanf("%d",&temp);
			if (temp >= (P/2)) cakewalk++;
			else if (temp <= (P/10)) hard++;
		}
		if (cakewalk ==1 && hard ==2) printf("yes\n");
		else printf("no\n");
	}
}
