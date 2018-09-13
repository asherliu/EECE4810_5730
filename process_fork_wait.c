/* Dr. Hang Liu 
 * UMass Lowell
 *
 * function specific: 
 * ->fork(): http://pubs.opengroup.org/onlinepubs/009695399/functions/fork.html
 * ->wait(): http://pubs.opengroup.org/onlinepubs/009695399/functions/wait.html
 * ->getpid(): http://pubs.opengroup.org/onlinepubs/009695399/functions/getpid.html
 * ->sleep(): //http://pubs.opengroup.org/onlinepubs/007904875/functions/sleep.html
 *
 ********************************
 * You can use top to check the process id of the child and parent processes.
 * */

#include <sys/types.h>
#include <sys/wait.h>       // Necessary on my machine for wait() function
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t ret;

    ret = fork();       // Create a child process
    pid_t mypid = getpid();

    if (ret < 0) {      // Error occurred
        fprintf(stderr, "Fork failed");
        return 1;
    }
    else if (ret == 0) {    // Child process
        printf("Child, pid = %d.\n\n", mypid);
        sleep(10);//http://pubs.opengroup.org/onlinepubs/007904875/functions/sleep.html
        //execlp("/bin/ls", "ls", NULL);
    }
    else {              // Parent process—wait for child to complete
        printf("Parent, pid = %d.\n\n", mypid);
        sleep(10);
        wait(NULL);
        printf("Child complete\n\n");
    }
    return 0;
}
