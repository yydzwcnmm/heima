#获取当前目录下所有.C
SRC:=$(wildcard * .c)
BIN:= $(patsubst %.c, %, $(SRC))
INC:= /usr/local/mysql/lib/
LIBPATH:= /usr/local/mysql/lib/
LIB:= mysqlclient

all:$(BIN)
%:%.c
	gcc $< -o $@ -L$(LIBPATH) -l$(LIB)

.PHONY:clean
clean:
	$(RM) $(BIN)


