Overview
The code implements a priority queue for managing patients in a hospital using a linked list. It allows adding, processing, updating, and displaying patients based on their medical condition's priority.
The conditions are categorized into three levels of priority: critical, urgent, and normal.

Key Components
Class Patient

Attributes:
name: The name of the patient.
age: The age of the patient.
condition: The medical condition of the patient.
priority: An integer representing the priority of the patient.
Constructor: Initializes the name, age, and condition attributes and sets the priority based on the condition.
Method determine_priority: Determines the priority level based on the condition.
Friend Function: Overloads the << operator to print patient details.
Class priorityQueue

Attributes:
pq: A linked list of Patient objects.
Methods:
addPatient: Adds a new patient to the queue, maintaining the order based on priority.
process_patient: Removes and returns the patient with the highest priority.
update_patient: Updates the condition and priority of a specified patient.
displayQueue: Displays all patients in the queue, sorted by priority.
queue_size: Returns the number of patients in the queue.
front_name: Returns the name of the patient at the front of the queue.
Main Function
Initialization:

Creates an instance of priorityQueue.
Predefines some patient objects (p1, p2, p3, p4).
User Input:

Prompts the user to enter the number of patients.
Takes user input for each patient's name, age, and condition, and adds the patient to the queue.
Operations:

Display Queue: Shows the list of patients ordered by priority.
Process Patient: Removes and displays the patient with the highest priority.
Update Patient: Changes the condition (and thus priority) of specific patients.
Display Queue: Shows the updated list of patients after processing and updating conditions.
Example Usage
User enters the number of patients and their details.
Queue is displayed: Lists patients sorted by their priority.
Process patient: Removes the patient with the highest priority and shows their details.
Update conditions: Changes the condition of specific patients and displays the updated queue.
Summary
The code provides a priority queue system for managing patients based on their medical condition's priority. It includes functionalities to add patients, process the highest-priority patient, update patient conditions, and display the queue.
