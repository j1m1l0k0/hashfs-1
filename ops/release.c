static int hashfs_release(const char *path, struct fuse_file_info *info)
{
  	char	realpath[ PATH_MAX ];
	int	ret = 0;

  	debug(1, "calling release %s", path);
	if (info->fh < 0) {
	  	error("file already closed");
		ret = -EBUSY;
	} else {
	  	debug(1, "release %d", info->fh);
	  	close(info->fh);
		info->fh = -1;
	}

	return ret;
}
