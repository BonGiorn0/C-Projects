#include <stdio.h>
#include <unistd.h>

int main(){
    for (size_t i = 0; i < 3; i++)
    {
        int pid = fork();
        if(pid == 0)
            printf("I'm %d, a child of a %d\n", getpid(), getppid());
        else
            printf("I'm %d, the daddy\n", getpid());
    }
    
    return 0;
}