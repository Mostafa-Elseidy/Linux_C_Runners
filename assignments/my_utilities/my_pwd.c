#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int main()
{
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        write(1, cwd, strlen(cwd));
        write(1, "\n", strlen("\n"));
    }
    else
    {
        perror("getcwd() error");
        return 1;
    }
    return 0;
}