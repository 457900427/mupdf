#if !defined(_NTKOSignHelperDll_h__) 
#define _NTKOSignHelperDll_h__

#ifdef NTKOSERVERSIGNHELPER_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#define		EXTERN		extern
#define		CONST		const

#define NTKOSignHelper_GetClassObjMethodName "NtkoDllGetClassObject"
#define NTKOSignHelper_DelClassObjMethodName "NtkoDllDelClassObject"

#include "ntkosigndef.h"

enum NTKOSecsignLineMode{
	LineMode_NoPress = 0,
	LineMode_ImitatePress,
	LineMode_RealPress
};
// �Ǵ�ֱ�����λ��
enum NTKOSecsignCommentLocationV{
	NTKOSignCommentLocationV0 = 0,
	NTKOSignCommentLocationV1,
	NTKOSignCommentLocationV2,
	NTKOSignCommentLocationV3,
	NTKOSignCommentLocationV4,
	NTKOSignCommentLocationV5,
	NTKOSignCommentLocationV6,
	NTKOSignCommentLocationV7,
	NTKOSignCommentLocationV8,
	NTKOSignCommentLocationV9,
	NTKOSignCommentLocationVA,
	NTKOSignCommentLocationVB
};
// �Ǵ�ֱ�����λ��
enum NTKOSecsignCommentLocationH{
	NTKOSignCommentLocationH_0 = 0,
	NTKOSignCommentLocationH_1,
	NTKOSignCommentLocationH_2,
};
enum NTKOSecsignTimeAlignV{
	TIMEAlignV_NO = 0,	// "ӡ���ڶ���"
	TIMEAlignV_N1,		// "�м�ƫ��"
	TIMEAlignV_N2,		// "�м�ƫ��"
	TIMEAlignV_N3,		// "ӡ���ڵײ�"
	TIMEAlignV_N4,		// "ӡ���·�"
	TIMEAlignV_N5,		// "����ʾ"
	TIMEAlignV_N6,		// "ӡ���ھ���"
	TIMEAlignV_N7,		// "�Զ���λ��"
};

enum NTKOSecsignTimeAlignH{
	TIMEAlignH_NO = 0,	// "ӡ���ڶ���"
	TIMEAlignH_N1,		// "�м�ƫ��"
	TIMEAlignH_N2,		// "�м�ƫ��"
};
enum NTKOSecsignTimeMode{
	NTKOSignTimeMode_0 = 0, //����������һ�¶�ʮ����
	NTKOSignTimeMode_1,		//2009��1��22��
	NTKOSignTimeMode_2,		//2009-1-22
	NTKOSignTimeMode_3,		//2009.1.22
};

//0: Other; 1:Word, 2:Excel,6:WPS,7 ET���ӱ�,5 pdf
enum NTKOAPPType{
	NTKOAPPType_Other	= 0,	// "Other Application"
	NTKOAPPType_Word	= 1,	// "MS Word"
	NTKOAPPType_Excel	= 2,	// "MS Excel"
	NTKOAPPType_Web		= 3,	// "HTML ӡ��"
	NTKOAPPType_PDF		= 5,	// "NTKO Pdf"
	NTKOAPPType_WPS		= 6,	// "WPS ����"
	NTKOAPPType_ETd		= 7,	// "WPS ���ӱ��" 
	NTKOAPPType_YoZo	= 8		// "��������"
};

enum NTKOServerRequestType{
	NTKOServerRequestType_GetRootServerInfo			= 1,	// 1:��ȡ����������Ϣ��
	NTKOServerRequestType_UNKOWN					= 2,
	NTKOServerRequestType_Login						= 3,	// 3:�û���¼��
	NTKOServerRequestType_GetSignList				= 4,	// 4:��ȡ���������ӡ���б�
	NTKOServerRequestType_GetEkeyUseableState		= 5,	// 5.��ȡ�û�EKEY����״̬
	NTKOServerRequestType_CheckRightHandsign		= 6,	// 6:�����дǩ��Ȩ��
	NTKOServerRequestType_CheckRightKeyBoradComment = 7,	// 7:��������עȨ��	
	NTKOServerRequestType_DosignLog					= 8,	// 8:ǩ�������־��¼
	NTKOServerRequestType_GetBinaryFile				= 9,	// 9:�������ļ�����,δʹ��
	NTKOServerRequestType_Logout					= 10,	// 10:�û�ע������
	NTKOServerRequestType_TestConnetServer			= 11,	// 11:���Է���������
	NTKOServerRequestType_GetserverTime				= 12,	// 12:��ȡ������ʱ��
	NTKOServerRequestType_CheckSign					= 13,	// 13:���ӡ��,
	NTKOServerRequestType_GetServerChangeInfo		= 14,	// 14:��ȡ���������(����)��Ϣ
	NTKOServerRequestType_GetRightOfEkeyAndSign		= 15,	// 15:��ȡ�û�EKEY��ӡ�µĹ���Ȩ��
	NTKOServerRequestType_GetServerComments			= 16,	// 16:��ȡ��������ע�б�
	NTKOServerRequestType_SetServerComments			= 17,	// 17:�趨��������ע�б�
	NTKOServerRequestType_KeepSession				= 18,	// 18:����session
	NTKOServerRequestType_CheckRightBarcode			= 20,	// 20:����ά��Ȩ��
};

enum NtkoSignOpType {
	NtkoSignOpType_Add = 0,
	NtkoSignOpType_Lock,
	NtkoSignOpType_UnLock,
	NtkoSignOpType_Protect,
	NtkoSignOpType_Unprotect,
	NtkoSignOpType_EnableCheckDocChange,
	NtkoSignOpType_DisableCheckDocChange,
	NtkoSignOpType_Delete,
	NtkoSignOpType_Uncrypt
};

// ����ӡ������趨
struct NtkoSecsignSettings
{
	int		ScalePic;				// ��дǩ��ͼƬ���ű���
	NTKOSecsignLineMode	LineMode;	// ��ģʽ
	int		PenWidth;				// �ʿ�
	DWORD	PenColor;				// ��ɫ
	NTKOSecsignCommentLocationV		CommentLocationV;	// ��עλ��
	HFONT	HFontComment;				// ��ע����
	NTKOSecsignTimeAlignV	TimeAlignV;	// ����λ��
	NTKOSecsignTimeMode		TimeMode;	// ���ڷ��
	HFONT	HFontTime;					// ��������

	BOOL	bSignOverText;	  // ǩ��λ�������Ϸ�
	BOOL	bAutoAcceptRivise;// �Զ������޶��ٸ���
	CHAR	CertIssuerName[MAX_PATH];	  // ����֤�鷢��������
	LANGID	CurLangId;		  // ����ID
	// ������ǰ�汾������
	BOOL bLockSign;
	BOOL bLockDoc;

	// sign setting:function setting
	BOOL bCheckDocChange;// ����ĵ��ı�
	BOOL bHandsign;		 // ǩ��ʱ��дǩ��
	BOOL bComment;		 // �����ע	
	BOOL bAddTime;		 // �������
	BOOL bKeboardBorder; // ������ע�߿�

	// sign setting:safety setting
	NTKOSecsignPrintMode  PrintMode;		// ��ӡ ģʽ
	BOOL bUseCert;		// �Ƿ�ʹ��
	BOOL bFuzzyPic;		// ӡ���Ƿ��黯
	BOOL bCheckFont;	// �������ı�
	BOOL bShowUI;		// �Ƿ���ʾUI
	BOOL bAllowLockAdd;	// �Ƿ���������ʱ����(����word,excel���ĵ�)

	BOOL	bUseEkeyLogin;									// �Ƿ�ʹ��ekey��¼
	CHAR	serverURL[MAX_PATH];							// ������URL
	BOOL	bUseDefaultsignPassowrd;						// �Ƿ�ʹ��Ĭ������
	CHAR	defaultSignPassword[NTKO_MAX_PASSWORD+1];		// Ĭ������
	BOOL	bRememberUserName;								// �Ƿ��ס�û���
	CHAR	rememberedUserName[NTKO_MAX_LOGINUSERNAME+1];	// �û���

	NtkoSptKeyType ekeyType;
};

// ����CA���ƹ�˾��Ϣ�ṹ��
struct NTKO_CUSTOM_jiangshuCA_CompanyInfo{
	LPWSTR companyId;
	LPWSTR companyName;
	LPWSTR companyCode;
};

// Ȩ������
struct NtkoSecsignRightSettings
{
	BOOL bUseHandsign;
	BOOL bUseKeyboardsign;
	BOOL bUseNormalsign;
	BOOL bUseEkeySign;
	BOOL bUseBarcode;
	BOOL bUseFingerPrint;
	BOOL bUseMutisignEkey;		// ��ҳ���Ƿ�ʹ��EKEY
	BOOL bUseMuticrosssignEkey; // ������Ƿ�ʹ��EKEY
	BOOL bUseMutisign;
	BOOL bUseMutiCrossPageSign;
	BOOL bUseDbCrossPagesign;
};

#define NtkoServerSecsignRightSettings	NtkoSecsignRightSettings
#define NtkoPublishRightSettings		NtkoSecsignRightSettings

typedef struct CNTKOSignsInfo
{
	BSTR	bstrSignName;	// ����CA���ư汾��,��ΪЭ���е�signname
	BSTR	bstrSignUser;	// ����CA���ư汾��,��ΪЭ���е�Type
	BSTR	bstrSignURL;	// ����CA���ư汾��,��ΪЭ���е�ID
	BOOL	bIsESPSign;		// ��espӡ�£����ǽ���ca��ͼƬ��
}CNTKOSignsInfo,*PCNTKOSignsInfo;


typedef struct CNTKODocSignsInfo
{
	BSTR	bstrSignGUID;
	BSTR	bstrSigner;
	BSTR	bstrSignName;
	long	iSignServerId;
	BOOL	bIsSignChecked;
	BSTR	bstrSignCheckInfoTitle;
	BSTR	bstrSignCheckInfoText;
	DWORD	dwIndexInDoc;
}CNTKODocSignsInfo,*PCNTKODocSignsInfo;

typedef struct CNTKOServerSignsInfo
{
	BSTR	bstrSignGUID;
	BOOL	bFound;
	BSTR	bstrSigner;
	BSTR	bstrSignName;
	BSTR	bstrSignUser;
	BSTR	bstrSignSN;
	BSTR	bstrEkeySN;
	BSTR	bstrServerTime;
	BSTR	bstrAppName;
	BSTR	bstrClientIP;
	long	iSignServerId;
}CNTKOServerSignsInfo,*PCNTKOServerSignsInfo;

typedef struct CNTKOCheckSignServersInfo
{
	long	iSignServerId;
	BSTR	bstrSignServerName;
	BSTR	bstrServerAppURL;
	BOOL	bIsUsedInThisDoc;
	LPWSTR	pwszPostPara;
}CNTKOCheckSignServersInfo,*PCNTKOCheckSignServersInfo;

//************************************
// Class:	CNTKOServerSignHelper
// Describe:�����������ӡ��������ع��ܵİ�����
//************************************
class INTKOServerSignHelper {
public:
	virtual void  SetSignSvrLicType(NtkoSignSvrLicType iSignSvrLicType) = 0;
	virtual BOOL  InitNew (HWND hwndParent,HMODULE hModuleIncludePublishData)=0;
	virtual BOOL  DoLogin (LPWSTR username, LPWSTR password, BOOL bUseEkey)=0;
	virtual BOOL  DoLogout()=0;
	virtual VOID  ClearUserSigns()=0;
	virtual BOOL  IsLogin()=0;
	virtual CONST NtkoServerSecsignRightSettings * GetServerSetting() = 0;
	virtual CONST NtkoPublishRightSettings * GetPublishSetting() = 0;
	virtual CONST NtkoSecsignSettings * GetSecsignSetting()=0;
	virtual CONST LPWSTR GetServerTime()=0;
	virtual CONST LPWSTR GetLoginUserName()=0;
	virtual CONST LPWSTR GetLoginRealName()=0;
	virtual BOOL CheckOpRight(NTKOServerRequestType opType)=0;
	virtual LPWSTR GetLoadedToLocalsignPath(NtkoSignType signtype)=0;// ��Ҫ����MemFree
	virtual BOOL CheckEkeyToSignRel(LPWSTR ekeySN,LPWSTR signSN) = 0;
	//////////////////////////////////////////////////////////////////////////
	virtual BOOL DoServerSignLog(NtkoSecuritySignInfo  * pSignInfo,NtkoSignOpType opType,LPWSTR fileName,LPWSTR fileInfo)=0;// pdfӡ����־��¼
	// �����ĵ��е�����ӡ����Ϣ,����ӡ�·������ϵ�����ӡ����Ϣ!!!
	virtual CNTKOServerSignsInfo * DoCheckSigns(PNtkoSecuritySignInfo pInfo,int len,int * outServersignCount)=0;// ���pdfӡ��
	//////////////////////////////////////////////////////////////////////////
	virtual BOOL DoServerSignLog(IDispatch* pSecsignControl,NtkoSignOpType opType,LPWSTR fileName,LPWSTR fileInfo)=0;
	virtual BOOL DocheckSigns(CNTKODocSignsInfo * pNtkoDocSignsInfo, int len)=0;
	//////////////////////////////////////////////////////////////////////////
	virtual LONG GetLogServerId() = 0;
	virtual LPWSTR GetLogServerName() = 0;
	virtual BOOL ShowServerConfigDlg() = 0;
	virtual BOOL SetAppType(NTKOAPPType appType)=0;
	virtual BOOL SetSvrUrl(LPSTR url) = 0;
	virtual VOID FreeMyMem(LPWSTR p) = 0;

	virtual	VOID SetSignsFilter(LPWSTR pwszSignFilter) = 0;
	virtual LPWSTR GetSignsFilter() = 0;
	virtual BOOL NTKO_Custom_SetComName(LPWSTR comName) = 0;
	virtual LPWSTR GetSelectedSignName() = 0; //����Ҫ�ͷŷ���ֵ
	virtual LPWSTR GetSelectedSignUser() = 0; //����Ҫ�ͷŷ���ֵ
	virtual LPWSTR GetSelectedSignSN() = 0; //����Ҫ�ͷŷ���ֵ
	virtual BOOL   GetSelectedSignIsESP() = 0;	//����Ҫ�ͷŷ���ֵ
	virtual LPWSTR GetLogonCertSubject() = 0; //��ҪSAFE_FREESTRING�ͷŷ���ֵ
	virtual PCRYPT_HASH_BLOB GetLogonCertSHA1Hash() = 0; //��ҪSAFE_FREESTRING�ͷŷ���ֵ����pbData����
	virtual VOID SetIsJSCAUseSealSvr(BOOL bUse) = 0; //����CA�Ƿ�ʹ����ģ������
	virtual BOOL GetIsJSCAUseSealSvr() = 0;
	
	//������ʤ��������ӿ�,�����û���Ӧ��֤�����,����Ҫ�ͷŷ���ֵ.
	//2014.06.19 �޸�Ϊ����ȫ�����⣬���ŷָ�
	virtual LPWSTR GetUserCertSN() = 0;

	virtual VOID SetHiddenCheckItems(DWORD HiddenFlag) = 0; //�趨�������汾���ӡ�¶Ի����е�������Ŀ
	virtual DWORD GetHiddenCheckItems() = 0;
	virtual VOID SetEkeyPassword(LPSTR ekeyPass) = 0;
};

typedef INTKOServerSignHelper* PINTKOServerSignHelper;

INTKOServerSignHelper * WINAPI  NtkoDllGetClassObject();
void WINAPI NtkoDllDelClassObject();

typedef INTKOServerSignHelper* (WINAPI *DllGetClassObjFunPoint)(void);
typedef void(WINAPI * DllDelClassObjFunPoint)();


struct NtkosignHelperFuncs
{
	DllGetClassObjFunPoint GetClassObj;
	DllDelClassObjFunPoint DelClassObj;
};

#endif // _NTKOSignHelperDll_h__