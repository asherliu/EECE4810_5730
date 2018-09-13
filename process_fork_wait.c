/* Dr. Hang Liu 
 * UMass Lowell
 *
 * function specific: 
 * ->fork(): http://pubs.opengroup.org/onlinepubs/009695399/functions/fork.html
 * ->wait(): http://pubs.opengroup.org/onlinepubs/009695399/functions/wait.html
 * ->getpid(): http://pubs.opengroup.org/onlinepubs/009695399/functions/getpid.html
 * */

#include <sys/types.h>
#include <sys/wait.h>       // Necessary on my machine for wait() function
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();       // Create a child process

    if (pid < 0) {      // Error occurred
        fprintf(stderr, "Fork failed");
        return 1;
    }
    else if (pid == 0) {    // Child process
        printf("Child: listing of current directory\n\n");
        execlp("/bin/ls", "ls", NULL);
    }
    else {              // Parent process—wait for child to complete
        printf("Parent: waits for child to complete\n\n");
        wait(NULL);
        printf("Child complete\n\n");
    }
    return 0;
}
