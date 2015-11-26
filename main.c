#include"./FileRW/ReadWriteFile.h"
#include "./Log/Log.h"
#include "./Time/Time.h"
int main(){
	/*const char* path = "./main.c";
	int size = 10;
	char data[100];
	if(readFile(path,data,size) >= 0){
		printf(" hello %s\n",data);
	}else{

	
		printf("read faild \n");
	}

	if(writeFile("./test","123",3,2) >= 0){
		printf("write ok!\n");
	}else{
		printf("wrte faild\n");
	}*/
		
	int n = 0;
	char data[100][1024];
	char head[100][1024];
	//char** datap = &data;
	if((n = readInitFile("confi.ini",data,head)) >= 0){
		int i = 0;
		printf("read %d \n",n );
		for(i = 0;i < n; i ++){
			printf("%s=", head[i]);
			printf("%s\n",data[i] );
		}
	}

	if(writeLog("success!") == 0){
		printf("success\n");
		return 0;
	}else{
		printf("faild\n");
		return 0;
	
	}


}
