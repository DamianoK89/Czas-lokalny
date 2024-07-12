//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TImage *Image1;
        TPanel *Panel2;
        TPanel *Panel3;
        TMainMenu *MainMenu1;
        TMenuItem *Plik1;
        TMenuItem *Oprogramie1;
        TMenuItem *Zamknij1;
        TMenuItem *Pomoc1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TEdit *Edit5;
        TEdit *Edit6;
        TLabel *Label12;
        TLabel *Label13;
        TButton *Button1;
        TComboBox *ComboBox1;
        TComboBox *ComboBox2;
        TLabel *Label14;
        TEdit *Edit7;
        TEdit *Edit8;
        TLabel *Label15;
        TLabel *Label16;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Oprogramie1Click(TObject *Sender);
        void __fastcall Zamknij1Click(TObject *Sender);
        void __fastcall Edit1Exit(TObject *Sender);
        void __fastcall Edit2Exit(TObject *Sender);
        void __fastcall Edit5Exit(TObject *Sender);
        void __fastcall Edit3Exit(TObject *Sender);
        void __fastcall Edit4Exit(TObject *Sender);
        void __fastcall Edit6Exit(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Edit7Exit(TObject *Sender);
        void __fastcall Edit8Exit(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 