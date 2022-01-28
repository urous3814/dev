//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <cmath>
#include <Algorithm>
#include <iostream>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "perfgrap"
#pragma resource "*.dfm"
TForm1 *Form1;
TBitmap *Mask1;
float x = 0, y;
float expd, expj;
float logd, logj;
float ang, multi;
bool draw = true, autoc = false;
int scale = 5;
float Pi = 3.1416926;
float PenScale = 5;
TBitmap *Bit;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
    Image1->Picture->Bitmap = Bit;
	Image1->Picture->Bitmap->Height = Image1->Height;
	Image1->Picture->Bitmap->Width = Image1->Width;
	Image1->Picture->Bitmap->Canvas->Pen->Color = clBlack;
	Image1->Picture->Bitmap->Canvas->Pen->Width = 1;
//	Image1->Picture->Bitmap->Canvas->MoveTo(125,0);
//	Image1->Picture->Bitmap->Canvas->LineTo(125,250);
//	Image1->Picture->Bitmap->Canvas->MoveTo(0,125);
//	Image1->Picture->Bitmap->Canvas->LineTo(250,125);
//	Image1->Picture->Bitmap->Canvas->MoveTo(0,125);
//	Image1->Picture->Bitmap->Canvas->LineTo(250,125);
	for(int i=0; i < 125; i+=scale)
	{
		Image1->Picture->Bitmap->Canvas->MoveTo(125, 125 + i);
		Image1->Picture->Bitmap->Canvas->LineTo(125,125+scale + i);
		Image1->Picture->Bitmap->Canvas->MoveTo(125, 125+scale + i);
		Image1->Picture->Bitmap->Canvas->LineTo(127,125+scale + i);
		Image1->Picture->Bitmap->Canvas->MoveTo(125, 125+scale + i);
		Image1->Picture->Bitmap->Canvas->LineTo(123,125+scale + i);
	}
	for(int i=0; i < 125; i+=scale)
	{
		Image1->Picture->Bitmap->Canvas->MoveTo(125, 125 - i);
		Image1->Picture->Bitmap->Canvas->LineTo(125,125+scale - i);
		Image1->Picture->Bitmap->Canvas->MoveTo(125, 125+scale - i);
		Image1->Picture->Bitmap->Canvas->LineTo(127,125+scale - i);
		Image1->Picture->Bitmap->Canvas->MoveTo(125, 125+scale - i);
		Image1->Picture->Bitmap->Canvas->LineTo(123,125+scale - i);
	}
    for(int i=0; i < 125; i+=scale)
	{
		Image1->Picture->Bitmap->Canvas->MoveTo(125 + i, 125);
		Image1->Picture->Bitmap->Canvas->LineTo(125+scale + i, 125);
		Image1->Picture->Bitmap->Canvas->MoveTo(125+scale + i, 125);
		Image1->Picture->Bitmap->Canvas->LineTo(125+scale + i, 127);
		Image1->Picture->Bitmap->Canvas->MoveTo(125+scale + i, 125);
		Image1->Picture->Bitmap->Canvas->LineTo(125+scale + i, 123);
	}
    for(int i=0; i < 125; i+=scale)
	{
		Image1->Picture->Bitmap->Canvas->MoveTo(125 - i, 125);
		Image1->Picture->Bitmap->Canvas->LineTo(125+scale - i, 125);
		Image1->Picture->Bitmap->Canvas->MoveTo(125+scale - i, 125);
		Image1->Picture->Bitmap->Canvas->LineTo(125+scale - i, 127);
		Image1->Picture->Bitmap->Canvas->MoveTo(125+scale - i, 125);
		Image1->Picture->Bitmap->Canvas->LineTo(125+scale - i, 123);
	}

	Image1->Picture->Bitmap->Canvas->Pen->Color = clBlue;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	float cola = TrackBar1->Position;
	x = cola/100;
	Edit12->Text = cola/100;
	expd = Slicing(Edit1->Text);
	expj = Slicing(Edit2->Text);
	Edit3->Text = pow(expd, expj);
	if(draw)
	{
		Dot(x, StrToFloat(Edit3->Text));
	}
}

float __fastcall TForm1::Slicing(String Temp)
{
	float d[3] = {1, 1, 1};
	if(Temp.Pos("-") == 1)
	{
		d[0] = -1;
		Temp.Delete(1, 1);
	}
	if(Temp.Pos("x"))
	{
		if(Temp.SubString(1, Temp.Pos("x")-1) != "")
			d[1] = StrToFloat(Temp.SubString(1, Temp.Pos("x")-1));
		d[2] = x;
	}
	else
	{
		d[1] = StrToFloat(Temp);
	}
	return(d[0]*d[1]*d[2]);
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    float cola = TrackBar1->Position;
	x = cola/100;
	Edit12->Text = cola/100;
	if(CheckBox5->Checked)
	{
		logj = Slicing(Edit11->Text);
		if(logj > 0)
		{
			Edit3->Text = log(logj);
            if(draw)
			{
				Dot(x, StrToFloat(Edit3->Text));
			}
		}
	}
	else
	{
		logd = Slicing(Edit10->Text);
		logj = Slicing(Edit11->Text);
		if(logj > 0 && logd > 0 && logd != 1)
		{
			Edit3->Text = log10(logj)/log10(logd);
			if(draw)
			{
				Dot(x, StrToFloat(Edit3->Text));
			}
		}
	}

}

//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
	float cola = TrackBar1->Position;
	x = cola/100;
	Edit12->Text = cola/100;
    if(ComboBox2->ItemIndex == 1)
	{
		Button1Click(Sender);
	}
	else if(ComboBox2->ItemIndex == 2)
	{
		Button2Click(Sender);
	}
	else if(ComboBox2->ItemIndex == 3)
	{
		Button7Click(Sender);
	}

	
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
	y = TrackBar2->Position;
	Edit13->Text = TrackBar2->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox5Click(TObject *Sender)
{
	if(CheckBox5->Checked)
	{
		Edit10->Text = "e";
		Edit10->ReadOnly = true;
	}
	else
	{
		Edit10->Text = "";
		Edit10->ReadOnly = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit4Exit(TObject *Sender)
{
	TrackBar1->Min = StrToFloat(Edit4->Text)*100;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit5Exit(TObject *Sender)
{
	TrackBar1->Max = StrToFloat(Edit5->Text)*100;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit8Exit(TObject *Sender)
{
	TrackBar2->Min = StrToFloat(Edit8->Text)*100;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit9Exit(TObject *Sender)
{
	TrackBar2->Max = StrToFloat(Edit9->Text)*100;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit12Exit(TObject *Sender)
{
	TrackBar1->Position = StrToFloat(Edit12->Text)*100;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit13Exit(TObject *Sender)
{
	TrackBar2->Position = StrToFloat(Edit13->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
	draw = CheckBox2->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Dot(float i, float j)
{
	i = scale*i+125;
	j = 125-j*scale;
	Image1->Picture->Bitmap->Canvas->Pen->Width = PenScale;
	Image1->Picture->Bitmap->Canvas->MoveTo(i,j);
	Image1->Picture->Bitmap->Canvas->LineTo(i+0.01,j+0.01);

}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	ComboBox2->ItemIndex = 0;
	autoc = true;
	for (float i = TrackBar1->Min/100; i <= TrackBar1->Max/100; i+=0.01)
	{
		TrackBar1->Position = i*100;
		Button1Click(Sender);
	}
	autoc = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	ComboBox2->ItemIndex = 0;
	autoc = true;
	for (float i = TrackBar1->Min/100; i <= TrackBar1->Max/100; i+=0.01)
	{
		TrackBar1->Position = i*100;
		Button2Click(Sender);

	}
    autoc = false;
}
//---------------------------------------------------------------------------







void __fastcall TForm1::Button6Click(TObject *Sender)
{
	SavePictureDialog1->Execute();
	Image1->Picture->SaveToFile(SavePictureDialog1->FileName);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	if(ComboBox1->ItemIndex == 0)
	{
		Panel1->Visible = true;
		Button3->Visible = true;
        Button4->Visible = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ColorBox2Change(TObject *Sender)
{
	Image1->Picture->Bitmap->Canvas->Pen->Color = ColorBox2->Selected;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ColorBox1Change(TObject *Sender)
{
	Image1->Picture->Bitmap->Canvas->Pen->Color = ColorBox1->Selected;
    Image1->Picture->Bitmap->Canvas->Pen->Width = 2;
	Image1->Picture->Bitmap->Canvas->MoveTo(125,0);
	Image1->Picture->Bitmap->Canvas->LineTo(125,250);
	Image1->Picture->Bitmap->Canvas->MoveTo(0,125);
	Image1->Picture->Bitmap->Canvas->LineTo(250,125);
    Image1->Picture->Bitmap->Canvas->Pen->Color = ColorBox2->Selected;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit15Change(TObject *Sender)
{
	PenScale = StrToInt(Edit15->Text);
}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button7Click(TObject *Sender)
{
	float cola = TrackBar1->Position;
	x = cola/100;
	Edit12->Text = cola/100;
	ang = Slicing(Edit16->Text);
	multi = Slicing(Edit17->Text);
	if(ComboBox3->ItemIndex == 0)
		Edit3->Text = multi*sin( ang * Pi / 180);
	else if(ComboBox3->ItemIndex == 1)
		Edit3->Text = multi*cos( ang * Pi / 180);
	else
		Edit3->Text = multi*tan( ang * Pi / 180);
	if(draw)
	{
		Dot(x, StrToFloat(Edit3->Text));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	ComboBox2->ItemIndex = 0;
	autoc = true;
	for (float i = TrackBar1->Min/100; i <= TrackBar1->Max/100; i+=0.01)
	{
		TrackBar1->Position = i*100;
		Button7Click(Sender);
	}
	autoc = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit14Exit(TObject *Sender)
{
    scale = StrToInt(Edit14->Text);
	FormShow(Sender);
}
//---------------------------------------------------------------------------

