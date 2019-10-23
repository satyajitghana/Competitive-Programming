#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
char shift[] = {'A','V','X','S','W','D','F','G','U','H','J','K','N','B','I','O','Q','E','A','R','Y','C','Q','Z','T','Z'};
        int T;
	scanf("%d",&T);
        while (T--) {
	    char str[10007];
	    //scanf("\n\n");
	    //scanf("%[^\n]s", str);
	    gets(str);
            for (int i = 0 ; i < strlen(str) ; i++) {
                char currChar = str[i];
		int lower; 
		if (isalpha(currChar)) {lower = islower(currChar); currChar = toupper(currChar);}
                if (currChar ==' ' || currChar=='\t') continue;
                else if ((int)currChar == 91) str[i]='P';
                else if ((int)currChar == 59) str[i]='L';
                else if ((int) currChar == 44) str[i]='M';
                else {
			if (lower) {
			str[i] = tolower(shift[(int)currChar-'A']);
			}
			else
			str[i] = shift[(int)currChar-'A'];
			}
            }
                printf("%s\n",str);
        }
}
