/****************** CLIENT CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE_COMMUNICATION 99998
#define BUFFER_SIZE 1024
int CONNECTED = 0;
char buffer[1024];

void Receive(int newSocket);
char *trim (char *s);
void doProcess(int newSocket);

char *trim (char *s) {
	int i = strlen(s) - 1;
	if ((i > 0) && (s[i] == '\n'))
		s[i] = '\0';
	return s;
}

void doProcess(int newSocket) {
	char string[256];
	fgets(string, 254, stdin);
	char tmp[] = "";
	strcpy(tmp, trim(string));
	strcpy(buffer,string);
	send(newSocket,buffer,BUFFER_SIZE,0);
	Receive(newSocket);
}

void Receive(int newSocket) {
	/*---- Read the message from the server into the buffer ----*/
	recv(newSocket, buffer, SIZE_COMMUNICATION, 0);
	/*---- Print the received message ----*/
	printf("%s \n",trim(buffer)); 
	if (strncmp(buffer, "BYE", 3) == 0) {
		exit(1);
	}
	doProcess(newSocket);
}


int main(){
  int clientSocket;
  char buffer[BUFFER_SIZE];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  /*---- Create the socket. The three arguments are: ----*/
  /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  /*---- Configure settings of the server address struct ----*/
  /* Address family = Internet */
  serverAddr.sin_family = AF_INET;
  /* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(7891);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  /* Set all bits of the padding field to 0 */
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*---- Connect the socket to the server using the address struct ----*/
  addr_size = sizeof serverAddr;
  if (connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size) < 0) {
	printf("Error on accept \n");
	exit(1);
  }
  strcpy(buffer,"BONJ");
  send(clientSocket,buffer,BUFFER_SIZE,0);
  Receive(clientSocket);

  return 0;
}