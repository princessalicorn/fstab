/* Copyright (C) 2022 PrincessAlicorn*/

#include <stdio.h>
#include "../lib/proginfo.h"

void help_statement() {
  printf("Usage:\n");
  printf("  fstab [options]\n\n");
  printf("View and modify /etc/fstab and other filesystem tables.\n");
  printf("Subcommands: \n\n");
  printf("--help    | -h: prints this help statement\n");
  printf("--version | -v: prints version information\n");
  printf("--list    | -l: lists fstab entries\n");
  printf("--remove  | -r: interactive prompt to assist in removing fstab entries\n");
  printf("--add     | -a: interactive wizard to creat fstab entries\n");
  return;
}

void program_information() {
  printf("    ____________________    ____ \n");
  printf("   / ____/ ___/_  __/   |  / __ )\n");
  printf("  / /_   \\__ \\ / / / /| | / __  |\n");
  printf(" / __/  ___/ // / / ___ |/ /_/ / \n");
  printf("/_/    /____//_/ /_/  |_/_____/  \n\n");
  printf("Fstab version 1.0.1\n\n");
  printf("Copyright (C) 2022 princessalicorn (https://gitlab.com/PrincessAlicorn)\n");
  printf("FSTAB is free software: you can redistribute it and/or modify\n");
  printf("it under the terms of the GNU Affero General Public License as\n");
  printf("published by the Free Software Foundation, either version 3 of the\n");
  printf("License, or (at your option) any later version.\n\n");
  printf("FSTAB is distributed in the hope that it will be useful,\n");
  printf("but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
  printf("MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
  printf("GNU Affero General Public License for more details.\n\n");
  printf("You should have received a copy of the GNU Affero General Public License\n");
  printf("along with this program.  If not, see <https://www.gnu.org/licenses/>.\n");

  return;
}
