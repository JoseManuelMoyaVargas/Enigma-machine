# Enigma-machine
C++ program that implements a variant of the Enigma machine used in the Second World War.

In this case the machine encrypts messages in an alphabet consisting of n letters denoted by numbers {1,2,...,n}. 
Symbol 0 ends the message.

## Rotors and reflectors 
Rotors Wx={wx, 0, wx, 1,...,wx, n} and reflectors Ry={ry, 0, ry, 1,...,ry, n} are given as permutations of numbers {1,2,...,n} and simulate mechanical parts that can be used by an operator.mThe internal "wiring" of these parts does not change.  
Typing a letter into the input encrypts it by passing it through the rotors into reflector and back through the rotors in the inverse sequence, as seen here. A stationary sequence of rotors and a reflector represent a simple substitution cipher, it is their movement which makes the decoding chalenging.  
Each rotor can move counterclockwise by at most one step during each encoding. The first rotor moves before every encoding; therefore if the initial position of this single rotor is denoted by the last letter of the alphabet (i.e. n, see example I) the first letter is encoded according to substitutions as stated in the rotor's definition.  
Further rotors move according to rules outlined in section "Turnover notch positions" of this link and this section. Additional information about double stepping can be found here.  
In case there are more than 3 rotors only the first 3 rotate.  

## Input format

Input can be thought as divided into two parts: definitions of pieces of the machine and p instructions how to encode a given message using some of those parts. Before encoding a message the machine is assembled from k out of m rotors and a single reflector (out of l) and the rotors are set to some initial positions.  

Input:  
Defintions of parts of the machine :  
n- number of letters (numbers) in the alphabet  
m - number of rotors, followed by their definitions W0,...,Wm-1. 
definition of rotor Wi - permutation of the alphabet  
number of letters which cause turnover, followed by these letters as in "Position of turnover notches" table  
l - number of reflectors  
definitions of reflectors R0,...,Rl-1 - permutation of the alphabet  

A set of p tasks to perform:  
each task consists of 2 parts: machine setup and a message to encrypt.  
p number of tasks  
k - number of rotors in the machine  
k pairs K0,...,Kk-1 - where Ki=(j, t), where j is an index of a copy of rotor Wj and t is its initial position  
rotors are given in order from fastest to slowest  
initial position of a rotor - it is set as if it was rotated (no actual rotations occur) prior to encoding, e.g. 1 - rotor is set as stated in permutation, 2 - it is shifted by one letter, etc.  
r index of a reflector Rr  
a sequence of numbers separated by whitespaces to encrypt, ending with the 0 character  

## Output format
Output:  
encrypted sequences of numbers (without the 0 character). 


## Example of input/output:

4   
4  
1 2 4 3  
1 2    
3 2 1 4   
0  
4 3 1 2  
0  
3 2 1 4  
0  
3  
2 1 4 3  
4 3 2 1  
1 2 4 3  

6  
1 0 4 2  
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 0  
1 0 4 0  
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 0  
1 0 4 1  
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 0  
1 2 4 0  
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 0  
1 3 4 0  
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 0  
2 0 4 0 1 0  
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 0  


Output:  
 
1 1 1 3 2 4 2 2 4 3 4 1 3 2 3 4  
2 3 2 3 1 4 1 4 4 1 4 1 3 2 3 2  
3 4 3 4 4 3 4 3 1 2 1 2 2 1 2 1  
2 3 2 3 1 4 1 4 4 1 4 1 3 2 3 2  
4 4 4 4 3 3 3 3 2 2 2 2 1 1 1 1  
2 2 4 2 3 4 1 4 4 4 2 4 1 2 3 2 2 2 4 2 3 4 1 4 4 4 2 4 1 2 3 2   

