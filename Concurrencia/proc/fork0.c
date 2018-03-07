#include <stdio.h>
#include <unistd.h>
int main()
{
    int pid;

    pid = fork();

    if(pid)
        printf ("Este es el proceso padre\n");
    else
        printf ("Este es el proceso hijo\n");

    return 0;
}
