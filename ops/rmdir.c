static int hashfs_rmdir(const char *path)
{
  	char	realpath[ PATH_MAX ];
	int	ret;

  	debug(1, "calling rmdir %s", path);

	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else if ((ret = rmdir(realpath)) < 0) {
	  	ret = -errno;
	}

	return ret;
}
