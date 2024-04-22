import socket

server_name = 'localhost'
server_port = 9999

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_ip = socket.gethostbyname(server_name)
s.connect((server_ip, server_port))
while True:
    msg = input("Enter the message: ")
    s.send(msg.encode())
    reply = s.recv(1024)
    print("Received ", reply.decode())
s.close()
