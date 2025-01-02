# Event Management System

## Description
A C program designed to process and analyze event data from input files, calculating attendance metrics and financial summaries. The system reads event information including dates, attendance figures, and ticket costs, then generates comprehensive reports with revenue calculations and statistical summaries.

## Features
- File I/O operations for data processing
- Event attendance tracking
- Revenue calculations
- Detailed reporting functionality
- Summary statistics generation

## Technical Details
- Language: C
- Input: Text file (dec_events.txt)
- Output: Formatted report (report.txt)
- Data processing: File handling
- Calculations: Revenue and averages

## Usage
1. Prepare input file with event data in format: `day attendance cost`
2. Compile the program
3. Run the executable
4. View generated report with attendance and revenue details

## Functions
- `readEventData`: Processes input file data
- `calculateRevenue`: Computes event revenue
- `printReportLine`: Formats and displays event details
- `printSummary`: Generates statistical summary

## Output Format
```
Date | Attendance | Cost Per Person | Gross Revenue

*****Summary*****
Total Attendance: [value]
Total Revenue: $[value]
Average Cost Per Person: $[value]
```

## Author
Rashil Shibakoti  
CSC150 Fall 2023  
South Dakota State University
