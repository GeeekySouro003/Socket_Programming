import socket

own_name='localhost'
own_port=8800

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

s.bind((own_name,own_port))

s.listen(1)

c,addr=s.accept()

print("Connection from:",str(addr))

c.send(b"...")
msg=input("Enter your message!!")
c.send(msg.encode())

c.send(b"hello everyone.Socket is working!! Connection established")
msg= "\n \nKabhi Alvida nah Khena"

c.send(msg.encode())
s.close()
