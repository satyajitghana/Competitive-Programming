#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void encode (char* str, int K) {
	for (int i = 0 ; strlen(str+i) >= 1 ; i++) {
		if( isalpha( *(str+i) ) ){
			if ( ( *(str+i) + K ) > 'z') {
				*(str+i) = (*(str+i)+K) - 'z' + 'a';
			}
			if ( ( *(str+i) + K ) > 'Z') {
				*(str+i) = (*(str+i)+K) - 'Z' + 'A';
			}
		}
	}
}

int main() {
	char *string = calloc(10,sizeof(*string));
	scanf("%s",string);
	int K;
	scanf("%d",&K);
	encode(string,K);
	printf("%s",string);
}
