#include<stdio.h>
#include<math.h>
long int top=-1;
int s[1000000];

void push(int x){
    s[++top]=x;
}

int pop(){
    return s[top--];
}

int main(){
    long int n,count=0,max=0;
    int r;
    scanf("%ld",&n);
    while(n>0){
        r=n%2;
        n/=2;
        push(r);
    }
    while(top!=-1){
        printf("%ld ",top);
        r=pop();
        printf("%d\n",r);
        if(r==1){
            count++;
            if(top==-1&&max<count) {
                max=count;
            }
        }
        else if(r==0){
            int temp=count;
            count=0;
            if(max<temp){
                max=temp;
                //printf("\n%ld\n",max);
            }
        }
    }
    printf("%ld",max);
}
