#	Copyright (C) 2022  PrincessAlicorn
#
#	This program is free software: you can redistribute it and/or modify
#       it under the terms of the GNU Affero General Public License as
#       published by the Free Software Foundation, either version 3 of the
#       License, or (at your option) any later version.
#
#       This program is distributed in the hope that it will be useful,
#       but WITHOUT ANY WARRANTY; without even the implied warranty of
#       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#       GNU Affero General Public License for more details.
#
#       You should have received a copy of the GNU Affero General Public License
#       along with this program.  If not, see <https://www.gnu.org/licenses/>.


CC=gcc
BIN_NAME = fstab
INSTALL_DIR = /bin
EXEC_LOCATION = $(INSTALL_DIR)/$(BIN_NAME)

make:
		$(CC) -o $(BIN_NAME) ../main.c ../include/*.h ../functions/*.c

install:	
		mv $(BIN_NAME) $(EXEC_LOCATION)
		chmod 755 $(EXEC_LOCATION)

uninstall:
		rm $(EXEC_LOCATION)

clean:
		rm $(BIN_NAME)
