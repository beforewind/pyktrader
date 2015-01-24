/*!
* \file LTSMdSpi.h
* \brief ʾ������������ӿ�
*
* ����Ŀ�ǻ��ڻ�������LTS֤ȯ�ӿ�C#������ʾ����������չʾLTS�����DoNet��������C#���п�����ʾ��������ʾ��LTS����ӿ�C#�ĵ��ã��ڱ�д�����Ŀʱ���Բο���
* �ɶ�����Ϣ�ṩ��Դ�����´���ɴ�http://github.com/REInfo��ȡ��
* �Ϻ�������Ϣ�Ƽ����޹�˾�ṩ֤ȯ���ڻ�����Ȩ���ֻ����г����ס����㡢 ���ҵ��Ŀͻ������Ʒ���
*
* \author wywty
* \version 1.0
* \date 2014-6-30
* 
*/

#pragma once

#include <vcclr.h>
#include "util.h"
#include "Callbacks.h"
#include "LTSMdAdapter.h"

namespace RELib_LTSNative
{
	/// ���й���
	class CLTSMdSpi : public CSecurityFtdcMdSpi
	{
	public:
		/// ���캯��
		CLTSMdSpi(LTSMDAdapter^ pAdapter);

		///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
		virtual void OnFrontConnected();

		///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ���������
		///@param nReason ����ԭ��
		///        0x1001 �����ʧ��
		///        0x1002 ����дʧ��
		///        0x2001 ����������ʱ
		///        0x2002 ��������ʧ��
		///        0x2003 �յ�������
		virtual void OnFrontDisconnected(int nReason);

		///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
		///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
		virtual void OnHeartBeatWarning(int nTimeLapse);

		

		/// <summary>
		/// 
		/// </summary>
		virtual void OnRspError(CSecurityFtdcRspInfoField *pRspInfo,int nRequestID, bool bIsLast);
		/// <summary>
		/// 
		/// </summary>
		virtual void OnRspUserLogin(CSecurityFtdcRspUserLoginField *pRspUserLogin,CSecurityFtdcRspInfoField *pRspInfo,int nRequestID, bool bIsLast);
		/// <summary>
		/// 
		/// </summary>
		virtual void OnRspUserLogout(CSecurityFtdcUserLogoutField *pUserLogout,CSecurityFtdcRspInfoField *pRspInfo,int nRequestID, bool bIsLast);
		

		///��������Ӧ��
		virtual void OnRspSubMarketData(CSecurityFtdcSpecificInstrumentField *pSpecificInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///ȡ����������Ӧ��
		virtual void OnRspUnSubMarketData(CSecurityFtdcSpecificInstrumentField *pSpecificInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///�������֪ͨ
		virtual void OnRtnDepthMarketData(CSecurityFtdcDepthMarketDataField *pDepthMarketData);

#ifdef __LTS_MA__
		// �ص�����
	public:
		Callback_OnFrontConnected p_OnFrontConnected;
		Callback_OnFrontDisconnected p_OnFrontDisconnected;
		Callback_OnHeartBeatWarning p_OnHeartBeatWarning;
		


		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspError	p_OnRspError;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspUserLogin	p_OnRspUserLogin;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspUserLogout	p_OnRspUserLogout;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspOrderInsert	p_OnRspOrderInsert;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspOrderAction	p_OnRspOrderAction;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspUserPasswordUpdate	p_OnRspUserPasswordUpdate;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspTradingAccountPasswordUpdate	p_OnRspTradingAccountPasswordUpdate;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspQryExchange	p_OnRspQryExchange;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspQryInstrument	p_OnRspQryInstrument;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspQryInvestor	p_OnRspQryInvestor;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspQryTradingCode	p_OnRspQryTradingCode;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspQryTradingAccount	p_OnRspQryTradingAccount;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspQryDepthMarketData	p_OnRspQryDepthMarketData;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspQryInvestorPositionDetail	p_OnRspQryInvestorPositionDetail;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspQryBondInterest	p_OnRspQryBondInterest;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspQryOrder	p_OnRspQryOrder;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspQryTrade	p_OnRspQryTrade;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRspQryInvestorPosition	p_OnRspQryInvestorPosition;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRtnOrder	p_OnRtnOrder;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnRtnTrade	p_OnRtnTrade;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnErrRtnOrderInsert	p_OnErrRtnOrderInsert;

		/// <summary>
		/// 
		/// </summary>
		Callback_OnErrRtnOrderAction	p_OnErrRtnOrderAction;

		// �ص�������Ӧ��delegate�����뱣��һ�ݶԸ�deleage�����ã�����GC���Զ����ո�deleage����������Ļص�����ʧЧ
		gcroot<Internal_FrontConnected^> d_FrontConnected;
		gcroot<Internal_FrontDisconnected^> d_FrontDisconnected;
		gcroot<Internal_HeartBeatWarning^> d_HeartBeatWarning;
		gcroot<Internal_PackageStart^> d_PackageStart;
		gcroot<Internal_PackageEnd^> d_PackageEnd;

		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspError^> d_RspError;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspUserLogin^> d_RspUserLogin;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspUserLogout^> d_RspUserLogout;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspOrderInsert^> d_RspOrderInsert;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspOrderAction^> d_RspOrderAction;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspUserPasswordUpdate^> d_RspUserPasswordUpdate;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspTradingAccountPasswordUpdate^> d_RspTradingAccountPasswordUpdate;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspQryExchange^> d_RspQryExchange;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspQryInstrument^> d_RspQryInstrument;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspQryInvestor^> d_RspQryInvestor;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspQryTradingCode^> d_RspQryTradingCode;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspQryTradingAccount^> d_RspQryTradingAccount;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspQryDepthMarketData^> d_RspQryDepthMarketData;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspQryInvestorPositionDetail^> d_RspQryInvestorPositionDetail;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspQryBondInterest^> d_RspQryBondInterest;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspQryOrder^> d_RspQryOrder;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspQryTrade^> d_RspQryTrade;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RspQryInvestorPosition^> d_RspQryInvestorPosition;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RtnOrder^> d_RtnOrder;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_RtnTrade^> d_RtnTrade;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_ErrRtnOrderInsert^> d_ErrRtnOrderInsert;
		/// <summary>
		/// 
		/// </summary>
		gcroot<Internal_ErrRtnOrderAction^> d_ErrRtnOrderAction;
#else
	private:
		gcroot<LTSMDAdapter^> m_pAdapter;
#endif

	};
};