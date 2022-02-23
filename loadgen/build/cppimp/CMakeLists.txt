# Copyright 2018 gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.
#
# cmake build file for C++ helloworld example. Assumes protobuf and gRPC have
# been installed using cmake. See cmake_externalproject/CMakeLists.txt for
# all-in-one cmake build that automatically builds all the dependencies before
# building helloworld.

cmake_minimum_required(VERSION 3.5.1)

project(MLPerfGRPC C CXX)

include(./common.cmake)
# Proto file get_filename_component(basic_proto "../basic.proto" ABSOLUTE)
# get_filename_component(basic_proto_path "${basic_proto}" PATH)

# MLPerf sources
set(mlperf_dataset_src dataset.cpp)
set(mlperf_dataset_hdr dataset.h)
set(mlperf_runner_src runner.cpp)
set(mlperf_runner_hdr runner.h)
set(mlperf_sut_src sut.cpp)
set(mlperf_sut_hdr sut.h)

set(HEADER_FILES
    ${mlperf_dataset_src} ${mlperf_dataset_hdr} ${mlperf_runner_src}
    ${mlperf_runner_hdr} ${mlperf_sut_src} ${mlperf_sut_hdr})

# Generated sources
# TODO: use lib from root directory instead of symlinks
set(basic_proto_srcs "${CMAKE_CURRENT_SOURCE_DIR}/lib/basic.pb.cc")
set(basic_proto_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/lib/basic.pb.h")
set(basic_grpc_srcs "${CMAKE_CURRENT_SOURCE_DIR}/lib/basic.grpc.pb.cc")
set(basic_grpc_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/lib/basic.grpc.pb.h")
# add_custom_command( OUTPUT "${basic_proto_srcs}" "${basic_proto_hdrs}"
# "${basic_grpc_srcs}" "${basic_grpc_hdrs}" COMMAND ${_PROTOBUF_PROTOC} ARGS
# --grpc_out "${CMAKE_CURRENT_BINARY_DIR}" --cpp_out
# "${CMAKE_CURRENT_BINARY_DIR}" -I "${basic_proto_path}"
# --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}" "${basic_proto}"
# DEPENDS "${basic_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")
include_directories("/home/onaman/.local/include/")

# Find original mlperf library
find_library(MLPERF_LIBRARY mlperf_loadgen HINTS "${CMAKE_CURRENT_SOURCE_DIR}/../build")

# basic_grpc_proto
add_library(basic_grpc_proto ${basic_grpc_srcs} ${basic_grpc_hdrs}
                             ${basic_proto_srcs} ${basic_proto_hdrs})
target_link_libraries(basic_grpc_proto ${_REFLECTION} ${_GRPC_GRPCPP}
                      ${_PROTOBUF_LIBPROTOBUF})

# mlperf_library
add_library(mlperf_lib_dataset ${mlperf_dataset_src} ${mlperf_dataset_hdr})
add_library(mlperf_lib_runner ${mlperf_runner_src} ${mlperf_runner_hdr})
add_library(mlperf_lib_sut ${mlperf_sut_src} ${mlperf_sut_hdr})
add_library(grpc_basic_client lib/basic_client.h lib/basic_client.cpp)
target_link_libraries(
  grpc_basic_client basic_grpc_proto
  # ${MLPERF_LIBRARY}
  ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})

add_dependencies(mlperf_lib_runner grpc_basic_client)
add_dependencies(mlperf_lib_sut mlperf_lib_dataset)
add_executable(loadgen cppimp.cpp)
target_link_libraries(
  loadgen
  basic_grpc_proto
  mlperf_lib_dataset
  mlperf_lib_sut
  mlperf_lib_runner
  grpc_basic_client
  ${MLPERF_LIBRARY}
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

add_executable(grpc_server lib/basic_server.cpp)
target_link_libraries(
  grpc_server basic_grpc_proto
  # ${MLPERF_LIBRARY}
  ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})
