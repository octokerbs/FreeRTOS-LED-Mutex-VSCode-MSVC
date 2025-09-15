# FreeRTOS LED Color Simulation

A small demo using FreeRTOS tasks and a mutex to switch between two LED colors (RED, GREEN).

## Features
- `vLedStartRedColor`: Prints **RED** if the resource is free.  
- `vLedStartGreenColor`: Locks the resource for a random time and prints **GREEN**.  
- `vLedColor`: Refreshes the console every 100ms with the current color.  

## Requirements
- [MSVC](https://visualstudio.microsoft.com/vs/features/cplusplus/)  
- [FreeRTOS-LTS](https://www.freertos.org/) (next to `main.c`)  
- [CMake](https://cmake.org/download/)  
- Console with ANSI or `system("cls")` support  

## How It Works
- Green task randomly takes the mutex → shows **GREEN**.  
- Red task runs when mutex is free → shows **RED**.  
- Display task continuously prints the active color.  

## Example
```
RED
RED
GREEN
RED
GREEN
```
