# Smart Energy System (C++)

A simple console-based Smart Energy System built in C++.  
This program allows users to register home appliances, calculate daily energy consumption, and generate billing summaries.

## Features

- Register appliances (name, power rating, hours used per day)
- View all registered appliances
- Calculate total daily energy consumption (kWh)
- Calculate electricity bill based on tariff
- Save appliance data to file
- Load saved appliance data on startup
- Save billing summaries to file

## How It Works

Energy is calculated using:

Energy (kWh) = (Power in Watts × Hours per day) / 1000

The system stores:
- Appliance data in `appliances.txt`
- Billing summaries in `billing_summary.txt`

## Menu Options

1. Register Appliance  
2. View Appliances  
3. Calculate Total Energy  
4. Calculate Billing  
5. Exit  

When exiting, appliance data is automatically saved.

## Requirements

- C++ compiler (g++, MinGW, or any standard C++ compiler)
- Works in terminal / command prompt

## How to Compile

Using g++:

```bash
g++ main.cpp -o smart_energy
./smart_energy
```

(Replace `main.cpp` with your actual file name if different.)

## Project Structure

- Uses `struct` for appliance data
- Uses `vector` to store appliances
- Uses file handling (`fstream`) for saving/loading data
- Modular functions for clean code organization

## Notes

- Appliance names should not contain spaces (current version uses `cin >> name`).
- Billing history is appended to the billing file.
- Data is saved when the program exits.

---

This project was built step-by-step to demonstrate:
- Structs
- Vectors
- File handling
- Functions
- Modular programming in C++
