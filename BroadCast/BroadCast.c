#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "BroadCast.h"
#include "../Log/Log.h"

#define PORT 8888

int startBroadCast(){
	setvbuf(stdout,NULL,_IONBF,0);
	fflush(stdout);
	int sock = -1;
	
	if((sock = socket(AF_INET,SOCK_DGRAM,0)) == -1){
		printf("socket errno\n");
		writeLog("can not create the socket");
		return -1;
	}

	const int opt = 1;
	 int nb = 0;
	//设置该socket为广播类型
	nb = setsockopt(sock,SOL_SOCKET,SO_BROADCAST,(char *)&opt,sizeof(opt));
	if(nb == -1){
		printf("set socket be BroadCast faild\n");
		writeLog("set socket be BroadCast faild");
		return -1;
	}

	struct sockaddr_in addrto;
	bzero(&addrto,sizeof(struct sockaddr_in));
	addrto.sin_family = AF_INET;
	addrto.sin_addr.s_addr = htonl(INADDR_BROADCAST);
	addrto.sin_port = htons(PORT);
	int nlen = sizeof(addrto);

	while(1){
		sleep(1);
		char smsg[] = {"hello !"};
		int ret = sendto(sock,smsg,strlen(smsg),0,(struct sockaddr*)&addrto,nlen);
		if(ret < 0){
			printf("send message faild\n");
			writeLog("send message faild");
		}else{
			printf("send message success!\n");
			writeLog("send message success!");
		}
	}
}
void startBroadCastRV(){
	setvbuf(stdout, NULL, _IONBF, 0);   
    fflush(stdout);   
  
    // 绑定地址  
    struct sockaddr_in addrto;  
    bzero(&addrto, sizeof(struct sockaddr_in));  
    addrto.sin_family = AF_INET;  
    addrto.sin_addr.s_addr = htonl(INADDR_ANY);  
    addrto.sin_port = htons(PORT);  
      
    // 广播地址  
    struct sockaddr_in from;  
    bzero(&from, sizeof(struct sockaddr_in));  
    from.sin_family = AF_INET;  
    from.sin_addr.s_addr = htonl(INADDR_ANY);  
    from.sin_port = htons(PORT);  
      
    int sock = -1;  
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)   
    {     
        printf("can not create recieve sock\n"); 
        writeLog("can not create recieve sock") ;
        return -1;  
    }     
  
    const int opt = 1;  
    //设置该套接字为广播类型，  
    int nb = 0;  
    nb = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char *)&opt, sizeof(opt));  
    if(nb == -1)  
    {  
        printf("set socket error...\n");  
        writeLog("set socket error...");
        return -1;  
    }  
  
    if(bind(sock,(struct sockaddr *)&(addrto), sizeof(struct sockaddr_in)) == -1)   
    {     
        printf("bind error...\n");  
        writeLog("bind error...");
        return -1;  
    }  
  
    int len = sizeof(struct sockaddr_in);  
    char smsg[100] = {0};  
  
    while(1)  
    {  
        //从广播地址接受消息  
        int ret=recvfrom(sock, smsg, 100, 0, (struct sockaddr*)&from,(socklen_t*)&len);  
        if(ret<=0)  
        {  
            printf("read error....\n");  
        }  
        else  
        {         
            printf("%s\t", smsg);     
        }  
  
        sleep(1);  
    }  
}