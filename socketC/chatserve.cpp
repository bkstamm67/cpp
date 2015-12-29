/***************************
 * Program Filename:  chatserve.cpp
 * Author:  Brian Stamm
 * Date:  11.1.15
 * Notes:  Refer to the README.txt for any notes.
 * ***********************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <iostream>
#include <cstring>

using namespace std;

/************
 * Function:  error
 * Variables:  string and an int
 * Outcome:  It prints the string as an error message, and 
 * passess the int to exit (setting exit status).
 * **********/
void error(const char *msg, int x){
   perror(msg);
   exit(x);
}

/****************
 * Function:  toSend
 * Variables:  socketFile, array of chars, and its size
 * Outcomes:  It connects to the socket and sends the array and its
 * size through the socket.
 * **************/
void toSend(int socket, char* message, int size){
   int bytes = 0;

   while(bytes != size){
      int current;
      current = send(socket, message, size, 0);
      if(current == -1){
	 error("Error in the writing.\n", 1);
      }
      bytes += current;
   }
}

/*******************
 * Function:  toReceive
 * Variables:  socketfile, array of chars, and its size
 * Outcomes:  It connects to the socket and fills the array up to its
 * size.
 * *****************/
void toReceive(int socket, char* message, int size){
   int bytes = 0;

   while(bytes != size){
      int current = 0;
      current = recv(socket, message, size, 0);
      if(current == -1){
	 error("Error in the reading.\n", 1);
      }
      bytes += current;
   }
}

/*******************
 * Function:  reset
 * Variables:  char array and its size
 * Outcomes:  It connects to the socket and fills the array
 * up to its size
 * ****************/
void reset(char* message, int size){
   int i;
   for(i = 0; i<size; i++){
      message[i] = '\0';
   }
}

/*******************
 * Function:  checker
 * Variables:  2 char arrays 
 * Outcomes:  It takes the first 5 chars of the message char
 * array and compares it to the truth array.  If they are equal,
 * it returns 1, if not, then 0.
 * *****************/
int checker(char* message, char* truth){
   char checker[5];
   int i;
   for(i = 0; i<5; i++){
      checker[i] = message[i]; 
   }
   for(i = 0; i<5; i++){
      if(checker[i] != truth[i]){
	 return 0;
      }
   }
   return 1;
}

/**********************
 * Function:  stripper
 * Variables:  char array and its size
 * Outcome:  It goes through the array of chars and strips off the
 * newline character, replacing it with an end character.
 * ******************/
void stripper(char* message, int size){
   int i;
   for(i = 0; i<size; i++){
      if(message[i] == '\n'){
	 message[i] = '\0';
      }
   }
}

//Main.
int main(int argc, char** argv){
   
   //Creates the initial variables, for sockets 
   int sockfd, newsockfd, portno;
   socklen_t clilen;
   struct sockaddr_in sAdd, cAdd;
   
   if(argc < 2){
      error("Error.  Need port.\n", 1);
   }  
   
   //Checks to make sure user passes a port #, basic error checking.
   char myName[10];
   char yourName[10];
   char ender[5] = {'\\', 'q', 'u', 'i', 't'};
   
   //Gets user name from user
   cout << "User name: ";
   fgets(myName, 10, stdin);
   
   //Gets Host name information and prints to screen.
   char name[500];
   name[499] = '\0';
   gethostname(name, sizeof(name) -1);
   cout << "Host name for connections:  ";
   cout << name << endl;
   
   //Creates a socket
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0){
      error("Error opening socket.\n", 1);
   }
   
   //Initializing
   memset((char*)&sAdd, 0, sizeof(sAdd));	//fills string sAdd with 0's
   portno = atoi(argv[1]);			//Gets port number
   sAdd.sin_family = AF_INET;			//Sets values for sAdd
   sAdd.sin_addr.s_addr = INADDR_ANY;		//Accepts anyone who comes knocking
   sAdd.sin_port = htons(portno);		//Sets port
   
   //Sets up bind
   if (bind(sockfd, (struct sockaddr *) &sAdd, sizeof(sAdd)) < 0){
      error("Error in binding\n", 1);
   }
   
   //Starts listening, can take up to 5 calls at one time.
   listen(sockfd, 5);
   clilen = sizeof(cAdd);	//Client socket
   while(1){
      int status;		//Used for child PID
      newsockfd = accept(sockfd, (struct sockaddr *) &cAdd, &clilen);
      
      if(newsockfd < 0){
	 error("Error on accepting.\n", 1);
      }

      //Then forks off a process to do the work
      pid_t childPID = fork();
      if(childPID < 0){
	 error("PID ERROR!\n", 1);
      }

      //In child process
      if(childPID == 0){
	 close(sockfd);	

	 //Gets, sends name of host/client
	 toReceive(newsockfd, yourName, sizeof(yourName));
	 toSend(newsockfd, myName, sizeof(myName));

	 //Stips off \n from the names
	 stripper(yourName, 10);
	 stripper(myName, 10);
	 
	 //Initializes communication
         int truth = 1;
	 while(truth){
	    char messageSend[500];
	    char messageGotten[500];
	    
	    //First receives from client
	    toReceive(newsockfd, messageGotten, sizeof(messageGotten));	    
	    cout << yourName << ":  " << messageGotten <<endl;
	    //Ends loop, no need for server to reply
	    if(checker(messageGotten, ender)){
	       truth = 0;
	    }
	    else{
	       //Server reply
	       cout << myName <<": ";
	       fgets(messageSend, 500, stdin);
	       //Checks if server quit
	       if(checker(messageSend, ender)){
		  truth = 0;
	       }
	       //Sends message
	       toSend(newsockfd, messageSend, sizeof(messageSend));
	    }
	    //Clears out messages  
	    reset(messageSend, 500);
	    reset(messageGotten, 500);
	 }	 
	 close(newsockfd);
	 exit(0);
      }
      //In parent process
      else{
	 pid_t endedPID = waitpid(childPID, &status, 0);
	 if(endedPID == -1){
	    error("Error with endedPID\n", 1);
	 }
	 //close(newsockfd);
      }
   }
   return 0;
}

