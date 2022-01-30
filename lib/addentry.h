/* Copyright (C) 2022 PrincessAlicorn*/

#include <limits.h>
#define MAX_FIELD_LENGTH (LINE_MAX - 4) / 4

struct fields {
    char drive_name[MAX_FIELD_LENGTH];
    char mount_point[MAX_FIELD_LENGTH];
    char fs[MAX_FIELD_LENGTH];
    char opts[MAX_FIELD_LENGTH];
    char dump;
    char pass;
};

int add_field_wizard();
