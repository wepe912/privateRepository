#include "./Time.h"
#include <string.h>
int getTime(char * nowtime){
	time_t t;
	struct tm* timeinfo;
	time(&t);

	timeinfo = localtime(&t);
	strcpy(nowtime, asctime(timeinfo)) ;
	
	
}