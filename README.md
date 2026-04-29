# Multi-Threaded Inventory and Order Processing System (C++)


## Project Overview

This project is a **Multi-Threaded Inventory and Order Processing System** developed in **C++** as part of a final-year group assignment. The system simulates a real-world inventory and order management environment where multiple operations occur concurrently.

The primary goal of the system is to efficiently handle **inventory updates** and **order processing** using **multi-threading techniques**, ensuring data consistency, synchronization, and optimal performance.

All functional and technical requirements specified for the project were **successfully implemented and completed**.

---

## Objectives

- Design and implement a concurrent system using C++
- Simulate real-time inventory management
- Process multiple customer orders simultaneously
- Ensure thread safety and data integrity
- Apply synchronization mechanisms effectively

---

##  Features

- Inventory management (add, update, and track stock levels)
-  Order creation and processing
-  Multi-threaded execution for concurrent operations
-  Thread synchronization (e.g., mutexes, locks)
-  Efficient handling of multiple requests
- Console-based interaction/output


---

##  Key Concepts Used

- Multi-threading
- Concurrency control
- Mutexes and locks
- Critical sections
- Race condition prevention
- Object-Oriented Programming (OOP)

---
## System Design
![Alt text](https://github.com/Msiziy/Inventory-and-Order-Processing-System/blob/main/CodeFellazProject/Screenshot%202026-04-30%20000342.png?raw=true)

---

##  How It Works

1. The system initializes inventory with predefined or user-defined items
2. Multiple threads are created to simulate concurrent order requests
3. Each thread processes an order independently
4. Shared resources (inventory) are protected using synchronization techniques
5. The system updates stock levels safely without data corruption
6. The system produces output as shown below (see screenshots):

![Alt text](https://github.com/Msiziy/Inventory-and-Order-Processing-System/blob/main/CodeFellazProject/CodeFellazProjectLatest%20(3)/CodeFellazProjectLatest%20(1)/CodeFellazProject/Screenshot1.png?raw=true)

![Alt text](https://github.com/Msiziy/Inventory-and-Order-Processing-System/blob/main/CodeFellazProject/CodeFellazProjectLatest%20(3)/CodeFellazProjectLatest%20(1)/CodeFellazProject/Screenshot2.png?raw=true)

![Alt text](https://github.com/Msiziy/Inventory-and-Order-Processing-System/blob/main/CodeFellazProject/CodeFellazProjectLatest%20(3)/CodeFellazProjectLatest%20(1)/CodeFellazProject/Screenshot3.png?raw=true)

![Alt text](https://github.com/Msiziy/Inventory-and-Order-Processing-System/blob/main/CodeFellazProject/CodeFellazProjectLatest%20(3)/CodeFellazProjectLatest%20(1)/CodeFellazProject/Screenshot4.png?raw=true)

![Alt text](https://github.com/Msiziy/Inventory-and-Order-Processing-System/blob/main/CodeFellazProject/CodeFellazProjectLatest%20(3)/CodeFellazProjectLatest%20(1)/CodeFellazProject/Screenshot5.png?raw=true)

![Alt text](https://github.com/Msiziy/Inventory-and-Order-Processing-System/blob/main/CodeFellazProject/CodeFellazProjectLatest%20(3)/CodeFellazProjectLatest%20(1)/CodeFellazProject/Screenshot6.png?raw=true)

![Alt text](https://github.com/Msiziy/Inventory-and-Order-Processing-System/blob/main/CodeFellazProject/CodeFellazProjectLatest%20(3)/CodeFellazProjectLatest%20(1)/CodeFellazProject/Screenshot7.png?raw=true)

![Alt text](https://github.com/Msiziy/Inventory-and-Order-Processing-System/blob/main/CodeFellazProject/CodeFellazProjectLatest%20(3)/CodeFellazProjectLatest%20(1)/CodeFellazProject/Screenshot8.png?raw=true)

---

##  Technologies Used

- **Language:** C++
- **Concepts:** Standard Thread Library (`<thread>`), Mutex (`<mutex>`), STL
- **Development Type:** Console Application

---

##  Future Improvements

- Add graphical user interface (GUI)
- Integrate database for persistent storage
- Implement advanced scheduling algorithms
- Enhance logging and monitoring

---

##  Acknowledgements

Special thanks to the lecturer and institution for providing the project requirements and guidance throughout the development process.

---

> ⭐ If you find this project useful, consider giving it a star!
