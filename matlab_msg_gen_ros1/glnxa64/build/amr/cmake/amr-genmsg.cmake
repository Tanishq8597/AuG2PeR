# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "amr: 2 messages, 0 services")

set(MSG_I_FLAGS "-Iamr:/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg;-Istd_msgs:/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg;-Istd_msgs:/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(amr_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg/IMU_10dof.msg" NAME_WE)
add_custom_target(_amr_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "amr" "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg/IMU_10dof.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg/wheel.msg" NAME_WE)
add_custom_target(_amr_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "amr" "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg/wheel.msg" "std_msgs/Header"
)

#
#  langs = gencpp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(amr
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg/IMU_10dof.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/amr
)
_generate_msg_cpp(amr
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg/wheel.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/amr
)

### Generating Services

### Generating Module File
_generate_module_cpp(amr
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/amr
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(amr_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(amr_generate_messages amr_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg/IMU_10dof.msg" NAME_WE)
add_dependencies(amr_generate_messages_cpp _amr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg/wheel.msg" NAME_WE)
add_dependencies(amr_generate_messages_cpp _amr_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(amr_gencpp)
add_dependencies(amr_gencpp amr_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS amr_generate_messages_cpp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(amr
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg/IMU_10dof.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/amr
)
_generate_msg_py(amr
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg/wheel.msg"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/amr
)

### Generating Services

### Generating Module File
_generate_module_py(amr
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/amr
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(amr_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(amr_generate_messages amr_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg/IMU_10dof.msg" NAME_WE)
add_dependencies(amr_generate_messages_py _amr_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/amr/msg/wheel.msg" NAME_WE)
add_dependencies(amr_generate_messages_py _amr_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(amr_genpy)
add_dependencies(amr_genpy amr_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS amr_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/amr)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/amr
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(amr_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(amr_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/amr)
  install(CODE "execute_process(COMMAND \"/home/tanishqjain/.matlab/R2020b/ros1/glnxa64/venv/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/amr\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/amr
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(amr_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(amr_generate_messages_py std_msgs_generate_messages_py)
endif()
