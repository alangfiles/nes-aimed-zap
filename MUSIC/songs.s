;this file for FamiTone2 library generated by text2data tool

brian2_music_data:
	.byte 1
	.word @instruments
	.word @samples-3
	.word @song0ch0,@song0ch1,@song0ch2,@song0ch3,@song0ch4,307,256 ; New song

@instruments:
	.byte $30 ;instrument $00
	.word @env1,@env5,@env0
	.byte $00
	.byte $70 ;instrument $01
	.word @env2,@env0,@env0
	.byte $00
	.byte $b0 ;instrument $02
	.word @env3,@env0,@env0
	.byte $00
	.byte $b0 ;instrument $03
	.word @env4,@env0,@env0
	.byte $00

@samples:
@env0:
	.byte $c0,$00,$00
@env1:
	.byte $c2,$c1,$c2,$c1,$c0,$00,$04
@env2:
	.byte $cd,$cb,$c9,$c7,$c6,$c5,$c4,$c3,$c2,$c1,$00,$09
@env3:
	.byte $c3,$c2,$02,$c1,$00,$03
@env4:
	.byte $cb,$c9,$c8,$c5,$c4,$c3,$00,$05
@env5:
	.byte $c3,$c2,$c1,$00,$00


; New song
@song0ch0:
	.byte $fb,$06
@song0ch0loop:
@ref0:
	.byte $82,$4b,$53,$59,$4b,$53,$58,$89
@ref1:
	.byte $9f
@ref2:
	.byte $87,$4a,$85,$54,$85,$58,$85
@ref3:
	.byte $87,$58,$85,$53,$55,$52,$85
@ref4:
	.byte $4e,$85,$4a,$85,$4b,$54,$54,$4a,$85
@ref5:
	.byte $52,$85,$4e,$8d,$52,$85
@ref6:
	.byte $4e,$85,$4a,$83,$52,$4a,$85,$4a,$85
@ref7:
	.byte $58,$85,$48,$85,$54,$85,$4e,$85
@ref8:
	.byte $4a,$8b
	.byte $fd
	.word @song0ch0loop

; New song
@song0ch1:
@song0ch1loop:
@ref9:
	.byte $97,$86,$4b,$52,$81
@ref10:
	.byte $59,$4b,$53,$59,$00,$8d
@ref11:
	.byte $87,$59,$53,$4a,$85,$00,$85
@ref12:
	.byte $9f
@ref13:
	.byte $87,$59,$53,$62,$85,$00,$85
@ref14:
	.byte $9f
@ref15:
	.byte $87,$59,$55,$4a,$85,$00,$85
@ref16:
	.byte $9f
@ref17:
	.byte $8d
	.byte $fd
	.word @song0ch1loop

; New song
@song0ch2:
@song0ch2loop:
@ref18:
	.byte $87,$84,$1b,$23,$28,$85,$32,$85
@ref19:
	.byte $87,$1b,$23,$28,$85,$32,$85
	.byte $ff,$07
	.word @ref19
	.byte $ff,$07
	.word @ref19
	.byte $ff,$07
	.word @ref19
	.byte $ff,$07
	.word @ref19
	.byte $ff,$07
	.word @ref19
	.byte $ff,$07
	.word @ref19
@ref26:
	.byte $8d
	.byte $fd
	.word @song0ch2loop

; New song
@song0ch3:
@song0ch3loop:
@ref27:
	.byte $80,$20,$02,$83,$20,$03,$02,$20,$02,$83,$20,$02,$83
@ref28:
	.byte $20,$02,$83,$20,$03,$02,$20,$02,$83,$20,$02,$83
	.byte $ff,$0c
	.word @ref28
	.byte $ff,$0c
	.word @ref28
	.byte $ff,$0c
	.word @ref28
	.byte $ff,$0c
	.word @ref28
	.byte $ff,$0c
	.word @ref28
	.byte $ff,$0c
	.word @ref28
@ref35:
	.byte $8d
	.byte $fd
	.word @song0ch3loop

; New song
@song0ch4:
@song0ch4loop:
@ref36:
	.byte $9f
@ref37:
	.byte $9f
@ref38:
	.byte $9f
@ref39:
	.byte $9f
@ref40:
	.byte $9f
@ref41:
	.byte $9f
@ref42:
	.byte $9f
@ref43:
	.byte $9f
@ref44:
	.byte $8d
	.byte $fd
	.word @song0ch4loop