Tracer: main.o Tracing_Record.o Tracing_Database.o Date.o Time.o
	g++ main.o Tracing_Record.o Tracing_Database.o Date.o Time.o -o Tracer

main.o: main.cpp Tracing_Record.h Tracing_Database.h Date.h Time.h
	g++ -c main.cpp

Tracing_Record.o: Tracing_Record.cpp Tracing_Record.h Date.h Time.h
	g++ -c Tracing_Record.cpp

Tracing_Database.o: Tracing_Database.cpp Tracing_Record.h Tracing_Database.h Time.h Date.h
	g++ -c Tracing_Database.cpp

Date.o: Date.cpp Date.h
	g++ -c Date.cpp

Time.o: Time.cpp Time.h
	g++ -c Time.cpp

clean:
	rm -f *.o Tracer
