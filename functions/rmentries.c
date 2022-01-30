/* Copyright (C) 2022 PrincessAlicorn*/

#include "../lib/misc.h"
#include "../lib/listfstab.h"
#include "../lib/rmentries.h"

int rw_operation(int delline) {
    FILE *fstab = fopen(FSTAB_FILE, "r");
    FILE *tmp = fopen(TEMP_FILE, "w"); //TMP_FILE + FSTAB_FILE (defined in misc.h) it does not exist by default so we will close and re-open later for reading.
    if (fstab == NULL || tmp == NULL) { //make sure there is no errors while opening files.
        return 1;
    }
    int lineincr = 1; //used to increment through file
    char buf[LINE_MAX];
    while (fgets(buf, LINE_MAX, fstab)) {
            if (lineincr != delline) {
                fprintf(tmp, "%s", buf);
            }
            lineincr++;
    }
    remove(FSTAB_FILE);
    fclose(tmp);
    fclose(fstab);
    FILE *tmpr = fopen(TEMP_FILE, "r");
    FILE *fstabw = fopen(FSTAB_FILE, "w");
    while (fgets(buf, LINE_MAX, tmpr)) { //Write from tmp file to /etc/fstab
          fprintf(fstabw, "%s", buf);
    }
    fclose(fstabw);//close files
    fclose(tmpr);
    remove(TEMP_FILE); //remove temportary file
    return 0; //and done
}

int rm_entry_wizard() {
    FILE *fstab = fopen(FSTAB_FILE, "r"); //Open FSTAB, will be important later
    if (fstab == NULL) {
        return 1; //Error checking
    }
    if (check_for_root() == 0) { //check for root
        printf("You are noot root! Use su, sudo, or doas to continue!\n");
        return 1;
    }

    char buf1[LINE_MAX]; //buffer

    int ent_num = 1; //incremented later to get entry number, compare to remove_val
    int line_num = 1; //incremented later to get what line ent_num is on
    errno = 0;
    long int remove_val;
    char *optptr = NULL;
    char user_input[16];

    list_fstab_files(); //Producing a viewable list of entries in /etc/fstab
    printf("\nWhich entry do you wish to remove?\n");

    // int scan_result = scanf("%d", &remove_val); //Accepting user input from STDIN
    // if ( scan_result == EOF) { //Catching errors while reading from stdin
    //     return 1;
    // }
    // if (scan_result == 0) { //Catching incorrect types and no entries at all
    //     printf("Please enter a proper value!\n");
    //     return 1;
    // }

    if(fgets(user_input, 16, stdin)) {
        remove_val = strtol(user_input, &optptr, 10);
    }
    if (user_input == optptr) {
        printf("Please enter a valid number!\n");
        return 1;
    } else if (errno == ERANGE && remove_val == INT_MIN) {
        printf("Buffer underflow\n");
        return 1;
    } else if (errno == ERANGE && remove_val == 16) {
        printf("Buffer overflow\n");
        return 1;
    } else if (remove_val <= 0) {
        printf("Please enter a number greater than 0\n");
    } else if (errno != 0) {
        printf("Unspecified error\n");
        return 1;
    }
    flush_input
    remove_val = (int)remove_val;

    while (fgets(buf1, LINE_MAX, fstab)) { //reading like we did in the list file
            if(buf1[0] != '#' && buf1[0] != ' ' && buf1[0] != '\0' && buf1[0] != '\n') { //check to see if first value of buffer is not any trash value! Important for our option numbers.
                if (remove_val == ent_num) {
                    break; //if the selected number is equal to the entry number we found, exit the loop.
                }
              ent_num+=1; //increment if the if-statement is true
            }
            line_num++; //Always increment the line number! Will be important for the rw_operation() function.
        }
    fclose(fstab); //close fstab when we are done!
    if (rw_operation(line_num) != 0) { //go to rw_operation
         printf("There was an error writing a temporary file, or could not read /etc/fstab");
         return 1;
        }

    int has_systemd = check_for_sysd(); //Refresh systemd if that is what PID 1 is.
    if (has_systemd == 1) {
        system("systemctl daemon-reload");
    }
    return 0;
}
