##
## EPITECH PROJECT, 2022
## B-CPE-110-MPL-1-1-bsbsq-louis.rollet
## File description:
## Makefile
##

SRC = $(wildcard *.c)
CC = gcc
TARGET = bsq
CL = *~

$(TARGET) :
	$(CC) -o $(TARGET) $(SRC) -I./ -O3

all :	$(TARGET)

clean :
	rm -rf $(CL)

fclean : clean
	rm -rf $(TARGET)

re : fclean all
