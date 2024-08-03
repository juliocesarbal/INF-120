//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
bool EsLetra(char x)
{ AnsiString L;
  L="aeiouAEIOUáéíóúÁÉÍÓÚüÜQWRTYPSDFGHJKLZXCVBNMqwrtypsdfghjklzxcvbnmÑñ";
  return L.Pos(x)>0;
}
bool EsNumero(char x)
{ AnsiString L;
  L="1234567890";
  return L.Pos(x)>0;
}
 //---------------------------------------------------------------------------
 Word CantidadLin(AnsiString nom)
 { char x; bool sw=false;   Word aux=0;  Word c=0;
   ifstream fi(nom.c_str());
   if(!fi.fail())
   {
	while(!fi.eof())
	{
		c=0;
	   x=fi.get();
	   while(x!=10 && !fi.eof())
	   {
		 if(EsLetra(x) && sw==false)
		 {
		   c++;
		   sw=true;
		 }else if(!EsLetra(x))
		 {
		  sw=false;
		 }
		 x=fi.get();
	   }
	   if(x==10 && sw==true )
	   {
        c++;
	   }
	   if(c>=2)
	   {
		 aux++;
       }
	}
	fi.close();
   }
   return aux;

 }
 //---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	if(OpenTextFileDialog1->Execute())
	{
	  Edit1->Text=OpenTextFileDialog1->FileName;
	  Edit2->Text=CantidadLin(OpenTextFileDialog1->FileName);

    }
}
//---------------------------------------------------------------------------
void EliminarNUm(AnsiString nom)
{char x; bool sw=false;  Word Long=0;  AnsiString s="";
  ifstream fi(nom.c_str());
  ofstream fo("Resultado.txt");
  if(!fi.fail())
  {
	   while (!fi.eof()) {
            s = "";
            Long = 0;
            sw = false;
            x = fi.get();
			while (x != 10 && !fi.eof()) {
				if (EsNumero(x)) {
                    Long++;
				} else {
					Long = 0;
				}
                if (Long >= 4) {
                    sw = true;
                }
                s += x;
                x = fi.get();
			}
            if (!fi.eof()) {
                s += '\n';
            }
			if (!sw) {
                fo << s;
            }
		}
	  fi.close();
      fo.close();
  }
}

//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
  if(OpenTextFileDialog1->Execute())
  {
	  Edit1->Text=OpenTextFileDialog1->FileName;
	  EliminarNUm(OpenTextFileDialog1->FileName);
  }
}
//---------------------------------------------------------------------------
