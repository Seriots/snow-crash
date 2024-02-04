#include <strings.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

        char *a = argv[argc - 1];
        int file = open(a, O_RDONLY);
        char b[100];
        bzero(&b, 100);

        read(file, &b, 100);
        int i = 0;

        while (b[i] != 0)
        {
                printf("%c", b[i] - i);
                i++;
        }
        printf("");
}
