#if !defined(_NTKOServerSignHelper_h__) 
#define _NTKOServerSignHelper_h__

#include <windows.h>
#include "ntkokeyintfc.h"
#include <wininet.h>
#include "NTKOUtil.h"
#include "ntkosignekey.h"
#include "NTKOSignHelperDll.h"
#include <commctrl.h>
class CNtkoSecStrs;
class CNtkoSignEkey;
class CNtkoUIDelayDlg;
class CNtkoMuiHelper;


//************************************
// Class:	CNTKOServerSignHelper
// Describe:�����������ӡ��������ع��ܵİ�����
//************************************
class CNTKOServerSignHelper:public INTKOServerSignHelper{
public:
	void  SetSignSvrLicType(NtkoSignSvrLicType iSignSvrLicType);
	BOOL  InitNew (HWND hwndParent,HMODULE hModuleIncludePublishData);// ��ʼ��,�������.
	BOOL  DoLogin (LPWSTR username, LPWSTR password, BOOL bUseEkey);  // ��¼������
	BOOL  DoLogout();					// �ӷ�����ע��
	BOOL  IsLogin(){return m_IsLogin;}; // ��ȡ�Ƿ��Ѿ���¼
	CONST NtkoServerSecsignRightSettings * GetServerSetting(){return &m_serverRightSettings;};// ��ȡ����������ӡ��Ȩ��
	CONST NtkoPublishRightSettings * GetPublishSetting(){return &m_publishRightSettings;};	// ��ȡ��������ӡ��Ȩ��
	CONST NtkoSecsignSettings * GetSecsignSetting(){return &m_secsignSettings;};			// ��ȡӡ������
	CONST LPWSTR GetServerTime();	// �ӷ�������ȡʱ���ַ���				
	CONST LPWSTR GetLoginUserName(){return m_LoginUserName;};		// ���ص�¼�û���.
	CONST LPWSTR GetLoginRealName(){return m_LoginRealName;};		//���ص�¼���ص�ʵ������
	BOOL  CheckOpRight(NTKOServerRequestType opType);				// ����Ȩ�޼��
	LPWSTR GetLoadedToLocalsignPath(NtkoSignType signtype);			// pdf ӡ�·������汾��־����
	BOOL CheckEkeyToSignRel(LPWSTR ekeySN,LPWSTR signSN);			// ���ekey��ӡ�µĹ�����ϵ.(��ekey�Ƿ���ԸǴ�ӡ��)
	//////////////////////////////////////////////////////////////////////////
	BOOL DoServerSignLog(NtkoSecuritySignInfo  * pSignInfo,NtkoSignOpType opType,LPWSTR fileName,LPWSTR fileInfo);	// pdfӡ����־��¼
	CNTKOServerSignsInfo * DoCheckSigns(PNtkoSecuritySignInfo pInfo,int count,int * outServersignCount);			// ���pdfӡ��
	//////////////////////////////////////////////////////////////////////////
	BOOL DoServerSignLog(IDispatch* pSecsignControl,NtkoSignOpType opType,LPWSTR fileName,LPWSTR fileInfo);
	BOOL DocheckSigns(CNTKODocSignsInfo * pNtkoDocSignsInfo, int len);
	//////////////////////////////////////////////////////////////////////////
	LONG GetLogServerId()  {return m_iThisServerInfoServerId;};		// �������÷�����ID
	LPWSTR GetLogServerName(){return m_bstrThisServerInfoName;};	// �������÷���������.
	BOOL ShowServerConfigDlg(); // ��ʾ���������öԻ���
	BOOL SetAppType(NTKOAPPType appType);
	BOOL SetSvrUrl(LPSTR url);
	VOID FreeMyMem(LPWSTR p);	// �ͷ�dll�ڲ�������ڴ�

	VOID SetSignsFilter(LPWSTR pwszSignFilter);
	LPWSTR GetSignsFilter(){return m_pwszSignFilter;};

//////////////////////////////////////////////////////////////////////////
//  ����Ϊ����CA���ư汾Э�����
	BOOL NTKO_Custom_SetComName(LPWSTR comName);
//////////////////////////////////////////////////////////////////////////
	LPWSTR GetSelectedSignName();	//����Ҫ�ͷŷ���ֵ
	LPWSTR GetSelectedSignUser();	//����Ҫ�ͷŷ���ֵ
	LPWSTR GetSelectedSignSN();	//����Ҫ�ͷŷ���ֵ
	BOOL   GetSelectedSignIsESP();	//���������ѡ��ӡ���Ƿ���ESPӡ��
	LPWSTR GetLogonCertSubject();	//��Ҫ�ͷŷ���ֵ
	PCRYPT_HASH_BLOB GetLogonCertSHA1Hash(); //��ҪSAFE_FREESTRING�ͷŷ���ֵ����pbData����
	VOID	SetIsJSCAUseSealSvr(BOOL bUse); //����CA�Ƿ�ʹ����ģ������
	BOOL	GetIsJSCAUseSealSvr();

	//������ʤ��������ӿ�,�����û���Ӧ��֤�����,����Ҫ�ͷŷ���ֵ.
	//2014.06.19 �޸�Ϊ����ȫ�����⣬���ŷָ�
	LPWSTR GetUserCertSN(){return m_bstr_custom_ChuanDaZhiSheng_UserCertSN;};

	VOID SetHiddenCheckItems(DWORD HiddenFlag){m_dwHiddenCheckItems = HiddenFlag;};
	DWORD GetHiddenCheckItems(){return m_dwHiddenCheckItems;};
	VOID SetEkeyPassword(LPSTR ekeyPass);

public:
	CNTKOServerSignHelper(void);
	~CNTKOServerSignHelper();
private:
	INT ShowMsgBoxMUIStrW(DWORD idText,DWORD idCaption,UINT type);
	INT ShowMsgBoxMUIStrW(HWND hwndParent,DWORD idText,DWORD idCaption,UINT type);
	void SetMUIDlgItemStringW(HWND hDlg,UINT idItem,DWORD dwKey);
	LPWSTR LoadMUIStringW(DWORD dwKey);
	VOID SetMUIItemStrW(HWND hDlg,UINT idItem,DWORD dwKey);
	BOOL CreateHiddenWindowForMsg();
	BOOL ShowDelayDlg(LPWSTR pwszMes);
	BOOL CloseDelayDlg();

	void HideUIDelayDlg();
	void ShowUIDelayDlgAgain();

	VOID ShowDelayDlgMUIStrW(UINT idText);
	VOID ShowCheckSignListDlg();
	BOOL CheckServerName(LPSTR szServerName);
	// ������غ���
	BOOL DoWebGet(LPSTR pszServerApp,LPWSTR pwszURL,BSTR* pbstr);
	BOOL GetHTTPReturnData(HINTERNET hReq,BSTR* pbstr);
	BOOL DownLoadURLToILockBytes(LPSTR pszServerApp,LPWSTR pwszURL,ILockBytes* pILockBytes);
	BOOL DoWebExecute2(LPSTR pszServerApp,LPWSTR pwszURL,LPWSTR pwszCPARA,BSTR* pbstr);
	BOOL IsInternetSettingEnableHTTP11();
	BOOL DownLoadURLToFile(LPSTR pszServerApp,LPWSTR pwszURL, LPWSTR pwszFile);
	BOOL TestSignServer(HWND hwndParent,BOOL bShowPrompt,BOOL bSetDlgItemText,INT dlgItem);
	// ���� xml
	BOOL ParseXML(BSTR bstrXML);
	BOOL ParseRootServerInfo();
	BOOL ParseThisServerInfo();
	BOOL ParseThisUserInfo();
//////////////////////////////////////////////////////////////////////////
//  ����Ϊ����CA���ư汾Э�����
	BOOL NTKO_Custom_ParseThisSealServerInfo();
	void NTKO_Custom_ClearCompanyInfo();
	void NTKO_Custom_IniteCompanyInfo();
	BOOL NTKO_Custom_ParseSigns();
	BOOL NTKO_Custom_ParseSigns_New();
	BOOL NTKO_Custom_CreateKey(LPWSTR * md5, LPWSTR * timestamp);
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//  ����Ϊ������ʤ���ư汾Э�����
	BOOL NTKO_Custom_ParseCertSN();
//////////////////////////////////////////////////////////////////////////


//����֤��SSL˫����֤���
	void		ReleaseCurCert();
	void		ReleaseCurStore();
	BOOL		SelectLogonCert(HINTERNET hReq);
	BOOL		SelectLogonCertNoHTTPS(BOOL bSignSomeData);
	LPWSTR		GenTempSignedPKCS7Msg();
//////////////////////////////////////////////////////////////////////////

	BOOL ParseUserRights();
	BOOL ParseResponseStatus();
	BOOL ParseSignOptions();
	BOOL ParseNtkoCheckEkey();
	BOOL ParseServerTime();
	BOOL ParseServerInfo();
	BOOL ParseNtkoUserSigns();
	BOOL ParseCheckSignServers();
	BOOL ParseSignsCheckStatus();
	// Ȩ�޼��
	BOOL CheckEKEYUsageWithMes(DWORD ekeyUsage,DWORD usage=NTKO_EKEYUSAGE_EKEY_LOGIN);//DWORD usage=NTKO_EKEYUSAGE_EKEY_LOGIN=1
	BOOL CheckServerBeforeHandSign ();
	BOOL CheckServerBeforeKeyboard ();
	BOOL CheckServerBeforeEkeySign ();
	BOOL CheckServerBeforeNomalSign();
	BOOL CheckServerBeforeBarcode();
	// BOOL RefreshServerSignSettings();
	void ClearServerSigns();
	VOID ClearCheckSignServers();
private:
	VOID SetDlgListImageList(HWND hWndListView,int iDlgType);
	BOOL InitSelSignListViewColumns(HWND hWndListView); 
	BOOL FillSelSignListWithSignsInfo(HWND hWndListView,BOOL isIncludeBlankSigns,LPWSTR pwszFilter);
	VOID AutoAdjustListViewColumn(HWND hWndListView);
	VOID DestroyDlgListImageList();
	VOID ClearUserSigns();
	BOOL InitCheckSignListViewColumns(HWND hWndListView); 
	BOOL FillCheckSignListWithSignsInfo(HWND hWndListView,BOOL bIsForServerSigns);
	VOID ShowSelectedDocSignInfo(BOOL bIsForServerSigns);
	VOID GotoSelectedDocSign(){return;};
	BOOL GetCertificateLogonInfo(HWND hwndDlgParent,LPWSTR* ppwszCertName,LPWSTR* ppwszCertSN);
public:
	static BOOL FSSFindMSDocWinProc(HWND hwndChild, LPARAM lParam);
	static STDMETHODIMP_(INT_PTR) LoginDlgFrameHandler(HWND hDlg,HWND hwndTab,UINT Msg,WPARAM wParam,LPARAM lParam,LPVOID pUserParam);
	static STDMETHODIMP_(INT_PTR) LoginDlgTabProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static DWORD WINAPI Notify_SlotChanged(BOOL bIsOk,LPVOID pParam,BOOL bIsInserted);
	static LRESULT CALLBACK HiddenWindowForMsgProcess(HWND hwnd, UINT uMsg,WPARAM wParam,LPARAM lParam);
	static STDMETHODIMP_(INT_PTR) SelSignIndexDlgFrameHandler(HWND hDlg,HWND hwndTab,UINT Msg,WPARAM wParam,LPARAM lParam,LPVOID pUserParam);
	static STDMETHODIMP_(INT_PTR) SelSignIndexDlgTabProc(HWND hDlg, UINT Msg, WPARAM wParam,LPARAM lParam);
	static BOOL GetTempNewFilePath(WCHAR** ppwszLocalFile,LPSTR preStr,LPSTR extStr);
	static STDMETHODIMP_(INT_PTR) SysConfigSvrDlgHandler(HWND hDlg,HWND hwndTab,UINT Msg,WPARAM wParam,LPARAM lParam,LPVOID pUserParam);
	static STDMETHODIMP_(INT_PTR) SysConfigSvrDlgProc(HWND hDlg, UINT Msg, WPARAM wParam,LPARAM lParam);
	static STDMETHODIMP_(INT_PTR) CheckSignDlgWindowProc(HWND hDlg, UINT Msg, WPARAM wParam,LPARAM lParam);
	static STDMETHODIMP GetProperty(LPDISPATCH pDisp, LPOLESTR pszName, VARIANT* pvResult); // ��ȡidispatch�ӿڵ�����.

private:
	NtkoSecsignSettings  m_secsignSettings;
	NtkoServerSecsignRightSettings m_serverRightSettings;
	NtkoPublishRightSettings m_publishRightSettings;
	BOOL	m_IsLogin;
	WCHAR	m_LoginUserName[NTKO_MAX_LOGINUSERNAME+1];
	WCHAR	m_LoginPassword[NTKO_MAX_PASSWORD+1];
	WCHAR	m_LoginRealName[NTKO_MAX_LOGINUSERNAME+1];
	CHAR	m_rootSvrUrl[MAX_PATH]; //��¼������(root Server url),���õķ�������m_secsignSetting->serverurl��.
	// ����CA���ư汾����ӡ���б�URL
	CHAR	m_CustomSignServerUrl[MAX_PATH];
	CNtkoSecStrs   * m_pNTkoSecstrPublishInfo;
	CNtkoSignEkey  * m_pNtkoSignEkey;
	CNtkoUIDelayDlg* m_pNtkoUIDelayDlg;	
	CNtkoMuiHelper * m_pNtkoMuiHelper;
	BOOL			m_PublishInfo_AUTOUseEkeyLogin;
	HWND			m_HwndHiddenForMsg;
	HWND			m_hwndParent;
	char			m_EKEYPassword[NTKO_MAX_PASSWORD+1];
	BSTR			m_bstrEKEYSN;
	NTKOAPPType		m_appType;
	IXMLDOMDocument * m_pXMLDoc;
	BSTR					m_bstrServerVersion;
	BSTR					m_bstrServerInfoVersion;
	BSTR					m_bstrServerInfoName;
	BSTR					m_bstrServerInfoLicenseUserName;
	BSTR					m_bstrServerInfoLicenseCount;
	BSTR					m_bstrThisServerInfoName;
	int						m_iThisServerInfoServerId;
	int						m_iServerErrCode;
	BSTR					m_bstrFailReason;
	BOOL					m_CanUseThisEkey;
	BSTR					m_bstrServerTime;
	CNTKOSignsInfo			m_NtkoUserSigns[NTKO_MAX_SIGNS]; // �����û����÷����������ӡ��
	long					m_iUserSignsCount;
	int						m_iSelectedSignIndex;// ����ӡ�¼���б��ѡ���ӡ�����.
	CNTKOCheckSignServersInfo	m_NtkoCheckSignServers[NTKO_MAX_CHECKSIGN_SERVERS];  // ����������ı���Ϣ
	long					m_iCheckSignServersCount;
	CNTKOServerSignsInfo	m_NtkoServerSigns[NTKO_MAX_DOC_SERVER_SIGNS]; // ������������ص�ӡ����Ϣ
	long					m_iServerSignsCount;
	CNTKODocSignsInfo	*   m_docSigns;
	long					m_iDocSignsCount;
	long					m_iCurServerId; 
	HWND					m_hwndCheckSignDlg;
	DWORD m_dwReceiveDataTimeOut;
	DWORD m_dwConnectServerTimeOut;
	HIMAGELIST		m_hLargeSelSign;   // image list for icon view 
    HIMAGELIST		m_hSmallSelSign;   // image list for other views 
	LONG			m_selectedSignIndex;
	NTKOServerRequestType m_serverReqestType;
	HMODULE			m_hModulePublishInfo;

	HBITMAP			m_hbmpError;
	HBITMAP			m_hbmpOk;

	LPWSTR			m_pwszSignFilter;

	DWORD			m_dwHiddenCheckItems;

	NtkoSignSvrLicType m_iSignSvrLicType;


	NTKO_CUSTOM_jiangshuCA_CompanyInfo m_Custom_jiangshuCA_CompanyInfo;
	BOOL			m_IsJSCAUseSealSvr;

//����֤��SSL˫����֤���
	HCERTSTORE    m_hCertStore;  //store 
	PCCERT_CONTEXT   m_pCurSignCert; //�û�ѡ���֤��
//////////////////////////////////////////////////////////////////////////

	BSTR		m_bstr_custom_ChuanDaZhiSheng_UserCertSN;
};

#endif
