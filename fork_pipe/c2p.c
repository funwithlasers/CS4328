#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

main()
{
    int p[2];
    pid_t pid;

    pipe(p);
    pid = fork();

    if(pid < 0) fprintf(stderr, "pipe failed\n");

    if(pid == 0) //child
    {
        close(1);
        dup(p[1]);
        close(p[0]);
        close(p[1]);
        execl("./pre", "pre", 0);
    }

    else //parent
    {
        close(0);
        dup(p[0]);
        close(p[0]);
        close(p[1]);
        execl("./sort", "sort", 0);
    }
}
