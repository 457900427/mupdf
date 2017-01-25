#include "ntkomemstr.h"
#include "NTKOServerSignHelper.h"
#include <windows.h>
#include "ntkomuiHelper.h"
#include "ntkocusdraw.h"
#include "ntkosecstr.h"
#include "ntkosignekey.h"
#include "res/resource.h"

// ���̼乲��ĵ�¼״̬
// #pragma data_seg(".NTKOSSSrd")
// volatile BOOL	sg_isLogIn				= FALSE;
// volatile BOOL	sg_hasRight_handSign	= FALSE;
// volatile BOOL	sg_hasRight_keyComment	= FALSE;
// volatile BOOL	sg_hasRight_sign		= FALSE;
// volatile BOOL	sg_hasRight_keySign		= FALSE;
// #pragma data_seg()
// 
// __declspec(allocate(".NTKOSSSrd")) volatile  WCHAR sg_LoginUserName[NTKO_MAX_LOGINUSERNAME+1];
// __declspec(allocate(".NTKOSSSrd")) volatile  WCHAR sg_LoginPassword[NTKO_MAX_PASSWORD+1];
// __declspec(allocate(".NTKOSSSrd")) volatile  char  sg_EkeyPassword [NTKO_MAX_PASSWORD+1];
// 
// #pragma comment(linker,"/SECTION:.NTKOSSSrd,RWS")
//CNtkoMuiHelper * v_pNtkoMUIHelper = NULL;

NtkoSecsignSettings g_DefaultSecsignSettings = {
	100,				// ��дǩ��ͼƬ���ű���
	LineMode_NoPress,	// ��ģʽ
	3,					// �ʿ�
	RGB(0xFF,0x00,0x00),		// ��ɫ
	NTKOSignCommentLocationV0,	// ��עλ��
	NULL,				// ��ע����
	TIMEAlignV_N1,		// ����λ��
	NTKOSignTimeMode_0,	// ���ڷ��
	NULL,	// ��������
	TRUE,	// ǩ��λ�������Ϸ�
	TRUE,	// �Զ������޶��ٸ���
	{'\0'},	// ����֤�鷢��������
	GetSystemDefaultLangID(),
	FALSE,
	FALSE,
	TRUE,	// ����ĵ��ı�
	TRUE,	// ǩ��ʱ��дǩ��
	TRUE,	// �����ע	
	TRUE,	// �������
	TRUE,	// ������ע�߿�
	NTKOSecsignPrintMode_Origin ,// ��ӡ ģʽ
	TRUE,	// �Ƿ�ʹ��
	FALSE,	// ӡ���Ƿ��黯
	FALSE,	// �������ı�
	TRUE,	// �Ƿ���ʾUI
	TRUE,	// �Ƿ���������ʱ����(����word,excel���ĵ�)
	FALSE,
	NULL, 
	FALSE,
	{'\0'},
	FALSE,
	{'\0'},
	ntkoSptKeyHaiTai
};

HANDLE g_hModule		= NULL;
BOOL   v_fUnicodeAPI    = FALSE;  // Flag to determine if we should us Unicode API
BOOL   v_fWindows2KPlus = FALSE;
BOOL   v_fWindowsXPPlus = FALSE;
CNTKOServerSignHelper * g_pHelper = NULL;
DWORD  v_RefCount		= 0;
HICON  g_signListDlgICON = NULL;

BOOL APIENTRY DllMain( HANDLE hModule, 
					  DWORD  ul_reason_for_call, 
					  LPVOID lpReserved
					  )
{
    switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
			g_hModule = hModule;
			OSVERSIONINFO osvi;
			osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
			GetVersionEx (&osvi);
			v_fUnicodeAPI = (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT); //unicode support
			v_fWindows2KPlus = ((v_fUnicodeAPI) && (osvi.dwMajorVersion  > 4)); //2k plus
			v_fWindowsXPPlus = ((v_fWindows2KPlus) && (osvi.dwMinorVersion  > 0)); //xp,2003
			g_signListDlgICON = (HICON)LoadImage((HINSTANCE)g_hModule, MAKEINTRESOURCE(IDI_ICONLOGO), IMAGE_ICON, 16, 16, 0);
		}
		break;
	case DLL_PROCESS_DETACH:
		{
			if (g_signListDlgICON)
			{
				DestroyIcon(g_signListDlgICON);
				g_signListDlgICON = NULL;
			}
		}
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
    }
    return TRUE;
}

INTKOServerSignHelper * WINAPI NtkoDllGetClassObject()
{
	if (!g_pHelper)
	{
		g_pHelper = new CNTKOServerSignHelper;
	}
	v_RefCount++;
	TRACE1_NTKOLIB("NtkoDllGetClassObject,ref=%d\n",v_RefCount);
	return (PINTKOServerSignHelper)g_pHelper;
}

void WINAPI NtkoDllDelClassObject()
{
	v_RefCount--;
	TRACE1_NTKOLIB("NtkoDllDelClassObject,ref=%d\n",v_RefCount);
	if(0 == v_RefCount)
	{
		NTKO_SAFEFreePoint(g_pHelper);
		ODS_NTKOLIB("NtkoDllDelClassObject, object deleted,end\n");
	}	
}
