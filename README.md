
Quiz
Question 1 (2.1 points)
 

Which instruction(s) require memory access, either for reading, writing, or both?
Question 1 options:
	

add eax, dword ptr[Var]
	

add dword ptr[Var], eax
	

Push eax
	

Pop eax
	

Jmp esp
	

Call esp
	

Ret
Question 2 (1 point)
 

Which one is different from the others in terms of purpose?
Question 2 options:
	

DEP
	

ASLR
	

NOP sled
	

Stack Cookies
Question 3 (1.5 points)
 

Suppose that EAX holds the address where instruction X is stored. Which instruction(s) will redirect execution to instruction X?
Question 3 options:
	

jmp EAX
	

jmp ESP
	

call EAX
	

call ESP
	

Ret
	

mov EAX, EIP
Question 4 (2 points)
 

Consider the following pseudocode for a vulnerable server:
Void foo(char *msg){
    char buf1[45];
    char buf2[18];
    Strcpy(buf1, msg);
}

Main(){
    Msg = sock.recv(1000)
    If (strncmp(msg, "PT", 2) == 0){
        Foo(msg)
    }
    ...
}
The following diagram shows the stack frame of the foo function:
What is the bad string you need to send to the server to overwrite the EBP with "AAAA" and the EIP with "BBBB"? Write your answer as a Python string, such as, "Hello World"  + "A" * 123.
Question 4 options:
Question 4 options:
Question 5 (1 point)
 

Mark each statement that is true about a reverse shell.
Question 5 options:
	

Victim initiates the connection to the attacker's machine.
	

The payload runs on the victim machine and connects back to the attacker's IP and port.
	

It crashes the target machine due to a buffer overflow.
	

The attacker sets up a listening socket on their own machine using the victim's IP and port. 

0 of 5 questions saved
