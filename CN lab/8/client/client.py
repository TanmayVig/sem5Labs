import socket

HOST = '127.0.0.1'
PORT = 3000

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    while True:
        choice = int(input("""
        Enter:
            1. to send text file
            2. to send image
            3. to exit
        """))
        if choice == 1:
            choice=3
            path = input("Enter path: ")
            s.sendall(path.encode())
            with open(path,'rb') as f:
                line = f.read(1024)
                while line:
                    s.sendall(line)
                    print("sending: "+line.decode('utf-8'))
                    line = f.read(1024)
                s.sendall(bytes(False))
            print("Task completed: File sent to server.")
        elif choice==2:
            choice=3
            path = input("Enter path: ")
            s.sendall(path.encode())
            with open(path, 'rb') as f:
                while True:
                    line = f.read(1024)
                    if not line:
                        break
                    s.sendall(line)
                s.sendall(bytes(False))
            print("Task completed: Image sent to servre")
        else:
            break

        
        if ext:=s.recv(1024):
            ext = ext.decode().split(".")[1]
            with open("recv.{}".format(ext),'wb') as f:
                while True:
                    data= s.recv(1024)
                    try:
                        if data.decode():
                            break
                    except UnicodeDecodeError:
                        pass
                    f.write(data)
                print("New File Recieved")
        else:
            break
