project('ginitd', 'c', version: '1.0.0')

subdir('man')
subdir('src')

if get_option('debug')
	add_project_arguments('-DDEBUG', language: 'c')
endif
