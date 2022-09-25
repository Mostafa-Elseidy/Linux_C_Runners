#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char buf[100];
    int count;
    if (argc != 3)
    {
        return -1;
    }
    int fd1 = open(argv[1], O_RDONLY, 0644);
    int fd2 = open(argv[2], O_WRONLY | O_CREAT, 0644);

    while ((count = read(fd1, buf, 100)) != 0)
    {
        write(fd2, buf, count);
    }

    close(fd1);
    close(fd2);

    return 0;
}