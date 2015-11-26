main: main.o ./FileRW/ReadWriteFile.o ./Log/Log.o ./Time/Time.o
main.o:main.c
	cc -c main.c
ReadWriteFile.o:./FileRW/ReadWriteFile.c ./FileRW/ReadWriteFile.h
	cc -c ./FileRW/ReadWriteFile.c
Log.o:./Log/Log.c ./Log/Log.h
	cc -c ./Log/Log.c
Time.o:./Time/Time.c ./Time/Time.h
	cc -c ./Time/Time.c
clean:
	rm main.o ./FileRW/ReadWriteFile.o ./Log/Log.o ./Time/Time.o