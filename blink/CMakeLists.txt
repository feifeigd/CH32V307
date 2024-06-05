aux_source_directory(User SRC)

set(cur_project blink)
add_executable(${cur_project} ${SRC})
target_include_directories(${cur_project} PRIVATE
    .
	User
)

ch32v_target_set_device(${cur_project} ch32v307vct6 DEBUG)
ch32v_target_generate_map(${cur_project})
ch32v_target_generate_hex(${cur_project})
ch32v_target_show_size(${cur_project})
