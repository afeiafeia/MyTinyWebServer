CXX ?= g++

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CXXFLAGS += -g
else
    CXXFLAGS += -O2

endif

server: ../log/log.cpp ../lock/locker.cpp  ../lock/cond.cpp  ../lock/sem.cpp \
		./test_log.cpp
	$(CXX) -o testLog  $^ $(CXXFLAGS) -lpthread -lmysqlclient
clean:
	rm  -r test_log
