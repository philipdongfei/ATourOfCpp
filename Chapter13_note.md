# 13 Concurrency

## 13.1 Introduction

  Concurrency - the execution of several tasks simultaneously - is widely used to improve throughtput (by using several processors for a single computation) or to improve responsiveness (by allowing one part of a program to progress while another is waiting for a response).
  The standard library directly supports concurrent execution of multiple threads in a single address space. To allow that, C++ provides a suitable memory model and a set of atomic operations. The atomic operations allows lock-free programming.
  Do not consider concurrency a panacea. If a task can be done sequentially, it is often simpler and faster to do so.

## 13.2 Tasks and threads

  We call a computation that can potentially be executed concurrently with other computations a *task*. A *thread* is the system-level representation of a task in a program.
  Threads of a program share a single address space. In this, threads differ from processes, which generally do not directly share data. Since threads share an address space, they can communicate through shared objects(13.5).
  When defining tasks of a concurrent program, our aim is to keep tasks completely separate except where they communicate in simple and obvious ways. The simplest way of thinking of a concurrent task is as a function that happens to run concurrently with its caller. For that to work, we just have to pass arguments, get a result back, and make sure that there is no use of shared data in between(no data races).

## 13.3 Passing Arguments

  Passing vec2 by value would eliminate that risk.
  The **ref()** is a type function from **<functional>** that unfortunately is needed to tell the variadic template to treate **some_vec** as a reference, rather than as an object.

## 13.4 Returning Results

## 13.5 Sharing Data

  On the other hand, modern machines are very good at copying data, especially compact data, such as **vector** elements. So don't choose shared data for communication because of "efficiency" without thought and preferably not without measurement.

## 13.6 Waiting for Events

## 13.7 Communicating Tasks

1. **future** and **promise** for returning a value from a task spawned on a separate thread
2. **packaged_task** to help launch tasks and connect up the mechanisms for returning a result
3. **async()** for launching of a task in a manner very similar to calling a function.

### 13.7.1 future and promise

 The important point about **future** and **promise** is that they enable a transfer of a value between two tasks without explicit use of a lock; "the system" implements the transfer efficiently. The basic idea is simple: When a task wants to pass a value to another, it puts the value into a **promise**. 
  The reason that a **packaged_task** cannot be copied is that it is a resource handle: it owns its **promise** and is (indirectly) responsible for whatever resources its task may own.
  Please note the absence of explicit mention of locks in this code: we are able to concentrate on tasks to be done, rather than on the mechanisms used to manage their communication.

### 13.7.3 async()

  Using **async()**, you don't have to think about threads and locks. Instead, you think just in terms of tasks that potentially compute their results asynchronously.
  Please note that **async()** is not just a mechanism specialized for parallel computation for increased performance.


