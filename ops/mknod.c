static int hashfs_mknod(const char *path, mode_t mode, dev_t dev)
{
  	char	realpath[ PATH_MAX ];
	int	ret;

  	debug(1, "calling mknod %s mode %o", path, mode);

	if (mtor(path, realpath, sizeof(realpath)) < 0) {
	  	ret = ENOMEM;
	} else if ( S_ISREG(mode) ) {
	  	if ((ret = open(realpath, O_CREAT | O_EXCL | O_WRONLY, mode)) < 0) {
		  	ret = -errno;
		} else {
		  	close(ret);
			ret = 0;
		}
	} else if ( S_ISFIFO(mode) ) {
	  	if ((ret = mkfifo(realpath, mode)) < 0) {
		  	ret = -errno;
		} else {
			ret = 0;
		}
	} else if ((ret = mknod(realpath, mode, dev)) < 0) {
	  	ret = -errno;
	} else {
		ret = 0;
	}

	return ret;
}
    
