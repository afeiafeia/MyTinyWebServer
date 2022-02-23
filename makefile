CXX ?= g++

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CXXFLAGS += -g
else
    CXXFLAGS += -O2

endif

server: ./main.cpp ./log/log.cpp ./lock/locker.cpp  ./lock/cond.cpp  ./lock/sem.cpp \
		./time/Util.cpp ./time/util_time.h ./time/time_heap.cpp \
		./CGImysql/sql_connection_pool.cpp ./CGImysql/connectionRAII.cpp ./http/http.cpp ./webserver.cpp ./config.cpp
	$(CXX) -o server  $^ $(CXXFLAGS) -lpthread -lmysqlclient
clean:
	rm  -r server
