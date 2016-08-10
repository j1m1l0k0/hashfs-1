static int hashfs_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *info)
{
  	char	realpath[ PATH_MAX ];
	int	ret = -1;

  	debug(1, "calling read %s", path);

	if (info->fh < 0) {
	  	error("read with invalid file handle");
		ret = -EBUSY;
	} else if ((ret = pread(info->fh, buf, size, offset)) < 0) {
	  	ret = -errno;
	}

  	return ret;
}
