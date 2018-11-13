//Jason Kim
//Systems -- Work#13
//DUE: 11-13-18

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo) {
  if (signo == SIGINT) {
    int file = open("err.txt", O_WRONLY | O_CREAT, 0644);
    lseek(file, 0, SEEK_END);
    write(file, "Program exited due to keyboard interruption.\n", sizeof("Program exited due to keyboard interruption.\n"));
    close(file);
    exit(0);
  }
  if (signo == SIGUSR1) {
    printf("PPID: %d\n", getppid());
  }
}

int main() {
  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);
  while(1) {
    printf("PID: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
