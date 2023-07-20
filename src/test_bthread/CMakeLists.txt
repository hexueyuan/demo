link_libraries(bthread butil gflags ${DYNAMIC_LIB})

add_executable(test_bthread ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
install(TARGETS test_bthread
        RUNTIME DESTINATION ${PROJECT_OUTOUT_BIN_DIR}
        LIBRARY DESTINATION ${PROJECT_OUTOUT_LIB_DIR}
        ARCHIVE DESTINATION ${PROJECT_OUTOUT_LIB_DIR})