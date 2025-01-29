libopus = static_library(
	'opus',

	# cli
	'cli_args.c',

	# getopt
	'getopt_args_error.c',
	'getopt_args.c',
	'getopt_error.c',
	'getopt_init.c',
	'getopt_private.c',
	'getopt_usage.c',

	# init
	'init_comm_error.c',
	'init_handle_selinux.c',
	'init_main.c',
	'init_maintain_runlevel.c',
	'init_parse_code.c',
	'init_private.c',
	'init_read_code.c',
	'init_reap_zombies.c',
	'init_runlevel_script.c',
	'init_send_code.c',
	'init_userspace.c',

	# logging
	'logging_errno.c',
	'logging_init.c',
	'logging_logf.c',
	'logging_private.c',
	'logging_write.c',

	# runlevel
	'runlevel_info.c',
	'runlevel_info_raw.c',
	'runlevel_main.c',
	'runlevel_show.c'
)

executable(
	'init',

	# init
	'init.c',

	link_with: libopus,
	install: true,
	install_dir: '/sbin'
)

executable(
	'runlevel',

	# runlevel
	'runlevel.c',

	link_with: libopus,
	install: true,
	install_dir: '/bin'
)

install_symlink(
	'telinit',

	install_dir: '/sbin',
	pointing_to: '/sbin/init'
)
