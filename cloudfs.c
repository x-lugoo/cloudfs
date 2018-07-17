#include <stdio.h>

#include "fs.h"
#define DEFAULT_TIMEOUT_S 1

struct arginfo{
	char *hostfile;
	char *mountpoint;
	int  num_args;
	int timeout;
};

enum{
	KEY_HELP = 0,
	KEY_ASUSER,
	KEY_TIMEOUT,
};

static const struct fuse_opt cloud_opts[] = {
        FUSE_OPT_KEY("-h",  KEY_HELP),
        FUSE_OPT_KEY("-u ", KEY_ASUSER),
        FUSE_OPT_KEY("-t ", KEY_TIMEOUT),
        FUSE_OPT_END,
};

int main(int argc,char **argv)
{
//	struct arginfo arginfo;
	struct fuse_args args = FUSE_ARGS_INIT(argc,argv);
//	arginfo.timeout = DEFAULT_TIMEOUT_S;
	/* Always run FUSE in foreground */
//	fuse_opt_add_arg(&args, "-f");

	/* Run FUSE single threaded */
//	fuse_opt_add_arg(&args, "-s");

	/* Default permissions handling, allow all users
	 * Directory is 775 so only root can use it anyway */
//	fuse_opt_add_arg(&args, "-odefault_permissions,allow_other");

	/* Enable direct IO so we can do partial read/writes */
//	fuse_opt_add_arg(&args, "-odirect_io");

	printf("Mounting filesystem\n");
	fuse_main(args.argc, args.argv, &fs_ops, NULL);
	//fuse_opt_free_args(&args);

	printf("cloudfs\n");
	return 0;
}

