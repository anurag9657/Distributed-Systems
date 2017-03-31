

#include<stdio.h>
#include<stdlib.h> //for exit
#include<string.h> // for bzero
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
int sockfd;
struct sockaddr_in server_addr;
char send_data[1024],recv_data[1024];
int bytes_received;

//Step-1
if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
 {
  printf("\nSocket creation problem !!!");
  exit(1);
 }

//Step-2 
 server_addr.sin_family=AF_INET;
 server_addr.sin_port=htons(5000);
 server_addr.sin_addr.s_addr=INADDR_ANY;
 bzero(&(server_addr.sin_zero),8);
 
//Step-3
 if(connect(sockfd,(struct sockaddr *)&server_addr,sizeof(struct sockaddr))==-1)
 {
  printf("\nSocket connection problem !!!");
  exit(1);  
 }

 
 while(1)
 {
     //Step-3.1-Receiving data
     bytes_received=recv(sockfd,recv_data,1024,0);
     recv_data[bytes_received]='\0';
     if(strcmp(recv_data,"q")==0 || strcmp(recv_data,"Q")==0)
     {
         close(sockfd);
         break;
     }
     else
        printf("\n RECIEVED DATA = %s",recv_data);

     //Step-3.2-Sending data
     printf("\nSEND Q or q to quit : ");
     gets(send_data);

     if(strcmp(send_data,"q")==0 || strcmp(send_data,"Q")==0)
     {
         send(sockfd,send_data,strlen(send_data),0);
         close(sockfd); //Step-4-closing socket
         break;
     }
     else
      
         send(sockfd,send_data,strlen(send_data),0);  
 }
return(0);
}

