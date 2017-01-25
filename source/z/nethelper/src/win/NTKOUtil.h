#if !defined(_NTKOUtil_h__) 
#define _NTKOUtil_h__

#include <windows.h>


//#define NTKO_CUSTOM_SHANGHAI_WEITAI	//�����Ϻ�ά̩����
//#define NTKO_LICENSE_PANGANG			//�ʸֶ��ƹ���

//#define NTKO_CUSTOM_JIANGSU_CA			//����CA����
//#define NTKO_CUSTOM_JIANGSU_CA_NO_HTTPS	//����CA����

//#define NTKO_CUSTOM_CHUANDA_ZHISHENG	//������ʤ

//#define NTKO_CUSTOM_DOLOGIN_USECERT	//ʹ��֤�鼰���кŵ�¼ϵͳ


#if defined(NTKO_CUSTOM_SHANGHAI_WEITAI)
	#pragma message(NTKOPRGWARNNING "���棺***���棺*****���棺***���棺����������������- ���ڱ��� �Ϻ�ά̩ �Ķ��ư汾!! ����������������--")
#endif

#if defined(NTKO_LICENSE_PANGANG)
	#pragma message(NTKOPRGWARNNING "���棺***���棺*****���棺***���棺����������������- ���ڱ��� �ʸ� �Ķ��ư汾!! ����������������--")
#endif

#if defined(NTKO_CUSTOM_JIANGSU_CA)
	#pragma message(NTKOPRGWARNNING "���棺***���棺*****���棺***���棺����������������- ���ڱ��� ����CA �Ķ��ư汾!! ����������������--")
#endif

#if defined(NTKO_CUSTOM_DOLOGIN_USECERT)
	#pragma message(NTKOPRGWARNNING "���棺***���棺*****���棺***���棺����������������- ���ڱ��� ʹ��֤�鼰���кŵ�¼ϵͳ �Ķ��ư汾!! ����������������--")
#endif


#if defined(NTKO_CUSTOM_CHUANDA_ZHISHENG)
	#pragma message(NTKOPRGWARNNING "���棺***���棺*****���棺***���棺����������������- ���ڱ��� ������ʤ �Ķ��ư汾!! ����������������--")
#endif


#define NTKO_WM_USER_EKEYINERT			WM_APP+400
#define NTKO_HIDDEN_MSGWIN_PROP			"_NTKO_HIDDEN_MSGWIN_PROP"
#define NTKO_MAX_HTTPHEADER				4096	//����Զ���Header�ܳ���
#define MAX_HEADER_LEN					100		// MAXIMIZE HTML FORM DATA HEADER LEN
#define NTKO_DEF_NETREADBUFFERSIZE		131072	//������
#define NTKO_INIT_NETBUFFERSIZE			8192*2	//�����ٶȵĻ���
#define NTKO_MAX_NETBUFFERSIZE			16777216// 16Megs //��󻺴�
#define HTML_HEADER_CR					"\r\n"
#define NTKO_DEFAULT_NOLOAD_SERVERURL	L"http://localhost/ntkosss/"
#define NTKO_MAX_SIGNS					50
#define NTKO_MAX_DOC_SERVER_SIGNS		500
#define NTKO_MAX_CHECKSIGN_SERVERS		500
#define NTKO_DEFAULT_THEME				(ntkoThemeTypeBlue) // common��Ĭ�϶Ի������

#define NTKO_HIDDENCHECK_SIGNSN			0x00000001L
#define NTKO_HIDDENCHECK_EKEYSN			0x00000002L
#define NTKO_HIDDENCHECK_SIGNGUID		0x00000004L
#define NTKO_HIDDENCHECK_SIGNSERVERNAME	0x00000008L
#define NTKO_HIDDENCHECK_SIGNER			0x00000010L
#define NTKO_HIDDENCHECK_SIGNNAME		0x00000020L
#define NTKO_HIDDENCHECK_SIGNUSER		0x00000040L
#define NTKO_HIDDENCHECK_SERVERTIME		0x00000080L
#define NTKO_HIDDENCHECK_APPNAME		0x00000100L
#define NTKO_HIDDENCHECK_CLIENTIP		0x00000200L


#define NTKO_ServerSecsignControlProtocalVersion	L"1.0"	
// HKEY_CURRENT_USER\NTKOSecsignConfigInformation
#define NTKOSecsignConfigHk					"NTKOSecsignConfigInformation" 

// ����ǩ��ϵͳ�趨��
#define NTKO_HC_SETTING_IsCheckDocChange	"IsCheckDocumentChange"
#define NKTO_HC_SETTING_IsAddHandSignOnSign	"IsAddHandSignOnSign"
#define	NKTO_HC_SETTING_IsAddCommentOnSign	"IsAddCommentOnSign"
#define NKTO_HC_SETTING_IsAddTimeOnSign		"IsAddTimeOnSign"
#define NKTO_HC_SETTING_IsUseKeyboardborder	"IsUseKeyboardborder"
#define NKTO_HC_SETTING_PrintMode			"PrintMode"
#define NKTO_HC_SETTING_IsUseCert			"IsUseCert"
#define NKTO_HC_SETTING_IsFuzzySignPic		"IsFuzzySignPic"
#define NKTO_HC_SETTING_IsCheckFont			"IsCheckFont"
#define NKTO_HC_SETTING_IsShowUI			"IsShowUI"

#define NKTO_HC_SETTING_HandSignScale		"HandSignScale"
#define NKTO_HC_SETTING_LineStyle			"HandSignLineStyle"
#define NKTO_HC_SETTING_LineWidth			"HandSignLineWidth"
#define NKTO_HC_SETTING_LineColor			"HandSignLineColor"
#define NKTO_HC_SETTING_CommentLocationV	"CommentLocationV"
#define NKTO_HC_SETTING_CommentLocationH	"CommentLocationH"
#define NKTO_HC_SETTING_CommentFont			"CommentFont"
#define NKTO_HC_SETTING_TimeLocationV		"TimeLocationV"
#define NKTO_HC_SETTING_TimeLocationH		"TimeLocationH"
#define NKTO_HC_SETTING_TimeStyle			"TimeStyle"
#define NKTO_HC_SETTING_TimeFont			"DateFont"

#define NTKO_HC_SETTING_IsAddSginTop		"IsAddSignTop"
#define NTKO_HC_SETTING_IsAutoAcceptRev		"IsAutoAcceptRev"
#define NTKO_HC_SETTING_CertIssuerName		"CertIssuerName"
#define NTKO_HC_SETTING_LangID				"LangId"

#define NTKO_HC_SETTING_IsAllowLockAdd		"IsAllowLockAdd"
#define NTKO_HC_SETTING_ISAUTOLOCKSIGN		"IsAutoLockSign"
#define NTKO_HC_SETTING_ISAUTOLOCKDOC		"IsAutoLockDoc"
//�����Ƿ������汾�趨
#define NTKO_HC_SETTING_SecsignServerName	 "SecSignServerName"
#define NTKO_HC_SETTING_IsRememberUserName   "IsRememberUsername"
#define NTKO_HC_SETTING_RememberedUserName   "RememberedUsername"
#define NTKO_HC_SETTING_IsUseEkeyLogin		 "IsUseEkeyLogin"
#define NTKO_HC_SETTING_IsUseDefaultPassword "IsUseDefPass"
#define NTKO_HC_SETTING_DefaultSignPassword	 "DefSignPass"

#define NTKO_HC_AGENT						"NTKO_SECSIGN_CLIENT_AGENT"
#define NTKO_HC_TEMPFILEPATH				"NTKOSSTmpFiles" // ��ʱ�ļ�Ŀ¼
#define CUSTOMHTTPUSERPASS  //iis��֤֧��
#define NTKO_HTTP_USER					NULL
#define NTKO_HTTP_PASS					NULL



#if defined(_DEBUG)
	//#define NTKO_USE_TESTSIGNSERVER

//֧�ֵĹ���.��ʽ:HS,KC,SS,ES,...ע�⣺��,�ָ����ұ����Զ��Ž�β 
//HS=��д��KC=���̣�SS=���£�ES=KEY��,BC=��ά�� FP=ָ��ǩ��,EN=����NTKF,SC=����
//MS=У����(��ҳ���),ME=У����(��ҳEKEY) Q2=�Գ������ QN=��������� QE=�����ʹ��EKEY
	//#define NTKO_DEFAULT_NOLOAD_SPTFUNCTIONS	(L"HS,KC,SS,ES,SC,MS,ME,BC,Q2,QN,QE,")
	#define NTKO_DEFAULT_NOLOAD_SPTFUNCTIONS	(L"HS,KC,SS,ES,BC,SC,ME,Q2,QN,QE,")
#else
	#define NTKO_DEFAULT_NOLOAD_SPTFUNCTIONS	(L"HS,KC,SS,ES,BC,SC,ME,Q2,QN,QE,")
#endif

#if defined(NTKO_USE_TESTSIGNSERVER)
#define NTKO_HC_GETROOTSERVER_URL	L"GetRootServer.asp"
#define NTKO_HC_LOGIN_URL			L"login.asp"
#define NTKO_HC_LOGOFF_URL			L"logoff.asp"
#define NTKO_HC_GETRIGHTS_URL		L"getrights.asp"
#define NTKO_HC_CHECKEKEY_URL		L"checkekey.asp"
#define NTKO_HC_LISTSIGNS_URL		L"listsigns.asp"
#define NTKO_HC_GETSERVERINFO_URL	L"getserverinfo.asp"
#define NTKO_HC_GETSERVERTIME_URL	L"getservertime.asp"
#define NTKO_HC_DOLOGSIGN_URL		L"dologsign.asp"
#define NTKO_HC_CHECKSIGNS_URL		L"checksigns.asp"
#define NTKO_HC_GETCHGEDSVRS_URL	L"getchkservers.asp"
#define NTKO_HC_SIGN2EKEYCHECK_URL	L"sign2ekeycheck.asp"
#define NTKO_HC_GETSERVERCOMMENTS_URL	L"getcomments.asp"
#define NTKO_HC_SETSERVERCOMMENTS_URL	L"setcomments.asp"
#else
#define NTKO_HC_GETROOTSERVER_URL	L"GetRootServer"

#if !defined(NTKO_CUSTOM_JIANGSU_CA)
	#define NTKO_HC_LOGIN_URL			L"login"
#else
	#define NTKO_HC_LOGIN_URL			L"certlogin"
#endif

#define NTKO_HC_LOGOFF_URL			L"logoff"
#define NTKO_HC_GETRIGHTS_URL		L"getrights"
#define NTKO_HC_CHECKEKEY_URL		L"checkekey"


#define NTKO_HC_LISTSIGNS_URL		L"listsigns"

#if defined(NTKO_CUSTOM_JIANGSU_CA)
	#define NTKO_HC_LISTSIGNS_URL_JSCA	L"listseals"
	#define NTKO_HC_DOWNLOADSIGN_URL_JSCA	L"getseal"
#endif

#define NTKO_HC_GETSERVERINFO_URL	L"getserverinfo"
#define NTKO_HC_GETSERVERTIME_URL	L"getservertime"
#define NTKO_HC_DOLOGSIGN_URL		L"dologsign"
#define NTKO_HC_CHECKSIGNS_URL		L"checksigns"
#define NTKO_HC_GETCHGEDSVRS_URL	L"getchkservers"
#define NTKO_HC_SIGN2EKEYCHECK_URL	L"sign2ekeycheck"
#define NTKO_HC_GETSERVERCOMMENTS_URL	L"getcomments"
#define NTKO_HC_SETSERVERCOMMENTS_URL	L"setcomments"
#endif

#define NTKO_TIP_TEXTCOLOR		(RGB(0x33,0x33,0xFF))
#define NTKO_HILIGHT_TEXTCOLOR	(RGB(0x00,0x00,0xC0))
#define NTKO_DEFAULT_EKEY_TYPE  (ntkoSptKeyLongMai)


BOOL ReadRegisterInfo	(HKEY hkParent, LPCSTR pszSubKey,LPSTR infoName,LPSTR resultBuf,DWORD dwBufSize);
BOOL WriteRegisterInfo	(HKEY hkParent, LPCSTR pszSubKey,LPSTR infoName,LPSTR infoBuf);
long ReadRegisterLong	(HKEY hkParent, LPCSTR pszSubKey,LPSTR infoName,long ifFailReturnThis);
BOOL WriteRegisterLong	(HKEY hkParent, LPCSTR pszSubKey,LPSTR infoName,long lValue);
BOOL ReadRegisterBinary	(HKEY hkParent, LPCSTR pszSubKey,LPSTR infoName,BYTE* resultBuf,DWORD* pdwBufSize);
BOOL WriteRegisterBinary(HKEY hkParent, LPCSTR pszSubKey,LPSTR infoName,BYTE* infoBuf,DWORD dwBufSize);

STDAPI_(void)	ConvertANSIToUTF8Hex(LPSTR pszANSI); //������1024���ַ�����
STDAPI_(LPWSTR)	ConvertLPWSTRToUTF8HexW(LPWSTR pwsz); //����ֵ��Ҫ�ͷ�

#define NTKO_SAFEFreePoint(p) if(p){ delete p; p=NULL;}

struct NtkoSecsignSettings ;

BOOL ReadNtkoSecsignSettings (NtkoSecsignSettings * pSecsignSettings);
BOOL WriteNtkoSecsignSettings(NtkoSecsignSettings * pSecsignSettings);

#endif // _NTKOUtil_h__
