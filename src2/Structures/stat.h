//
// Created by Paul McGinley on 11/09/2024.
//

#ifndef STAT_H
#define STAT_H

struct Stat {
    int base;
    int bonus;
    int modifier;

    // Calculate the value of the stat
    // This is fine... Addition is a fast operation... This is not a problem.
    int value() {
        return base + bonus + modifier;
    };
    // Having a single variable to store the value of the stat may cause issues
    // If the value of the stat is changed, the modifier will not be updated,
    // would need to make sure I do that myself. If I mess up then boom! Nightmare!
    // Just leave it as a function, it's not a problem.

    // Calculate the value of the stat using x86 assembly
    // int value() {
    //     int result;
    //     asm (
    //         "movl %1, %%eax;"  // Move base into EAX
    //         "addl %2, %%eax;"  // Add bonus to EAX
    //         "addl %3, %%eax;"  // Add modifier to EAX
    //         "movl %%eax, %0;"  // Move the result from EAX to result
    //         : "=r" (result)    // Output operand
    //         : "r" (base), "r" (bonus), "r" (modifier)  // Input operands
    //         : "%eax"           // Clobbered register
    //     );
    //     return result;
    // }
    /*
    Explanation of the inline assembly code:
        1. Inline Assembly Block: The asm keyword is used to include assembly code.
        2. Assembly Instructions:
            -   movl %1, %%eax; moves the value of base into the EAX register.
            -   addl %2, %%eax; adds the value of bonus to EAX.
            -   addl %3, %%eax; adds the value of modifier to EAX.
            -   movl %%eax, %0; moves the result from EAX to the result variable.

        3. Output Operand: The =r constraint specifies that the result will be stored in a general-purpose register.
        4. Input Operands: The r constraints specify that the values of base, bonus, and modifier will be loaded into general-purpose registers.
        5. Clobbered Register: The "%eax" specifies that the EAX register is modified by the assembly code.

    FULL DISCLOSURE: This is a CoPilot generated code.
    I just wanted to benchmark what was faster xD
    */

    // So I'm on a Mac and I can't run x86 assembly code xD

    // Calculate the value of the stat using inline ARM64 assembly
    // int value() {
    //     int result;
    //     asm (
    //         "ldr w0, %1;"  // Load base into w0
    //         "ldr w1, %2;"  // Load bonus into w1
    //         "ldr w2, %3;"  // Load modifier into w2
    //         "add w0, w0, w1;"  // Add w1 to w0
    //         "add w0, w0, w2;"  // Add w2 to w0
    //         "str w0, %0;"  // Store the result in result
    //         : "=m" (result)  // Output operand
    //         : "m" (base), "m" (bonus), "m" (modifier)  // Input operands
    //         : "w0", "w1", "w2"  // Clobbered registers
    //     );
    //     return result;
    // }
    /*
    Explanation:
        1. Inline Assembly Block: The asm keyword is used to include assembly code.
        2. Assembly Instructions:
            -   ldr w0, %1; loads the value of base into the w0 register.
            -   ldr w1, %2; loads the value of bonus into the w1 register.
            -   ldr w2, %3; loads the value of modifier into the w2 register.
            -   add w0, w0, w1; adds the value in w1 to w0.
            -   add w0, w0, w2; adds the value in w2 to w0.
            -   str w0, %0; stores the result from w0 into the result variable.
        3. Output Operand: The =m constraint specifies that the result will be stored in memory.
        4. Input Operands: The m constraints specify that the values of base, bonus, and modifier will be loaded from memory.
        5. Clobbered Registers: The "w0", "w1", "w2" specifies that the w0, w1, and w2 registers are modified by the assembly code.
     */

    // Long story short, the inline assembly code is not worth it in this use case.
    // I have previously used inline assembly in a project to open a custom file type (reverse engineering).
    // It was a team effort and I didn't fully grasp the concept.
    // I get it a bit more now.
};

#endif //STAT_H
