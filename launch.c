//
// Created by Phillip Dumitru on 2022-11-26.
// A simple application to launch UNIX programs in complete silence
// STDOUT and STDERR are redirected to dev null, and then the program is launched
//
#include "launch.h"

pid_t launch(char *argv[]){
    pid_t pid = fork();
    if(!pid){
        // Child
        int fd_dev_null = open("/dev/null", O_RDWR);
        if(fd_dev_null < 0){
            perror("Error opening /dev/null\n");
            exit(EXIT_FAILURE);
        }
        printf("Launching...\n");
        dup2(fd_dev_null, STDOUT_FILENO);
        dup2(fd_dev_null, STDERR_FILENO);
        execvp(argv[0], argv);
        exit(0);
    } else {
        // Parent
        sleep(1);
        if(waitpid(pid,NULL,WNOHANG) == 0){
            return pid;
        } else {
            return -1;
        }
    }
}

void usage(){
    printf("Usage: launch <cmd> <cmd args>\n");
}

int main(int argc, char *argv[]) {
    if(argc < 2){
        usage();
        return 0;
    }
    pid_t pid = launch(++argv);
    if(pid < 0){
        perror("Error Launching process\n");
    } else {
        printf("Launched process with pid: %d\n", pid);
    }
    exit(0);
}