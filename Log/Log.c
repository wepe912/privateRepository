#include "./Log.h"

int writeLog(const char* log){
	char nowtime[1024];
	getTime(nowtime);
	if(writeFile(LOG_PATH,nowtime,strlen(nowtime) - 1,2) > 0){
		if(writeFile(LOG_PATH,log,strlen(log),2) > 0 ){
		return 0;
	}else{
		return -1;
	}
	}else{
		return -1;
	}
	

}
