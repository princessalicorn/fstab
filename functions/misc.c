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

#include "../include/misc.h"

int check_for_root() {
  uid_t uid = getuid();
  if (uid == 0) {
    return 1;
  } else {
    return 0;
  }
}

int check_for_sysd() {
  FILE *init_daemon = fopen("/proc/1/status", "r");
  if (init_daemon == NULL) { //if you do not have /proc, you are not on linux, and thus, likely do not have systemd!
      return 0;
  }
  char daemon_name[32];
  fgets(daemon_name, 32, init_daemon);
  if (daemon_name[6] == 's' && daemon_name[7] == 'y' && daemon_name[12] == 'd') {
      return 1;
  }
  return 0;
}
