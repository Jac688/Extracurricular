#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <pthread.h>

#define NAME_SIZE 20
#define BUF_SIZE 1024
#define PORT 6666
#define MAX_USER_NUM 256
// #include1<mysql/mysql.h>
// #include<sys/socket.h>
void * send_msg(void * arg);
void * recv_msg(void * arg);
char name[NAME_SIZE]="[Client]";

struct protocol{
    int type;
    bool state;
    char name[32];
    char data[64];
};

struct user{
    int fd;
    bool state;
    char name[32];
    char password[32];
};

struct user User[MAX_USER_NUM];

void broadcast(int index,struct protocol*msg)
{
    int i;
    char buf[128]={0};
    sprintf(buf,"%s say:%s\n",online[index].name ,msg->data);

    for(i=0;i<MAX_USER_NUM;i++)
    {// jump offline and sender self
        if((online[i].fd == -1)||(i == index))
        {
            continue;
        }
        write(online[i].fd,buf,strlen(buf));  
    }  
}

int main(int argc, char* argv[]){
    int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	int clnt_adr_sz;
	pthread_t t_id;

    pthread_mutex_init(&mutx, NULL);
	serv_sock = Socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET; 
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(PORT);

    Bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr);
	Listen(serv_sock, 5);
    
    return 0;
}