# Test-task
Qt application demonstrating multi-threaded number generation with FIFO queue and GUI list display. <br>

## Description
This is a Qt C++ GUI application demonstrating multi-threaded programming with three separate threads:<br>
- Number Generator – generates numbers incrementally.<br>
- Queue Writer – maintains a FIFO queue of 20 numbers which was generated; if the queue is full, the oldest number is removed.<br>
- Loose Number Observer – monitors numbers that are about to leave the queue (without removing them).<br>

The GUI displays three list widgets:<br>
- Generated numbers<br>
- Current queue<br>
- Numbers that will be removed from the queue<br>

The list widgets refresh at least 3 times per second, reflecting the real-time state of each thread.<br>

## Usage
- Press Start Generator to start number generation.
- Press Stop Generator to pause the generator thread.
- Press Start Loose Observer to monitor numbers that will leave the queue.
- Press Stop Loose Observer to pause the observer thread.

Below is an example of how the program functions.
### Start window:
<img width="995" height="728" alt="image" src="https://github.com/user-attachments/assets/bfcf4e0f-43b3-46d3-9989-eb3f13dd9ae9" /> <br>
### Start of programme operation:
<img width="996" height="742" alt="image" src="https://github.com/user-attachments/assets/1b3776c9-8d4d-4449-87be-504e2299943d" /> <br>
### If the queue is full, the third list box displays the number that will be deleted after the next generation:
<img width="990" height="709" alt="image" src="https://github.com/user-attachments/assets/c1131507-59a3-4982-a8ca-f305b6d9ccdb" /> <br>
### When you press the same button again, a message will be displayed informing you of this:
<img width="997" height="238" alt="image" src="https://github.com/user-attachments/assets/d6f5c633-a83c-43ec-9025-d77a0c871b0a" />
