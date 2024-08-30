
// Test_EncodingDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Test_Encoding.h"
#include "Test_EncodingDlg.h"
#include "afxdialogex.h"

#include <iostream>
#include <fstream>
#include <string>
#include <locale>

#include <ShObjIdl_core.h>

#include "../../Common/Functions.h"
#include "../../Common/SeedProvider.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestEncodingDlg 대화 상자



CTestEncodingDlg::CTestEncodingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST_ENCODING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pTaskbarList = NULL;
}

void CTestEncodingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestEncodingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DROPFILES()
	ON_BN_CLICKED(IDOK, &CTestEncodingDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTestEncodingDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CTestEncodingDlg 메시지 처리기

BOOL CTestEncodingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	setlocale(LC_ALL, "ko-KR");
	DragAcceptFiles();

	CoInitialize(NULL);
	m_pTaskbarList.CoCreateInstance(CLSID_TaskbarList);

#if 0
	//SeedProvider, base64_encode를 이용한 파라미터 encrypt 예제
	CString str = _T("AP2P RC sl.linkmemine.com 7001 047C163E60A1945218687741 user1 TRUE 1 1 0 0 0 일반사용자1 b1064f61cec38b957c3aaa4cac4e588b324d0011 1 sl.linkmemine.com 7002 sl.linkmemine.com 8443 듀얼모니터&nbsp;테스트 1 0 sl.linkmemine.com 443");
	std::string src = "AP2P RC sl.linkmemine.com 7001 047C163E60A1945218687741 user1 TRUE 1 1 0 0 0 일반사용자1 b1064f61cec38b957c3aaa4cac4e588b324d0011 1 sl.linkmemine.com 7002 sl.linkmemine.com 8443 듀얼모니터&nbsp;테스트 1 0 sl.linkmemine.com 443";
	SeedProvider sp;
	std::string encoded, decoded;

	sp.SetHeader("Koino1807!123456\0");
	sp.SetKey("LinkMeMine123456\0");

	sp.Encrypt((char*)(src.c_str()), src.size(), true);
	TRACE(_T("src     = %s\n"), CString(src.c_str()));
	encoded = base64_encode(src);
	TRACE(_T("encoded = %s\n"), CString(encoded.c_str()));

	decoded = base64_decode(encoded);
	TRACE(_T("decoded = %s\n"), CString(decoded.c_str()));
	src = decoded;
	sp.Encrypt((char*)(src.c_str()), src.size(), false);
	TRACE(_T("src     = %s\n"), CString(src.c_str()));

	//base64
	//str = _T("동해물과 백두산이 abcde!@#$%");
	sp.Encrypt(str, true);
	str = base64_encode(str);
	//for (int i = 0; i < 1; i++)
	//	str = base64_encode(str);

	str = base64_decode(str);;
	//for (int i = 0; i < 1; i++) 
	//	str = base64_decode(str);
	sp.Encrypt(str, false);
#endif
	

	/*
	std::vector<CString> text;
	
	text.push_back(_T("false한쒗넻而李⑦듃?댁옱??"));
	text.push_back(_T("true한rmf글"));
	text.push_back(_T("가힣SKM-S_?SLK한rmf글"));

	for (size_t i = 0; i < text.size(); i++)
	{
		bool b = is_valid_string(text[i], true);
		TRACE(_T("%s is valid hangul? = %d\n"), text[i], b);
	}
	*/

	//std::deque<CString> str = GetTokenString(CString(ststr.c_str()), _T("\n"));
	//line_count = str.size();
	/*
	int tcharsize = sizeof(TCHAR);

	TCHAR* data = new TCHAR[sizeof(TCHAR)*fsize];
	memset(data, 0, tcharsize * fsize);
	file_open(&fp, _T("rt"), file);
	//fread_s(data, sizeof(TCHAR), sizeof(TCHAR), tcharsize * fsize, fp);
	fread(data, sizeof(TCHAR), fsize, fp);

	std::deque<CString> str = GetTokenString(data, _T("\n"));

	//TRACE(_T("%s\n"), str);
	fclose(fp);
	delete[] data;
	*/

	//607에서 문제 발생, 608에서 나감
	/*
	std::ifstream stdfile(CString2string(file));
	if (!stdfile.is_open())
	{
		return FALSE;
	}

	std::string stdline;
	while (std::getline(stdfile, stdline))
	{
		line_count++;
		TRACE(_T("[%5d] %s\n"), line_count, CString(stdline.c_str()));
	}
	stdfile.close();
	*/

	/*
	file_open(&fp, _T("rt"), file);

	while (!feof(fp))
	{
		line_count++;
		TCHAR* ret = _fgetts(tline, _countof(tline), fp);
		TRACE(_T("[%5d] %s"), line_count, tline);

		//607에서 문제 발생, 608에서 나감
		if (ret == NULL)
			break;
	}

	fclose(fp);
	*/

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTestEncodingDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTestEncodingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTestEncodingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestEncodingDlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	TCHAR tfile[MAX_PATH];
	DragQueryFile(hDropInfo, 0, tfile, MAX_PATH);

	//FILE* fp = NULL;
	int line_count = 0;
	//CString file = _T("D:\\1.Projects_C++\\DBRecovery\\bin\\data\\kmslog[20230216 161338].txt");
	//CString file = _T("D:\\1.Projects_C++\\DBRecovery\\bin\\data\\time_error_remain.txt");
	uint64_t fsize = get_file_size(tfile);

	std::ifstream infile(CString2string(tfile), std::ifstream::binary);
	std::ofstream outfile("d:\\temp\\outfile.txt");
	std::string ststr;

	infile.seekg(0, std::ios::end);
	ststr.reserve(infile.tellg());
	infile.seekg(0, std::ios::beg);

	ststr.assign((std::istreambuf_iterator<char>(infile)),
		std::istreambuf_iterator<char>());

	infile.close();

	TRACE(_T("read size = %ld\n"), ststr.size());
	outfile.write(ststr.c_str(), ststr.size());
	outfile.close();


	CString src(ststr.c_str());
	CString sline;
	int start_pos = 0;
	int end_pos;

	while (true)
	{
		line_count++;

		end_pos = src.Find(_T("\r\n"), start_pos);

		if (end_pos < 0)
			break;

		sline = src.Mid(start_pos, end_pos - start_pos);
		//str = str.Mid(end_pos + 2);
		start_pos = end_pos + 2;
		TRACE(_T("[%5d] %s\n"), line_count, sline);
	}

	CDialogEx::OnDropFiles(hDropInfo);
}


void CTestEncodingDlg::OnBnClickedOk()
{
	//m_pTaskbarList->SetProgressState(m_hWnd, TBPF_INDETERMINATE);
	m_pTaskbarList->SetProgressValue(m_hWnd, 50, 100);
}


void CTestEncodingDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_pTaskbarList)
		m_pTaskbarList.Release();

	CDialogEx::OnCancel();
}
