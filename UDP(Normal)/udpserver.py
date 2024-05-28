import socket
import time

own_name = 'localhost'
own_port = 6889

#creating socket object
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

#waiting time of the server
time.sleep(5)

s.sendto(b"Hello class!! Welcome to your lab class", (own_name, own_port))
msg = "Goodbye!!"
s.sendto(msg.encode(), (own_name, own_port))
s.close()