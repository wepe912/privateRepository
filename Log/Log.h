#include "../Time/Time.h"
#include "../FileRW/ReadWriteFile.h"
#define LOG_PATH "./mylog.log"
int writeLog(const char* log);
/*****************************
/*功能：在当前目录下新建一个名为mylog.log的日志文件并写入
/*参数：log - 传入的日志文件内容
/*返回值：0 成功 -1 失败
*****************************/