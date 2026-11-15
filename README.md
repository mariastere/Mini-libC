# Mini-libc

## 📌 Overview
**Mini-libc** is a minimalistic, freestanding standard C library implementation for Linux (x86_64). Built from scratch as a replacement for the system's `libc` (glibc), this project is implemented directly on top of the Linux system call interface without relying on any external library calls.

The core objective of this project is to provide a deeper understanding of how the standard C library interacts with the Linux kernel, how memory management functions operate behind the scenes, and how low-level POSIX file I/O works.

## ⚙️ Architecture & Implementation Details
* **Freestanding:** Does not use any outside library calls. Every standard function is implemented from scratch.
* **Syscall Interface:** All interactions with the kernel are done via a custom `syscall()` wrapper tailored for the **x86_64 architecture**.
* **Error Handling:** Implements proper `errno` population on system call failures, mirroring the behavior of the standard `libc`.

## 🛠️ Features & Implemented API

### 1. String & Memory Manipulation (`<string.h>`)
Custom implementations of standard string and memory handling functions:
* `strcpy()`, `strncpy()`, `strcat()`, `strncat()`
* `strlen()`, `strcmp()`, `strncmp()`, `strstr()`, `strrstr()`
* `memcpy()`, `memset()`, `memmove()`, `memcmp()`

### 2. Memory Allocation (`<stdlib.h>`, `<sys/mman.h>`)
Dynamic memory management capabilities utilizing `mmap` and a custom linked-list structure for tracking memory blocks:
* `malloc()`, `free()`, `calloc()`, `realloc()`, `realloc_array()`
* `mmap()`, `mremap()`, `munmap()`

### 3. POSIX File I/O (`<unistd.h>`, `<sys/fcntl.h>`, `<sys/stat.h>`)
Low-level primitives for file manipulation:
* `open()`, `close()`, `lseek()`
* `stat()`, `fstat()`
* `truncate()`, `ftruncate()`

### 4. Standard I/O (`<stdio.h>`)
* `puts()`

### 5. Time Operations (`<time.h>`)
* `sleep()`, `nanosleep()`

## 🚀 Key Learnings
* Understanding the internal structure and responsibilities of the standard C library.
* Direct interaction with the Linux kernel via x86_64 system calls.
* Manual dynamic memory management and building custom wrappers over `mmap`.
* Handling POSIX standard file descriptors, metadata (`stat`), and error codes (`errno`).
