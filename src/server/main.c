#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  pid_t	pid = getpid();

  printf("pid: %u\n", pid);
  pause();
}