#include "checkupdate.h"
#include <iostream>
#include <wuapi.h>
#include <ATLComTime.h>
#include <wuerror.h>
#include <locale.h>
#include <fstream>
#include <ATLComTime.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <wuerror.h>
#include <Wuapi.h>
#include <string.h>
#include <OleAuto.h>
#include <wtypes.h>
#include <WinBase.h>
#include <winerror.h>
#include <wbemidl.h>
#include <lmcons.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <cstdlib>
#include <locale.h>
#include <clocale>
#include <map>
#include <qlabel.h>
#include <qapplication.h>
#include <qtextstream.h>
#include <QDebug>
#include <QTextCodec>
#include <locale>


#pragma warning(disable:4996)
//#pragma execution_character_set("utf-8")

using namespace std;

QString checkupdate::update()
{
	QString returnResult;
	HRESULT hr;
//	QLocale curLocale(QLocale("kor"));
//	QLocale::setDefault(curLocale);
	//QTextCodec::codecForName("eucKR");

			hr = CoInitialize(NULL);

			IUpdateSession* iUpdate;
			IUpdateSearcher* searcher;
			ISearchResult* results;
			BSTR criteria = SysAllocString(L"IsInstalled=0");

			hr = CoCreateInstance(CLSID_UpdateSession, NULL, CLSCTX_INPROC_SERVER, IID_IUpdateSession, (LPVOID*)&iUpdate);
			hr = iUpdate->CreateUpdateSearcher(&searcher);
			//std::wcout.imbue(std::locale("korean"));
			returnResult = QString::fromLocal8Bit("업데이트를 찾고 있습니다",-1);
			hr = searcher->Search(criteria, &results);
			SysFreeString(criteria);

			switch (hr) {
			case S_OK:
				QTextStream(&returnResult) << L"시스템에 적용 할 수있는 목록:" << endl;
				break;
			case WU_E_LEGACYSERVER:
				QTextStream(&returnResult) << L"서버를 찾을수 없다" << endl;
			case WU_E_INVALID_CRITERIA:
				QTextStream(&returnResult) << L"잘못된 검색 기준입니다." << endl;
			}

			IUpdateCollection* updateList;
			IUpdateCollection* bundledUpdates;
			IUpdate* updateItem;
			IUpdate* bundledUpdateItem;
			LONG updateSize;
			LONG bundledUpdateSize;
			BSTR updateName;
			BSTR severity;


			results->get_Updates(&updateList);
			updateList->get_Count(&updateSize);

			if (updateSize == 0) {
				QTextStream(&returnResult) << L"업데이트 할수 있는 목록이 없습니다." << endl;
			}

			for (LONG i = 0; i < updateSize; i++) {
				updateList->get_Item(i, &updateItem);
				updateItem->get_Title(&updateName);
				UINT length = SysStringLen(updateName);
				wchar_t *nameofUpdate = new wchar_t[length + 1];
				wcscpy(nameofUpdate, updateName);
				severity = NULL;
				updateItem->get_MsrcSeverity(&severity);
				if (severity != NULL) {
					QTextStream(&returnResult) << QString::fromWCharArray(L" 보안 업데이트: ", -1) << severity << endl;
				}
				//qDebug(updateName);
				QTextStream(&returnResult) << i + 1 << " : " << QString::fromWCharArray(nameofUpdate, -1) << endl;

				// bundled updates
				updateItem->get_BundledUpdates(&bundledUpdates);
				bundledUpdates->get_Count(&bundledUpdateSize);

				if (bundledUpdateSize != 0) {
					// iterate through bundled updates
					for (LONG ii = 0; ii < bundledUpdateSize; ii++) {
						bundledUpdates->get_Item(ii, &bundledUpdateItem);
						severity = NULL;
						bundledUpdateItem->get_MsrcSeverity(&severity);
						if (severity != NULL) {
							QTextStream(&returnResult) << QString::fromWCharArray(L" 번들 업데이트: ",-1) << severity << endl;
						}
					}
				}
			}

			::CoUninitialize();
			qDebug() << returnResult;
			return returnResult;
	}


QString checkupdate::history() {
	HRESULT hr;
	hr = CoInitialize(NULL);
	QString histories;


	IUpdateSession* iUpdate;
	IUpdateSearcher* searcher;
	IUpdateHistoryEntryCollection* historyEntryCollection;
	IUpdateHistoryEntry* historyEntry;
	//BSTR criteria = SysAllocString(L"IsInstalled=1 or IsHidden=1 or IsPresent=1");
	LONG historyCount = 0;

	//wofstream outfile;
	//outfile.imbue(std::locale("Korean"));
	//outfile.open("log.txt", ios::app);

	hr = CoCreateInstance(CLSID_UpdateSession, NULL, CLSCTX_INPROC_SERVER, IID_IUpdateSession, (LPVOID*)&iUpdate);
	hr = iUpdate->CreateUpdateSearcher(&searcher);
	hr = searcher->GetTotalHistoryCount(&historyCount);
	hr = searcher->QueryHistory(0, historyCount, &historyEntryCollection);
	//hr = historyEntryCollection->get_Item()

	QTextStream(&histories)  << L"Searching for recent updates ..." << endl;
	//SysFreeString(criteria);

	switch (hr)
	{
	case S_OK:
		QTextStream(&histories) << L"List of applicable items on the machine:" << endl;
		break;
	}
	setlocale(LC_ALL, "Korean");

	BSTR updateName;
	DATE retdate;
	COleDateTime dateupdate;

	//DateTime upTime;
//	char *time = NULL;
	std::locale::global(std::locale("Korean"));

	for (LONG i = 0; i < historyCount; ++i)
	{


		hr = historyEntryCollection->get_Item(i, &historyEntry);

		hr = historyEntry->get_Title(&updateName);
		UINT length = SysStringLen(updateName);
		wchar_t *nameofUpdate = new wchar_t[length + 1];
		wcscpy(nameofUpdate, updateName);
	//	if (nameofUpdate[35] == 0x2013) {
	//		nameofUpdate[35] = ' ';
		//}
		//outfile << nameofUpdate << std::endl;
		QTextStream(&histories) << QString::fromWCharArray(nameofUpdate, -1)<<endl;

		//	hr = historyEntry->get_ServiceID(&ClientAppID);
		//	UINT idlength = SysStringLen(ClientAppID);
		//	wchar_t *nameofID = new wchar_t[idlength + 1];
		//	wchar_t *blank = new wchar_t[5];
		//	wcscpy(nameofID, ClientAppID);
		//	if (nameofUpdate[35] == 0x2013) {
		//		nameofUpdate[35] = ' ';
		//	}
		//	outfile << nameofID << std::endl;
		//	std::wcout << nameofID << std::endl;

		hr = historyEntry->get_Date(&retdate);

		//	upTime = DateTime::FromOADate(retdate);
		dateupdate = retdate;
		int year = dateupdate.GetYear();
		int month = dateupdate.GetMonth();
		int day = dateupdate.GetDay();
		//outfile << L"update date : " << year << "/" << month << "/" << day << std::endl;
		QTextStream(&histories) << year << "/" << month << "/" << day << endl;

		SysFreeString(updateName);
		//		SysFreeString(ClientAppID);
	}
	//outfile.close();
	::CoUninitialize();
	wcin.get();
	return histories;

}
