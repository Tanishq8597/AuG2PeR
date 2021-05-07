# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "rplidar_ros: 0 messages, 1 services")

set(MSG_I_FLAGS "-Istd_msgs:/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg;-Istd_msgs:/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(rplidar_ros_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/rplidar_ros/srv/StartMotor.srv" NAME_WE)
add_custom_target(_rplidar_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rplidar_ros" "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/rplidar_ros/srv/StartMotor.srv" "std_msgs/UInt16"
)

#
#  langs = gencpp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(rplidar_ros
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/rplidar_ros/srv/StartMotor.srv"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/UInt16.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rplidar_ros
)

### Generating Module File
_generate_module_cpp(rplidar_ros
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rplidar_ros
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(rplidar_ros_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(rplidar_ros_generate_messages rplidar_ros_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/rplidar_ros/srv/StartMotor.srv" NAME_WE)
add_dependencies(rplidar_ros_generate_messages_cpp _rplidar_ros_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rplidar_ros_gencpp)
add_dependencies(rplidar_ros_gencpp rplidar_ros_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rplidar_ros_generate_messages_cpp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(rplidar_ros
  "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/rplidar_ros/srv/StartMotor.srv"
  "${MSG_I_FLAGS}"
  "/usr/local/MATLAB/R2020b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/UInt16.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rplidar_ros
)

### Generating Module File
_generate_module_py(rplidar_ros
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rplidar_ros
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(rplidar_ros_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(rplidar_ros_generate_messages rplidar_ros_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tanishqjain/catkin_ws/src/aug2per/matlab_msg_gen_ros1/glnxa64/src/rplidar_ros/srv/StartMotor.srv" NAME_WE)
add_dependencies(rplidar_ros_generate_messages_py _rplidar_ros_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rplidar_ros_genpy)
add_dependencies(rplidar_ros_genpy rplidar_ros_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rplidar_ros_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rplidar_ros)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rplidar_ros
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(rplidar_ros_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(rplidar_ros_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rplidar_ros)
  install(CODE "execute_process(COMMAND \"/home/tanishqjain/.matlab/R2020b/ros1/glnxa64/venv/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rplidar_ros\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rplidar_ros
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(rplidar_ros_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(rplidar_ros_generate_messages_py std_msgs_generate_messages_py)
endif()
