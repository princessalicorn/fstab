/*      Copyright (C) 2022  PrincessAlicorn

        This program is free software: you can redistribute it and/or modify
        it under the terms of the GNU Affero General Public License as
        published by the Free Software Foundation, either version 3 of the
        License, or (at your option) any later version.

        This program is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU Affero General Public License for more details.

        You should have received a copy of the GNU Affero General Public License
        along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


/*System headers*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>
#include <errno.h>

/*Commonly used vairables across multiple files*/
#define arr_len(x) (sizeof(x) / sizeof((x)[0]))
#define flush_input while(getchar() != '\n');

#define FSTAB_FILE "/etc/fstab"
#define TEMP_FILE "/etc/fstab.1"

/*Actual miscellanious functions from the misc.c file*/
int check_for_root();
int check_for_sysd();
