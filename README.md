<div align="center">

# 🟢🔴 FreeRTOS LED Color Simulation
This mini-project simulates the behavior of two tasks managing LED colors (red and green) using FreeRTOS and a mutual exclusion semaphore (mutex). The purpose is to demonstrate basic concepts of multitasking, synchronization, and resource protection in a real-time operating system.
</div>

## 🔧 Features
Three concurrent tasks:

1. `vLedStartRedColor`: Displays "RED" when no other task holds the shared resource.

2. `vLedStartGreenColor`: Simulates a task that uses the resource for a random duration, during which it displays "GREEN".

3. `vLedColor`: A display task that clears the console and prints the active color every 100ms. 


Mutual exclusion is handled with a FreeRTOS mutex to prevent data races when accessing `currentColor`.

## 🧠 Concepts 
FreeRTOS Task Creation
Using xTaskCreate() to launch multiple concurrent tasks.

Mutex Synchronization
Using xSemaphoreTake() and xSemaphoreGive() to safely share a resource (currentColor).

Task Scheduling & Delays
Using vTaskDelay() to simulate task execution time and control task frequency.

Randomized Task Behavior
Green task randomly holds the mutex and simulates different workloads.

## 📦 Requirements
[MSVC compiler](https://visualstudio.microsoft.com/vs/features/cplusplus/)

[FreeRTOS-LTS](https://www.freertos.org/) directory next to main.c.

Console terminal that supports ANSI or system("cls")

[CMake](https://cmake.org/download/)

## 🚀 How It Works
The green task randomly acquires the mutex and holds it (simulating a process).

While the mutex is held, the red task cannot access it, and GREEN is displayed.

When the green task releases the mutex, the red task picks it up and displays RED.

A third task (vLedColor) continuously updates the screen to show the current color state.

## 📝 Example
```
RED
RED
GREEN
RED
RED
GREEN
...
```
