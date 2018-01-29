#include<stdio.h>

int main() {
  char store[10][10];
  for (int i = 0 ; i < 10 ; i++) {
    for (int j = 0 ; j < 10 ; j++) {
      scanf("%c",&store[i][j]);
    }
  }
  int vertical[10]={};
  int vspaces = 0;
  int k=0;
  //int vindex[10]={};
  for (int i = 0 ; i < 10 ; i++) {
    int pos=0;
    for (int j = 0 ; j < 10 ; j++) {
      if (store[i][j]=='-') {
        pos++;
      }
      else {
        pos=0;
      }
    }
    vertical[i]=pos; printf("%d ",vertical[i]);
  }
}
