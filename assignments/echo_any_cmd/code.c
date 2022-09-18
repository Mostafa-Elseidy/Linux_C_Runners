#include <stdio.h>
#include <string.h>

int main()
{
    char txt_in[20];

    while (1)
    {
        printf("Please enter a command > ");
        scanf("%s", txt_in);

        if (strcmp(txt_in, "exit") != 0)
        {
            printf("%s \n", txt_in);
        }
        else
        {
            printf("Good Bye :) \n");
            return 0;
        }
    }
}