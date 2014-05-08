#ifdef ACK
! (ACK needs an #ifdef before the first comment !)

!****************************************************************************
!
!     _ m l i . s                                                M I N I X
!
!     Basic fast signed multiplication routine
!****************************************************************************
!
!
!============================================================================
! Edition history
!
!  #    Date                         Comments                       By
! --- -------- ---------------------------------------------------- ---
!   1 15.07.89 totally rewritten                                    RAL
!   2 26.07.89 bug fixes                                            KS
!   3 01.08.89 minor improvements and comment fixes                 RAL
!
!****************************************************************************

           .sect    .text
           .sect    .rom
           .sect    .data
           .sect    .bss


           .sect    .text

           .define  .mli

!****************************************************************************
!
!          . m l i
!
!          Fast signed LW multiplication routine
!****************************************************************************
!
! Input:   on stack:
!                 m2.l  -  multiplicand
!                 m1.l  -  multiplier
!          (a7) ->(rts_ptr.l) - abs. return ptr.
!
! Output:  d0.l  - high order result
!          d1.l  - low order result
!          d2,a0,a1  - *
!
!****************************************************************************

.mli:
           move.l   (sp)+,a0        ! get return ptr.
           clr.l    d2
           move.l   (sp)+,d1        ! get multiplier (m1) and test it
           bpl      next_arg
           not.l    d2              ! if negativ: store sign and neg
           neg.l    d1
next_arg:
           move.l   (sp)+,d0        ! get multiplicand (m2) and test it
           bpl      sav_reg
           not.l    d2              ! if negativ: store sign and neg
           neg.l    d0
sav_reg:   movem.l  d3-d4,-(sp)     ! save used registers

           move.l   d1,d4
           move.l   d1,d3
           swap     d3              ! d3.w = high m1
           mulu     d0,d1           ! d1 = low m2 x low m1
           move.w   d3,d2
           bne      long_mul
           swap     d0              ! d0.w = high m2
           tst.w    d0              !                and test it
           bne      mid_mul         ! high m2 x low m1 <> 0 ->
           clr.l    d0              ! high order result = 0
set_sign:
           tst.l    d2
           bpl      end
           neg.l    d1
           negx.l   d0
end:
           movem.l  (sp)+,d3-d4     ! restore used registers
           jmp      (a0)


mid_mul:
           mulu     d0,d4           ! d4 = low m1 * high m2
mid_mul2:
           clr.l    d0              ! and  high m2 * high m1  == 0
           swap     d1              ! result = d1 + d4 << 16
           add.w    d4,d1
           swap     d4
           addx.w   d4,d0
           swap     d1
           bra      set_sign

long_mul:
           mulu     d0,d3           ! d3 = low m2 x high m1
           swap     d0              ! d0.w = high m2
           tst.w    d0              ! high m2 == 0
           bne      really_long
           move.l   d3,d4
           bra      mid_mul2        ! identical as mid_mul

really_long:
           mulu     d0,d4           ! d4 = high m2 * low m1
           mulu     d2,d0           ! d0 = high m1 * high m2
           swap     d1              ! upper word of low order res.
           add      d3,d1
           clr      d3
           swap     d3
           addx.l   d3,d0           ! add with x-bit of low order result
           add      d4,d1
           swap     d1              ! low order result
           clr      d4
           swap     d4
           addx.l   d4,d0           ! add with x-bit of low order result
           bra      set_sign
#endif

