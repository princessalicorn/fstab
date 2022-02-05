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

#include "include/listfstab.h"
#include "include/misc.h"
#include "include/rmentries.h"
#include "include/proginfo.h"
#include "include/addentry.h"
#include <getopt.h>

int main (int argc, char *argv[]) {
    while (1) {
        int opts;
        int opt_index = 0;
        static struct option long_options[] =
        {
            {"add", no_argument, NULL, 'a'},
            {"help", no_argument, NULL, 'h'},
            {"version", no_argument, NULL, 'v'},
            {"list", no_argument, NULL, 'l'},
            {"remove", no_argument, NULL, 'r'},
            {NULL,  0,           NULL, 0}
        };
        opts = getopt_long(argc, argv, "hvlra", long_options, &opt_index);
        if (opts == -1) {
            break;
            }
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
