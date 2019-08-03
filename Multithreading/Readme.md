#### 多线程

线程可以提高应用程序在多核环境下处理诸如文件I/O或者socket I/O等会产生堵塞的情况的表现性能。

- 头文件

  #include <pthread.h>

- 线程声明

  pthread_t thread1;

- 创建线程

  pthread_create();

线程声明：pthread_t th;

编译：gcc example.c -o example -lpthread