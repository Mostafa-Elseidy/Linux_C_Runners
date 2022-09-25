#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[1])
{
    for (int i = 1; i < argc; i++)
    {
        write(1, argv[i], strlen(argv[i]));
        write(1, "\n", strlen("\n"));
    }
    return 0;
}
