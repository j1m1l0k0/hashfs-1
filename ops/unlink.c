static int hashfs_unlink(const char *path)
{
  	char	realpath[ PATH_MAX ];
	int	ret;

  	debug(1, "calling unlink %s", path);

	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else if ((ret = unlink(realpath)) < 0) {
	  	ret = -errno;
	}

	return ret;
}
