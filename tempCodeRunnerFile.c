
      }
      pid_t pid = fork();

      if(pid == 0){
         execve(args[0] , args);

      }else if(pid >0){
         int *status;
         waitpid(pid,&status , 0);`
      }else{
         perror("how did we get here");
      }


      args[i] = NULL;