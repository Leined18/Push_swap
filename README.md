# Cloning

 ```
 git clone --recursive git@github.com:Leined18/Push_swap.git
 cd Minitalk
 make all

 ```


Available operations

    sa : Swap the first two elements on stack 'a'.
    sb : Swaps the first two elements on stack 'b'.
    ss : Execute sa and sb simultaneously.
    pa : Takes the first element of stack 'b' and puts it on stack 'a'.
    pb : Takes the first element of stack 'a' and puts it on stack 'b'.
    ra : Moves all elements of stack 'a' up one position.
    rb : Moves all elements of stack 'b' up one position.
    rr : Executes ra and rb simultaneously.
    rra : Moves all elements on the 'a' stack one position down.
    rrb : Moves all elements of stack 'b' down one position.
    rrr: Run rra and rrb simultaneously.


ARG="numbers with spaces"; ./push_swap $ARG
