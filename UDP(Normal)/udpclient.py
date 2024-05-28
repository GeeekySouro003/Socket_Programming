import socket

server_name = 'localhost'
server_port = 6889

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((server_name, server_port))

msg, addr = s.recvfrom(1024)
#s.settimeout(5)

while msg:
    
    print("Received: "+ msg.decode())
    msg, addr = s.recvfrom(1024)


s.close()