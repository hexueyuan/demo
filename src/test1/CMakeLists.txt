link_libraries(butil ${DYNAMIC_LIB})

add_executable(test1 ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
install(TARGETS test1
        RUNTIME DESTINATION ${PROJECT_OUTOUT_BIN_DIR}
        LIBRARY DESTINATION ${PROJECT_OUTOUT_LIB_DIR}
        ARCHIVE DESTINATION ${PROJECT_OUTOUT_LIB_DIR})