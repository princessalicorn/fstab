/* Copyright (C) 2022 PrincessAlicorn*/

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
