import socket

def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 8087))


    while True:
        mensagem_servidor = client_socket.recv(1024).decode("utf-8")
        print (mensagem_servidor)
        if mensagem_servidor:
            mensagem = "P"
            client_socket.send(mensagem.encode("utf-8"))
    client_socket.close()

if __name__ == "__main__":
    start_client()