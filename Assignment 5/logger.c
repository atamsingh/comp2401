#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUF  64

FILE *logFile;
int myListenSocket;

void handle(int);

int main()
{
  signal(SIGINT, handle);
  FILE *configFile;
  char logName[MAX_BUF];
  char ip[MAX_BUF];
  int  port;
  char str[MAX_BUF];
  int  clientSocket;
/* get IP address and port number from config file */
  if (!(configFile=fopen(".config","r"))) {
    printf("cannot read config file...\n");
    exit(1);
  }
  fscanf(configFile, "%s", ip);
  fscanf(configFile, "%d", &port);
  fclose(configFile);

/* create name of log file;  format is
    username followed by timestamp
    usernameYYYYMMDDHHMM.log */
  strcpy(logName, getenv("USER"));
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(str, "%4d%02d%02d%02d%02d",
          tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
          tm.tm_hour, tm.tm_min);
  strcat(logName, str);
  strcat(logName, ".log");

/* open log file for writing */
  if (!(logFile=fopen(logName,"w"))) {
    printf("cannot write to file...\n");
    exit(1);
  }
/* set up connection, receive commands typed
   into cuShell process, and log them to the
   logFile */
  struct sockaddr_in  myAddr, clientAddr;
  int i, addrSize, bytesRcv;
  char buffer[30];
  //Create socket
  myListenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (myListenSocket < 0) {
    printf("eek! couldn't open socket\n");
    exit(-1);
  }
  int optval = 1;
  setsockopt(myListenSocket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
/* setup my server address */
  memset(&myAddr, 0, sizeof(myAddr));
  myAddr.sin_family = AF_INET;
  myAddr.sin_addr.s_addr = inet_addr(ip); //inet_addr(ip)
  myAddr.sin_port = htons((unsigned short) port);

/* bind my listen socket */

  i = bind(myListenSocket, 
           (struct sockaddr *) &myAddr,
           sizeof(myAddr));
  if (i < 0) {
    printf("eek! couldn't bind socket\n");
    exit(-1);
  }


/* listen */
  i = listen(myListenSocket, 5);
  if (i < 0) {
    printf("eek! couldn't listen\n");
    exit(-1);
  }

/* wait for connection request */

  addrSize = sizeof(clientAddr);

  while(1){
    clientSocket = accept(myListenSocket,
                         (struct sockaddr *) &clientAddr,
                         &addrSize);
    if (clientSocket < 0) {
      printf("eek! couldn't accept the connection\n");
      exit(-1);
    }
    /* read message from client and do something with it */
    while (1) {
      bytesRcv = recv(clientSocket, buffer, sizeof(buffer), 0);
       if(bytesRcv == 0){
        printf("\nClient Disconnected.. Timing out\n");
        break;
      }
      buffer[bytesRcv] = 0;
      printf("$ : %s\n", buffer);
      fprintf(logFile, "[%4d-%02d-%02d-%02d:%02d:%02d]:\t%s\n",
          tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
          tm.tm_hour, tm.tm_min, tm.tm_sec, buffer);
      if(strcmp(buffer,"quit") == 0 || strcmp(buffer,"exit") == 0)
        break;
    }
    close(clientSocket);
    if(strcmp(buffer, "exit") == 0)
      break;
  }
  close(myListenSocket);
  fclose(logFile);

  return 0;
}

void handle(int signal)
{
  printf("Process Interrupted: Exiting Program\n");
  fclose(logFile);
  close(myListenSocket);
  exit(0);
}
