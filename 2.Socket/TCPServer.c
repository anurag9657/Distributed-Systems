TITLE:     Socket Programming(Server)
ROLL  NO. B3082

#include<stdio.h>
#include<stdlib.h> //for exit
#include<string.h> // for bzero
#include<sys/types.h> //includes datatypes used in system calls
#include<sys/socket.h> //includes structures needed for sockets
#include<netinet/in.h> //includes constsnts & structures needed
		       //for internet domain address


int main()
{
 int sockfd,newsockfd;
 struct sockaddr_in server_addr,client_addr;
 char send_data[1024],recv_data[1024];
 int client_len;
 int bytes_received;

 //step-1-Creation of Socket
 if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
 {
  printf("\nSocket creation problem !!!");
  exit(1);
 }
 
 //step-2-Initializing Server info
 server_addr.sin_family=AF_INET;
 server_addr.sin_port=htons(5000);
 server_addr.sin_addr.s_addr=INADDR_ANY;
 bzero(&(server_addr.sin_zero),8);

 //step-3-binding 
 if(bind(sockfd,(struct sockaddr *)&server_addr,sizeof(struct sockaddr))==-1)
 {
  printf("\nSocket binding problem !!!");
  exit(1);  
 }

 //step-4-listining
 if(listen(sockfd,5)==-1)
 {
  printf("\nSocket listening problem !!!");
  exit(1);    
 }

 printf("TCPServer is waiting for client on port no 5000");
 fflush(stdout);
 
 //step-5-Accepting connection request
 while(1)
 {
   client_len=sizeof(struct sockaddr);
   newsockfd=accept(sockfd,(struct sockaddr *)&client_addr,&client_len);
   //step-5.1-sending data
   while(1)
   {
     printf("\nSEND Q or q to quit : ");
     gets(send_data);

     if(strcmp(send_data,"q")==0 || strcmp(send_data,"Q")==0)
     {
         send(newsockfd,send_data,strlen(send_data),0);
         close(newsockfd);
         break;
     }
     else
         send(newsockfd,send_data,strlen(send_data),0);

     //step-5.2-Receiving Data
     bytes_received=recv(newsockfd,recv_data,1024,0);
     recv_data[bytes_received]='\0';
     if(strcmp(recv_data,"q")==0 || strcmp(recv_data,"Q")==0)
     {
         close(newsockfd);
         break;
     }
     else
        printf("\n RECIEVED DATA = %s",recv_data);

     fflush(stdout);
   }
 }
 // before closing server, closing socket
 close(sockfd);
 return(0);
}

