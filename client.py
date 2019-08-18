# -*- coding: utf-8 -*-
"""
Created on Fri Aug 16 12:28:18 2019

@author: vivek
"""

import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0);
#if client_socket < 0:
 #   print("Error making socket!");
client_socket.connect((socket.gethostname(), 9001));
client_socket.sendall(bytes("This is data sent from client to verify connection to server", "utf-8"));
msg = client_socket.recv(50);
print(msg);
client_socket.close();