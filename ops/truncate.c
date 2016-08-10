static int hashfs_truncate(const char *path, off_t size)
{
  	char	realpath[ PATH_MAX ];
	int	ret;

  	debug(1, "calling truncate %s", path);

	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else if ((ret = truncate(realpath, size)) < 0) {
	  	ret = -errno;
	}

	return ret;
}
