static int hashfs_chown(const char *path, uid_t uid, gid_t gid)
{
  	char	realpath[ PATH_MAX ];
	int	ret;

  	debug(1, "calling chown %s %d:%d", path, uid, gid);

	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else if ((ret = chown(realpath, uid, gid)) < 0) {
	  	ret = -errno;
	}

	return ret;
}
