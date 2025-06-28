
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

// very simple shell in c.


#define max_input 1024
#define max_args 64
int main(){
   char input[max_input];
   char* args[max_args];
   while(1){

      printf("$~");
      fflush(stdout);

      if(fgets(input, max_input, stdin) == NULL){
         perror("error inputing");
      }
      input[strcspn(input,"\n")] = '\0';

      if(strcmp("exit", input) == 0){
         printf("Exiting.....\n");
         break;
      }
      int i =0;
      char *token = strtok(input," ");

      while(token != NULL &&  i < max_args){
         args[i++] = token;
         token = strtok(NULL," ");
      }
      args[i] = NULL;

      pid_t pid = fork();

      if(pid == 0){
         execvp(args[0] , args);
         perror("zsh: invalid command try again.");

      }else if(pid >0){
         int status;
         waitpid(pid,&status , 0);
      }else{
         perror("how did we get here");
      }


   






      


   }


}


