import socket
import serial
import time

serial_port_name = '/dev/ttyACM0'
serial_port = serial.Serial(serial_port_name, 9600)
time.sleep(2)


def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 8102))
    server_socket.listen(5) 

    print("Aguardando conexão...")

    client_socket, client_address = server_socket.accept()
    print(f"Conexão estabelecida com o cliente: {client_address}")

    while True:
        mensagem_arduino = serial_port.readline().decode('utf-8').strip()
        print(mensagem_arduino)
        client_socket.send(mensagem_arduino.encode('utf-8'))

        mensagem_cliente = client_socket.recv(1024).decode("utf-8")
        
        if mensagem_cliente:
            serial_port.write(f"{mensagem_cliente}\n".encode('utf-8'))




    '''client_socket.close()
    server_socket.close()''' 


if __name__ == "__main__":
    start_server()
