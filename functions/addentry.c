/* Copyright (C) 2022 PrincessAlicorn */

#include "../lib/misc.h"
#include "../lib/addentry.h"
#include "../lib/listfstab.h"

void drive_help() {
    printf("Here you want to enter the drive you want to make the entry for. \n");
    printf("The default formatting for this option is /dev/(device_name)\n");
    printf("If you are not sure what drive you are looking for, exit and\n");
    printf("enter \"blkid\" (as root) or \"parted -l\" in your terminal!\n\n");
    return;
}

void mount_help() {
    printf("This is where your file or drive will be mounted.\n");
    printf("Root: /\n");
    printf("Home: /home\n");
    printf("Swap: none\n");
    printf("Here are examples of common mountpoints. If you do not know\n");
    printf("where your drive is mounted, please exit your program and\n");
    printf("refer to your documentation or reference manual.\n\n");
    return;
}

void fs_help() {
    printf("You need to enter the filesystem your drive uses.\n");
    printf("Common ones include: ext4, btrfs, xfs, vfat\n");
    printf("If you are using UEFI, and you are making the entry for your\n");
    printf("/boot or /boot/efi partition, use vfat. Swap drives use swap.\n");
    printf("If you do not know what the fs should be, please exit your program\n");
    printf("and refer to your documentation or reference manual.\n\n");
    return;
}

void opt_help() {
    printf("Here you will place nessecary options for your drive entry.\n");
    printf("Common ones include:\n");
    printf("defaults: enables default options.\n");
    printf("noauto: disables automatic mounting. Useful for things like cd-rom drives.\n");
    printf("ro: mounts drive read only\n");
    printf("user: allows anyone to mount/unmount a filesystem\n");
    printf("There are many options so it is very important you refrence your\n");
    printf("documentation or reference manual to make an informed decision.\n\n");
    return;
}

int check_for_scanf_errors(int ret_status) {
    if (ret_status == EOF) { //Catching errors while reading from stdin
        return 1;
    }
    if (ret_status == 0) { //Catching incorrect types and no entries at all
        printf("Please enter a proper value!\n");
        return 1;
    }
    return 0;
}

int add_field_wizard() {
    if (check_for_root() == 0) { //check for root
        printf("You are noot root! Use su, sudo, or doas to continue!\n");
        return 1;
    }
    struct fields new_entry;
    printf("Add a new FSTAB Entry:\n");
    list_fstab_files();
    printf("\nEnter the following:\nEnter ? at any time for help or exit to stop.\n");
    int need_help = 1;
    while (need_help == 1) {
        printf("Drive: ");
        if (fgets(new_entry.drive_name, MAX_FIELD_LENGTH, stdin) == NULL) {
            return 1;
        }
        if (new_entry.drive_name[0] == '?') {
            memset(&new_entry.drive_name[0], 0, sizeof(new_entry.drive_name));
            drive_help();
        } else if (new_entry.drive_name[0] == 'e' && new_entry.drive_name[1] == 'x' && new_entry.drive_name[2] == 'i' && new_entry.drive_name[3] == 't') {
            return 1;
        } else {
            new_entry.drive_name[strcspn(new_entry.drive_name, "\n")] = 0;
            need_help = 0;
        }
    }

    need_help = 1;
    while (need_help == 1) {
        printf("\nMountpoint: ");
        if (fgets(new_entry.mount_point, MAX_FIELD_LENGTH, stdin) == NULL) {
            return 1;
        }
        if (new_entry.mount_point[0] == '?') {
            memset(&new_entry.mount_point[0], 0, sizeof(new_entry.mount_point));
            mount_help();
        } else if (new_entry.mount_point[0] == 'e' && new_entry.mount_point[1] == 'x' && new_entry.mount_point[2] == 'i' && new_entry.mount_point[3] == 't') {
            return 1;
        } else {
            new_entry.mount_point[strcspn(new_entry.mount_point, "\n")] = 0;
            need_help = 0;
        }
    }

    need_help = 1;
    while (need_help == 1) {
        printf("\nFilesystem: ");
        if (fgets(new_entry.fs, MAX_FIELD_LENGTH, stdin) == NULL) {
            return 1;
        }
        if (new_entry.fs[0] == '?') {
            memset(&new_entry.fs[0], 0, sizeof(new_entry.fs));
            fs_help();
        } else if (new_entry.fs[0] == 'e' && new_entry.fs[1] == 'x' && new_entry.fs[2] == 'i' && new_entry.fs[3] == 't') {
            return 1;
        } else {
            new_entry.fs[strcspn(new_entry.fs, "\n")] = 0;
            need_help = 0;
        }
    }

    need_help = 1;
    while (need_help == 1) {
        printf("\nOpts: ");
        if (fgets(new_entry.opts, MAX_FIELD_LENGTH, stdin) == NULL) {
            return 1;
        }
        if (new_entry.opts[0] == '?') {
            memset(&new_entry.opts[0], 0, sizeof(new_entry.opts));
            opt_help();
        } else if (new_entry.opts[0] == 'e' && new_entry.opts[1] == 'x' && new_entry.opts[2] == 'i' && new_entry.opts[3] == 't') {
            return 1;
        } else {
            new_entry.opts[strcspn(new_entry.opts, "\n")] = 0;
            need_help = 0;
        }
    }

    for (long unsigned int i = 0; i < arr_len(new_entry.opts); i++) {
        if (new_entry.opts[i] == ' ') {
            new_entry.opts[i] = ',';
        }
    }
    for (long unsigned int j = 0; j < arr_len(new_entry.opts); j++) {
        if (new_entry.opts[j] == ',') {
            if (new_entry.opts[j+1] == ' ' || new_entry.opts[j+1] == '\0' || new_entry.opts[j+1] == '\n') {
                new_entry.opts[j] = ' ';
            }
        }
    }

    char dump_pass_opt[16];
    int dump_pass_int;
    char *optptr;
    errno = 0;
    printf("Options for dump and pass:\n");
    printf("1. 0 1 (Use this on / if it is not BTRFS or XFS)\n");
    printf("2. 0 2 (Use this on most other dirves/mountpoints)\n");
    printf("3. 0 0 (Disables FS scanning, use only for swap and sometimes f2fs drives.)\n");
    printf("If you are unsure, please refer to your refrence manual or documentation\n");
    printf("Option: ");
    // int dump_pass_results = scanf("%i", &dump_pass_opt);
    // if (check_for_scanf_errors(dump_pass_results) == 1) {
    //     return 1;
    // }
    if(fgets(dump_pass_opt, 16, stdin)) {
        dump_pass_int = strtol(dump_pass_opt, &optptr, 10);
    }
    if (dump_pass_opt == optptr) {
        printf("Please enter a valid number!\n");
        return 1;
    } else if (errno == ERANGE && dump_pass_int == INT_MIN) {
        printf("Buffer underflow\n");
        return 1;
    } else if (errno == ERANGE && dump_pass_int == 16) {
        printf("Buffer overflow\n");
        return 1;
    } else if (dump_pass_int <= 0) {
        printf("Please enter a number greater than 0\n");
    } else if (errno != 0) {
        printf("Unspecified error\n");
        return 1;
    }
    dump_pass_int = (int)dump_pass_int;
    switch (dump_pass_int) {
        case 3:
            new_entry.dump = '0';
            new_entry.pass = '0';
            break;
        case 2:
            new_entry.dump = '0';
            new_entry.pass = '2';
            break;
        case 1:
            new_entry.dump = '0';
            new_entry.pass = '1';
            break;
        default:
            printf("Please enter a valid operation!\n");
            return 1;
    }
    printf("%s %s %s %s %c %c\n", new_entry.drive_name, new_entry.mount_point, new_entry.fs, new_entry.opts, new_entry.dump, new_entry.pass);
    char opt[16];
    need_help = 1;
    while (need_help == 1) {
        printf("Does this seem correct? (y/n): ");
        if (fgets(opt, 16, stdin) == NULL) {
            return 1;
        }
        if (opt[0] == 'n' || opt[0] == 'N') {
            return 1;
        } else if (opt[0] == 'y' || opt[0] == 'Y') {
            need_help = 0;
        } else {
            printf("Please enter a valid option.");
        }
    }
    // int question_reply = scanf("%s", opt);
    // if (check_for_scanf_errors(question_reply) == 1) {
    //     return 1;
    // }
    // if (opt[0] == 'n' || opt[0] == 'N') {
    //     return 1;
    // }
    FILE *fstab = fopen("/etc/fstab", "a");
    if (fstab == NULL) {
        return 1;
    }
    fprintf(fstab, "%s %s %s %s %c %c\n", new_entry.drive_name, new_entry.mount_point, new_entry.fs, new_entry.opts, new_entry.dump, new_entry.pass);
    fclose(fstab);
    int has_systemd = check_for_sysd(); //Refresh systemd if that is what PID 1 is.
    if (has_systemd == 1) {
        system("systemctl daemon-reload");
    }
    return 0;
}
