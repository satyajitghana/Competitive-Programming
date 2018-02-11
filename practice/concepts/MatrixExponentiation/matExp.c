//Matrix Exponentiation
#include<stdio.h>

#define ll long long int
void multiply(ll A[2][2],ll B[2][2]){
	ll C[2][2];
	for(int i=0; i<2; i++){  //Row
		for(int j=0; j<2; j++){  //Column
			C[i][j]=0;
			for(int k=0; k<2; k++){ //Element-Wise
				C[i][j]+=A[i][k]*B[k][j];
			}
		} 
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			A[i][j]=C[i][j];
		}
	}
}

ll power(ll A[2][2],int n){
	if(n==0){
		return 1;
	}
	else if(n==1){
		return A[0][0]+A[0][1];
	}
	else{
		ll C[2][2]={{1,1},{1,0}};
		power(A,n/2);
		multiply(A,A);

		if(n%2!=0){
			multiply (A,C);
		}
		return A[0][0]+A[0][1];
	}
}

int fib(int n){
	ll A[2][2]={{1,1},{1,0}};
	return power(A,n);
}
int main(){
	int n;
	scanf("%lld",&n);
	printf("%lld\n",fib(n));
	return 0;
}