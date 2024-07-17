# Airport Control System Simulation

This project simulates an airport control system that manages the takeoff and landing of airplanes based on priority. The system reads input data from a file, processes it to determine the order of takeoffs and landings, and outputs the results to another file. The priorities are assigned to different types of aircraft, and delays are handled according to specified rules.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [File Descriptions](#file-descriptions)
- [Function Descriptions](#function-descriptions)
- [Sources](#sources)

## Introduction

The airport control system simulation is designed to manage and prioritize the takeoff and landing sequences of airplanes at an airport. The system reads data from an input file, processes it to prioritize the airplanes based on their types, and manages delays and reschedules. The results are then written to an output file.

## Features

- Prioritizes airplanes based on their types:
  - 1: Ambulance Plane
  - 2: Fighter Jet
  - 3: Passenger Plane
  - 4: Cargo Plane
- Manages takeoff and landing sequences.
- Handles delays and reschedules flights if necessary.
- Outputs the final schedule and delay information to a file.

## Installation

To install and run this project, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/200202087/Airport-Control-System-Simulation.git
    ```
2. Navigate to the project directory:
    ```sh
    cd Airport-Control-System-Simulation
    ```

## Usage

To use the airport control system simulation, follow these steps:

1. Prepare an `input.txt` file with the required format:
    ```txt
    priorityID planeID requestedTime
    ```
    - Example:
      ```txt
      1 101 5
      3 203 6
      2 302 7
      ```

2. Run the executable:
    ```sh
    ./main.exe
    ```

3. The results will be printed to the console and written to an `output.txt` file.

## File Descriptions

- `main.c`: The main source code file containing all the functions and logic for the simulation.
- `input.txt`: Input file containing the flight data (to be created by the user).
- `output.txt`: Output file where the results of the simulation are written.
- `main.exe`: The compiled executable of the project.
- `main.o`: The object file generated during compilation.
- `bekleme.txt`: An additional file used in the project.
- `AirportSystemRep.pdf`: A PDF report detailing the project.

## Function Descriptions

### `void dosyadanOku()`
Reads data from `input.txt`, parses it, and initializes the necessary arrays for further processing.

### `void kuyrEkle(int istenenSaat[], int oncelikID[], int ucakID[], int ertelenmeSaati[])`
Adds flights to the queue, manages delays, and handles the scheduling of takeoffs and landings.

### `void sirala()`
Sorts the flights based on their priority and other criteria.

### `void yazdir(int inissira[])`
Writes the final schedule and delay information to `output.txt` and prints it to the console.

### `int main()`
The main function that initializes the program, reads the input data, processes it, and outputs the results.

# Sources

You can review the project code [here](main.c).

You can review the project report [here](AirportSystemRep.pdf).

