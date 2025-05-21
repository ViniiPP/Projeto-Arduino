import socket
from datetime import *

HOST = '10.1.25.117'
PORT =  8083

def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((HOST, PORT))


    while True:
        data = datetime.now()
        dataa = data.strftime('%d/%m/%Y %H:%M')
        mensagem_servidor = client_socket.recv(1024).decode("utf-8")
        print (mensagem_servidor + f" \ndata:{dataa}")
        if mensagem_servidor:
            mensagem = "P"
            client_socket.send(mensagem.encode("utf-8"))
        
    '''client_socket.close()'''

if __name__ == "__main__":
    start_client()