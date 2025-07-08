.extern _start 
.section .hardware_init,"ax",@progbits 
 
.global _hardware_init 
.ent        _hardware_init 
_hardware_init: 
//////////////////////////////////////////////////// 
// disable write back data cache 

       mfcr        r5, cr4 
       nop 
       li        r7, 0x80 
       andri        r6, r5, 0x80 
       cmp.c        r7, r6                # Check under WB mode? 
       bne        under_wt 
       nop 
under_wb: 
       la        r7, tgl_wb 
       cache        0x1f, [r7, 0]        # force write out dirty entry and set invalid 
       nop 
       nop 
       nop 
tgl_wb: 
       cache        0x1d, [r7, 0]        # toggle write-back function 
       nop 
under_wt:                                # Processor is under write-through mode 

//Interrupt enable 
       li r4, 0x1 
       mtcr r4, cr0 
//change exception vector base to 0xa0000000 
       nop
       nop
       nop
       nop
       nop
       li r4, 0xa0000000 
       mtcr r4, cr3 

//LDM enable 
       li    r5,  0xa1000000        /*The start address of data segment will move to LDM*/ 
       cache 0xb, [r5,0]        /*The size of data segment will move to LDM(8k byte)*/ 
       mfcr  r11, cr4 
       ori   r11, 0x8                /*Enable LDM bit(bit 3) of CCR4*/ 
       bitset.c r11,r11,16     /*Enable low power mode*/ 
       mtcr  r11, cr4                /*Enable LDM bit(bit 3) of CCR4 (W-Sttage)*/ 
       nop 
       nop 
       nop
       nop
       nop
       nop

       
       la r0,_stack 


///////////////////////////////////////////////////// 

// Enable BIU Write buffer 
       mfcr        r5, cr4 
       nop 
       li        r7, 0x01 
       andri        r6, r5, 0x01 
       cmp.c        r7, r6                // Check under write buffer mode? 
       beq        wbuff_on 
       nop 
wbuff_off: 
       la        r7, biu_wben 
       cache        0x1a, [r7, 0]        // drain write buffer
       nop 
       nop 
       nop 
biu_wben: 
       cache        0x1b, [r7, 0]        // toggle write buffer function 
       nop 
wbuff_on:                                // Processor is write buffer mode 

        j        _start; 
               
               .end        _hardware_init 
