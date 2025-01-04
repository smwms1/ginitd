libginitd = static_library(
	'ginitd',

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
