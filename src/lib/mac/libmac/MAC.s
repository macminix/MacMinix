	.sect .text
	.sect .rom
	.sect .data
	.sect .bss
!
! Macintosh low memory global variables. Based on 
! Inside Macintosh volumes 3 & 4
!
	.globl _ABusVars; _ABusVars=0x02D8
	.globl _ACount; _ACount=0x0A9A
	.globl _ANumber; _ANumber=0x0A98
	.globl _ApFontID; _ApFontID=0x0984
	.globl _ApplLimit; _ApplLimit=0x0130
	.globl _ApplScratch; _ApplScratch=0x0A78
	.globl _ApplZone; _ApplZone=0x02AA
	.globl _AppParmHandle; _AppParmHandle=0x0AEC

	.globl _BootDrive; _BootDrive=0x0210
	.globl _BufPtr; _BufPtr=0x010C
	.globl _BufTgDate; _BufTgDate=0x0304
	.globl _BufTgFBkNum; _BufTgFBkNum=0x0302
	.globl _BufTgFFlg; _BufTgFFlg=0x0300
	.globl _BufTgFNum; _BufTgFNum=0x02FC

	.globl _CaretTime; _CaretTime=0x02F4
	.globl _CrsrThresh; _CrsrThresh=0x08EC
	.globl _CurActivate; _CurActivate=0x0A64
	.globl _CurApName; _CurApName=0x0910
	.globl _CurApRefNum; _CurApRefNum=0x0900
	.globl _CurDeactive; _CurDeactive=0x0A68
	.globl _CurDirStore; _CurDirStore=0x0398
	.globl _CurJTOffset; _CurJTOffset=0x0934
	.globl _CurMap; _CurMap=0x0A5A
	.globl _CurPageOption; _CurPageOption=0x0936
	.globl _CurPitch; _CurPitch=0x0280
	.globl _CurrentA5; _CurrentA5=0x0904
	.globl _CurStackBase; _CurStackBase=0x0908

	.globl _DABeeper; _DABeeper=0x0A9C
	.globl _DAStrings; _DAStrings=0x0AA0
	.globl _DefltStack; _DefltStack=0x0322
	.globl _DefVCBPtr; _DefVCBPtr=0x0352
	.globl _DeskHook; _DeskHook=0x0A6C
	.globl _DeskPattern; _DeskPattern=0x0A3C
	.globl _DlgFont; _DlgFont=0x0AFA
	.globl _DoubleTime; _DoubleTime=0x02F0
	.globl _DragHook; _DragHook=0x09F6
	.globl _DragPattern; _DragPattern=0x0A34
	.globl _DrvQHdr; _DrvQHdr=0x0308
	.globl _DSAlertRect; _DSAlertRect=0x03F8
	.globl _DSAlertTab; _DSAlertTab=0x02BA
	.globl _DSErrCode; _DSErrCode=0x0AF0

	.globl _EventQueue; _EventQueue=0x014A
	.globl _ExtStsDT; _ExtStsDT=0x02BE

	.globl _FCBSPtr; _FCBSPtr=0x034E
	.globl _FinderName; _FinderName=0x02E0
	.globl _FondID; _FondID=0x0BC6
	.globl _FractEnable; _FractEnable=0x0BF4
	.globl _FScaleDisable; _FScaleDisable=0x0A63
	.globl _FSFCBLen; _FSFCBLen=0x03F6
	.globl _FSQHdr; _FSQHdr=0x0360

	.globl _GhostWindow; _GhostWindow=0x0A84
	.globl _GrayRgn; _GrayRgn=0x09EE
	.globl _GZRootHnd; _GZRootHnd=0x0328

	.globl _HeapEnd; _HeapEnd=0x0114

	.globl _IntlSpec; _IntlSpec=0x0BA0

	.globl _JFetch; _JFetch=0x08F4
	.globl _JIODone; _JIODone=0x08FC
	.globl _JournalFlag; _JournalFlag=0x08DE
	.globl _JournalRef; _JournalRef=0x08E8
	.globl _JStash; _JStash=0x08F8

	.globl _KeyRepThresh; _KeyRepThresh=0x0190
	.globl _KeyThresh; _KeyThresh=0x018E

	.globl _LastFond; _LastFond=0x0BC2
	.globl _Lo3Bytes; _Lo3Bytes=0x031A
	.globl _Lvl1DT; _Lvl1DT=0x0192
	.globl _Lvl2DT; _Lvl2DT=0x01B2

	.globl _MBarEnable; _MBarEnable=0x0A20
	.globl _MBarHeight; _MBarHeight=0x0BAA
	.globl _MBarHook; _MBarHook=0x0A2C
	.globl _MemErr; _MemErr=0x0220
	.globl _MemTop; _MemTop=0x0108
	.globl _MenuFlash; _MenuFlash=0x0A24
	.globl _MenuHook; _MenuHook=0x0A30
	.globl _MenuList; _MenuList=0x0A1C
	.globl _MinStack; _MinStack=0x031E
	.globl _MinusOne; _MinusOne=0x0A06

	.globl _OldContent; _OldContent=0x09EA
	.globl _OldStructure; _OldStructure=0x09E6
	.globl _OneOne; _OneOne=0x0A02

	.globl _PaintWhite; _PaintWhite=0x09DC
	.globl _PortAUse; _PortAUse=0x0290
	.globl _PortBUse; _PortBUse=0x0291
	.globl _PrintErr; _PrintErr=0x0944

	.globl _RAMBase; _RAMBase=0x02B2
	.globl _ResErr; _ResErr=0x0A60
	.globl _ResErrProc; _ResErrProc=0x0AF2
	.globl _ResLoad; _ResLoad=0x0A5E
	.globl _ResumeProc; _ResumeProc=0x0A8C
	.globl _RndSeed; _RndSeed=0x0156
	.globl _ROM85; _ROM85=0x028E
	.globl _ROMBase; _ROMBase=0x02AE
	.globl _RomFont0; _RomFont0=0x0980
	.globl _RomMapInsert; _RomMapInsert=0x0B9E

	.globl _SaveUpdate; _SaveUpdate=0x09DA
	.globl _SaveVisRgn; _SaveVisRgn=0x09F2
	.globl _SCCRd; _SCCRd=0x01D8
	.globl _SCCWr; _SCCWr=0x01DC
	.globl _ScrapCount; _ScrapCount=0x0968
	.globl _ScrapHandle; _ScrapHandle=0x0964
	.globl _ScrapName; _ScrapName=0x096C
	.globl _ScrapSize; _ScrapSize=0x0960
	.globl _ScrapState; _ScrapState=0x096A
	.globl _Scratch8; _Scratch8=0x09FA
	.globl _Scratch20; _Scratch20=0x01E4
	.globl _ScrDmpEnb; _ScrDmpEnb=0x02F8
	.globl _ScrHRes; _ScrHRes=0x0104
	.globl _ScrnBase; _ScrnBase=0x0824
	.globl _ScrVRes; _ScrVRes=0x0102
	.globl _SdVolume; _SdVolume=0x0260
	.globl _SEvtEnb; _SEvtEnb=0x015C
	.globl _SFSaveDisk; _SFSaveDisk=0x0214
	.globl _SoundBase; _SoundBase=0x0266
	.globl _SoundLevel; _SoundLevel=0x027F
	.globl _SoundPtr; _SoundPtr=0x0262
	.globl _SPAlarm; _SPAlarm=0x0200
	.globl _SPATalkA; _SPATalkA=0x01F9
	.globl _SPATalkB; _SPATalkB=0x01FA
	.globl _SPClikCaret; _SPClikCaret=0x0209
	.globl _SPConfig; _SPConfig=0x01FB
	.globl _SPFont; _SPFont=0x0204
	.globl _SPKbd; _SPKbd=0x0206
	.globl _SPMisc2; _SPMisc2=0x020B
	.globl _SPPortA; _SPPortA=0x01FC
	.globl _SPPortB; _SPPortB=0x01FE
	.globl _SPPrint; _SPPrint=0x0207
	.globl _SPValid; _SPValid=0x01F8
	.globl _SPVolCtl; _SPVolCtl=0x0208
	.globl _SysEvtMask; _SysEvtMask=0x0144
	.globl _SysFontFam; _SysFontFam=0x0BA6
	.globl _SysFontSize; _SysFontSize=0x0BA8
	.globl _SysMap; _SysMap=0x0A58
	.globl _SysMapHndl; _SysMapHndl=0x0A54
	.globl _SysParam; _SysParam=0x01F8
	.globl _SysResName; _SysResName=0x0AD8
	.globl _SysZone; _SysZone=0x02A6

	.globl _TEDoText; _TEDoText=0x0A70
	.globl _TERecal; _TERecal=0x0A74
	.globl _TEScrpHandle; _TEScrpHandle=0x0AB4
	.globl _TEScrpLength; _TEScrpLength=0x0AB0
	.globl _TheMenu; _TheMenu=0x0A26
	.globl _TheZone; _TheZone=0x0118
	.globl _Ticks; _Ticks=0x016A
	.globl _Time; _Time=0x020C
	.globl _TmpResLoad; _TmpResLoad=0x0B9F
	.globl _ToExtFS; _ToExtFS=0x03F2
	.globl _ToolScratch; _ToolScratch=0x09CE
	.globl _TopMapHndl; _TopMapHndl=0x0A50

	.globl _UTableBase; _UTableBase=0x011C

	.globl _VBLQueue; _VBLQueue=0x0160
	.globl _VCBQHdr; _VCBQHdr=0x0356
	.globl _VIA; _VIA=0x01D4

	.globl _WidthListHand; _WidthListHand=0x08E4
	.globl _WidthPtr; _WidthPtr=0x0B10
	.globl _WidthTabHandle; _WidthTabHandle=0x0B2A
	.globl _WindowList; _WindowList=0x09D6
	.globl _WMgrPort; _WMgrPort=0x09DE
