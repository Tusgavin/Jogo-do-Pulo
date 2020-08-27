CC=g++
CFLAGS=-std=c++14 -Wall

BUILD_DIR=./build
PLAYER_DIR=./Player
BOARD_DIR=./Board

EXEC=./tp1
TARGET=tp1

$(EXEC): ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/Board.o ${BUILD_DIR}/main.o
	${CC} ${CFLAS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/Board.o: ${BOARD_DIR}/Board.hpp ${BOARD_DIR}/Board.cpp
	${CC} ${CFLAGS} -I ${BOARD_DIR}/ -c ${BOARD_DIR}/Board.cpp -o ${BUILD_DIR}/Board.o

${BUILD_DIR}/main.o: ${BOARD_DIR}/Board.hpp main.cpp
	${CC} ${CFLAGS} -I ${BOARD_DIR}/ -c main.cpp -o ${BUILD_DIR}/main.o

#${BUILD_DIR}/Player.o: ${PLAYER_DIR}/Player.hpp ${PLAYER_DIR}/Player.cpp
#	${CC} ${CFLAGS} -I ${PLAYER_DIR}/ -c ${PLAYER_DIR}/Player.cpp -o ${BUILD_DIR}/Player.o

clean:
	rm -f ${BUILD_DIR}/*

