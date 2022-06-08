#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//#include <fcntl.h>
#include <pthread.h>

#define NAME_SIZE 20
#define BUF_SIZE 1024
#define PORT 6666
// #include<mysql/mysql.h>
// #include<sys/socket.h>

char name[NAME_SIZE]="[Client]";

void * recv_msg(void * arg);
int regist(int fd);
int login(int fd);
void Private(int fd);
void groupChat(int fd);
int menu(int choice);
bool connectdb();

int main(int argc, char* argv[])
{   
    int choice = 0;
	
    sockfd = Socket(PF_INET,SOCK_STREAM,0); 
    server_addr.sin_family =  PF_INET; 
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("42.192.120.19");

    addrlen = sizeof(struct sockaddr_in);
    Connect(sockfd,(struct sockaddr*)&server_addr,addrlen);
    
    pthread_create(&pid, NULL, recv_msg, NULL); 
    menu(choice);
    return 0;
}

struct protocol{
    int cmd;
    bool state;
    char name[32];
    char data[64];
};

// struct user{
//     int fd;
//     bool state;
//     char name[32];
//     char password[32];
// };

struct protocol{
    int type;
    bool state;
    char name[32];
    char msg[32];
};

pthread_t pid;
bool state = 0;
int sockfd;
int addrlen;
struct sockaddr_in server_addr; 

int menu(int choice)
{
    while(1){
        // Select from the main menu
        if(state == 1){
            printf("\n\t#################################################\n");
            printf("\t*\t\t\t\t\t\t*\n");
            printf("\t*\t\t    Menu\t\t\t*\n");
            printf("\t*\t\t\t\t\t\t*\n");
            // printf("\t*\t1. Registrate identity\t\t*\n");
            // printf("\t*\t2. Login account\t\t\t*\n");
            printf("\t*\t1. Participate in the group chat\t*\n");
            printf("\t*\t2. Private chat\t\t\t\t*\n");
            printf("\t*\t3. Send file to others\t\t\t*\n");
            printf("\t*\t4. Quit\t\t\t\t\t*\n");
            printf("\t*\t\t\t\t\t\t*\n");
            printf("\t#################################################\n");
            printf("\n");
            printf("Please use the following menu to start(1/2/3/4): ");
        } 
        else{
            printf("\n\t#################################################\n");
            printf("\t*\t\t\t\t\t\t*\n");
            printf("\t*\t\t    Menu\t\t\t*\n");
            printf("\t*\t\t\t\t\t\t*\n");
            printf("\t*\t5. Registrate identity\t\t*\n");
            printf("\t*\t6. Login account\t\t\t*\n");
            // printf("\t*\t7. Quit\t\t\t\t\t*\n");
            printf("\t*\t\t\t\t\t\t*\n");
            printf("\t#################################################\n");
            printf("\n");
            printf("Please use the following menu to start(1/2/3): ");
        }
        scanf("%d", &choice); 
        int min01, max01;
        if(state == 1)
        {
            min01 = 1;
            max01 = 4;
        }else if(state == 0){
            min01 = 5;
            max01 = 6;
        }
        if(choice<min01 || choice > max01)
        {
            printf("Please enter the number in the correct range! \n");
            continue;
        }
        switch(choice)
        {
            case 1:
                printf("Welcome to register your account \n");
                regist(sockfd);
                break;
            case 2:
                printf("Welcome to register your account \n");
                login(sockfd);
                break;
            case 3:
                printf("Welcome to the chat group! \n");
                groupChat(sockfd);
                break;
            case 4:
                printf("Creating a connection... \n");
                /* code */
                Private(sockfd);
                break;
            case 5:
                printf("Welcome to the file transfer system! \n");
                /* code */
                fileTransfer(sockfd);
                break;
            case 6:
                /* code */
                quit(sockfd);
                break;    
            default:
                printf("Please enter a number between 1 and 4! \n");
                break;
        }
        if(choice == 4 && state == 0)
        {
            exit(0);
        }
    }	
}

void Private(int sockfd){


}

void fileTransfer(int sockfd){

}

void *recv_msg(void *arg)
{   
    int sock=*((int*)arg);
    int final_length = NAME_SIZE+BUF_SIZE;
	char name_msg[final_length];
	int str_len;
    memset(name_msg,0,sizeof(name_msg));
	while(1)
	{
		str_len=read(sock, name_msg, NAME_SIZE+BUF_SIZE-1);
		if(str_len==-1) 
			return (void*)-1;
		name_msg[str_len]=0;
		fputs(name_msg, stdout);
	}
	return NULL;
}

int regist(int fd)
{
    struct protocol msg;
    msg.type = 1;

    printf("Please input your name: "); 
    scanf("%s",msg.name);
    printf("Plsase input your passwd: "); 
    scanf("%s",msg.msg);

    write(sockfd,&msg,sizeof(msg));
    read(sockfd,&msg,sizeof(msg));
    if(msg.state == false)
    {
        printf("Name had exist,try again!\n"); 
        getchar();
        getchar();
        return -1;
    }
    else{
        printf("Regist success!\n");
        getchar();
        getchar();
        return 0;
    }
}

int login(int sockfd){
    struct protocol msg;
    msg.type = 2; 
    printf("Please input your name: "); 
    scanf("%s", msg.name);
    printf("Please input your passwd: "); 
    scanf("%s",msg.msg);
    write(sockfd, &msg, sizeof(msg));
    read(sockfd, &msg, sizeof(msg));
    if(msg.state != true)
    {
        printf("Login fail!\n");
        getchar();
        getchar();
        state = -1;
        return 0;
    }else{
        printf("Login success!\n");
        getchar();
        getchar();
        state = 1;
        return 1;
    }
}

void groupChat(int sockfd){
    struct protocol msg;
    
    msg.type = 3;
    printf("say:\n#");
    scanf("%s", msg.msg);
    
    write(sockfd, &msg, sizeof(msg));
    return (void)NULL;
}

int quit(int fd)
{
    close(fd);
    state = -1;
}

