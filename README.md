# To-Do List Management System in C++

A console-based To-Do List application implemented in C++ using singly linked lists. This program allows users to add, display, update, and delete tasks dynamically.

Features

Add Task: Insert a new task with a status (e.g., pending, completed).

Display Tasks: View all tasks with their status.

Update Task Name & Status: Modify a task’s name and/or its status.

Update Status Only: Quickly update the status of an existing task.

Delete Task by Position: Remove a task from the list using its position.

Dynamic Memory Management: Uses pointers and dynamic memory allocation with new and delete.

Data Structure Used

Singly Linked List:
Each task is a node containing:

task (string) → the task description

status (string) → the task’s current status

link (pointer) → pointer to the next task

Advantages:

Dynamic size, easy insertion/deletion.

Traversal is straightforward.
