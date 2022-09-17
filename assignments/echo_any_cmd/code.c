#include <stdio.h>
#include <string.h>

int main()
{
    char txt_in[20];

    while (strcmp(txt_in, "exit"))
    {
        printf("Please enter a command > ");
        scanf("%s", txt_in);
        printf("%s \n", txt_in);
    }
    printf("Good Bye :) \n");
    return 0;
}