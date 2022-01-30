/*     Copyright (C) 2022  PrincessAlicorn
3	
4	   This program is free software: you can redistribute it and/or modify
5	   it under the terms of the GNU Affero General Public License as
6	   published by the Free Software Foundation, either version 3 of the
7	   License, or (at your option) any later version.
8	
9	   This program is distributed in the hope that it will be useful,
10	   but WITHOUT ANY WARRANTY; without even the implied warranty of
11	   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
12	   GNU Affero General Public License for more details.
13	
14	   You should have received a copy of the GNU Affero General Public License
15	   along with this program.  If not, see <https://www.gnu.org/licenses/>.*/

#include "lib/listfstab.h"
#include "lib/misc.h"
#include "lib/rmentries.h"
#include "lib/proginfo.h"
#include "lib/addentry.h"

int main (int argc, char *argv[]) {
    int opts;
    while ((opts = getopt(argc, argv, "hvlra")) != -1) {
        switch (opts) {
            case 'h':
                help_statement();
                break;
            case 'v':
                program_information();
                break;
            case 'l':
                list_fstab_files();
                break;
            case 'r':
                if (rm_entry_wizard() != 0) {
                    exit(EXIT_FAILURE);
                }
                break;
            case 'a':
                if (add_field_wizard() != 0) {
                    exit(EXIT_FAILURE);
                }
                break;
            default:
                program_information();
                break;
      }
    }
  }
