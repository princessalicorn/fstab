CC=gcc
BIN_NAME = fstab
INSTALL_DIR = /bin
EXEC_LOCATION = $(INSTALL_DIR)/$(BIN_NAME)

make:
		$(CC) -o $(BIN_NAME) ../main.c ../lib/*.h ../functions/*.c

install:	
		mv $(BIN_NAME) $(EXEC_LOCATION)
		chmod 755 $(EXEC_LOCATION)

uninstall:
		rm $(EXEC_LOCATION)

clean:
		rm $(BIN_NAME)
