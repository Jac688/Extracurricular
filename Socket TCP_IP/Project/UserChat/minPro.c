#include "network.h"


//define global variables
#define MAX_USER 256
#define BUF_SIZE 128
#define Login 1
#define Logout 0

int clnt_cnt = 0;
int clnt_socks[MAX_USER];
int user_cnt = 0;
struct User users[MAX_USER];

pthread_mutex_t mutx;

void * handle_clnt(void * arg);
int userRegister(struct User user);
int userLogin(struct User user);
char* findUser(struct User user);
void groupChat(struct User user);
void privateChat(struct User user, char * name);
void send_msg_group(char * msg, int len, int sq);
void send_msg_private(char * msg, int len, int sq, char * name);
void fileTrans();


int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s <Port>\n", argv[0]);
		exit(1);
	}

	//variable initialization
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	socklen_t clnt_adr_sz;
	pthread_t t_id;

	//socket's creation
	serv_sock = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&serv_adr, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_port = htons(atoi(argv[1]));
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);

	Bind(serv_sock, (SA*)&serv_adr, sizeof(serv_adr));

	Listen(serv_sock, MAX_USER);

	while(1)
	{
		clnt_adr_sz = sizeof(clnt_adr);
		clnt_sock = Accept(serv_sock, (SA*)&clnt_adr, &clnt_adr_sz);

		pthread_mutex_lock(&mutx);
		clnt_socks[clnt_cnt++] = clnt_sock;
		pthread_mutex_unlock(&mutx);
		
		pthread_create(&t_id, NULL, handle_clnt, (void*)&clnt_sock);
		pthread_detach(t_id);
		printf("Connected client: IP: %s\n", inet_ntoa(clnt_adr.sin_addr));
	}

	close(serv_sock);
	return 0;
}

void * handle_clnt(void * arg)
{
	int clnt_sock = *((int*)arg);
    char buf[BUF_SIZE];
    struct User user;
    struct protocol conn;

    if(read(clnt_sock, buf, BUF_SIZE) < 0)
    {
        write(clnt_sock, "Server cannot receive user's information\n", BUF_SIZE);
        exit(1);
    }

    if(read(clnt_sock, &conn, sizeof(conn)) < 0)
    {
        write(clnt_sock, "Server cannot receive user's information\n", BUF_SIZE);
        exit(1);
    }

    strcpy(user.name, conn.name);
    strcpy(user.password, conn.msg);
    user.fd = clnt_sock;
    user.state = Login;

	//Login / Register
	if(buf[0] == '1')
	{
        if (userRegister(user) == -1) {
            printf("Register failed\n");
            exit(1);
        }
    }
	else if(buf[0] == '2')
    {
        if (userLogin(user) == -1) {
            printf("Login failed\n");
            exit(1);
        }
    }
	else
        return;
    bzero(buf,BUF_SIZE);

    if((read(user.fd, buf, BUF_SIZE)) < 0)
        write(user.fd, "read() error", BUF_SIZE);

	switch(buf[0]){
		case '1':
		    groupChat(user);
		case '2':
			privateChat(user, conn.msg);
		case '3':
		    fileTrans();
		default:
            exit(0);
	}
}

int userRegister(struct User user)
{
    pthread_mutex_lock(&mutx);
    for (int i = 0;i < user_cnt;i++)
    {
        if(users[i].name == user.name) {
            return -1;
        }
    }
    users[user_cnt++] = user;
    pthread_mutex_unlock(&mutx);
    return 0;
}

int userLogin(struct User user)
{
    char password[64];
    if(findUser(user) != NULL)
        strcpy(password, findUser(user));
    if(strcmp(password, user.password))
        return 0;
    return -1;
}

char* findUser(struct User user)
{
    pthread_mutex_lock(&mutx);
    for(int i = 0;i < user_cnt;i++)
    {
        if(strcmp(users[i].name, user.name))
            return users[i].password;
    }
    pthread_mutex_unlock(&mutx);
    return NULL;
}

void groupChat(struct User user)
{
    int str_len;
    char buf[BUF_SIZE];
    int clnt_sock = user.fd;
    while((str_len = read(clnt_sock, buf, BUF_SIZE)) != 0)
        send_msg_group(buf, sizeof(buf), clnt_sock);

    //remove the current clnt_sock from the array
    pthread_mutex_lock(&mutx);
    for (int i = 0; i < clnt_cnt;i++)
    {
        if (clnt_sock == clnt_socks[i])
        {
            while(i++ < clnt_cnt - 1)
                clnt_socks[i] = clnt_socks[i + 1];
            break;
        }
    }
    for (int i = 0; i < user_cnt;i++)
    {
        if (strcmp(user.name, users[i].name))
        {
            users[i].state = Logout;
            while(i++ < user_cnt - 1)
                users[i] = users[i + 1];
            break;
        }
    }
    pthread_mutex_lock(&mutx);
}

void send_msg_group(char * msg, int len, int sq)
{
	int i;
	pthread_mutex_lock(&mutx);
	for(i = 0;i < clnt_cnt; i++)
	{	
		if(clnt_socks[i] != sq)
			write(clnt_socks[i], msg, len);
	}
	pthread_mutex_unlock(&mutx);
}

void privateChat(struct User user, char * name)
{
    int clnt_sock = user.fd;
    int str_len;
    char msg[BUF_SIZE];


    bzero(msg, sizeof(msg));
    while((str_len = read(clnt_sock, msg, BUF_SIZE)) != 0)
        send_msg_private(msg, sizeof(msg), clnt_sock, name);

    pthread_mutex_lock(&mutx);
    for (int i = 0; i < clnt_cnt;i++)
    {
        if (clnt_sock == clnt_socks[i])
        {
            while(i++ < clnt_cnt - 1)
                clnt_socks[i] = clnt_socks[i + 1];
            break;
        }
    }
    for (int i = 0; i < user_cnt;i++)
    {
        if (strcmp(user.name, users[i].name))
        {
            users[i].state = Logout;
            while(i++ < user_cnt - 1)
                users[i] = users[i + 1];
            break;
        }
    }
    pthread_mutex_lock(&mutx);
}

void send_msg_private(char * buf, int len, int sq, char * name)
{
    pthread_mutex_lock(&mutx);
    for (int i = 0;i < user_cnt;i++)
    {
        if(users[i].name == name)
            write(users[i].fd, buf, len);
    }
    pthread_mutex_unlock(&mutx);
}

void fileTrans()
{

}
