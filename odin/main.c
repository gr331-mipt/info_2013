#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE *f1, *f2;
    char m[1025];
    int i;
    f1 = fopen("input.txt","r");
    if (f1 != NULL)
    {
        f2 = fopen("output.txt","w");
        if (f2 != NULL)
        {
            while(fgets(m, 1025, f1))
            {
                if (m[strlen(m) - 1] == '\n')
                		m[strlen(m) - 1] = '\0';
                for (i = strlen(m)-1; i>=0; i--)
                    fprintf(f2, "%c", m[i]);
                fprintf(f2, "\n");
            }
            fclose(f2);
        }
        else
            perror("Error");
        fclose(f1);
    }
    else
        perror("Error");
    return 0;
    }
