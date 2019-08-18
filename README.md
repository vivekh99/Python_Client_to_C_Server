# python_client_to_c_server
This shows how to connect a client programmed in Python to a server programmed in C
in socket programming
------------------------------------------------------------------------------------
Basic implementation of connecting a Python client to a C server and 
sending data from BOTH

To run:
  1) Open two terminal windows and navigate to directory path which each file is stored on both terminals
  2) Run gcc -o test_server test_server.c, hit ENTER, then type ./test_server.c
  3) Run client in seperate terminal window by typing python3 client.py
  4) If successful, you should see messages appear on both terminals confirming connections between client and server!
