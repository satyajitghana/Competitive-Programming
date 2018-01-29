#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main() {
	srand(time(NULL));
	char* base = calloc(50,sizeof(*base));
	char* message = calloc(50,sizeof(*message));
	printf("\nEnter a string in which message is to be encrypted : ");
	gets(base);
	printf("\nEnter the message to be encrypted : ");
	gets(message);
	int flag = 0;
	int i = 0;
	for (int j = 0 ; j < 26*strlen(message) ; j++)
	{
		if (j%26==0) {printf("\n"); flag = 0;}
		if (j%26 == (tolower(*(message+i))-'a') ) {
			if (flag == 0) {putchar(rand()%26+'a');i++;}
			else putchar(*(base+(j%strlen(base))));
			flag = 1;
		}
		else putchar(*(base+(j%strlen(base))));
	}
	printf("\n");
}
