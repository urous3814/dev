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
void __fastcall Tblue_v2::Button8Click(TObject *Sender)
{
	if(swich==0)
	{
		Timer1->Enabled=true;  //켜기
		Timer1->Interval=50;
		Button3->Text="OFF";
		swich=1;
	}
	else
	{
		Timer1->Enabled=false;
		Timer1->Interval=0;   //끄기
		Button3->Text="ON";
        swich=0;
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
void __fastcall Tblue_v2::Timer1Timer(TObject *Sender)
{
	String data;
	data = TEncoding::UTF8->GetString(soc->ReceiveData());
	if(!data.IsEmpty())
	{
		if(data<=170){
		Memo1->Lines->Add(data);
        }

	}
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
		ShowMessage("Pairing Completed.");
		TBluetoothServiceList *service = blue->LastServiceList(blue->PairedDevices()->Items[a]);
		soc = blue->CreateClientSocket(blue->PairedDevices()->Items[a],service->Items[0].UUID,false);
		soc->Connect();
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
		Button3->Text="OFF";
		swich=1;
	}
	Timer2->Enabled=true;
	Timer2->Interval=50;
	Button5->Text="OFF";
	swich=1;
}
//---------------------------------------------------------------------------

void __fastcall Tblue_v2::Timer2Timer(TObject *Sender)
{
	String data;
	data = TEncoding::ASCII->GetString(soc->ReceiveData());
	if(!data.IsEmpty())
	{

		ProgressBar1->Value=StrToInt(data);

	}
}
//---------------------------------------------------------------------------

