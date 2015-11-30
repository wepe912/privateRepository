将sqlite3编译成动态库供使用
gcc  sqlite3.h sqlite3.c -fPIC -shared -o libsqlite3.so
将libsqlite3.so拷到/usr/lib下,程序运行是会自动在该目录下去找相应的动态库
gcc test.c -lsqlite3 -lpthread -ldl