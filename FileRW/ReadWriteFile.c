#include "./ReadWriteFile.h"
#include <memory.h>
#include <string.h>
int readFile(const char* path,char* data,int size){
	FILE *pf = NULL;
	
	if(data == NULL){
		printf("the buffer is not exist \n");
		return -1;
		
	}
	
	if(path == NULL){
		printf("the file path is not right \n");
		return -1;
	}
	
	pf = fopen(path,"r");
	
	if(pf == NULL){
		printf("can not open the file:%s\n",path);
		return -1;
	}else{
		size_t realSize = fread(data,size,1,pf);
		fclose(pf);
		return realSize;
	}
	

}


int readInitFile(const char* path,char data[][1024],char head[][1024]){
	if(path == NULL){
		printf("the file path is not right\n");
	}
	if(data == NULL){
		printf("the buffer is not exist\n");
	}
	if(head == NULL){
		printf("the buffer is not exist\n");
	}
	FILE* pf = fopen(path,"r");
	if(pf == NULL){
		printf("can not open the file\n");
	}else{
		char temp[READ_MAX_SIZE];
		int iniNum = 0;
		while(!feof(pf)){
			char* tempP = fgets(temp,READ_MAX_SIZE,pf);
			int n  = 0;
			if(strlen(temp) > 2){
				//用fgets读到的字符串至少有两个字节，一个是'\n',一个是'\0'
				while(*(tempP + n) != '\n' && *(tempP + n) != '\0' && *(tempP + n) != '#'  ){
				if(*(tempP + n) == '='){
					*(tempP + n ) = '\0';
					strcpy(head[iniNum],tempP);
					strcpy(data[iniNum],tempP + n + 1);
					iniNum ++;
					break;
				}
				n++;
			}
			}
			
		}
		fclose(pf);
		//去掉回车,文件末尾那一行没有'\n'
		int i = 0;
		for(;i < iniNum ; i++){
			if(data[i][strlen(data[i]) - 1] == '\n'){
				data[i][strlen(data[i]) - 1] ='\0';
			}
		}
		return iniNum;
	}
}

int writeFile(const char* path,const char* data,int size,int method){
	FILE *pf = NULL;
	if(path == NULL){
		printf("the file path is not right \n" );
		return -1;
	}

	if(data == NULL){
		printf("the write data is NULL\n");
		return -1;
	}
	switch(method){
		case 0:
			pf = fopen(path ,"w");
			//直接写入覆盖
			break;
		case 1:
			pf = fopen(path ,"a+");
			//文件后追加写入
			break;
		case 2:
		pf = fopen(path ,"a+");
			if(pf == NULL){
				printf("can not open the file :%s\n",path );
				return -1;
			}
			fwrite("\n",1,1,pf);
			
			//换行写入
			break;
	}
	
	if(pf == NULL){
		printf("can not open the file :%s\n",path );
		return -1;
	}else{
		size_t realSize = fwrite(data,size,1,pf);
		fclose(pf);
		return realSize; 
	}
}


