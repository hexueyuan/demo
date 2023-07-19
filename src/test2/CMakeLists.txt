link_libraries(gflags brpc protobuf butil bvar bthread mcpack2pb json2pb leveldb ssl snappy crypto dl z ${DYNAMIC_LIB})

# Compile proto file
set(PROTO_SOURCE_DIR ${PROJECT_BINARY_DIR}/proto)
file(MAKE_DIRECTORY ${PROTO_SOURCE_DIR})
add_custom_command(
    OUTPUT "${PROTO_SOURCE_DIR}/echo.pb.h" "${PROTO_SOURCE_DIR}/echo.pb.cc"
    COMMAND /Users/hexueyuan/Workroot/CPPRELEASE/bin/protoc -I${CMAKE_CURRENT_SOURCE_DIR} --cpp_out=${PROTO_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/echo.proto
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/echo.proto)
include_directories(${PROTO_SOURCE_DIR})

add_executable(test2 ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ${PROTO_SOURCE_DIR}/echo.pb.cc)
install(TARGETS test2
        RUNTIME DESTINATION ${PROJECT_OUTOUT_BIN_DIR}
        LIBRARY DESTINATION ${PROJECT_OUTOUT_LIB_DIR}
        ARCHIVE DESTINATION ${PROJECT_OUTOUT_LIB_DIR})