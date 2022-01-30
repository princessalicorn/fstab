# FSTAB

A basic C utility made to simplify the viewing, deleting, and editing of FSTAB files! This is my first large C project.

## Getting started

To install the program, cd into the bin/ directory and execute
```
make && sudo make install
```
It should compile nearly instantly!

## What does the program do?

It does three things currently. It cam

1. List fstab entries. run `fstab -l`! This also will also return the drive names for any UUIDs you have inside your /etc/fstab file/
2. Remove fstab entries. You can use this utillity to interactivly delete fstab entries using `fstab -r`
3. Add fstab entries. You can add entries with an interactive prompt and help menus using `fstab -a`

## Platforms?

Currently this will only work on linux systems due to the fact the returning of UUID functions is currently dependent on a directory that only Linux has. I could likely fix this if I decide to continue to work on the project so it works on other UNIX-based or UNIX-like systems. 

## Roadmap?
If I continue to add features, it will likely be as follows :

1. Make it so if you type `fstab -r (drive_name)`, it will search your fstab file and delete entries with a matching partition/drive name
2. Add long options
3. Make a way to edit fstab entries inline?

## License
This is licensed under the AGPL license. A copy of the License is in this repository as well as a disclaimer

## Project status
This is the first release of this program
