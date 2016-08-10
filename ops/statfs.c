static int hashfs_statfs(const char *path, struct statvfs *stbuf)
{
  	char	realpath[ PATH_MAX ];
	int	ret;

  	debug(1, "calling statfs %s", path);

	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else if ((ret = statvfs(realpath, stbuf)) < 0) {
	  	ret = -errno;
	}

	return ret;
}
