
#获取所有的源文件
SRCS:=$(wildcard *.c*)
#获取所有的目标文件
OBJS:=$(patsubst %.c*, %.o, $(SRCS))

#指定编译器
CC:= g++
#指定目标
TARGET:=write

$(TARGET):$(OBJS)
	$(CC) $^  -o $@ 

%.o:%.c*
	$(CC) -c -std=c++11 $< -o $@ 

.PHONY:clean
clean:
	rm -rf $(OBJS) $(TARGET)

