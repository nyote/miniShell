#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> //fork exec etc
#include <errno.h>

#define BUFSIZE 1024
static char child_stack[1048576];


int main(int argc, char *argv[]) {
  //char *line = NULL;

  //char **args;
  char *path = "/bin/";
  //char *cmd = cmdline;
  char *buffer;
  //buffer = malloc(sizeof(char) * buffer); //to be finished
  while(1){
    printf("Welcome to SHell, Use at your own risk. \n");
    printf("Shell>  ");

    buffer = read_cmd();
    if(strcmp(buffer,"exit\n") || strcmp(buffer,"quit\n")){
      break;
    }
    else{parseline();}
  }
  free(buffer);
  return EXIT_SUCCESS;
}
#define DELIM " \n\t"
  void parseline(char *cmd){
    char *toke1, *toke2;
    toke1 = strtok(cmd,DELIM);
    toke2 = strtok(NULL,DELIM);
    executeline(toke1,toke2);
  }

  static int childf_newnet(){
    char *args[] = {"ip","link",NULL};

    if(execvp("ip",args)<0){
      printf("The requested file does not exist\n");
    }
    Return 0;
  }


  static int childf_newns(){
    pid_t thepid;
    thepid = fork();  //create subshell definitely not fork
    thepid = getpid();
  }

  static int clonechildf_newuts(){
    printf("New UTS namespace node name is changed to: ");
    sethostname("NewOS", 9);
  }

  static void uts_nodename(){// NEWUTS
    struct utsname uts_name;
    uname(&uts_name);
    printf("%s\n", uts_name.nodename);
  }

  void executeline(char *arg1, char arg2){
    pid_t newpid, wpid, cpid;
    int status;

    if(strcmp("clone",arg1) == 0){
      if(strcmp("ipc",arg2) ==0){   //NEWIPC

      }
      else if(strcmp("uts", arg2) == 0){  //NEWUTS
        cpid = clonechildf_newuts,child_stack+1048576, CLONE_NEWPID |
CLONE_NEWUTS | SIGCHLD, NULL); //try out
        sleep(1);
        printf(“Original UTS node: ”);
        uts_nodename();
        //call waitpids in functions as well as at the end of executeline
      }
      else if(strcmp("user",arg2) == 0){  //NEWUSER

      }
      else if(strcmp("new", arg2) == 0){
        printf(“NEWNET Namespace:\n”);
        cpid = clone(childf_newnet,child_stack+1048576, CLONE_NEWPID | CLONE_NEWNET | SIGCHLD, NULL);
      }
      else if(strcmp("ns",arg2) == 0){ //NEWNS
        cpid = clone(childf_newns,child_stack+1048576, CLONE_NEWPID |
CLONE_NEWNS | SIGCHLD, NULL);
      }
    }

    else{
    newpid = fork();  //create a new child process that is the same as parent process

    if(newpid < 0){
      fprintf(stderr, " Child Process could not be created %s\n",strerror(errno) );  //is this correct?
      exit(EXIT_FAILURE);
    } //doesn't create a child process when pid number is negative

    else if(newpid == 0){
      if(execvp(*args, args) < 0){  //if (execvp(args[0], args) == -1) an example
        fprintf(stderr, "Exec failed %s\n", strerror(errno)); //could not make it to be independent
      }
      exit(EXIT_FAILURE);
    }
    else{
      do{
        pid_t wpid = waitpid(pid_t newpid, int *status, WUNTRACED); //WUNTRACED = return if a child has stopped
        //with waitpit(), wait until a specific process finishes based on its pid.

        //there needs to be a while statement
        }
      }
    }
  }

  char *read_cmd(void)
  {
    char *line = NULL;
    ssize_t bufsize = 0; // have getline allocate a buffer for us
    getline(&line, &bufsize, stdin);
    return line;
  }
