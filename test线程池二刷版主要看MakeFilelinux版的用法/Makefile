#自动变量
#$@表示目标
#$<表示第一个依赖
#$^表示所有依赖

SRCS:=$(wildcard ./*.c)
OBJS:=$(patsubst ./%.c, ./%.o, $(SRCS))
INC:=./

TARGET:= ./bin/test


$(TARGET):$(OBJS)
	gcc $^ -o $@ -lpthread

./obj/%.o:./src/%.c
	gcc -c -I$(INC) $< -o $@ -lpthread


.PHONY:clean
clean:
	rm -rf $(OBJS) $(TARGETS)
