import socket

server_name='localhost'
server_port=8800

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

server_ip=socket.gethostbyname(server_name)

print(server_ip)

s.connect((server_ip,server_port))

msg=s.recv(1024)

while msg:
    print("Received dost" + msg.decode())
    msg=s.recv(1024)
s.close()