CC:=g++
CFLAGS:=-std=c++14 -Wall

BUILD_DIR:=./build
PLAYER_DIR:=./Player
BOARD_DIR:=./Board
GAME_DIR:=./Game
INCLUDE_DIR:=./Include

EXEC:=./tp1
TARGET:=tp1

$(EXEC): ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/Board.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/main.o
	${CC} ${CFLAS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/Board.o: ${INCLUDE_DIR}/Board.hpp ${BOARD_DIR}/Board.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${BOARD_DIR}/Board.cpp -o ${BUILD_DIR}/Board.o

${BUILD_DIR}/Player.o: ${INCLUDE_DIR}/Player.hpp ${PLAYER_DIR}/Player.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${PLAYER_DIR}/Player.cpp -o ${BUILD_DIR}/Player.o

${BUILD_DIR}/Game.o: ${INCLUDE_DIR}/Game.hpp ${GAME_DIR}/Game.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${GAME_DIR}/Game.cpp -o ${BUILD_DIR}/Game.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Board.hpp ${INCLUDE_DIR}/Player.hpp ${INCLUDE_DIR}/Game.hpp main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c main.cpp -o ${BUILD_DIR}/main.o

clean:
	rm -f ${BUILD_DIR}/*

