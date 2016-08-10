#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#include <linux/limits.h>
#include <errno.h>

#define	FUSE_USE_VERSION	26
#include <fuse.h>

#include "hashfs.h"

const char	ROOTDIR[] = "/tmp/root";

int mtor(const char *path, char *ret, int bufsiz) 
{
  	int len = strlen(ret) + strlen(ROOTDIR);

	if ( len > (bufsiz - 1) ) {
	  	return -1;
	}
	strcpy(ret, ROOTDIR);
	strcat(ret, path);

	return len;
}

#include "ops/getattr.c"
#include "ops/readlink.c"
#include "ops/getdir.c"
#include "ops/mknod.c"
#include "ops/mkdir.c"
#include "ops/unlink.c"
#include "ops/rmdir.c"
#include "ops/symlink.c"
#include "ops/rename.c"
#include "ops/link.c"
#include "ops/chmod.c"
#include "ops/chown.c"
#include "ops/truncate.c"
#include "ops/utime.c"
#include "ops/open.c"
#include "ops/read.c"
#include "ops/write.c"
#include "ops/statfs.c"
#include "ops/flush.c"
#include "ops/release.c"
#include "ops/fsync.c"
#include "ops/setxattr.c"
#include "ops/getxattr.c"
#include "ops/listxattr.c"
#include "ops/removexattr.c"
#include "ops/opendir.c"
#include "ops/readdir.c"
#include "ops/releasedir.c"
#include "ops/fsyncdir.c"
#include "ops/init.c"
#include "ops/destroy.c"
#include "ops/access.c"
#include "ops/create.c"
#include "ops/ftruncate.c"
#include "ops/fgetattr.c"
#include "ops/lock.c"
#include "ops/utimens.c"
#include "ops/bmap.c"
#include "ops/ioctl.c"
#include "ops/poll.c"
#include "ops/write_buf.c"
#include "ops/read_buf.c"
#include "ops/flock.c"
#include "ops/fallocate.c"

static struct fuse_operations hashfs_ops =
    	{

	  .getattr	= hashfs_getattr,
	  .readlink	= hashfs_readlink,
	  .getdir	= 0L,
	  .mknod	= hashfs_mknod,
	  .mkdir	= hashfs_mkdir,
	  .unlink	= hashfs_unlink,
	  .rmdir	= hashfs_rmdir,
	  .symlink	= hashfs_symlink,
	  .rename	= hashfs_rename,
	  .link		= hashfs_link,
	  .chmod	= hashfs_chmod,
	  .chown	= hashfs_chown,
	  .truncate	= hashfs_truncate,
	  .utime	= 0L,

	  .open 	= hashfs_open,
	  .read 	= hashfs_read,

	  .write	= hashfs_write,
	  .statfs	= hashfs_statfs,
	  .flush	= 0L,
	  .release	= hashfs_release,
	  .fsync	= 0L,
	  .setxattr	= 0L,
	  .getxattr	= 0L,
	  .listxattr	= 0L,
	  .removexattr	= 0L,
	  .opendir	= 0L,

	  .readdir	= hashfs_readdir,
	  .releasedir	= 0L,
	  .fsyncdir	= 0L,
	  .init		= 0L,
	  .destroy	= 0L,
	  .access	= hashfs_access,
	  .create	= 0L,
	  .ftruncate	= 0L,
	  .fgetattr	= 0L,
	  .lock		= 0L,
	  .utimens	= 0L,
	  .bmap		= 0L,
	  .ioctl	= 0L,
	  .poll		= 0L,
	  .write_buf	= 0L,
	  .read_buf	= 0L,
	  .flock	= 0L,
	  .fallocate	= 0L,
	};

static int
option(int argc, char *argv[])
{
  	int i;
	for (i = 0; i < argc; i++) 
	{
	  	char * o = argv[i];
	}
	return argc;
}

int
main(int argc, char *argv[])
{
	debug_init("hashfs", 2);

	if ((argc = option(argc, argv)) < 0) {
		return 2;
	}

  	fuse_main(argc, argv, &hashfs_ops, 0L);
  	return 0;
}
