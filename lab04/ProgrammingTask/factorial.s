.globl main
.text              
#// start code here
#// Insert your code here
main:
    la t0, n    # load address of num for factorial
    # setup registers for function call
    lw a0, 0(t0)
    li t0, 0  # to stop recursive function at 1
    jal ra, factorial
    la t1, result   # load address of the result variable to t1
    sw a0, 0(t1)     # store the factorial result at the address
    j write_tohost


factorial:
    # YOUR CODE HERE
    # BEGIN PROLOGUE
    addi sp, sp, -16
    sw ra, 4(sp)
    # END PROLOGUE
    
    bgt a0, t0, recursive_call # if a0 > t0 then target
    addi t0, x0, 1
    mv a0, t0 # if n <= 1 return 1
    j end_recursive_call

recursive_call:
    sw a0, 0(sp) # save value of n (a0) for recursive calls
    addi a0, a0 , -1 # decrement the value of n, n-1 for every call
    jal ra, factorial # recursive call to factorial

    # Restore the values after the call
    lw t3, 0(sp)

    # calculate the result
    mul a0, a0 , t3 # x = x * x
end_recursive_call:
    # Clean up the stack frame
    # Restore registers from the stack
    lw ra, 4(sp)   # Restore the return address
    addi sp, sp, 16   # Deallocate the stack frame (32 bytes)

    jr ra  # Return to the caller      
# end code here

write_tohost:
li x1, 1
sw x1, tohost, t5
j write_tohost
.data 
#// start data section here      
#// Initialize data here (if required)
n: .word 3
result: .word 0
#// end data section here

.align 12
.section ".tohost","aw",@progbits;                            
.align 4; .global tohost; tohost: .dword 0;                     
.align 4; .global fromhost; fromhost: .dword 0;
