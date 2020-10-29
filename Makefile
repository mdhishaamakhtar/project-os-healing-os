bin/makemake: bin/app.o  bin/rainbow.o bin/logger.o bin/log_processor.o bin/watcher.o bin/git_actions.o
	g++ --std=c++17 bin/app.o bin/rainbow.o  bin/log_processor.o bin/logger.o bin/watcher.o bin/git_actions.o -o bin/dist

bin/app.o: source/app.cpp
	g++ --std=c++17 -c source/app.cpp -o bin/app.o

bin/rainbow.o: includes/rainbow/rainbow.cpp includes/rainbow/rainbow.h
	g++ --std=c++17 -c includes/rainbow/rainbow.cpp -o bin/rainbow.o

bin/logger.o: includes/logger/logger.cpp includes/logger/logger.h
	g++ --std=c++17 -c includes/logger/logger.cpp -o bin/logger.o

bin/log_processor.o : includes/log_processor/log_processor.h includes/log_processor/log_processor.cpp
	g++ --std=c++17 -c includes/log_processor/log_processor.cpp -o bin/log_processor.o

bin/watcher.o: includes/watcher/watcher.cpp includes/watcher/watcher.h
	g++ --std=c++17 -c includes/watcher/watcher.cpp -o bin/watcher.o

bin/git_actions.o: includes/git_actions/git_actions.cpp includes/git_actions/git_actions.h
	g++ --std=c++17 -c includes/git_actions/git_actions.cpp -o bin/git_actions.o

clean:
	rm -rf bin/*.o
	echo  "" > logs.txt