//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tblue_v2 *blue_v2;
int y=0,sw=0,sw1=0,swich=0;
TBluetoothSocket* soc; //���� ����
int sendcheck=0; //������ ������ ������ �ƴ� �� Ȯ�� ��
int trash=0; //�����Ⱚ ������
//---------------------------------------------------------------------------
__fastcall Tblue_v2::Tblue_v2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tblue_v2::Button9Click(TObject *Sender)
{

	Timer1->Enabled=false;
	Timer1->Interval=0;   //����
}
//---------------------------------------------------------------------------
void __fastcall Tblue_v2::Button8Click(TObject *Sender)
{
  if(swich==0)
	{
		Timer1->Enabled=true;  //�ѱ�
		Timer1->Interval=65;
		Button3->Text="OFF";
		swich=1;
	}
	else
	{
		Timer1->Enabled=false;
		Timer1->Interval=0;   //����
		Button3->Text="ON";
		swich=0;
	}

}
//---------------------------------------------------------------------------
void __fastcall Tblue_v2::Button1Click(TObject *Sender)
{
	blue->Enabled=true;  //����
	blue->DiscoverDevices(5000);
	blue->CurrentManager->GetPairedDevices();
}
//---------------------------------------------------------------------------
void __fastcall Tblue_v2::Timer1Timer(TObject *Sender)
{

	if(trash>=3)
	{
		String data;
		data = TEncoding::UTF8->GetString(soc->ReceiveData());
		if(!data.IsEmpty())
		{
			if(10<=StrToInt(data)&&StrToInt(data)<=50)
			{
				Memo1->Lines->Add(data);
				if(sendcheck==1)
				{
					IdTCPClient1->Socket->Write(data);

				}
			}
		}
	}
	else
	{
		trash++;
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
	Timer2->Interval=65;
	Button5->Text="OFF";
	swich=1;
}
//---------------------------------------------------------------------------

void __fastcall Tblue_v2::Timer2Timer(TObject *Sender)
{
	if(trash>=3)
	{
		String data;

		data = TEncoding::ASCII->GetString(soc->ReceiveData());
		if(!data.IsEmpty())
		{
			if(5<=StrToInt(data)&&StrToInt(data)<=50)
			{
				ProgressBar1->Value=StrToInt(data);
				Memo1->Lines->Add(data);
				if(sendcheck==1)
				{
					IdTCPClient1->Socket->Write(data);

				}
			}
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

		if(sendcheck==0)
		{
			sendcheck=1;
			Button10->Text="��������" ;
		}
		else
		{
			sendcheck=0;
			Button10->Text="�����ϱ�";
		}


}
//---------------------------------------------------------------------------


void __fastcall Tblue_v2::IdTCPClient1Connected(TObject *Sender)
{
	ShowMessage("���Ἲ��");
}
//---------------------------------------------------------------------------

void __fastcall Tblue_v2::Button11Click(TObject *Sender)
{
		IdTCPClient1->Socket->Write("123");
}
//---------------------------------------------------------------------------

