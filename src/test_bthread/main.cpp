#include <iostream>

#include <pthread.h>
#include <bthread/bthread.h>

#include "gflags/gflags.h"

DEFINE_string(thread_mode, "pthread", "");
DEFINE_int32(thread_num, 3, "");

/* thread执行逻辑 */
void* _do(void* p_args) {
    size_t& thread_index = *((size_t*)p_args);
    std::string start_message = "Sub thread " + std::to_string(thread_index) + " running.\n";
    std::cout << start_message << std::ends;

    sleep(10);

    std::string stop_message = "Sub thread " + std::to_string(thread_index) + " exit.\n";
    std::cout << stop_message << std::ends;
}

void run_as_pthread() {
    size_t* index_list = new size_t[FLAGS_thread_num];
    pthread_t* thread_ids = new pthread_t[FLAGS_thread_num];

    for (size_t index = 0; index < FLAGS_thread_num; ++index) {
        index_list[index] = index + 1;
        if (pthread_create(&thread_ids[index], NULL, _do, &index_list[index]) != 0) {
            std::cout << "Pthread create failed." << std::endl;
        }
    }
    std::cout << "Pthreads create success, join in main thread." << std::endl;
    for (size_t index = 0; index < FLAGS_thread_num; ++index) {
        pthread_join(thread_ids[index], NULL);
    }
    std::cout << "Pthreads all done, main thread exit.\n" << std::ends;
    delete[] thread_ids;
    delete[] index_list;
}

void run_as_bthread() {
    size_t* index_list = new size_t[FLAGS_thread_num];
    bthread_t* thread_ids = new bthread_t[FLAGS_thread_num];

    for (size_t index = 0; index < FLAGS_thread_num; ++index) {
        index_list[index] = index + 1;
        if (bthread_start_background(&thread_ids[index], NULL, _do, &index_list[index]) != 0) {
            std::cout << "Bthread create failed." << std::endl;
        }
    }
    std::cout << "Bthreads create success, join in main thread." << std::endl;
    for (size_t index = 0; index < FLAGS_thread_num; ++index) {
        bthread_join(thread_ids[index], NULL);
    }
    std::cout << "Bthreads all done, main thread exit.\n" << std::ends;
    delete[] thread_ids;
    delete[] index_list;
}

void start_all_threads() {
    if (FLAGS_thread_mode == "pthread") {
        run_as_pthread();
    } else if (FLAGS_thread_mode == "bthread") {
        run_as_bthread();
    } else {
        std::cout << "Bad thread mode." << std::endl;
    }
}

int main(int argc, char** argv) {
    google::ParseCommandLineFlags(&argc, &argv, true);
    start_all_threads();

    return 0;
}