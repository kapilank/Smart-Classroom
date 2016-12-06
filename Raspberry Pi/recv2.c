#include <stdio.h>   /* standard in and output*/
#include <sys/socket.h> /* for socket() and socket functions*/
#include <arpa/inet.h>  /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>    
#include <string.h>     
#include <unistd.h>     /* for close() */



int main(int argc, char *argv[]){
 int sock, connected, bytes_received;
 int true = 1;  
    char recv_data[255];      
 char *replyBuffer;
 



    struct sockaddr_in server_addr,client_addr;    
    int sin_size;       
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket");
        exit(1);
    }

    if (setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&true,sizeof(int)) == -1) {
        perror("Setsockopt");
        exit(1);
    }

    server_addr.sin_family = AF_INET;         
    server_addr.sin_port = htons(2404);     
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    bzero(&(server_addr.sin_zero),8); 

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Unable to bind");
            exit(1);
    }

    if (listen(sock, 5) == -1) {
        perror("Listen");
        exit(1);
    }

 printf("\n*******Waiting main client port 2404");

 //while(1){  
        sin_size = sizeof(client_addr);
        connected = accept(sock, (struct sockaddr *)&client_addr,&sin_size);
        //printf("\n Got a connection from (%s , %d)",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));


       while ((bytes_received = recv(connected,&recv_data,255,0)) > 0){
         // printf("\nrecv= %s\n", recv_data);


 close(connected);

FILE *fptr;




fptr=fopen("class.strm","w");
   
  
  fprintf(fptr,"%s", recv_data);   
printf("\n %s \n ", recv_data);
fclose(fptr);


  }
bzero(recv_data,8);
 // int success = 1;
  //sprintf(replyBuffer, "%d", success); 
  //printf("reply buffer = %s\n", replyBuffer);
  //if (send(connected, replyBuffer, strlen(replyBuffer), 0) == -1)
    //perror("send() failed"); 
    //success = 0;




//} //while end

}
