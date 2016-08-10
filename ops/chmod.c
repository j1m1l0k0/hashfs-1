static int hashfs_chmod(const char *path, mode_t mode)
{
  	char	realpath[ PATH_MAX ];
	int	ret;

  	debug(1, "calling chmod %s %o", path, mode);

	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else if ((ret = chmod(realpath, mode)) < 0) {
	  	ret = -errno;
	}

	return ret;
}
