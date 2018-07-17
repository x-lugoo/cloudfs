#ifndef __FS_H
#define __FS_H

#define FUSE_USE_VERSION 26

#include <sys/types.h>
#include <sys/stat.h>
#include <fuse.h>

extern const struct fuse_operations fs_ops;

#endif
