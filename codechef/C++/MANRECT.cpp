#include <bits/stdc++.h>
using namespace std;

static int T;
static int N, Q, X1, X2, Y1, Y2, q;
bool inside_shape(int X, int Y) {
	cout<<X<<' '<<Y;
	q++;
	if (q > Q) {
		printf("Wrong Answer. Used too many queries.\n");
		exit(0);
	}
	if (X <= 0 || X > N || Y <= 0 || Y > N) {
		printf("Wrong Answer. Query parameters out of range.\n");
		exit(0);
	}
	return (X >= X1 && X <= X2 && Y >= Y1 && Y <= Y2);
}

bool am_i_square(int N,int Q){
	int x=0,y=0;
	int mx=N+1,my=N+1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(inside_shape(i+1,j+1)){
				x=max(x,i);
				y=max(y,j);
				mx=min(i,mx);
				my=min(j,my);
			}
		}
	}
	return (x-mx)==(y-my);
}

int main() {
	if (scanf("%d%d%d", &T, &N, &Q) != 3) {
		printf("Input file invalid.\n");
		return 0;
	}
	int mxq = 0;
	for (int i = 0; i < T; i++) {
		if (scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2) != 4) {
			printf("Input file invalid.\n");
			return 0;
		}
		q = 0;
		bool user_ans = am_i_square(N, Q);
		bool act_ans = (Y2 - Y1) == (X2 - X1);
		if (user_ans != act_ans) {
			printf("Wrong Answer.\n");
			exit(0);
		}
		mxq = max(mxq, q);
	}
	printf("Correct. Used %d out of %d queries.\n", mxq, Q);
}
