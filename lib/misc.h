/* Copyright (C) 2022 PrincessAlicorn*/

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
