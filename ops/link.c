static int hashfs_link(const char *from, const char *to)
{
  	char	src[ PATH_MAX ];
  	char	dst[ PATH_MAX ];
	int	ret = ENOTSUP;

  	debug(1, "calling link %s -> %s", from, to);

	if (mtor(from, src, sizeof(src)) < 0) {
	  	ret = ENOMEM;
	} else if (mtor(to, dst, sizeof(dst)) < 0) {
	  	ret = ENOMEM;
	} else if ((ret = link(src, dst)) < 0) {
	  	ret = -errno;
	}

	return ret;
}
