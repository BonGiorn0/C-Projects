#include <stdio.h>
#include <unistd.h>

int main(){
    printf("It's before\n");

    char *cmd[] = {"file_counter", "$HOME/Progs++/SFMLProjects/Breakdown", NULL};
    execvp("../FileCounter/file_counter", cmd);

    perror("execvp");
    return 0;
}