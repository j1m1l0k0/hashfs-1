static int hashfs_mkdir(const char *path, mode_t mode)
{
  	char	realpath[ PATH_MAX ];
	int	ret;

  	debug(1, "calling mkdir %s", path);

	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else if ((ret = mkdir(realpath, mode)) < 0) {
	  	ret = -errno;
	}

	return ret;
}
