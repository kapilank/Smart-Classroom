#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
//#include "reader.c"

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n,abc,numbytes;
int  aa,fileLen;
    struct sockaddr_in serv_addr;
    struct hostent *server;
 //struct sockaddr_in serv_addr;
//int id=1000;
uint32_t uv=0;
char init[30]="smart";
char buff2[5];
int d;
char buff1[35]="class";

FILE *fp;
FILE *fp1;
FILE *fpp1;
FILE *fptr;
//system("./reader.bin");

 // fpp1 = fopen("/tmp/tmp.strm", "r");
//if(fpp1==NULL){
//      printf("Error!");   
//     exit(1);             
 //  }
//  fscanf(fpp1,"%d",&d); 
//printf("%d",d);
 /*fseek(fpp1, 0, SEEK_END);
fileLen = ftell(fp1);	
fseek(fpp1, 0, SEEK_SET);
fread(buff2, fileLen, 1, fpp1);
fclose(fpp1);

printf("%d \n ",buff2 );
*/

fptr=fopen("req.dat","w");
   if(fptr==NULL){
      printf("Error!");   
     exit(1);             
   }
  
  fprintf(fptr,"%s %s",init,buff1);   
printf("\n %s \n ",buff1);
   fclose(fptr);
    char buffer[9590];
    char buf[10];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
   
    fp1=fopen("req.dat","r"); 
    bzero(buf,10); 
  while((abc=fread(buf,1,10,fp1))>0)

{
//   numbytes = write(sockfd,buffer,strlen(buffer));
if ((numbytes=sendto(sockfd, buf, abc, 0,
            (struct sockaddr *)&serv_addr, sizeof serv_addr)) == -1) {
      perror("sendto");
      exit(1);
  }
//printf("Please enter the message: ");

    //fgets(buffer,100,fp);
//fread(buffer,1,100,fp);
//abc=fread(buffer,1,79590,fp);
//numbytes = write(sockfd,"po_da_paki",strlen(buffer));
/*aa=fread(buf,1,10,fp1);
if ((numbytes=sendto(sockfd,buf, aa, 0,
            (struct sockaddr *)&serv_addr, sizeof serv_addr)) == -1) {
      perror("sendto");
      exit(1);
  }
  printf("sent1 %d bytes1 to %s\n", numbytes, inet_ntoa(serv_addr.sin_addr));
fclose(fp1);
*/
/*
fp=fopen("1.jpg","rb");
    bzero(buffer,9590); 
  while((abc=fread(buffer,1,9590,fp))>0)

{
//   numbytes = write(sockfd,buffer,strlen(buffer));
if ((numbytes=sendto(sockfd, buffer, abc, 0,
            (struct sockaddr *)&serv_addr, sizeof serv_addr)) == -1) {
      perror("sendto");
      exit(1);
  }*/
 // printf("sent %d bytes to %s\n", numbytes, inet_ntoa(serv_addr.sin_addr));//
printf("****sending***");
 
   // if (n < 0) 
     //    error("ERROR writing to socket");
    //bzero(buffer,79590);
    //n = read(sockfd,buffer,79590);
    //if (n < 0) 
      //   error("ERROR reading from socket");
    //printf("%s\n",buffer);

}

// fclose(fp);
fclose(fp1);

    close(sockfd);
    return 0;
}
