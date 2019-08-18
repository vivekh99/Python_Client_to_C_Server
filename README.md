# Python_Client_to_C_Server
This shows how to connect a client programmed in Python to a server programmed in C
using socket programming
------------------------------------------------------------------------------------
Basic implementation of connecting a Python client to a C server and 
sending data from BOTH

To run Python client and C server:
  1) Open two terminal windows and navigate to directory path which each file is stored on both terminals
  2) Run gcc -o test_server test_server.c, hit ENTER, then type ./test_server.c
  3) Run client in seperate terminal window by typing python3 client.py
  4) If successful, you should see messages appear on both terminals confirming connections between client and server!
  
To run the Python GUI (made in PyQT5) with C server:
  1) Must have PyQT5 installed on computer (use pip)
  2) Open your IDE and open test_gui.py file in it (I used Spyder)
  3) Open a terminal window and navigate to directory path which each test_server.c file is stored
  4) Run gcc -o test_server test_server.c, hit ENTER, then type ./test_server.c
  5) Run the GUI file from your IDE
  6) A window should open where you can enter text and hit send. Enter text and press send
  7) In the terminal running the server, the text yhat you sent should show up in the terminal
  (unfortunately, some error occurs when trying to run the .py file in the terminal (not sure why), therefore I run it in the IDE)
