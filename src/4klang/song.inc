%macro export_func 1
   global _%1
   _%1:
%endmacro
%define AUTHORING					; Use to export the current tick being rendered
%define SINGLE_TICK_RENDERING		; Use to render single tick on _4klang_render invocation ( requires AUTHORING enabled )
%define SAMPLE_RATE	44100
%define MAX_INSTRUMENTS	7
%define MAX_VOICES 1
%define HLD 1
%define BPM 120.000000
%define MAX_PATTERNS 55
%define PATTERN_SIZE_SHIFT 4
%define PATTERN_SIZE (1 << PATTERN_SIZE_SHIFT)
%define	MAX_TICKS (MAX_PATTERNS*PATTERN_SIZE)
%define	SAMPLES_PER_TICK 5512
%define DEF_LFO_NORMALIZE 0.0000453515
%define	MAX_SAMPLES	(SAMPLES_PER_TICK*MAX_TICKS)
%define 	GO4K_USE_16BIT_OUTPUT
;%define 	GO4K_USE_GROOVE_PATTERN
;%define 	GO4K_USE_ENVELOPE_RECORDINGS
;%define 	GO4K_USE_NOTE_RECORDINGS
%define 	GO4K_CLIP_OUTPUT
%define 	GO4K_USE_DST
%define 	GO4K_USE_DLL
%define 	GO4K_USE_GLOBAL_DLL
%define 	GO4K_USE_ENV_CHECK
%define 	GO4K_USE_ENV_MOD_GM
%define 	GO4K_USE_VCO_CHECK
%define 	GO4K_USE_VCO_PHASE_OFFSET
%define 	GO4K_USE_VCO_SHAPE
%define 	GO4K_USE_VCO_MOD_PM
%define 	GO4K_USE_VCO_MOD_TM
%define 	GO4K_USE_VCO_MOD_DM
%define 	GO4K_USE_VCO_MOD_CM
%define 	GO4K_USE_VCF_CHECK
%define 	GO4K_USE_VCF_MOD_FM
%define 	GO4K_USE_VCF_MOD_RM
%define 	GO4K_USE_VCF_HIGH
%define 	GO4K_USE_VCF_BAND
%define 	GO4K_USE_VCF_PEAK
%define 	GO4K_USE_DST_CHECK
%define 	GO4K_USE_DST_SH
%define		GO4K_USE_DLL_CHORUS_CLAMP
%define 	GO4K_USE_DLL_DAMP
%define 	GO4K_USE_DLL_DC_FILTER
%define 	GO4K_USE_FSTG_CHECK
%define		GO4K_USE_WAVESHAPER_CLIP
%define	MAX_DELAY			65536
%define MAX_UNITS			64
%define	MAX_UNIT_SLOTS	    16
%define GO4K_BEGIN_CMDDEF(def_name)
%define GO4K_END_CMDDEF db 0
%define GO4K_BEGIN_PARAMDEF(def_name)
%define GO4K_END_PARAMDEF
GO4K_ENV_ID		equ		1
%macro	GO4K_ENV 5
	db	%1
	db	%2
	db	%3
	db	%4
	db	%5
%endmacro
%define	ATTAC(val)		val	
%define	DECAY(val)		val	
%define	SUSTAIN(val)	val	
%define	RELEASE(val)	val	
%define	GAIN(val)		val	
struc	go4kENV_val
	.attac		resd	1
	.decay		resd	1
	.sustain	resd	1
	.release	resd	1
	.gain		resd	1
	.size
endstruc
struc	go4kENV_wrk
	.state		resd	1
	.level		resd	1
	.gm			resd	1
	.am			resd	1
	.dm			resd	1
	.sm			resd	1
	.rm			resd	1
	.size
endstruc
%define ENV_STATE_ATTAC		0
%define ENV_STATE_DECAY		1
%define ENV_STATE_SUSTAIN	2
%define ENV_STATE_RELEASE	3
%define ENV_STATE_OFF		4
GO4K_VCO_ID		equ		2
%macro	GO4K_VCO 8
	db	%1
	db	%2
%ifdef GO4K_USE_VCO_PHASE_OFFSET	
	db	%3
%endif	
%ifdef GO4K_USE_VCO_GATE	
	db	%4
%endif	
	db	%5
%ifdef GO4K_USE_VCO_SHAPE	
	db	%6
%endif	
	db	%7
	db	%8
%endmacro
%define	TRANSPOSE(val)	val	
%define	DETUNE(val)		val	
%define	PHASE(val)		val	
%define	GATES(val)		val	
%define	COLOR(val)		val	
%define	SHAPE(val)		val 
%define	FLAGS(val)		val	
%define SINE		0x01
%define TRISAW		0x02
%define PULSE		0x04
%define NOISE		0x08
%define LFO			0x10
%define GATE		0x20
%define	VCO_STEREO	0x40
struc	go4kVCO_val
	.transpose	resd	1
	.detune		resd	1
%ifdef GO4K_USE_VCO_PHASE_OFFSET	
	.phaseofs	resd	1
%endif	
%ifdef GO4K_USE_VCO_GATE	
	.gate		resd	1
%endif	
	.color		resd	1
%ifdef GO4K_USE_VCO_SHAPE	
	.shape		resd	1
%endif	
	.gain		resd	1
	.flags		resd	1	
	.size
endstruc
struc	go4kVCO_wrk
	.phase		resd	1
	.tm			resd	1
	.dm			resd	1
	.fm			resd	1
	.pm			resd	1
	.cm			resd	1
	.sm			resd	1
	.gm			resd	1
	.phase2		resd	1
	.size
endstruc
GO4K_VCF_ID		equ		3
%macro	GO4K_VCF 3
	db	%1
	db	%2
	db	%3
%endmacro
%define LOWPASS		0x1
%define HIGHPASS	0x2
%define BANDPASS	0x4
%define	BANDSTOP	0x3
%define ALLPASS		0x7
%define	PEAK		0x8
%define STEREO		0x10
%define	FREQUENCY(val)	val
%define	RESONANCE(val)	val
%define	VCFTYPE(val)	val
struc	go4kVCF_val
	.freq		resd	1
	.res		resd	1
	.type		resd	1
	.size
endstruc
struc	go4kVCF_wrk
	.low		resd	1
	.high		resd	1
	.band		resd	1
	.freq		resd	1
	.fm			resd	1
	.rm			resd	1
	.low2		resd	1
	.high2		resd	1
	.band2		resd	1
	.size
endstruc
GO4K_DST_ID		equ		4
%macro	GO4K_DST 3
	db	%1
%ifdef GO4K_USE_DST_SH
	db	%2
%ifdef GO4K_USE_DST_STEREO
	db	%3
%endif
%else
%ifdef GO4K_USE_DST_STEREO
	db	%3
%endif
%endif
%endmacro
%define	DRIVE(val)		val
%define	SNHFREQ(val)	val
%define	FLAGS(val)		val
struc	go4kDST_val
	.drive		resd	1
%ifdef GO4K_USE_DST_SH	
	.snhfreq	resd	1
%endif	
	.flags		resd	1
	.size
endstruc
struc	go4kDST_wrk
	.out		resd	1
	.snhphase	resd	1
	.dm			resd	1
	.sm			resd	1
	.out2		resd	1
	.size
endstruc
GO4K_DLL_ID		equ		5
%macro	GO4K_DLL 8
	db	%1
	db	%2
	db	%3
%ifdef GO4K_USE_DLL_DAMP	
	db	%4
%endif		
%ifdef GO4K_USE_DLL_CHORUS	
	db	%5
	db	%6
%endif
	db	%7
	db	%8
%endmacro
%define PREGAIN(val)	val
%define	DRY(val)		val
%define	FEEDBACK(val)	val
%define	DEPTH(val)		val
%define DAMP(val)		val
%define	DELAY(val)		val
%define	COUNT(val)		val
struc	go4kDLL_val
	.pregain	resd	1
	.dry		resd	1
	.feedback	resd	1
%ifdef GO4K_USE_DLL_DAMP	
	.damp		resd	1	
%endif
%ifdef GO4K_USE_DLL_CHORUS
	.freq		resd	1
	.depth
%endif
	.delay		resd	1
	.count		resd	1
	.size
endstruc
struc	go4kDLL_wrk
	.index		resd	1
	.store		resd	1
	.dcin		resd	1
	.dcout		resd	1
%ifdef GO4K_USE_DLL_CHORUS
	.phase		resd	1
%endif
	.buffer		resd	MAX_DELAY
	.size
endstruc
struc	go4kDLL_wrk2
 .pm			resd	1
 .fm			resd	1
 .im			resd	1
 .dm			resd	1
 .sm			resd	1
 .am			resd	1
 .size
endstruc
GO4K_FOP_ID	equ			6
%macro	GO4K_FOP 1
	db	%1
%endmacro
%define	OP(val)			val
%define FOP_POP			0x1
%define FOP_ADDP		0x2
%define FOP_MULP		0x3
%define FOP_PUSH		0x4
%define FOP_XCH			0x5
%define FOP_ADD			0x6
%define FOP_MUL			0x7
%define FOP_ADDP2		0x8
%define FOP_LOADNOTE	0x9
%define FOP_MULP2		0xa
struc	go4kFOP_val
	.flags		resd	1
	.size
endstruc
struc	go4kFOP_wrk
	.size
endstruc
GO4K_FST_ID		equ		7
%macro	GO4K_FST 2
	db	%1
	dw	%2
%endmacro
%define	AMOUNT(val)		val
%define	DEST(val)		val
%define	FST_SET			0x0000
%define	FST_ADD			0x4000
%define	FST_POP			0x8000
struc	go4kFST_val
	.amount		resd	1
	.op1		resd	1
	.size
endstruc
struc	go4kFST_wrk
	.size
endstruc
GO4K_PAN_ID		equ		8
%macro	GO4K_PAN 1
%ifdef GO4K_USE_PAN
	db	%1
%endif
%endmacro
%define	PANNING(val)	val
struc	go4kPAN_val
%ifdef GO4K_USE_PAN
	.panning	resd	1
%endif
	.size
endstruc
struc	go4kPAN_wrk
	.pm			resd	1
	.size
endstruc
GO4K_OUT_ID		equ		9
%macro	GO4K_OUT 2
	db	%1
%ifdef GO4K_USE_GLOBAL_DLL	
	db	%2
%endif	
%endmacro
%define	AUXSEND(val)	val
struc	go4kOUT_val
	.gain		resd	1
%ifdef GO4K_USE_GLOBAL_DLL	
	.auxsend	resd	1
%endif
	.size
endstruc
struc	go4kOUT_wrk
	.am			resd	1
	.gm			resd	1
	.size
endstruc
GO4K_ACC_ID		equ		10
%macro	GO4K_ACC 1
	db	%1
%endmacro
%define OUTPUT			0
%define	AUX				8
%define ACCTYPE(val)	val
struc	go4kACC_val
	.acctype	resd	1
	.size
endstruc
struc	go4kACC_wrk
	.size
endstruc
%ifdef GO4K_USE_FLD
GO4K_FLD_ID	equ		11
%macro	GO4K_FLD 1
	db	%1
%endmacro
%define	VALUE(val)	val
struc	go4kFLD_val
	.value		resd	1
	.size
endstruc
struc	go4kFLD_wrk
	.vm			resd	1
	.size
endstruc
%endif
%ifdef GO4K_USE_GLITCH
GO4K_GLITCH_ID		equ		12
%macro	GO4K_GLITCH 5
	db	%1
	db	%2
	db	%3
	db	%4
	db	%5
%endmacro
%define	ACTIVE(val)		val
%define	SLICEFACTOR(val)val
%define	PITCHFACTOR(val)val
%define	SLICESIZE(val)	val
struc	go4kGLITCH_val
	.active		resd	1
	.dry		resd	1
	.dsize		resd	1
	.dpitch		resd	1
	.slicesize	resd	1
	.size
endstruc
struc	go4kGLITCH_wrk
	.index		resd	1
	.store		resd	1
	.slizesize	resd	1
	.slicepitch	resd	1
	.unused		resd	1
	.buffer		resd	MAX_DELAY
	.size
endstruc
struc	go4kGLITCH_wrk2
	.am			resd	1
	.dm			resd	1
	.sm			resd	1
	.pm			resd	1
	.size
endstruc
%endif
%ifdef GO4K_USE_FSTG
GO4K_FSTG_ID	equ		13
%macro	GO4K_FSTG 2
	db	%1
	dw	%2
%endmacro
struc	go4kFSTG_val
	.amount		resd	1
	.op1		resd	1
	.size
endstruc
struc	go4kFSTG_wrk
	.size
endstruc
%endif
struc	go4k_instrument
	.release	resd	1
	.note		resd	1
	.workspace	resd	MAX_UNITS*MAX_UNIT_SLOTS
	.dlloutl	resd	1
	.dlloutr	resd	1
	.outl		resd	1
	.outr		resd	1
	.size
endstruc
struc	go4k_synth
	.instruments	resb	go4k_instrument.size * MAX_INSTRUMENTS * MAX_VOICES
	.global			resb	go4k_instrument.size * MAX_VOICES
	.size
endstruc
%ifdef USE_SECTIONS
section .g4kmuc1 data align=1
%else
section .data align=1
%endif
go4k_patterns
	db	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	db	0, 0, 75, 0, 74, 0, 0, 0, 74, HLD, 0, 0, 0, 74, 0, 74, 
	db	0, 74, 0, 75, 0, 0, 74, 0, 0, 0, 74, 0, 0, 0, 74, 0, 
	db	74, HLD, 0, 74, 0, 79, 0, 74, 0, 0, 0, 74, 0, 0, 0, 0, 
	db	74, 0, 74, 0, 74, 0, 77, 0, 74, 0, 0, 0, 0, 74, 0, 0, 
	db	0, 74, 0, 74, 0, 74, HLD, 0, 75, 0, 74, 0, 0, 0, 74, 0, 
	db	0, 0, 0, 74, 0, 74, 0, 74, 0, 75, 0, 74, 0, 0, 0, 0, 
	db	74, 0, 0, 0, 74, 0, 74, 0, 74, 0, 79, HLD, 0, 74, 0, 0, 
	db	0, 74, 0, 0, 0, 74, 0, 0, 74, 0, 74, 0, 77, 0, 74, 0, 
	db	0, 0, 74, 0, 0, 0, 0, 74, 0, 74, 0, 74, 0, 75, 0, 74, 
	db	HLD, 0, 0, 0, 74, 0, 0, 0, 74, 0, 74, 0, 0, 74, 0, 75, 
	db	0, 74, 0, 0, 0, 74, 0, 0, 0, 0, 74, 0, 74, 0, 74, 0, 
	db	79, 0, 74, 0, 0, 0, 0, 74, 0, 0, 0, 74, 0, 74, 0, 74, 
	db	0, 0, 77, 0, 74, 0, 0, 0, 74, 0, 0, 0, 74, 0, 0, 74, 
	db	0, 74, 0, 75, 0, 74, 0, 0, 0, 74, HLD, 0, 0, 0, 74, 0, 
	db	74, 0, 74, 0, 75, 0, 0, 74, 0, 0, 0, 74, 0, 0, 0, 74, 
	db	0, 74, HLD, 0, 74, 0, 79, 0, 74, 0, 0, 0, 74, 0, 0, 0, 
	db	0, 74, 0, 74, 0, 74, 0, 77, 0, 74, 0, 0, 0, 0, 74, 0, 
	db	0, 0, 74, 0, 74, 0, 74, HLD, 0, 75, 0, 74, 0, 0, 0, 74, 
	db	0, 0, 0, 74, HLD, 0, 74, 0, 74, 0, 75, 0, 74, 0, 0, 0, 
	db	0, 74, 0, 0, 0, 74, 0, 74, 0, 74, 0, 79, HLD, 0, 74, 0, 
	db	0, 0, 74, 0, 0, 0, 74, 0, 74, HLD, 0, 74, 0, 77, 0, 74, 
	db	0, 0, 0, 74, 0, 0, 0, 0, 74, 0, 74, 0, 74, 0, 75, 0, 
	db	74, HLD, 0, 0, 0, 74, 0, 0, 0, 74, 0, 74, 0, 74, HLD, 0, 
	db	75, 0, 74, 0, 0, 0, 74, 0, 0, 0, 0, 74, 0, 74, 0, 74, 
	db	0, 79, 0, 74, 0, 0, 0, 0, 74, 0, 0, 0, 74, 0, 74, 0, 
	db	74, 0, 0, 77, 0, 74, 0, 0, 0, 74, 0, 0, 0, 74, 0, 0, 
	db	74, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	db	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43, HLD, 55, HLD, HLD, 
	db	43, HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, HLD, 55, HLD, 43, HLD, 55, 
	db	HLD, 43, HLD, 55, HLD, 43, HLD, HLD, 55, HLD, 43, HLD, 55, HLD, 39, HLD, 
	db	51, HLD, HLD, 39, HLD, 51, HLD, 39, HLD, 51, HLD, 39, HLD, 51, HLD, HLD, 
	db	48, HLD, 60, HLD, 48, HLD, 60, HLD, 48, HLD, 60, HLD, HLD, 48, HLD, 60, 
	db	HLD, 43, HLD, 55, HLD, 43, HLD, HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, 
	db	55, HLD, 43, HLD, HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, 43, 
	db	HLD, HLD, 55, HLD, 39, HLD, 51, HLD, 39, HLD, 51, HLD, HLD, 39, HLD, 51, 
	db	HLD, 39, HLD, 51, HLD, 48, HLD, 60, HLD, HLD, 48, HLD, 60, HLD, 48, HLD, 
	db	60, HLD, 48, HLD, 60, HLD, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, 43, 
	db	HLD, HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, HLD, 55, 
	db	HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, 39, HLD, HLD, 51, HLD, 39, HLD, 
	db	51, HLD, 39, HLD, 51, HLD, HLD, 39, HLD, 51, HLD, 48, HLD, 60, HLD, 48, 
	db	HLD, 60, HLD, HLD, 48, HLD, 60, HLD, 48, HLD, 60, HLD, 43, HLD, 55, HLD, 
	db	HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, HLD, 55, HLD, 43, HLD, 
	db	55, HLD, 43, HLD, 55, HLD, 43, HLD, HLD, 55, HLD, 43, HLD, 55, HLD, 39, 
	db	HLD, 51, HLD, 39, HLD, HLD, 51, HLD, 39, HLD, 51, HLD, 39, HLD, 51, HLD, 
	db	HLD, 48, HLD, 60, HLD, 48, HLD, 60, HLD, 48, HLD, 60, HLD, HLD, 48, HLD, 
	db	60, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, HLD, 43, HLD, 55, HLD, 43, 
	db	HLD, 55, HLD, 43, HLD, HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, 
	db	43, HLD, HLD, 55, HLD, 39, HLD, 51, HLD, 39, HLD, 51, HLD, 39, HLD, HLD, 
	db	51, HLD, 39, HLD, 51, HLD, 48, HLD, 60, HLD, HLD, 48, HLD, 60, HLD, 48, 
	db	HLD, 60, HLD, 48, HLD, 60, HLD, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, 
	db	43, HLD, HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, HLD, 
	db	55, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, 39, HLD, HLD, 51, HLD, 39, 
	db	HLD, 51, HLD, 39, HLD, 51, HLD, HLD, 39, HLD, 51, HLD, 48, HLD, 60, HLD, 
	db	48, HLD, 60, HLD, HLD, 48, HLD, 60, HLD, 48, HLD, 60, HLD, 43, HLD, 55, 
	db	HLD, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, HLD, 55, HLD, 43, 
	db	HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, HLD, 55, HLD, 43, HLD, 55, HLD, 
	db	39, HLD, 51, HLD, 39, HLD, HLD, 51, HLD, 39, HLD, 51, HLD, 39, HLD, 51, 
	db	HLD, HLD, 48, HLD, 60, HLD, 48, HLD, 60, HLD, 48, HLD, 60, HLD, HLD, 48, 
	db	HLD, 60, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, HLD, 43, HLD, 55, HLD, 
	db	43, HLD, 55, HLD, 43, HLD, HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, 55, 
	db	HLD, 43, HLD, HLD, 55, HLD, 39, HLD, 51, HLD, 39, HLD, 51, HLD, 39, HLD, 
	db	HLD, 51, HLD, 39, HLD, 51, HLD, 48, HLD, 60, HLD, HLD, 48, HLD, 60, HLD, 
	db	48, HLD, 60, HLD, 48, HLD, 60, HLD, HLD, 43, HLD, 55, HLD, 43, HLD, 55, 
	db	HLD, 43, HLD, 55, HLD, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, 
	db	HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, 39, HLD, HLD, 51, HLD, 
	db	39, HLD, 51, HLD, 39, HLD, 51, HLD, 39, HLD, HLD, 51, HLD, 48, HLD, 60, 
	db	HLD, 48, HLD, 60, HLD, HLD, 48, HLD, 60, HLD, 48, HLD, 60, HLD, 43, HLD, 
	db	55, HLD, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, 43, HLD, 55, HLD, HLD, 
	db	HLD, 39, HLD, 51, HLD, 39, HLD, HLD, 51, HLD, 39, HLD, 51, HLD, 39, HLD, 
	db	51, HLD, HLD, 48, HLD, 60, HLD, 48, HLD, 60, HLD, 48, HLD, 60, HLD, HLD, 
	db	48, HLD, 60, HLD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	db	55, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 67, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, 60, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 72, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, 51, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 70, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, 55, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 67, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 60, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, 72, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 51, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, 70, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 55, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, 67, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 60, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, 72, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	51, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 70, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, 55, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 67, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, 60, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 72, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, 51, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 70, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, 55, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 67, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 60, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, 72, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 51, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, 70, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 55, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, 67, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 60, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 72, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, 51, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 70, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, 55, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 67, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, 60, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 72, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, 51, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 70, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 55, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	67, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 60, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, 72, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 51, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, 70, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 55, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, 67, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	60, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 72, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, 51, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 70, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, 55, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 67, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, 60, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 72, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, 51, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	70, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 55, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, 67, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 60, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, 72, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 51, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, 70, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 55, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, 67, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, 60, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 72, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, 51, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 70, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	db	43, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, 36, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, 39, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, 43, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 36, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 39, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 43, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 36, HLD, 
	db	39, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, 43, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, 36, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, 39, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, 43, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 36, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 39, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 43, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 36, 
	db	HLD, 39, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	db	0, 0, 0, 0, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 60, 
	db	0, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 
	db	0, 60, 0, 0, 0, 60, 0, 0, 0, 60, HLD, 0, 0, 0, 60, 0, 
	db	0, 0, 60, 0, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 60, 
	db	0, 60, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 0, 60, 0, 
	db	0, 0, 60, 0, 0, 0, 60, HLD, 0, 0, 0, 60, 0, 0, 0, 60, 
	db	0, 0, 0, 60, HLD, 0, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, 
	db	0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 0, 60, 0, 0, 0, 60, 
	db	0, 0, 0, 60, 0, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 
	db	60, HLD, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 60, HLD, 0, 
	db	60, 0, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 
	db	0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 60, HLD, 0, 0, 0, 60, 
	db	0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 0, 60, 
	db	0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 0, 60, 0, 0, 0, 
	db	60, 0, 0, 0, 60, HLD, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 
	db	0, 0, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 
	db	0, 60, 0, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 60, 0, 
	db	0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 60, HLD, 0, 0, 0, 
	db	60, 0, 0, 0, 60, 0, 0, 0, 60, HLD, 0, 0, 0, 60, 0, 0, 
	db	0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 0, 
	db	60, 0, 0, 0, 60, 0, 0, 0, 60, 0, 0, 0, 0, 60, 0, 0, 
	db	0, 60, 0, 0, 0, 60, HLD, 0, 0, 0, 60, 0, 0, 0, 60, 0, 
	db	60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	db	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 24, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, 
	db	HLD, HLD, HLD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	db	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, 24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, HLD, 24, HLD, HLD, HLD, HLD, HLD, HLD, HLD, HLD, 24, HLD, 
	db	24, HLD, HLD, HLD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	db	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, HLD, 
	db	HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, HLD, 48, HLD, HLD, HLD, 
	db	48, HLD, HLD, HLD, 48, HLD, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, 
	db	HLD, 48, HLD, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, 
	db	HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, HLD, 
	db	48, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, HLD, 48, HLD, HLD, 
	db	HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, 
	db	HLD, HLD, 48, HLD, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, 
	db	HLD, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, HLD, 48, HLD, HLD, 
	db	HLD, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, 
	db	HLD, 48, HLD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	db	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, HLD, HLD, HLD, 48, 
	db	HLD, HLD, HLD, 48, HLD, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, 
	db	HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, HLD, 48, HLD, 
	db	HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, 
	db	48, HLD, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, HLD, 48, HLD, HLD, 
	db	HLD, HLD, 48, HLD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
go4k_patterns_end
%ifdef USE_SECTIONS
section .g4kmuc2 data align=1
%else
section .data
%endif
go4k_pattern_lists
Instrument0List		db	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 0, 0, 
Instrument1List		db	0, 0, 0, 0, 0, 0, 0, 0, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 29, 69, 70, 71, 0, 0, 
Instrument2List		db	72, 73, 74, 75, 76, 73, 77, 78, 79, 80, 81, 82, 83, 84, 73, 85, 86, 87, 73, 88, 89, 90, 91, 92, 93, 94, 95, 73, 96, 97, 98, 99, 100, 101, 102, 103, 73, 104, 105, 106, 73, 107, 108, 109, 110, 111, 112, 113, 114, 73, 115, 116, 117, 0, 0, 
Instrument3List		db	118, 73, 119, 120, 121, 73, 122, 123, 124, 73, 125, 73, 126, 127, 73, 128, 129, 130, 73, 131, 132, 133, 73, 134, 73, 135, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
Instrument9List		db	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 137, 138, 139, 140, 138, 141, 142, 143, 0, 144, 145, 146, 144, 145, 147, 148, 145, 147, 149, 150, 151, 149, 0, 0, 0, 0, 152, 153, 154, 155, 153, 156, 157, 158, 156, 159, 0, 0, 
Instrument10List		db	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 160, 161, 162, 163, 164, 165, 166, 167, 162, 168, 0, 0, 0, 169, 170, 171, 172, 173, 174, 167, 175, 171, 176, 0, 0, 
Instrument11List		db	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 177, 178, 179, 180, 181, 182, 180, 181, 182, 183, 181, 182, 183, 184, 185, 183, 184, 186, 187, 0, 0, 0, 188, 189, 190, 191, 189, 192, 191, 189, 192, 193, 0, 0, 
go4k_pattern_lists_end
%ifdef USE_SECTIONS
section .g4kmuc3 data align=1
%else
section .data
%endif
go4k_synth_instructions
GO4K_BEGIN_CMDDEF(Instrument0)
	db GO4K_ENV_ID
	db GO4K_VCO_ID
	db GO4K_FST_ID
	db GO4K_FST_ID
	db GO4K_FST_ID
	db GO4K_FOP_ID
	db GO4K_VCO_ID
	db GO4K_VCO_ID
	db GO4K_VCO_ID
	db GO4K_FOP_ID
	db GO4K_FOP_ID
	db GO4K_VCF_ID
	db GO4K_VCF_ID
	db GO4K_FOP_ID
	db GO4K_PAN_ID
	db GO4K_DLL_ID
	db GO4K_FOP_ID
	db GO4K_DLL_ID
	db GO4K_FOP_ID
	db GO4K_OUT_ID
GO4K_END_CMDDEF
GO4K_BEGIN_CMDDEF(Instrument1)
	db GO4K_ENV_ID
	db GO4K_FST_ID
	db GO4K_VCO_ID
	db GO4K_VCO_ID
	db GO4K_VCO_ID
	db GO4K_FST_ID
	db GO4K_FST_ID
	db GO4K_FOP_ID
	db GO4K_FOP_ID
	db GO4K_FOP_ID
	db GO4K_VCF_ID
	db GO4K_VCF_ID
	db GO4K_DST_ID
	db GO4K_PAN_ID
	db GO4K_DLL_ID
	db GO4K_FOP_ID
	db GO4K_DLL_ID
	db GO4K_FOP_ID
	db GO4K_OUT_ID
GO4K_END_CMDDEF
GO4K_BEGIN_CMDDEF(Instrument2)
	db GO4K_ENV_ID
	db GO4K_VCO_ID
	db GO4K_FOP_ID
	db GO4K_PAN_ID
	db GO4K_DLL_ID
	db GO4K_FOP_ID
	db GO4K_DLL_ID
	db GO4K_FOP_ID
	db GO4K_OUT_ID
GO4K_END_CMDDEF
GO4K_BEGIN_CMDDEF(Instrument3)
	db GO4K_ENV_ID
	db GO4K_VCO_ID
	db GO4K_DST_ID
	db GO4K_VCO_ID
	db GO4K_FOP_ID
	db GO4K_FST_ID
	db GO4K_FST_ID
	db GO4K_FOP_ID
	db GO4K_VCO_ID
	db GO4K_VCO_ID
	db GO4K_VCF_ID
	db GO4K_FOP_ID
	db GO4K_FOP_ID
	db GO4K_VCF_ID
	db GO4K_FOP_ID
	db GO4K_VCF_ID
	db GO4K_FOP_ID
	db GO4K_FOP_ID
	db GO4K_DLL_ID
	db GO4K_PAN_ID
	db GO4K_OUT_ID
GO4K_END_CMDDEF
GO4K_BEGIN_CMDDEF(Instrument9)
	db GO4K_ENV_ID
	db GO4K_FST_ID
	db GO4K_ENV_ID
	db GO4K_DST_ID
	db GO4K_FST_ID
	db GO4K_FOP_ID
	db GO4K_VCO_ID
	db GO4K_FOP_ID
	db GO4K_PAN_ID
	db GO4K_OUT_ID
GO4K_END_CMDDEF
GO4K_BEGIN_CMDDEF(Instrument10)
	db GO4K_ENV_ID
	db GO4K_FST_ID
	db GO4K_ENV_ID
	db GO4K_DST_ID
	db GO4K_FST_ID
	db GO4K_FOP_ID
	db GO4K_VCO_ID
	db GO4K_VCO_ID
	db GO4K_FOP_ID
	db GO4K_FOP_ID
	db GO4K_PAN_ID
	db GO4K_OUT_ID
GO4K_END_CMDDEF
GO4K_BEGIN_CMDDEF(Instrument11)
	db GO4K_ENV_ID
	db GO4K_VCO_ID
	db GO4K_FOP_ID
	db GO4K_VCF_ID
	db GO4K_PAN_ID
	db GO4K_OUT_ID
GO4K_END_CMDDEF
GO4K_BEGIN_CMDDEF(Global)
	db GO4K_ACC_ID
	db GO4K_DLL_ID
	db GO4K_FOP_ID
	db GO4K_DLL_ID
	db GO4K_FOP_ID
	db GO4K_ACC_ID
	db GO4K_FOP_ID
	db GO4K_OUT_ID
GO4K_END_CMDDEF
go4k_synth_instructions_end
%ifdef USE_SECTIONS
section .g4kmuc4 data align=1
%else
section .data
%endif
go4k_synth_parameter_values
GO4K_BEGIN_PARAMDEF(Instrument0)
	GO4K_ENV	ATTAC(0),DECAY(32),SUSTAIN(112),RELEASE(64),GAIN(78)
	GO4K_VCO	TRANSPOSE(64),DETUNE(64),PHASE(0),GATES(85),COLOR(128),SHAPE(64),GAIN(117),FLAGS(SINE)
	GO4K_FST	AMOUNT(112),DEST(6*MAX_UNIT_SLOTS+4+FST_SET)
	GO4K_FST	AMOUNT(112),DEST(7*MAX_UNIT_SLOTS+5+FST_SET)
	GO4K_FST	AMOUNT(40),DEST(8*MAX_UNIT_SLOTS+5+FST_SET)
	GO4K_FOP	OP(FOP_POP)
	GO4K_VCO	TRANSPOSE(64),DETUNE(64),PHASE(0),GATES(85),COLOR(64),SHAPE(64),GAIN(128),FLAGS(TRISAW)
	GO4K_VCO	TRANSPOSE(64),DETUNE(80),PHASE(80),GATES(85),COLOR(80),SHAPE(64),GAIN(128),FLAGS(TRISAW)
	GO4K_VCO	TRANSPOSE(64),DETUNE(48),PHASE(48),GATES(85),COLOR(48),SHAPE(64),GAIN(128),FLAGS(TRISAW)
	GO4K_FOP	OP(FOP_ADDP)
	GO4K_FOP	OP(FOP_ADDP)
	GO4K_VCF	FREQUENCY(48),RESONANCE(88),VCFTYPE(LOWPASS)
	GO4K_VCF	FREQUENCY(48),RESONANCE(88),VCFTYPE(LOWPASS)
	GO4K_FOP	OP(FOP_MULP)
	GO4K_PAN	PANNING(64)
	GO4K_DLL	PREGAIN(64),DRY(128),FEEDBACK(64),DAMP(64),FREQUENCY(0),DEPTH(0),DELAY(17),COUNT(1)
	GO4K_FOP	OP(FOP_XCH)
	GO4K_DLL	PREGAIN(64),DRY(128),FEEDBACK(64),DAMP(64),FREQUENCY(0),DEPTH(0),DELAY(17),COUNT(1)
	GO4K_FOP	OP(FOP_XCH)
	GO4K_OUT	GAIN(0), AUXSEND(69)
GO4K_END_PARAMDEF
GO4K_BEGIN_PARAMDEF(Instrument1)
	GO4K_ENV	ATTAC(32),DECAY(64),SUSTAIN(64),RELEASE(64),GAIN(64)
	GO4K_FST	AMOUNT(120),DEST(0*MAX_UNIT_SLOTS+2+FST_SET)
	GO4K_VCO	TRANSPOSE(64),DETUNE(64),PHASE(32),GATES(85),COLOR(80),SHAPE(64),GAIN(128),FLAGS(PULSE)
	GO4K_VCO	TRANSPOSE(64),DETUNE(72),PHASE(32),GATES(85),COLOR(96),SHAPE(64),GAIN(128),FLAGS(TRISAW)
	GO4K_VCO	TRANSPOSE(32),DETUNE(64),PHASE(0),GATES(85),COLOR(128),SHAPE(90),GAIN(128),FLAGS(SINE|LFO)
	GO4K_FST	AMOUNT(68),DEST(2*MAX_UNIT_SLOTS+2+FST_SET)
	GO4K_FST	AMOUNT(60),DEST(3*MAX_UNIT_SLOTS+2+FST_SET)
	GO4K_FOP	OP(FOP_POP)
	GO4K_FOP	OP(FOP_ADDP)
	GO4K_FOP	OP(FOP_MULP)
	GO4K_VCF	FREQUENCY(18),RESONANCE(64),VCFTYPE(PEAK)
	GO4K_VCF	FREQUENCY(32),RESONANCE(48),VCFTYPE(LOWPASS)
	GO4K_DST	DRIVE(88), SNHFREQ(128), FLAGS(0)
	GO4K_PAN	PANNING(64)
	GO4K_DLL	PREGAIN(64),DRY(128),FEEDBACK(96),DAMP(64),FREQUENCY(0),DEPTH(0),DELAY(18),COUNT(1)
	GO4K_FOP	OP(FOP_XCH)
	GO4K_DLL	PREGAIN(64),DRY(128),FEEDBACK(64),DAMP(64),FREQUENCY(0),DEPTH(0),DELAY(19),COUNT(1)
	GO4K_FOP	OP(FOP_XCH)
	GO4K_OUT	GAIN(47), AUXSEND(35)
GO4K_END_PARAMDEF
GO4K_BEGIN_PARAMDEF(Instrument2)
	GO4K_ENV	ATTAC(32),DECAY(80),SUSTAIN(64),RELEASE(64),GAIN(128)
	GO4K_VCO	TRANSPOSE(88),DETUNE(64),PHASE(0),GATES(85),COLOR(128),SHAPE(64),GAIN(128),FLAGS(SINE)
	GO4K_FOP	OP(FOP_MULP)
	GO4K_PAN	PANNING(64)
	GO4K_DLL	PREGAIN(96),DRY(64),FEEDBACK(64),DAMP(64),FREQUENCY(0),DEPTH(0),DELAY(19),COUNT(1)
	GO4K_FOP	OP(FOP_XCH)
	GO4K_DLL	PREGAIN(96),DRY(64),FEEDBACK(96),DAMP(64),FREQUENCY(0),DEPTH(0),DELAY(18),COUNT(1)
	GO4K_FOP	OP(FOP_XCH)
	GO4K_OUT	GAIN(57), AUXSEND(41)
GO4K_END_PARAMDEF
GO4K_BEGIN_PARAMDEF(Instrument3)
	GO4K_ENV	ATTAC(48),DECAY(80),SUSTAIN(64),RELEASE(64),GAIN(128)
	GO4K_VCO	TRANSPOSE(64),DETUNE(64),PHASE(0),GATES(85),COLOR(64),SHAPE(64),GAIN(64),FLAGS(NOISE)
	GO4K_DST	DRIVE(64), SNHFREQ(0), FLAGS(0)
	GO4K_VCO	TRANSPOSE(16),DETUNE(64),PHASE(0),GATES(85),COLOR(64),SHAPE(64),GAIN(128),FLAGS(TRISAW|LFO)
	GO4K_FOP	OP(FOP_ADDP)
	GO4K_FST	AMOUNT(40),DEST(10*MAX_UNIT_SLOTS+4+FST_SET)
	GO4K_FST	AMOUNT(58),DEST(10*MAX_UNIT_SLOTS+5+FST_SET)
	GO4K_FOP	OP(FOP_POP)
	GO4K_VCO	TRANSPOSE(88),DETUNE(64),PHASE(0),GATES(85),COLOR(128),SHAPE(64),GAIN(128),FLAGS(SINE)
	GO4K_VCO	TRANSPOSE(64),DETUNE(64),PHASE(64),GATES(85),COLOR(64),SHAPE(64),GAIN(5),FLAGS(NOISE)
	GO4K_VCF	FREQUENCY(77),RESONANCE(24),VCFTYPE(BANDPASS)
	GO4K_FOP	OP(FOP_ADDP)
	GO4K_FOP	OP(FOP_PUSH)
	GO4K_VCF	FREQUENCY(32),RESONANCE(128),VCFTYPE(BANDPASS)
	GO4K_FOP	OP(FOP_XCH)
	GO4K_VCF	FREQUENCY(96),RESONANCE(128),VCFTYPE(BANDPASS)
	GO4K_FOP	OP(FOP_ADDP)
	GO4K_FOP	OP(FOP_MULP)
	GO4K_DLL	PREGAIN(64),DRY(128),FEEDBACK(64),DAMP(64),FREQUENCY(0),DEPTH(0),DELAY(19),COUNT(1)
	GO4K_PAN	PANNING(64)
	GO4K_OUT	GAIN(64), AUXSEND(64)
GO4K_END_PARAMDEF
GO4K_BEGIN_PARAMDEF(Instrument9)
	GO4K_ENV	ATTAC(0),DECAY(32),SUSTAIN(96),RELEASE(64),GAIN(78)
	GO4K_FST	AMOUNT(128),DEST(0*MAX_UNIT_SLOTS+2+FST_SET)
	GO4K_ENV	ATTAC(0),DECAY(70),SUSTAIN(0),RELEASE(0),GAIN(128)
	GO4K_DST	DRIVE(32), SNHFREQ(128), FLAGS(0)
	GO4K_FST	AMOUNT(80),DEST(6*MAX_UNIT_SLOTS+1+FST_SET)
	GO4K_FOP	OP(FOP_POP)
	GO4K_VCO	TRANSPOSE(45),DETUNE(64),PHASE(0),GATES(85),COLOR(128),SHAPE(66),GAIN(128),FLAGS(SINE)
	GO4K_FOP	OP(FOP_MULP)
	GO4K_PAN	PANNING(64)
	GO4K_OUT	GAIN(128), AUXSEND(0)
GO4K_END_PARAMDEF
GO4K_BEGIN_PARAMDEF(Instrument10)
	GO4K_ENV	ATTAC(0),DECAY(75),SUSTAIN(0),RELEASE(0),GAIN(32)
	GO4K_FST	AMOUNT(128),DEST(0*MAX_UNIT_SLOTS+2+FST_SET)
	GO4K_ENV	ATTAC(0),DECAY(70),SUSTAIN(0),RELEASE(0),GAIN(128)
	GO4K_DST	DRIVE(8), SNHFREQ(128), FLAGS(0)
	GO4K_FST	AMOUNT(76),DEST(7*MAX_UNIT_SLOTS+1+FST_SET)
	GO4K_FOP	OP(FOP_POP)
	GO4K_VCO	TRANSPOSE(64),DETUNE(64),PHASE(64),GATES(85),COLOR(64),SHAPE(64),GAIN(128),FLAGS(NOISE)
	GO4K_VCO	TRANSPOSE(64),DETUNE(64),PHASE(64),GATES(85),COLOR(128),SHAPE(64),GAIN(128),FLAGS(SINE)
	GO4K_FOP	OP(FOP_ADDP)
	GO4K_FOP	OP(FOP_MULP)
	GO4K_PAN	PANNING(64)
	GO4K_OUT	GAIN(14), AUXSEND(0)
GO4K_END_PARAMDEF
GO4K_BEGIN_PARAMDEF(Instrument11)
	GO4K_ENV	ATTAC(0),DECAY(64),SUSTAIN(0),RELEASE(0),GAIN(128)
	GO4K_VCO	TRANSPOSE(64),DETUNE(64),PHASE(64),GATES(85),COLOR(64),SHAPE(64),GAIN(128),FLAGS(NOISE)
	GO4K_FOP	OP(FOP_MULP)
	GO4K_VCF	FREQUENCY(128),RESONANCE(128),VCFTYPE(HIGHPASS)
	GO4K_PAN	PANNING(64)
	GO4K_OUT	GAIN(64), AUXSEND(0)
GO4K_END_PARAMDEF
GO4K_BEGIN_PARAMDEF(Global)
	GO4K_ACC	ACCTYPE(AUX)
	GO4K_DLL	PREGAIN(40),DRY(128),FEEDBACK(125),DAMP(64),FREQUENCY(0),DEPTH(0),DELAY(1),COUNT(8)
	GO4K_FOP	OP(FOP_XCH)
	GO4K_DLL	PREGAIN(40),DRY(128),FEEDBACK(125),DAMP(64),FREQUENCY(0),DEPTH(0),DELAY(9),COUNT(8)
	GO4K_FOP	OP(FOP_XCH)
	GO4K_ACC	ACCTYPE(OUTPUT)
	GO4K_FOP	OP(FOP_ADDP2)
	GO4K_OUT	GAIN(64), AUXSEND(0)
GO4K_END_PARAMDEF
go4k_synth_parameter_values_end
%ifdef USE_SECTIONS
section .g4kmuc5 data align=1
%else
section .data
%endif
%ifdef GO4K_USE_DLL
global _go4k_delay_times
_go4k_delay_times
	dw 0
	dw 1116
	dw 1188
	dw 1276
	dw 1356
	dw 1422
	dw 1492
	dw 1556
	dw 1618
	dw 1140
	dw 1212
	dw 1300
	dw 1380
	dw 1446
	dw 1516
	dw 1580
	dw 1642
	dw 14700
	dw 11025
	dw 22050
%endif
