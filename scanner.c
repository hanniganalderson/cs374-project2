#define _DEFAULT_SOURCE
#include "scanner.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

long scan_directory(const char *path, const char *name) {
  DIR *dir;
  struct dirent *entry;
  struct stat info;
  long size;
  long total;
  char fullpath[MAX_PATH];
  char subname[MAX_PATH];
  long subsize;

  dir = opendir(path);
  if (dir == NULL) {
    perror("opendir");
    return -1;
  }

  total = 0;

  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0) {
      continue;
    }
    if (strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    snprintf(fullpath, MAX_PATH, "%s/%s", path, entry->d_name);

    if (lstat(fullpath, &info) == -1) {
      perror("lstat");
      continue;
    }

    if (S_ISREG(info.st_mode)) {
      size = info.st_size;
      total = total + size;
    }

    if (S_ISDIR(info.st_mode)) {
      snprintf(subname, MAX_PATH, "%s/%s", name, entry->d_name);
      subsize = scan_directory(fullpath, subname);

      if (subsize != -1) {
        total = total + subsize;
      }
    }
  }

  closedir(dir);

  printf("%s: %ld\n", name, total);

  return total;
}