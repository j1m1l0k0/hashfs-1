static int hashfs_symlink(const char *src, const char *path)
{
  	char	realpath[ PATH_MAX ];
	int	ret = ENOTSUP;

  	debug(1, "calling symlink %s %s", src, path);
	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else if ((ret = symlink(src, realpath)) < 0) {
	  	ret = -errno;
	}

	return ret;
}
