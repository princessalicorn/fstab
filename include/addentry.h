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
