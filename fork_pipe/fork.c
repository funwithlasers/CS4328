#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>

main(int argc, char *argv[])
{
    assert(argc > 1);
    for(int i = 1; i < argc; i++)
        argv[i - 1] = argv[i];
    argc--;
    argv[argc] = NULL;

    if(fork() < 0) printf("fork() failed");
    if(fork() == 0) //child
    {
        printf("from child: getpid() returns %d (child's pid)\n", getpid());
        printf("            getppid() returns %d (parent's pid)\n", getppid());
        if(execvp(argv[0], argv) < 0)
            printf("error: execvp failed");
        printf("child process ending\n");
    }
    else //parent
    {
        wait(NULL);
        printf("from parent: getpid() returns %d (parent's pid)\n", getpid());
    }
}
