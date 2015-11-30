objects=testBroadCast.o BroadCast.o ../Log/Log.o ../FileRW/ReadWriteFile.o ../Time/Time.o
testBroadCast:$(objects)
	cc -o testBroadCast $(objects)
testBroadCast.o:testBroadCast.c
	cc -c testBroadCast.c
BroadCast.o:BroadCast.c
	cc -c BroadCast.c
Log.o:../Log/Log.c
	cc -c ../Log/Log.c
ReadWriteFile.o:../FileRW/ReadWriteFile.c
	cc -c ../FileRW/ReadWriteFile.c
Time.o:../Time/Time.c
	cc -c ../Time/Time.c
clean:
	rm testBroadCast $(objects)