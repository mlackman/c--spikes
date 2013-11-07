INC_FOLDERS = -I c:\c++_libraries\boost_1_54_0
LIB_FOLDERS = -L ../../libs -Lc:\MinGW\lib
LIBRARIES = -lboost_system-mgw48-mt-d-1_54 -lwsock32 -lws2_32

socket: main.cpp
	g++ -s main.cpp -o socket -std=c++11 $(INC_FOLDERS) -D_WIN32_WINNT=0x0501 -DWINVER=0x0501 ${LIBRARIES} ${LIB_FOLDERS}