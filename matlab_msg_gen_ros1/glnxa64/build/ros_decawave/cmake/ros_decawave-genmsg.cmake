# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "ros_decawave: 4 messages, 0 services")

set(MSG_I_FLAGS "-Iros_decawave:/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg;-Istd_msgs:/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg;-Istd_msgs:/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(ros_decawave_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Anchor.msg" NAME_WE)
add_custom_target(_ros_decawave_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ros_decawave" "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Anchor.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Tag.msg" NAME_WE)
add_custom_target(_ros_decawave_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ros_decawave" "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Tag.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/AnchorArray.msg" NAME_WE)
add_custom_target(_ros_decawave_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ros_decawave" "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/AnchorArray.msg" "ros_decawave/Anchor:std_msgs/Header"
)

get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Acc.msg" NAME_WE)
add_custom_target(_ros_decawave_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ros_decawave" "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Acc.msg" "std_msgs/Header"
)

#
#  langs = gencpp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(ros_decawave
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Anchor.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_decawave
)
_generate_msg_cpp(ros_decawave
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Tag.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_decawave
)
_generate_msg_cpp(ros_decawave
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/AnchorArray.msg"
  "${MSG_I_FLAGS}"
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Anchor.msg;/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_decawave
)
_generate_msg_cpp(ros_decawave
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Acc.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_decawave
)

### Generating Services

### Generating Module File
_generate_module_cpp(ros_decawave
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_decawave
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(ros_decawave_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(ros_decawave_generate_messages ros_decawave_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Anchor.msg" NAME_WE)
add_dependencies(ros_decawave_generate_messages_cpp _ros_decawave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Tag.msg" NAME_WE)
add_dependencies(ros_decawave_generate_messages_cpp _ros_decawave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/AnchorArray.msg" NAME_WE)
add_dependencies(ros_decawave_generate_messages_cpp _ros_decawave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Acc.msg" NAME_WE)
add_dependencies(ros_decawave_generate_messages_cpp _ros_decawave_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ros_decawave_gencpp)
add_dependencies(ros_decawave_gencpp ros_decawave_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ros_decawave_generate_messages_cpp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(ros_decawave
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Anchor.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_decawave
)
_generate_msg_py(ros_decawave
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Tag.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_decawave
)
_generate_msg_py(ros_decawave
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/AnchorArray.msg"
  "${MSG_I_FLAGS}"
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Anchor.msg;/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_decawave
)
_generate_msg_py(ros_decawave
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Acc.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_decawave
)

### Generating Services

### Generating Module File
_generate_module_py(ros_decawave
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_decawave
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(ros_decawave_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(ros_decawave_generate_messages ros_decawave_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Anchor.msg" NAME_WE)
add_dependencies(ros_decawave_generate_messages_py _ros_decawave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Tag.msg" NAME_WE)
add_dependencies(ros_decawave_generate_messages_py _ros_decawave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/AnchorArray.msg" NAME_WE)
add_dependencies(ros_decawave_generate_messages_py _ros_decawave_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/ros_decawave/msg/Acc.msg" NAME_WE)
add_dependencies(ros_decawave_generate_messages_py _ros_decawave_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ros_decawave_genpy)
add_dependencies(ros_decawave_genpy ros_decawave_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ros_decawave_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_decawave)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ros_decawave
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(ros_decawave_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(ros_decawave_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_decawave)
  install(CODE "execute_process(COMMAND \"/home/tanishqjain/.matlab/R2020b/ros1/glnxa64/venv/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_decawave\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ros_decawave
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(ros_decawave_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(ros_decawave_generate_messages_py std_msgs_generate_messages_py)
endif()
