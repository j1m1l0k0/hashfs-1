#include <unistd.h>

static int hashfs_readlink(const char *path, char *buf, size_t size)
{
  	char	realpath[ PATH_MAX ];
	int	ret;

  	debug(1, "calling readlink %s", path);

	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else if ((ret = readlink(path, buf, size - 1)) < 0) {
	  	ret = -errno;
	} else {
	  	buf[ret] = '\0';
	}

	return ret;
}



