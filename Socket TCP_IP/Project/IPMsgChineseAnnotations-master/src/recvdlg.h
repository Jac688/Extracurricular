﻿/*	@(#)Copyright (C) H.Shirouzu 2013-2015   recvdlg.h	Ver3.60 */
/* ========================================================================
	Project  Name			: IP Messenger for Win32
	Module Name				: Receive Dialog
	Create					: 2013-03-03(Sun)
	Update					: 2015-11-01(Sun)
	Copyright				: H.Shirouzu
	Reference				: 
	======================================================================== */

#ifndef RECVDLG_H
#define RECVDLG_H

enum FileStatus {
	FS_DIRFILESTART, FS_OPENINFO, FS_FIRSTINFO, FS_NEXTINFO, FS_MAKEINFO, FS_TRANSINFO,
	FS_TRANSFILE, FS_ENDFILE, FS_MEMFILESTART, FS_COMPLETE, FS_ERROR
};

struct RecvFileObj {
	RecvFileObj() { Init(); }
	void Init() { memset(&conInfo, 0, sizeof(RecvFileObj));}

	ConnectInfo	*conInfo;
	FileInfo	*fileInfo;

	BOOL		isDir;
	BOOL		isClip;
	FileInfo	curFileInfo;

	_int64		offset;		// read offset
	_int64		woffset;	// written offset
	char		*recvBuf;
	HANDLE		hFile;
	HANDLE		hThread;

	int			infoLen;
	int			dirCnt;

	_int64		totalTrans;
	DWORD		startTick;
	DWORD		lastTick;
	int			totalFiles;
	FileStatus	status;
	AES			aes;

	char		saveDir[MAX_PATH_U8];
	char		path[MAX_PATH_U8];
	char		info[MAX_BUF];	// for dirinfo buffer
	char		u8fname[MAX_PATH_U8];	// for dirinfo buffer
};

struct ClipBuf : public TListObj {
	VBuf	vbuf;
	int		pos;
	BOOL	finished;
	ClipBuf(int size, int _pos) : vbuf(size), pos(_pos) { finished = FALSE; }
};

class RecvTransEndDlg : public TDlg {
	RecvFileObj	*fileObj;

public:
	RecvTransEndDlg(RecvFileObj *_fileObj, TWin *_win) : TDlg(_fileObj->status == FS_COMPLETE ? TRANSEND_DIALOG : SUSPEND_DIALOG, _win) { fileObj = _fileObj; }
	virtual BOOL	EvCreate(LPARAM lParam);
	virtual BOOL	EvCommand(WORD wNotifyCode, WORD wID, LPARAM hwndCtl);
};

class TRecvDlg : public TListDlg {
public:
	enum SelfStatus { INIT, SHOW, ERR, REMOTE };

protected:
	static int		createCnt;
	static HBITMAP	hDummyBmp;
	MsgMng			*msgMng;
	MsgBuf			msg;
	THosts			*hosts;
	char			head[MAX_LISTBUF];
	RECT			headRect;
	Cfg				*cfg;
	LogMng			*logmng;
	BOOL			openFlg;
	BOOL			isRep;	// reproduction
	static HFONT	hHeadFont;
	static HFONT	hEditFont;
	static LOGFONT	orgFont;
	TEditSub		editSub;
	SelfStatus		status;
	BOOL			isAutoSave;
	char			autoSaves[MAX_BUF];

	RecvFileObj		*fileObj;
	ShareInfo		*shareInfo;
	RecvTransEndDlg *recvEndDlg;
	TListEx<ClipBuf> clipList;
	int				useClipBuf;
	int				useDummyBmp;

	UINT_PTR	timerID;
	UINT		retryCnt;
	char		readMsgBuf[MAX_LISTBUF];
	ULONG		packetNo;
	UINT		cryptCapa;
	UINT		logOpt;

	enum	recv_item {
				title_item=0, head_item, head2_item, open_item, edit_item, image_item,
				ok_item, cancel_item, quote_item, file_item, max_recvitem
			};
	WINPOS	item[max_recvitem];

	BOOL	InitCliped(ULONG clipBase);
	BOOL	InitAutoSaved(const char *auto_saved);

	void	SetFont(BOOL force_reset=FALSE);
	void	SetSize(void);
	void	SetMainMenu(HMENU hMenu);
	void	PopupContextMenu(POINTS pos);
	BOOL	TcpEvent(SOCKET sd, LPARAM lParam);
	BOOL	StartRecvFile(void);
	BOOL	ConnectRecvFile(void);
	static UINT WINAPI RecvFileThread(void *_recvDlg);
	BOOL	SaveFile(BOOL auto_save=FALSE);
	BOOL	OpenRecvFile(void);
	BOOL	RecvFile(void);
	BOOL	RecvDirFile(void);
	BOOL	CloseRecvFile(BOOL setAttr=FALSE);
	BOOL	EndRecvFile(BOOL manual_suspend=FALSE);
	void	SetTransferButtonText(void);
	BOOL	CheckSpecialCommand();
	BOOL	DecodeDirEntry(char *buf, FileInfo *info, char *u8fname);
	BOOL	LoadClipFromFile(void);
	BOOL	AutoSaveCheck(void);

public:
	TRecvDlg(MsgMng *_msgmng, THosts *hosts, Cfg *cfg, LogMng *logmng, TWin *_parent=NULL);
	virtual ~TRecvDlg();

	virtual SelfStatus Init(MsgBuf *_msg, const char *rep_head=NULL, ULONG clipBase=0,
		const char *auto_saved=NULL);
	virtual BOOL	IsClosable(void) {
						return openFlg &&
							(!fileObj || !fileObj->conInfo) && !clipList.TopObj() && !recvEndDlg;
					}
	virtual BOOL	IsSamePacket(MsgBuf *test_msg);
	virtual BOOL	SendFinishNotify(HostSub *hostSub, ULONG packet_no);

	virtual BOOL	PreProcMsg(MSG *msg);
	virtual BOOL	EvCreate(LPARAM lParam);
	virtual BOOL	EvCommand(WORD wNotifyCode, WORD wID, LPARAM hwndCtl);
	virtual BOOL	EvSysCommand(WPARAM uCmdType, POINTS pos);
	virtual BOOL	EvSize(UINT fwSizeType, WORD nWidth, WORD nHeight);
	virtual BOOL	EvGetMinMaxInfo(MINMAXINFO *info);
	virtual BOOL	EvTimer(WPARAM timerID, TIMERPROC proc);
	virtual BOOL	EvContextMenu(HWND childWnd, POINTS pos);
	virtual BOOL	EventButton(UINT uMsg, int nHitTest, POINTS pos);
	virtual BOOL	EventApp(UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual BOOL	EventInitMenu(UINT uMsg, HMENU hMenu, UINT uPos, BOOL fSystemMenu);
	virtual BOOL	EventCtlColor(UINT uMsg, HDC hDcCtl, HWND hWndCtl, HBRUSH *result);
	virtual BOOL	EvNotify(UINT ctlID, NMHDR *pNmHdr);

	virtual void	Show(int mode = SW_NORMAL);
	virtual BOOL	InsertImages(void);
	SelfStatus		Status() { return status; }
	void			SetStatus(SelfStatus _status);
	static int		GetCreateCnt(void) { return createCnt; }
	Time_t			GetRecvTime() { return msg.timestamp; }
	MsgBuf			*GetMsgBuf() { return &msg; }

	int				UseClipboard() { return useClipBuf; }
	BOOL			FileAttached() { return !!shareInfo; }
};

#endif

