/* Copyright (C) 2022 PrincessAlicorn
   This program is meant to assist in the adding, listing, and removal of FSTAB entries
   This program is licensed under the AGPL, see license.txt for more information*/

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
