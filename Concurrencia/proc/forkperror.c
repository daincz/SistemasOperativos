#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main(void)
{
   pid_t pid;

   printf("Proceso principal: %d \n", getpid());
   pid = fork();
   switch(pid)
   {
      case -1:   /* error del fork() */
         perror("fork");
         break;
      case 0:    /* proceso hijo */
         printf("#PH Proceso %d; padre = %d \n", getpid(), getppid());
         break;
      default:   /* padre */
         printf("#PP Proceso %d; padre = %d \n", getpid(), getppid());
   }
}
