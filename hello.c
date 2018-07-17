/*
  FUSE: Filesystem in Userspace
  Copyright (C) 2001-2007  Miklos Szeredi <miklos@szeredi.hu>

  This program can be distributed under the terms of the GNU GPL.
  See the file COPYING.
*/

/** @file
 *
 * minimal example filesystem using high-level API
 *
 * Compile with:
 *
 *     gcc -Wall hello.c `pkg-config fuse3 --cflags --libs` -o hello
 *
 * ## Source code ##
 * \include hello.c
 */


#define FUSE_USE_VERSION 26

#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <assert.h>

/*
 * Command line options
 *
 * We can't set default values for the char* fields here because
 * fuse_opt_parse would attempt to free() them when the user specifies
 * different values on the command line.
 */
static struct options {
	const char *filename;
	const char *contents;
	int show_help;
} options;

int fd;
#define OPTION(t, p)                           \
    { t, offsetof(struct options, p), 1 }
static const struct fuse_opt option_spec[] = {
	OPTION("--name=%s", filename),
	OPTION("--contents=%s", contents),
	OPTION("-h", show_help),
	OPTION("--help", show_help),
	FUSE_OPT_END
};

static void *hello_init(struct fuse_conn_info *conn,
			struct fuse_config *cfg)
{
	fd = open("/dev/pts/3",2);
	
	dup2(fd,1);
	printf("%s\n",__func__);
	return NULL;
}

static int hello_getattr(const char *path, struct stat *stbuf,
			 struct fuse_file_info *fi)
{
	printf("%s\n",__func__);
	return 0;
}


static int hello_open(const char *path, struct fuse_file_info *fi)
{
	printf("%s\n",__func__);

	return 0;
}

static int hello_read(const char *path, char *buf, size_t size, off_t offset,
		      struct fuse_file_info *fi)
{
	printf("%s\n",__func__);
	return 0;
}

static int fs_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
	off_t offset, struct fuse_file_info *fi)
{

	printf("%s\n",__func__);
	return 0;
}


static int fs_unlink(const char *name)
{
	printf("%s\n",__func__);
	return 0;
}

static int fs_chmod(const char *name, mode_t mode)
{
	printf("%s \n",__func__);
	return 0;
}

static int fs_mkdir(const char *name, mode_t mode)
{
	printf("%s\n",__func__);
	return 0;
}

static void fs_destroy(void *data)
{
	printf("%s \n",__func__);
}

static int fs_write(const char *name, const char *buf, size_t size,
	off_t offset, struct fuse_file_info *fileinfo)
{

	printf("%s \n",__func__);
	return 0;
}

static int fs_inner_write(struct file *f, const char *buf, size_t size,
	off_t offset)
{
	printf("%s \n",__func__);
	return 0;
}

static int fs_rename(const char *name, const char *newname)
{
	printf("%s\n",__func__);
	return 0;
}

static struct fuse_operations hello_oper = {
	.init           = hello_init,
//	.getattr	= hello_getattr,
	.readdir 	= fs_readdir,
	.open		= hello_open,
	.read		= hello_read,
	.unlink         = fs_unlink,
	.write		= fs_write,
//	.rename		= fs_rename,
//	.destroy	= fs_destroy,
//	.mkdir		= fs_mkdir,
//	.chmod		= fs_chmod,
};

static void show_help(const char *progname)
{
	printf("usage: %s [options] <mountpoint>\n\n", progname);
	printf("File-system specific options:\n"
	       "    --name=<s>          Name of the \"hello\" file\n"
	       "                        (default: \"hello\")\n"
	       "    --contents=<s>      Contents \"hello\" file\n"
	       "                        (default \"Hello, World!\\n\")\n"
	       "\n");
}

int main(int argc, char *argv[])
{
	struct fuse_args args = FUSE_ARGS_INIT(argc, argv);

	/* Set defaults -- we have to use strdup so that
	   fuse_opt_parse can free the defaults if other
	   values are specified */
	options.filename = strdup("hello");
	options.contents = strdup("Hello World!\n");

	/* Parse options */
	if (fuse_opt_parse(&args, &options, option_spec, NULL) == -1)
		return 1;

	/* When --help is specified, first print our own file-system
	   specific help text, then signal fuse_main to show
	   additional help (by adding `--help` to the options again)
	   without usage: line (by setting argv[0] to the empty
	   string) */
	if (options.show_help) {
		show_help(argv[0]);
		assert(fuse_opt_add_arg(&args, "--help") == 0);
		args.argv[0] = (char*) "";
	}

	return fuse_main(args.argc, args.argv, &hello_oper, NULL);
}
