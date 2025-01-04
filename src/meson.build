libginitd = static_library(
	'ginitd',

	# getopt
	'getopt_error.c',
	'getopt_init.c',
	'getopt_private.c',
	'getopt_usage.c',

	# init
	'init_handle_selinux.c',
	'init_main.c',
	'init_maintain_runlevel.c',
	'init_private.c',
	'init_read_code.c',
	'init_reap_zombies.c',
	'init_runlevel_script.c',
	'init_send_code.c',
	'init_userspace.c',

	# path
	'path_concat.c',
	'path_private.c',

	# runlevel
	'runlevel_info.c',
	'runlevel_main.c',
	'runlevel_show.c',

	# supervise
	'supervise_control_mk.c',
	'supervise_private.c',
	'supervise_sv_status.c',
	'supervise_sv.c'
)

executable(
	'init',
	
	# init
	'init.c',
	
	link_with: libginitd,
	install: true,
	install_dir: 'sbin'
)

executable(
	'runlevel',
	
	# runlevel
	'runlevel.c',
	
	link_with: libginitd,
	install: true,
	install_dir: 'bin'
)
