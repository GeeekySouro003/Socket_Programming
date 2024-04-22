import socket

own_name = 'localhost'
own_port = 9099

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((own_name, own_port))
s.listen(3)

c, address = s.accept()
print("Connection from", str(address))

while True:
    msg = c.recv(1024)
    if not msg:
        break
    print("Received:", msg.decode())
    reply = input("Enter the reply: ")
    c.send(reply.encode())

c.close()
