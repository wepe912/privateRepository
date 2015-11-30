#include <stdio.h>
#include "BroadCast.h"
#include "../Log/Log.h"
int main(int argc, char const *argv[])
{
	if(argc < 2){
		printf("parameter is lack\n");
		writeLog("parameter is lack");
		return -1;
	}
	if(!strcmp(argv[1],"send")){
		startBroadCast();
	}else if(!strcmp(argv[1],"recieve")){
		startBroadCastRV();
		//startBroadCastRV
	}

	return 0;
}