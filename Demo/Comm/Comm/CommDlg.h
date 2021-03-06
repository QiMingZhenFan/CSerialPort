
// CommDlg.h : 头文件
//

#pragma once
#include "SerialPort.h"
#include "afxwin.h"

#define WM_TEST 1000

using namespace std;
using namespace itas109;

extern CSerialPort m_SerialPort;

// CCommDlg 对话框
#ifdef _SEND_DATA_WITH_SIGSLOT
	class CCommDlg : public CDialogEx, public has_slots<>
#else
	class CCommDlg : public CDialogEx
#endif
{
// 构造
public:
	CCommDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_COMM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	void OnSendMessage(unsigned char* str, int port, int str_len);

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnReceiveStr(WPARAM str, LPARAM commInfo);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CComboBox m_PortNr;
	CComboBox m_BaudRate;
	afx_msg void OnBnClickedButtonOpenClose();
	CButton m_OpenCloseCtrl;
	afx_msg void OnBnClickedButtonSend();
	CEdit m_Send;
	CEdit m_ReceiveCtrl;
	afx_msg void OnClose();
};
