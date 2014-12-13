Seena Rowhani
Assignment 1:

Provides the end user with the ability to encrypt and decrypt messages, using a secret key.

Your program will prompt the user to indicate whether they wish to encrypt a readable 
(“plaintext”) message or decrypt an already encrypted sequence of numbers 
(“ciphertext”) back to its readable form.

Source files:
 - a1.c

Header Files:
 - stdin.h
 - string.h

Compilation Command:

 - gcc -o <OUTPUT> a1.c 

Launching instructions:

	1. Navigate to the project folder
	2. Perform "gcc -o <OUTPUT> a1.c"
	3. Type in "./<OUTPUT>" to run the program. 

Command line instructions:

	1. Type in ./<OUTPUT> -h for a help prompt.
		./<output> <encrypt/decrypt> <plaintext/ciphertext> <key>

Operation instructions:
	
	1.  Enter "1" or "2", depending on if you intend to encrypt or decrypt your text.
			- Steps will be denoted a, or b for either option.
	2.a Enter a plaintext string
	3.a Enter an integer key to encrypt the string with.
	4.a Remember the key you used, and pass your encrypted message to its recipient.

	2.b Enter a ciphertext string (your encrypted plaintext string), followed by " -1".
	3.b Enter an integer key to decrypt the string with.
	4.b The decoded message will now print out!

