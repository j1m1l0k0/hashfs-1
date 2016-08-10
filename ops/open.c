static int hashfs_open(const char *path, struct fuse_file_info *info)
{
  	char	realpath[ PATH_MAX ];
	int	ret = -1;

  	debug(1, "calling open %s", path);
	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else if ((info->fh = open(realpath, info->flags)) < 0) {
	  	error("open failed for %s", realpath);
	  	ret = -errno;
		info->fh = -1;
	} else {
		ret = info->fh;
	}


	debug(1, "open returned %d", ret);
	
 return 0;
}
