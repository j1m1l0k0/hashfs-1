#include <dirent.h>

static int hashfs_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi)
{
  	char	realpath[ PATH_MAX ];
	int	ret;
	

	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else {
	  	DIR *	dp = opendir(realpath);
		if (dp == 0L) {
		  	ret = -errno;
		} else {
		  	struct dirent *	entry = 0L;

			while ((entry = readdir(dp)) != 0L) {
			  	struct stat stbuf;

				memset(&stbuf, '\0', sizeof(stbuf));
				stbuf.st_ino = entry->d_ino;
				stbuf.st_mode = entry->d_type << 12;
				if ( filler(buf, entry->d_name, &stbuf, 0) ) {
				  	break;
				}
			}
		  	closedir(dp);
			ret = 0;
		}
	}
	return ret;
}
