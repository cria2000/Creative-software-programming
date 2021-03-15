#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ioctl.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<netinet/in.h>
#include<errno.h>
#define SERVER_PORT 5000
#define MAX(X,Y) ((X)>(Y)?(X) : (Y))

void prompt()
{
	printf("<You> ");
	fflush(stdout);

}
int main(int argc, char *argv[])
{
	int len, rc;
	int sockfd;
	char send_buf[4096];
	char recv_buf[4096];
	struct sockaddr_in serv_addr;
	struct timeval timeout;
	fd_set master_set, select_result;
	int max_sd;

	if(argc!=2) exit(1);
	if((sockfd=socket(AF_INET, SOCK_STREAM, 0))<0)
		exit(2);
	memset(&serv_addr, 0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port=htons(SERVER_PORT);

	if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
		exit(3);
	if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
		exit(4);
	FD_ZERO(&master_set);
	FD_SET(fileno(stdin), &master_set);
	FD_SET(sockfd, &master_set);
	max_sd=MAX(fileno(stdin), sockfd);

	timeout.tv_sec=3*60;
	timeout.tv_usec=0;
	printf("Connected to remote host. Start seding messages. \n");
	prompt();
	while(1){
		memcpy(&select_result, &master_set, sizeof(master_set));
		rc=select(max_sd=1, &select_result, NULL,NULL,NULL);
		if(1==(FD_ISSET(0, &master_set)))
		{
			gets(send_buf);
			send(sockfd, send_buf, strlen(send_buf),0);
			prompt();
			}
		else if(0!=(FD_ISSET(0,&master_set)))
		{
			rc=recv(sockfd, recv_buf, 4096,0);
			if(rc<0) exit(-9);
			if(rc==0)
			{
				printf("Server disconnected\n");
				pclose(sockfd);
				exit(0);
			}
			recv_buf[rc]=0;
			printf("\r%s\n", recv_buf);
			prompt();
		}
		else {
			pclose(sockfd);
			return 0;
		}
	}
	close(sockfd);
	return 0;
}
