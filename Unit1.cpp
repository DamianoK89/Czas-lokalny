//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
double Xk, Xp, Yk, Yp;
double d1, d2, m1, m2, s1, s2;
String c1, c2;
double dt, th, tmin, t11, t22;
int tpom, t1, t2;
double h, min;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int ex (double x)
{
        return (x-Xp)/(Xk-Xp)*Form1->Image1->Width;
}
int ey (double y)
{
        return (Yk-y)/(Yk-Yp)*Form1->Image1->Height;
}

void RysujPoludniki(void)
{
        Form1->Image1->Canvas->MoveTo(ex(Xp+20),ey(0.0));
        Form1->Image1->Canvas->LineTo(ex(Xp+20),ey(20.0));
        Form1->Image1->Canvas->MoveTo(ex(Xp+80),ey(0.0));
        Form1->Image1->Canvas->LineTo(ex(Xp+80),ey(20.0));
        Form1->Image1->Canvas->MoveTo(ex(Xp+140),ey(0.0));
        Form1->Image1->Canvas->LineTo(ex(Xp+140),ey(20.0));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Xk = 80.0;
        Xp = -80.0;
        Yk = 20.0;
        Yp = 0.0;
        RysujPoludniki();

        d1 = 16;
        m1 = 54;
        s1 = 0;
        Edit1->Text=FloatToStr(d1);
        Edit2->Text=FloatToStr(m1);
        Edit5->Text=FloatToStr(s1);

        d2 = 19;
        m2 = 2;
        s2 = 24;
        Edit3->Text=FloatToStr(d2);
        Edit4->Text=FloatToStr(m2);
        Edit6->Text=FloatToStr(s2);

        h = 12;
        min = 00;
        Edit7->Text=FloatToStr(h);
        Edit8->Text=FloatToStr(min);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Oprogramie1Click(TObject *Sender)
{
       Application->MessageBox("Czas lokalny \nVersion 1.0 \nby Damian Kie³basa \n2022 \ncopyleft \nAll rights reversed", "O programie", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zamknij1Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
        double pom;
        String Napis;
        pom=Edit1->Text.ToDouble();
        //kontrola poprawnosci
        if (pom>=0) d1=pom;
        else
        {
                Napis="Wpisales/as zla wartosc.\n Wspolrzedna nie moze byc ujemna";
                Application->MessageBoxA(Napis.c_str(),"UWAGA", MB_OK | MB_ICONWARNING);
                Edit1->Text=FloatToStr(d1);
        }
        Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit2Exit(TObject *Sender)
{
        double pom;
        String Napis;
        pom=Edit2->Text.ToDouble();
        //kontrola poprawnosci
        if (pom>=0) m1=pom;
        else
        {
                Napis="Wpisales/as zla wartosc.\n Wspolrzedna nie moze byc ujemna";
                Application->MessageBoxA(Napis.c_str(),"UWAGA", MB_OK | MB_ICONWARNING);
                Edit2->Text=FloatToStr(m1);
        }
        Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit5Exit(TObject *Sender)
{
        double pom;
        String Napis;
        pom=Edit5->Text.ToDouble();
        //kontrola poprawnosci
        if (pom>=0) s1=pom;
        else
        {
                Napis="Wpisales/as zla wartosc.\n Wspolrzedna nie moze byc ujemna";
                Application->MessageBoxA(Napis.c_str(),"UWAGA", MB_OK | MB_ICONWARNING);
                Edit5->Text=FloatToStr(s1);
        }
        Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit3Exit(TObject *Sender)
{
        double pom;
        String Napis;
        pom=Edit3->Text.ToDouble();
        //kontrola poprawnosci
        if (pom>=0) d2=pom;
        else
        {
                Napis="Wpisales/as zla wartosc.\n Wspolrzedna nie moze byc ujemna";
                Application->MessageBoxA(Napis.c_str(),"UWAGA", MB_OK | MB_ICONWARNING);
                Edit3->Text=FloatToStr(d2);
        }
        Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit4Exit(TObject *Sender)
{
        double pom;
        String Napis;
        pom=Edit4->Text.ToDouble();
        //kontrola poprawnosci
        if (pom>=0) m2=pom;
        else
        {
                Napis="Wpisales/as zla wartosc.\n Wspolrzedna nie moze byc ujemna";
                Application->MessageBoxA(Napis.c_str(),"UWAGA", MB_OK | MB_ICONWARNING);
                Edit4->Text=FloatToStr(m2);
        }
        Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit6Exit(TObject *Sender)
{
        double pom;
        String Napis;
        pom=Edit6->Text.ToDouble();
        //kontrola poprawnosci
        if (pom>=0) s2=pom;
        else
        {
                Napis="Wpisales/as zla wartosc.\n Wspolrzedna nie moze byc ujemna";
                Application->MessageBoxA(Napis.c_str(),"UWAGA", MB_OK | MB_ICONWARNING);
                Edit6->Text=FloatToStr(s2);
        }
        Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit7Exit(TObject *Sender)
{
        double pom;
        String Napis;
        pom=Edit7->Text.ToDouble();
        //kontrola poprawnosci
        if (pom>=1 && pom<=24) h=pom;
        else
        {
                Napis="Wpisales/as zla wartosc.\n Godzina nie moze byc ujemna, mniejsza niz 1 i wieksza niz 24 ";
                Application->MessageBoxA(Napis.c_str(),"UWAGA", MB_OK | MB_ICONWARNING);
                Edit7->Text=FloatToStr(h);
        }
        Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit8Exit(TObject *Sender)
{
        double pom;
        String Napis;
        pom=Edit8->Text.ToDouble();
        //kontrola poprawnosci
        if (pom>=0 && pom<=59) min=pom;
        else
        {
                Napis="Wpisales/as zla wartosc.\n Minuty nie moga byc ujemne i wieksze niz 59";
                Application->MessageBoxA(Napis.c_str(),"UWAGA", MB_OK | MB_ICONWARNING);
                Edit8->Text=FloatToStr(min);
        }
        Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

        c1 = ComboBox1->Items->Strings[ComboBox1->ItemIndex];
        c2 = ComboBox2->Items->Strings[ComboBox2->ItemIndex];

        if (c1 == c2 && c1 == ComboBox1->Items->Strings[1]) //polkula E
        {
                if (d1 < d2 && d1 > 0)
                {
                        Label1->Caption = "0°";
                        Label2->Caption = FloatToStr(d1) + "° " + FloatToStr(m1) + "' " + FloatToStr(s1) + "'' ";
                        Label3->Caption = FloatToStr(d2) + "° " + FloatToStr(m2) + "' " + FloatToStr(s2) + "'' ";
                        Label1->Visible = true;
                        Label2->Visible = true;
                        Label3->Visible = true;

                        // 1 stopieñ = 4 min, 1' = 4 sekundy, 15" = 1 sekunda, 1" = 1/15 sekundy
                        dt = ((d2 * 240)+(m2 * 4)+(s2 *(1/15)))-((d1 * 240)+(m1 * 4)+(s1 *(1/15)));
                        t1 = dt/60;
                        //t2 = dt/360;

                        tpom = (min + t1);
                        if(tpom >= 60)
                        {
                                th = (h + (tpom/60));
                                tmin = (tpom%60);
                        }
                        else
                        {
                                th = (h + t2);
                                tmin = (min + t1);
                        }

                        Label4->Visible = false;
                        Label5->Caption = FloatToStr(h) + " h " + FloatToStr(min) + " min ";
                        Label5->Visible = true;
                        Label6->Caption = FloatToStr(th) + " h " + FloatToStr(tmin) + " min ";
                        Label6->Visible = true;
                }
                else if (d1 > d2 && d2 > 0)
                {
                        Label1->Caption = "0°";
                        Label2->Caption = FloatToStr(d2) + "° " + FloatToStr(m2) + "' " + FloatToStr(s2) + "'' ";
                        Label3->Caption = FloatToStr(d1) + "° " + FloatToStr(m1) + "' " + FloatToStr(s1) + "'' ";
                        Label1->Visible = true;
                        Label2->Visible = true;
                        Label3->Visible = true;

                        // 1 stopieñ = 4 min, 1' = 4 sekundy, 15" = 1 sekunda, 1" = 1/15 sekundy
                        dt = ((d1 * 240)+(m1 * 4)+(s1 *(1/15)))-((d2 * 240)+(m2 * 4)+(s2 *(1/15)));
                        t1 = dt/60;
                        //t2 = dt/360;

                        th = (h - (t1/60) - 1);
                        tmin = (60 - (t1%60));

                        Label4->Visible = false;
                        Label5->Caption = FloatToStr(th) + " h " + FloatToStr(tmin) + " min ";
                        Label5->Visible = true;
                        Label6->Caption = FloatToStr(h) + " h " + FloatToStr(min) + " min ";
                        Label6->Visible = true;
                }
                else if (d1 == d2)
                {
                        if (d2 > 0)
                        {
                               if (m1 < m2)
                               {
                                        Label1->Caption = "0°";
                                        Label2->Caption = FloatToStr(d1) + "° " + FloatToStr(m1) + "' " + FloatToStr(s1) + "'' ";
                                        Label3->Caption = FloatToStr(d2) + "° " + FloatToStr(m2) + "' " + FloatToStr(s2) + "'' ";
                                        Label1->Visible = true;
                                        Label2->Visible = true;
                                        Label3->Visible = true;

                                        // 1 stopieñ = 4 min, 1' = 4 sekundy, 15" = 1 sekunda, 1" = 1/15 sekundy
                                        dt = ((d1 * 240)+(m1 * 4)+(s1 *(1/15)))-((d2 * 240)+(m2 * 4)+(s2 *(1/15)));
                                        t1 = dt/60;
                                        //t2 = dt/360;

                                        th = (h - (t1/60));
                                        tmin = (60 - (t1%60) - 60);

                                        Label4->Visible = false;
                                        Label5->Caption = FloatToStr(h) + " h " + FloatToStr(min) + " min ";
                                        Label5->Visible = true;
                                        Label6->Caption = FloatToStr(th) + " h " + FloatToStr(tmin) + " min ";
                                        Label6->Visible = true;
                               }
                               else if (m1 > m2)
                               {
                               }
                               else if (m1 == m2)
                               {
                                        if (s1 < s2)
                                        {
                                        }
                                        else if (s1 > s2)
                                        {
                                        }
                                        else if (s1 == s2)
                                        {
                                        }
                               }
                        }
                        else if (d2 == 0)
                        {
                                if (m1 < m2)
                               {
                               }
                               else if (m1 > m2)
                               {
                               }
                               else if (m1 == m2)
                               {
                                        if (s1 < s2)
                                        {
                                        }
                                        else if (s1 > s2)
                                        {
                                        }
                                        else if (s1 == s2)
                                        {
                                        }
                               }
                        }
                }
        }
        else if (c1 == c2 && c1 == ComboBox1->Items->Strings[0]) //polkula W
        {
                if (d1 < d2 && d1 > 0)
                {
                        Label3->Caption = "0°";
                        Label2->Caption = FloatToStr(d1) + "° " + FloatToStr(m1) + "' " + FloatToStr(s1) + "'' ";
                        Label1->Caption = FloatToStr(d2) + "° " + FloatToStr(m2) + "' " + FloatToStr(s2) + "'' ";
                        Label1->Visible = true;
                        Label2->Visible = true;
                        Label3->Visible = true;

                        // 1 stopieñ = 4 min, 1' = 4 sekundy, 15" = 1 sekunda, 1" = 1/15 sekundy
                        dt = ((d2 * 240)+(m2 * 4)+(s2 *(1/15)))-((d1 * 240)+(m1 * 4)+(s1 *(1/15)));
                        t1 = dt/60;
                        //t2 = dt/360;

                        tpom = (t1 - min);
                        if(tpom >= 60)
                        {
                                th = t1;//(h - (tpom/60));
                                tmin = (tpom%60);
                        }
                        else
                        {
                                th = (h - t2);
                                tmin = (min - t1);
                        }

                        Label4->Visible = true;
                        Label4->Caption = FloatToStr(th) + " h " + FloatToStr(tmin) + " min ";
                        Label5->Visible = true;
                        Label5->Caption = FloatToStr(h) + " h " + FloatToStr(min) + " min ";
                        Label6->Visible = false;

                }
                else if (d1 > d2 && d2 > 0)
                {
                        Label3->Caption = "0°";
                        Label2->Caption = FloatToStr(d2) + "° " + FloatToStr(m2) + "' " + FloatToStr(s2) + "'' ";
                        Label1->Caption = FloatToStr(d1) + "° " + FloatToStr(m1) + "' " + FloatToStr(s1) + "'' ";
                        Label1->Visible = true;
                        Label2->Visible = true;
                        Label3->Visible = true;

                        // 1 stopieñ = 4 min, 1' = 4 sekundy, 15" = 1 sekunda, 1" = 1/15 sekundy
                        dt = ((d1 * 240)+(m1 * 4)+(s1 *(1/15)))-((d2 * 240)+(m2 * 4)+(s2 *(1/15)));
                        t1 = dt/60;
                        //t2 = dt/360;

                        //th = (h + (t1/60) - 1);
                        //tmin = (60 + (t1%60));

                        tpom = (min + t1);
                        if(tpom >= 60)
                        {
                                th = (h + (tpom/60));
                                tmin = (tpom%60);
                        }
                        else
                        {
                                th = (h + t2);
                                tmin = (min + t1);
                        }

                        Label4->Caption = FloatToStr(h) + " h " + FloatToStr(min) + " min ";
                        Label4->Visible = true;
                        Label5->Caption = FloatToStr(th) + " h" + FloatToStr(tmin) + " min ";
                        Label5->Visible = true;
                        Label6->Visible = false;

                }
                else if (d1 == d2)
                {
                        if (d2 > 0)
                        {
                               if (m1 < m2)
                               {
                               }
                               else if (m1 > m2)
                               {
                               }
                               else if (m1 == m2)
                               {
                                        if (s1 < s2)
                                        {
                                        }
                                        else if (s1 > s2)
                                        {
                                        }
                                        else if (s1 == s2)
                                        {
                                        }
                               }
                        }
                        else if (d2 == 0)
                        {
                                if (m1 < m2)
                               {
                               }
                               else if (m1 > m2)
                               {
                               }
                               else if (m1 == m2)
                               {
                                        if (s1 < s2)
                                        {
                                        }
                                        else if (s1 > s2)
                                        {
                                        }
                                        else if (s1 == s2)
                                        {
                                        }
                               }
                        }
                }
        }
        else if (c1 != c2)     //rozne polkule
        {
                if (c1 == ComboBox1->Items->Strings[0]) //c1 == W
                {
                        Label2->Caption = "0°";
                        Label1->Caption = FloatToStr(d1) + "° " + FloatToStr(m1) + "' " + FloatToStr(s1) + "'' ";
                        Label3->Caption = FloatToStr(d2) + "° " + FloatToStr(m2) + "' " + FloatToStr(s2) + "'' ";
                        Label1->Visible = true;
                        Label2->Visible = true;
                        Label3->Visible = true;

                        // 1 stopieñ = 4 min, 1' = 4 sekundy, 15" = 1 sekunda, 1" = 1/15 sekundy
                        dt = ((d1 * 240)+(m1 * 4)+(s1 *(1/15)))+((d2 * 240)+(m2 * 4)+(s2 *(1/15)));
                        t1 = dt/3600;
                        t2 = (dt - (t1 * 3600))/60;

                        th = (h + t1);
                        if(th > 24)
                        {
                                tpom = (min + t2);
                                if(tpom >= 60)
                                {
                                        th = ((h + t1) + (tpom/60)) - 24;
                                        tmin = (tpom%60);
                                }
                                else
                                {
                                        th = (h + t1) - 24;
                                        tmin = (min + t2);
                                }
                        }
                        else
                        {
                                tpom = (min + t2);
                                if(tpom >= 60)
                                {
                                        th = (h + t1) + (tpom/60);
                                        tmin = (tpom%60);
                                }
                                else
                                {
                                        th = (h + t1);
                                        tmin = (min + t2);
                                }
                        }

                        Label4->Caption = FloatToStr(h) + " h " + FloatToStr(min) + " min ";
                        Label4->Visible = true;
                        Label5->Visible = false;
                        Label6->Caption = FloatToStr(th) + " h " + FloatToStr(tmin) + " min ";
                        Label6->Visible = true;

                }
                else if (c1 == ComboBox1->Items->Strings[1]) //c1 == E
                {
                        Label2->Caption = "0°";
                        Label3->Caption = FloatToStr(d1) + "° " + FloatToStr(m1) + "' " + FloatToStr(s1) + "'' ";
                        Label1->Caption = FloatToStr(d2) + "° " + FloatToStr(m2) + "' " + FloatToStr(s2) + "'' ";
                        Label1->Visible = true;
                        Label2->Visible = true;
                        Label3->Visible = true;



                        Label4->Visible = true;
                        Label5->Visible = false;
                        Label6->Caption = FloatToStr(h) + " h " + FloatToStr(min) + " min ";
                        Label6->Visible = true;

                }
        }
}
//---------------------------------------------------------------------------


