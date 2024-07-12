//---------------------------------------------------------------------------

#include <vcl.h>
#include "Unit2.h"
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit2.cpp", Form2);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 TForm2* SplashScreen = new TForm2(Application);
                 SplashScreen->Show();
                 SplashScreen->Update();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Sleep(3000);
                 delete SplashScreen;
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
