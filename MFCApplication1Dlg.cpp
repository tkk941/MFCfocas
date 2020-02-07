
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "fwlib32.h"
#include<cstring>
#include<iostream>
#include<Windows.h>


#pragma comment(lib,"fwlib32.lib")


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using std::cout;
using std::endl;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(but1, &CMFCApplication1Dlg::OnBnClickedbut1)
	ON_BN_CLICKED(but2, &CMFCApplication1Dlg::OnBnClickedbut2)
	ON_BN_CLICKED(but1, &CMFCApplication1Dlg::OnBnClickedbut1)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CMFCApplication1Dlg::OnBnClickedbut1()
//{
//	unsigned short Flibhndl{ 0 };
//	CString ip;
//	CString port;
//	CString timeout;
//	GetDlgItem(txtip)->GetWindowText(ip);
//	GetDlgItem(txtport)->GetWindowText(port);
//	GetDlgItem(txttime)->GetWindowText(timeout);
//	//int mport = _ttol(port);
//	if (ip == "" || port == "" || timeout == "")
//	{
//		cout << "请输入相应地址端口" << endl;
//	}
//
//	int ret = cnc_allclibhndl3((char*)&ip, _ttol(port), _ttol(timeout), &Flibhndl);
//	if (ret == EW_OK)
//	{
//		cout << "连接成功！" << endl;
//	}
//	else
//	{
//		cout << "ret=" << ret << endl;       //-16检查以太网，CNC电源，连接电缆；   -15检查缺少的dll文件；   -8表示分配句柄失败
//	}
//}


void CMFCApplication1Dlg::OnBnClickedbut2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication1Dlg::OnBnClickedbut1()
{
	unsigned short Flibhndl{ 0 };
	CString ip;
	CString port;
	CString timeout;
	GetDlgItem(txtip)->GetWindowText(ip);
	GetDlgItem(txtport)->GetWindowText(port);
	GetDlgItem(txttime)->GetWindowText(timeout);
	USES_CONVERSION;
	char *ipaddr;
	ipaddr = W2A(ip);
	
	if (ipaddr == "" || port == "" || timeout == "")
	{
		MessageBox(_T("请输入相应地址端口"), _T("提示"), MB_OKCANCEL);
	}
	int ret = cnc_allclibhndl3(ipaddr, _ttol(port), _ttol(timeout), &Flibhndl);
	if (ret == EW_OK)
	{
		MessageBox(_T("连接成功!"), _T("提示"), MB_OKCANCEL);
	}
	else
	{
		MessageBox(_T("ret不对"), _T("提示"), MB_OKCANCEL);//-16检查以太网，CNC电源，连接电缆；   -15检查缺少的dll文件；   -8表示分配句柄失败
	}
}
