static int hashfs_getattr(const char *path, struct stat *stbuf)
{
  	char	realpath[ PATH_MAX ];
	int	ret;

  	debug(1, "calling getattr %s", path);

	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else if ((ret = lstat(realpath, stbuf)) < 0) {
	  	ret = -errno;
	}

	return ret;
}
