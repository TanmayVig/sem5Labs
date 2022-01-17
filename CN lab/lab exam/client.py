import socket

HOST:str = '127.0.0.1'
PORT:int = 3300

def count(s:list[str]) -> list[int]:
    c:list[int] = [0,0]
    for i in range(len(s)):
        if s[i]=="0":
            c[0]+=1
        elif s[i]=="1":
            c[1]+=1
        else:
            return [-1,-1]
    return c

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT)) # sending connection request
    text:str = s.recv(1024).decode('utf-8') #recieving data from Server
    print("Server: "+text)
    t:list[int] = count(text) #getting count of 0s and 1s
    if t[0]==-1:
        sen = "invalid string"
    else:
        sen = "No. of 0s: "+ str(t[0]) +"\nNo. of 1s: "+ str(t[1]) +"\n"
    s.sendall(sen.encode()) #sending data to Server
    print("Client: \n"+ sen)
