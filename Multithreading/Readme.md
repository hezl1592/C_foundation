#### 多线程

线程可以提高应用程序在多核环境下处理诸如文件I/O或者socket I/O等会产生堵塞的情况的表现性能。

- 头文件

  #include <pthread.h>

- 线程声明

  pthread_t thread1;

- 创建线程

  pthread_create();

- 终止线程

  - 从线程函数return；
  - 调用pthread_cancel终止同一进程中的另一个线程；
  - 线程使用pthread_exit终止自身；

编译：gcc example.c -o example -lpthread

##### 线程同步

多线程程序，访问冲突的问题是很普遍的，通常加入互斥锁进行解决。

- 获得锁的线程对共享数据进行操作，然后释放锁给其它线程，没有获得锁的线程只能等待而不能访问共享数据。

- Mutex

  ```c
  /*
  int pthread_mutex_destroy(pthread_mutex_t *mutex);
  int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
  返回值：成功返回0，失败返回错误号。*/
  
  pthread_mutex_t mutex;
  //如果Mutex变量是静态分配的（全局变量或static变量），用宏定义进行初始化，并且attr参数为NULL;
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
  
  /*
  int pthread_mutex_lock(pthread_mutex_t *mutex);
  int pthread_mutex_trylock(pthread_mutex_t *mutex);
  int pthread_mutex_unlock(pthread_mutex_t *mutex);
  返回值：成功返回0，失败返回错误号。*/
  
  
  ```

  一个线程可以调用pthread_mutex_lock获得Mutex，如果这时另一个线程已经调用pthread_mutex_lock获得了该Mutex，则当前线程需要挂起等待，直到另一个线程调用pthread_mutex_unlock释放Mutex，当前线程被唤醒，才能获得该Mutex并继续执行。如果一个线程既想获得锁，又不想挂起等待，可以调用pthread_mutex_trylock，如果Mutex已经被另一个线程获得，这个函数会失败返回EBUSY，而不会使线程挂起等待。

- Condition Variable

  线程间的同步还有这样一种情况：线程A需要等某个条件成立才能继续往下执行，现在这个条件不成立，线程A就阻塞等待，而线程B在执行过程中使这个条件成立了，就唤醒线程A继续执行。

  条件变量：

  ```c
  /*int pthread_cond_destroy(pthread_cond_t *cond);
  int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);
  pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
  返回值：成功返回0，失败返回错误号。*/
  
  ```
