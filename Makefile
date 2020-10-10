bin/makemake: bin/app.o  bin/rainbow.o bin/logger.o bin/log_processor.o
	g++ --std=c++17 bin/app.o bin/rainbow.o  bin/log_processor.o -o bin/dist

bin/app.o: source/app.cpp
	g++ --std=c++17 -c source/app.cpp -o bin/app.o

bin/rainbow.o: includes/rainbow/rainbow.cpp includes/rainbow/rainbow.h
	g++ --std=c++17 -c includes/rainbow/rainbow.cpp -o bin/rainbow.o

bin/logger.o: includes/logger/logger.cpp
	g++ --std=c++17 -c includes/logger/logger.cpp -o bin/logger.o

bin/log_processor.o : includes/log_processor/log_processor.h includes/log_processor/log_processor.cpp
	g++ --std=c++17 -c includes/log_processor/log_processor.cpp -o bin/log_processor.o

clean:
	rm -rf bin/*.o
