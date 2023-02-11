#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int spawn_process(const char * program, char * arg_list[]) {
pid_t child_pid = fork();

if (child_pid < 0) {
    perror("Error while forking");
    return 1;
} else if (child_pid == 0) {
    if (execvp(program, arg_list) == 0);
    perror("Execution failed");
    return 1;
} else {
    return child_pid;
}
}

int main() {
char *arg_list_A[] = {"/usr/bin/konsole", "-e", "./bin/processA", NULL};
char *arg_list_B[] = {"/usr/bin/konsole", "-e", "./bin/processB", NULL};

pid_t pid_procA = spawn_process("/usr/bin/konsole", arg_list_A);
pid_t pid_procB = spawn_process("/usr/bin/konsole", arg_list_B);

int status;
waitpid(pid_procA, &status, 0);
waitpid(pid_procB, &status, 0);

printf("Main program exiting with status %d\n", status);

return 0;
}
