CC = gcc
TARGET = crud
SRCS = main.c documento.c
OBJS = $(SRCS:.c=.o)

# Regra principal: como criar o programa
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# Regra padrão: como transformar qualquer .c em .o
%.o: %.c
	$(CC) -c $< -o $@

# Regra "clean": para limpar a bagunça
clean:
	rm -f $(TARGET) $(OBJS)