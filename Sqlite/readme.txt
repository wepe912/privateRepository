��sqlite3����ɶ�̬�⹩ʹ��
gcc  sqlite3.h sqlite3.c -fPIC -shared -o libsqlite3.so
��libsqlite3.so����/usr/lib��,���������ǻ��Զ��ڸ�Ŀ¼��ȥ����Ӧ�Ķ�̬��
gcc test.c -lsqlite3 -lpthread -ldl