# Project 2: Scan Directories

This program scans through a directory tree and prints the total size of all files. It goes in each directory adding up the file sizes and prints the total for each directory.

# Build

make

# Run

./filescanner [directory]

# Function Call Diagram

main calls scan_directory
scan_directory opens directory
reads each entry with readdir
uses lstat to get file info
if it's a regular file, size is added to total
if it's a directory, calls scan_directory again (recursion)
closes directory
prints directory name and total
returns total
(AI formatted diagram)
main()
  └── scan_directory()
        ├── opendir()
        ├── readdir() (loop)
        ├── lstat()
        ├── scan_directory() (recursive call for subdirectories)
        ├── closedir()
        └── printf()