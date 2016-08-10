static int hashfs_access(const char *path, int mask)
{
  	char	realpath[ PATH_MAX ];
	int	ret;

  	debug(1, "calling access %s", path);

	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else if ((ret = access(realpath, mask)) < 0) {
	  	ret = -errno;
	}

	return ret;
}
