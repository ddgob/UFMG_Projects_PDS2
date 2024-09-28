CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = vpl_execution

BUILD_DIR = ./build
SRC_DIR = ./src
SRC_ENTITIES_DIR = ./src/entidades
INCLUDE_DIR = ./include

all: ./${TARGET}

./${TARGET}: ${BUILD_DIR}/Cilindro.o ${BUILD_DIR}/Circulo.o ${BUILD_DIR}/Ponto.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o $@ ${BUILD_DIR}/*.o

${BUILD_DIR}/Cilindro.o: ${SRC_ENTITIES_DIR}/Cilindro.cpp ${INCLUDE_DIR}/Cilindro.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o $@

${BUILD_DIR}/Circulo.o: ${SRC_ENTITIES_DIR}/Circulo.cpp ${INCLUDE_DIR}/Circulo.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o $@

${BUILD_DIR}/Ponto.o: ${SRC_ENTITIES_DIR}/Ponto.cpp ${INCLUDE_DIR}/Ponto.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o $@

${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp ${INCLUDE_DIR}/Cilindro.hpp ${INCLUDE_DIR}/Circulo.hpp ${INCLUDE_DIR}/Ponto.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o $@

clean:
	rm -f ${BUILD_DIR}/*