#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    int i, j;
    for(i = 1; i < argc; i++)
    {
        for(j = 0; j < strlen(argv[i]); j++)
        {
            switch(argv[i][j])
            {
                                case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
					printf("%c",argv[i][j]);
					break;
				default:
					break;
            }
        }
    }
    printf("\n");
	
	return 0;
}

