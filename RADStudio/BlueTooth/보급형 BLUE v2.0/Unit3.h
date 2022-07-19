//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <System.Bluetooth.Components.hpp>
#include <System.Bluetooth.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Memo.Types.hpp>
//---------------------------------------------------------------------------
class Tblue_v2 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TButton *Button1;
	TButton *Button2;
	TListBox *ListBox1;
	TBluetooth *blue;
	TTimer *Timer1;
	TButton *Button3;
	TProgressBar *ProgressBar1;
	TGroupBox *GroupBox2;
	TMemo *Memo1;
	TEdit *Edit1;
	TButton *Button4;
	TButton *Button5;
	TTimer *Timer2;
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall blueDiscoveryEnd(TObject * const Sender, TBluetoothDeviceList * const ADeviceList);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall Tblue_v2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tblue_v2 *blue_v2;
//---------------------------------------------------------------------------
#endif
