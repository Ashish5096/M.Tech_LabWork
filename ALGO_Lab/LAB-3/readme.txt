SOURCE CODE FILES
----------------------------------

1. quickA.c            # Original Quick Sort program     
    Command to run this file:
    
    > gcc quickA.c
    >./a.out input_file.txt output_file.txt

2. quickB.c             # Quick sort with modified partition function as specified in the question
    Command to run this file:
    
    > gcc quickB.c
    >./a.out input_file.txt output_file.txt

INPUT FILES FOLDER
------------------------------------

desc_input-5000.txt :- contains elements in descending order, size 5000 elements.
rnd_input-5000.txt  :- contains elements in random order, size 5000 elements.
dup_input-5000.txt  :- contains large no of duplicate elements, size 5000 elements.

OUTPUT FILES FOLDER
-----------------------------

desc_output.txt :- contains output for descending order data.
rnd_output.txt  :- contains output for random order data.
dup_output.txt  :- contains output for dataset containg lots of duplicate element.


ANALYSIS
-----------

quickB.c

In this parition procedure of code is modified as mentioned in the question B of the assignment. when we run this code it goes in a infinite loop condition, its so because parition procedure does not contain any condition to tackle duplicate elements.


