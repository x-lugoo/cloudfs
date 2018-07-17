
#include "fs.h"
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct file {
	struct file *next;
	const char *name;
	struct chunk *chunks;
	mode_t mode;
};

struct file *files;

static void fs_free(struct file *f)
{
	printf("%s %d\n",__func__,__LINE__);
}

static size_t file_size(struct file *f)
{
	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static void *fs_init(struct fuse_conn_info *conn)
{
	printf("%s %d\n",__func__,__LINE__);
	return NULL;
}

static void fs_destroy(void *data)
{
	printf("%s %d\n",__func__,__LINE__);

}

static struct file *find_file(const char *name)
{
	printf("%s %d\n",__func__,__LINE__);
	return NULL;
}

static int fs_mkdir(const char *name, mode_t mode)
{
	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int fs_mknod(const char *name, mode_t mode, dev_t device)
{
	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int fs_chmod(const char *name, mode_t mode)
{
	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int fs_utime(const char *name, struct utimbuf *utim)
{
	/* No-op */
	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int fs_getattr(const char *name, struct stat *stat)
{
	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int fs_unlink(const char *name)
{
	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int fs_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
	off_t offset, struct fuse_file_info *fi)
{

	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int fs_open(const char *name, struct fuse_file_info *fileinfo)
{

	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int fs_inner_write(struct file *f, const char *buf, size_t size,
	off_t offset)
{
	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int fs_write(const char *name, const char *buf, size_t size,
	off_t offset, struct fuse_file_info *fileinfo)
{

	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int fs_read(const char *name, char *buf, size_t size,
	off_t offset, struct fuse_file_info *fileinfo)
{
	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int shrink_file(struct file *f, off_t length)
{
	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int grow_file(struct file *f, off_t length)
{
	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int fs_truncate(const char *name, off_t length)
{
	printf("%s %d\n",__func__,__LINE__);
	return 0;
}

static int fs_rename(const char *name, const char *newname)
{
	printf("%s %d\n",__func__,__LINE__);

	return 0;
}

const struct fuse_operations fs_ops = {
	.getattr = fs_getattr,
	.utime = fs_utime,
	.chmod = fs_chmod,
	.mkdir = fs_mkdir,
	.mknod = fs_mknod,
	.unlink = fs_unlink,
	.readdir = fs_readdir,
	.open = fs_open,
	.write = fs_write,
	.read = fs_read,
	.truncate = fs_truncate,
	.rename = fs_rename,
	.init = fs_init,
	.destroy = fs_destroy,
};

