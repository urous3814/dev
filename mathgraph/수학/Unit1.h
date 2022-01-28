//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "perfgrap.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TComboBox *ComboBox1;
	TPanel *Panel2;
	TImage *Image1;
	TColorBox *ColorBox1;
	TColorBox *ColorBox2;
	TLabel *Label2;
	TLabel *Label3;
	TPanel *Panel3;
	TLabel *Label4;
	TTrackBar *TrackBar1;
	TEdit *Edit4;
	TEdit *Edit5;
	TLabel *Label5;
	TCheckBox *CheckBox2;
	TEdit *Edit6;
	TEdit *Edit7;
	TPanel *Panel1;
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button1;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label6;
	TTrackBar *TrackBar2;
	TLabel *Label7;
	TEdit *Edit8;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit11;
	TButton *Button2;
	TCheckBox *CheckBox5;
	TEdit *Edit12;
	TEdit *Edit13;
	TButton *Button5;
	TButton *Button6;
	TSavePictureDialog *SavePictureDialog1;
	TComboBox *ComboBox2;
	TEdit *Edit14;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *Edit15;
	TLabel *Label10;
	TLabel *Label11;
	TEdit *Edit16;
	TButton *Button3;
	TButton *Button4;
	TComboBox *ComboBox3;
	TButton *Button7;
	TButton *Button8;
	TEdit *Edit17;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall CheckBox5Click(TObject *Sender);
	void __fastcall Edit4Exit(TObject *Sender);
	void __fastcall Edit5Exit(TObject *Sender);
	void __fastcall Edit8Exit(TObject *Sender);
	void __fastcall Edit9Exit(TObject *Sender);
	void __fastcall Edit12Exit(TObject *Sender);
	void __fastcall Dot(float i, float j);
	void __fastcall Edit13Exit(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
    float __fastcall Slicing(String Temp);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ColorBox2Change(TObject *Sender);
	void __fastcall ColorBox1Change(TObject *Sender);
	void __fastcall Edit15Change(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Edit14Exit(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
