//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tblue_v2 *blue_v2;
int y=0,sw=0,sw1=0,swich=0;
TBluetoothSocket* soc; //동적 생성
bool sendcheck="false"; //빌더로 데이터 보낼지 아닐 지 확인 용
int trash=0; //쓰레기값 버리기
int BL_MIN,BL_MAX,BL_TIME;
String old_data;
bool str=false;
//---------------------------------------------------------------------------
__fastcall Tblue_v2::Tblue_v2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tblue_v2::Button9Click(TObject *Sender)
{

	Timer1->Enabled=false;
	Timer1->Interval=0;   //끄기
}
//---------------------------------------------------------------------------
void __fastcall Tblue_v2::Button3Click(TObject *Sender)
{
	if(Timer1->Enabled==true)
	{
		Timer1->Enabled=false;
		Timer1->Interval=BL_TIME;
		Button3->Text="OFF";

	}
	else
	{
		Timer1->Enabled=false;
		Timer1->Interval=0;
		Button3->Text="ON";
        trash=0;
	}
}
//---------------------------------------------------------------------------
void __fastcall Tblue_v2::Button1Click(TObject *Sender)
{
	blue->Enabled=true;  //실행
	blue->DiscoverDevices(5000);
	blue->CurrentManager->GetPairedDevices();
}
//---------------------------------------------------------------------------
void __fastcall Tblue_v2::blueDiscoveryEnd(TObject * const Sender, TBluetoothDeviceList * const ADeviceList)

{
	for(int x=0; x < blue->LastPairedDevices->Count; x++)
	{
		ListBox1->Items->Add(blue->PairedDevices()->Items[x]->DeviceName);
	}
}
//---------------------------------------------------------------------------
void __fastcall Tblue_v2::Button4Click(TObject *Sender)
{
	/*String text;
	text=Edit1->Text;  */
	soc->SendData(TEncoding::UTF8->GetBytes("b"));
}
//---------------------------------------------------------------------------

void __fastcall Tblue_v2::Button2Click(TObject *Sender)
{
	int a=ListBox1->ItemIndex;

	if(blue->IsPaired(blue->PairedDevices()->Items[a]))
	{
		TBluetoothServiceList *service = blue->LastServiceList(blue->PairedDevices()->Items[a]);
		soc = blue->CreateClientSocket(blue->PairedDevices()->Items[a],service->Items[0].UUID,false);
		soc->Connect();
		ShowMessage("Pairing Completed.");
	}
	else
	{
		ShowMessage("Pairing Failed.");
	}
	//ShowMessage(TEncoding::UTF8->GetString(soc->ReceiveData()));
}
//---------------------------------------------------------------------------

void __fastcall Tblue_v2::Button5Click(TObject *Sender)
{
	if(Timer1->Enabled==true)
	{
		Timer1->Enabled=false;
		Timer1->Interval=0;
		swich=1;
		Timer2->Enabled=true;
		Timer2->Interval=BL_TIME;
		Button5->Text="PO";
		swich=1;
	}
	else
	{
		Timer2->Enabled=false;
		Timer2->Interval=0;
		Button5->Text="PU";
		trash=0;
	}

}
//---------------------------------------------------------------------------

void __fastcall Tblue_v2::Timer2Timer(TObject *Sender)
{
	if(trash>=3)
	{
	   /*	if(FLUS==0)
		{ */
		String data;

		if(StrToInt(data)<BL_MAX&&StrToInt(data)>BL_MIN) data = TEncoding::UTF8->GetString(soc->ReceiveData());
		if(!data.IsEmpty())
		{

			if(BL_MIN<=StrToInt(data)&&StrToInt(data)<=BL_MAX)
			{
				Memo1->Lines->Add(data);
				if(sendcheck==true)
				{
					IdTCPClient1->Socket->Write(data);
				}
			old_data=StrToInt(data);
			}
		}
	   //	}
		/*else
		{

			String data;
			if(data<BL_MAX&&data>BL_MIN) data = TEncoding::UTF8->GetString(soc->ReceiveData());
			if(old_data*2>data)
			{
				if(!data.IsEmpty())
				{

					if(BL_MIN<=StrToInt(data)&&StrToInt(data)<=BL_MAX)
					{
						Memo1->Lines->Add(data);
						if(sendcheck==true)
						{
							IdTCPClient1->Socket->Write(data);
						}
						old_data=StrToInt(data);
					}
				}
			}
			else
			{
				String data;
				data = TEncoding::UTF8->GetString(soc->ReceiveData());
				data=old_data;
			}       */
		}

	}
	else
	{

		trash++;

	}
}
//---------------------------------------------------------------------------

void __fastcall Tblue_v2::Button6Click(TObject *Sender)
{
	if(blue_v2->ClientWidth<700)
	{
		blue_v2->ClientWidth=714;
	}
	else
	{
		blue_v2->ClientWidth=444;
    }

}
//---------------------------------------------------------------------------

void __fastcall Tblue_v2::FormCreate(TObject *Sender)
{
	blue_v2->ClientWidth=444;
}
//---------------------------------------------------------------------------

void __fastcall Tblue_v2::Button7Click(TObject *Sender)
{
	IdTCPClient1->Host = Edit2->Text;
	IdTCPClient1->Port = StrToInt(Edit3->Text);
    IdTCPClient1->Connect();
}
//---------------------------------------------------------------------------

void __fastcall Tblue_v2::Button10Click(TObject *Sender)
{

		if(sendcheck==false)
		{
			sendcheck=true;
			Button10->Text="전송중지" ;
		}
		else
		{
			sendcheck=false;
			Button10->Text="전송하기";
		}


}
//---------------------------------------------------------------------------


void __fastcall Tblue_v2::IdTCPClient1Connected(TObject *Sender)
{
	ShowMessage("연결성공");
}
//---------------------------------------------------------------------------

void __fastcall Tblue_v2::Button11Click(TObject *Sender)
{
		IdTCPClient1->Socket->Write("123");
}
//---------------------------------------------------------------------------


void __fastcall Tblue_v2::Edit4Change(TObject *Sender)
{
	BL_MIN=StrToInt(Edit4->Text);
}
//---------------------------------------------------------------------------

void __fastcall Tblue_v2::Edit5Change(TObject *Sender)
{
	BL_MAX=StrToInt(Edit5->Text);
}
//---------------------------------------------------------------------------




void __fastcall Tblue_v2::Edit6Click(TObject *Sender)
{
    BL_TIME=StrToInt(Edit6->Text);
}
//---------------------------------------------------------------------------





void __fastcall Tblue_v2::Check_STRChange(TObject *Sender)
{
	str=Check_STR->IsChecked;
}
//---------------------------------------------------------------------------

