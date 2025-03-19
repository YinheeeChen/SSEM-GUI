# SSEM-GUI

## Introduction
SSEM-GUI is a C++ project with a graphical user interface (GUI) version of the Small-Scale Experimental Machine (SSEM). This project utilizes the Qt framework to provide an interactive and user-friendly way to simulate the operations of the SSEM.

## Features
- **GUI Interface**: Provides a user-friendly graphical interface to interact with the SSEM simulation.
- **Simulation Control**: Start, stop, and step through the simulation of the SSEM.
- **File Handling**: Load and process assembly language programs for the SSEM.

## Installation
To install and run this project, follow these steps:

1. Clone the repository:
   ```sh
   git clone https://github.com/YinheeeChen/SSEM-GUI.git
   cd SSEM-GUI
   ```

2. Install Qt:
   - Ensure you have Qt installed. You can download it from [Qt's official website](https://www.qt.io/download).

3. Build the project:
   ```sh
   qmake
   make
   ```

## Usage
To use the SSEM-GUI, follow these instructions:

1. Run the application:
   ```sh
   ./SSEM-GUI
   ```

2. Use the provided GUI to load assembly language programs, start the simulation, step through instructions, and observe the results.

## Code Structure
- **main.cpp**: Contains the main function which initiates the GUI application.
- **mainwindow.h**: Defines the MainWindow class with methods and slots for handling GUI interactions and simulation control.

## Methods in mainwindow.h
- `void on_btnStart_clicked()`: Slot to handle the start button click event.
- `void on_btnNext_clicked()`: Slot to handle the next button click event.
- `void on_btnAuto_clicked()`: Slot to handle the auto button click event.
- `void on_btnStop_clicked()`: Slot to handle the stop button click event.
- `void Show(QString strAcc, QString strCi, QString strPi, int iOpcode, int iOperand)`: Slot to display the current state of the SSEM.
- `void ShowDialog()`: Slot to show dialog messages.
