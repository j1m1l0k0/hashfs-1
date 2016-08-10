static int hashfs_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *info)
{
  	char	realpath[ PATH_MAX ];
	int	ret = -1;

  	debug(1, "calling write %s", path);

	if (info->fh < 0) {
	  	error("write with invalid file handle");
		ret = -EBUSY;
	} else if ((ret = pwrite(info->fh, buf, size, offset)) < 0) {
	  	ret = -errno;
	}

  	return ret;
}
