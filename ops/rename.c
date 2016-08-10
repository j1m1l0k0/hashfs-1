static int hashfs_rename(const char *from, const char *to)
{
  	char	src[ PATH_MAX ];
  	char	dst[ PATH_MAX ];
	int	ret;

  	debug(1, "calling rename %s -> %s", from, to);

	if (mtor(from, src, sizeof(src)) < 0) {
	  	ret = ENOMEM;
	} else if (mtor(to, dst, sizeof(dst)) < 0) {
	  	ret = ENOMEM;
	} else if ((ret = rename(src, dst)) < 0) {
	  	ret = -errno;
	}

	return ret;
}
