
#include <stdio.h>
#include "las.h"


// zmienne globalne:
const float ver=0.022;
const char opis1[]="     - usunięta funkcja >błąd<";
const char opis2[]="     - prosty podział na pliki";
const char opis3[]="     - dodany plik >makefile<" ;
const char opis4[]="";
const char opis5[]="";



struct OpisPostaci 
{
  int pozycja;			//liczbowe oznaczenia pozycji gracza
  int pozycja_stara;		//informacja gdzie gracz był przed chwilą
  char plec;			//przechowóje płeć gracza - m, k, i(inna)
  unsigned int krok;
  
};

struct OpisPostaci Postac;

void start ()
{
 //int WyborGracza=-1; 
 puts ("\n");
 puts ("** Witam w super trudnej i niezwykle wymagającej grze **");
 puts ("\n");
 puts ("             - - - LAS - - - ");
 printf("                wer %.3f \n", ver);
 printf(" %s \n %s \n %s",opis1, opis2, opis3);
 printf(" %s \n %s \n", opis4, opis5);
 puts ("\n\n");
 puts (" Aby rozpocząć grę potrzebuję określić twoją płeć");

		// *#*#*#*#*#*#*#*#*#*#*#*#*
 Postac.plec=wybor_tekst("Jesteś (m) mężczyzną, (k) kobietą, czy (i) kimś innym?","mki");
 		// *#*#*#*#*#*#*#*#*#*#*#*#*
 
 
 printf (" Budzisz się w środku lasu, nie wiesz jak tu ");
 	if (Postac.plec=='m') 
 		puts ("trafiłeś");
 	else
 		puts ("trafiłaś");
 puts (" jesteś na polanie z dużym kamieniem po środku,");
 puts ("");

  switch (wybor(" z polany są dwa wyjścia (1) na wschód i (2) na zachód,",2))
  {
    case 1: //wschód
      Postac.pozycja=1; 
      Postac.pozycja_stara=0;
      break;  
    case 2: //zachód
      Postac.pozycja=2;
      Postac.pozycja_stara=0;
      break;

  }
}
//*****************************************************************************
void gra() 
{
 Postac.krok = 1; 	//startowy krok 
do 
{
  switch (Postac.pozycja) 
  {
  	case 0:	//startowa polana 00
  	  if (Postac.plec=='m') 
  	  	printf (" Dotarłeś");
  	  else
  	  	if (Postac.plec=='k') 
  	  		printf (" Dotarłaś");
  	  	else
  	  		printf (" O szlachetna istoto, dotarłaś");
  	  puts (" do polany z dużym kamieniem na środku --- 00 ---");
  	  switch(Postac.pozycja_stara)
  	  {
  	     case 1:
		switch (wybor (" przez polankę można przejść (1) na wprost, lub (2) zawrócić,", 2))
		{
			case 1: Postac.pozycja=2; break;
			case 2: Postac.pozycja=1; break;
      		}
      		break;
              case 2:
                 switch (wybor (" przez polankę można przejść (1) na wprost, lub (2) zawrócić,", 2) )
                 {
                  	case 1: Postac.pozycja=1; break;
                  	case 2: Postac.pozycja=2; break;

                 }
                 break;
      	  } //koniec switcha dla Postac.pozycja_stara
      	  Postac.pozycja_stara=0;
      break; // koniec switch dla polany startowej 00
    case 1:	//wchodnia polana 01
      if (Postac.plec=='m')
      	puts (" Dotarłeś do niewielkiej polanki z wielkim dębem po środku --- 01 ---");
      else
        if (Postac.plec=='k')
          puts (" W swej Przepiękności zaszczyciłaś polankę z wielkim dębem po środku --- 01 ---");
        else
          puts (" O czująca istoto niech mi będzie wolno wprowadzić Cię na tę polanę. \n O tu jest wielki dąb po środku a tam są ścieżki, --- 01 --- ");
          
      switch (Postac.pozycja_stara) 
      {
        case 0:	//przyszedł ze startu 00-->01
          Postac.pozycja_stara=1;
          switch (wybor(" z polanki można wyjść przechodząc ją (1) na wprost, (2) idąc w lewo lub (3) zawracając", 3)) 
          {
            case 1: Postac.pozycja=3; break;		//idzie do północnej polany 3	
            case 2: Postac.pozycja=2; break;		//idzie do zachodniej polany 2
            case 3: Postac.pozycja=0; break; 		//idzie do startowej polany 0

          }
          break;
        
        case 2:	//przyszedł z zachodu 02 --> 01
          Postac.pozycja_stara=1;
          switch (wybor(" z polanki można wyjść przechodząc ją (1) w prawo, (2) w lewo lub (3) zawracając", 3))
          {
            case 1: Postac.pozycja=0; break;		//idzie do startowej polany 0	
            case 2: Postac.pozycja=3; break;		//idzie do północnej polany 3
            case 3: Postac.pozycja=2; break; 		//idzie do zachodniej polany 2

          }
          break;
         
        case 3: //przyszedł z północy 03 --> 01
          Postac.pozycja_stara=1;
         switch (wybor(" z polanki można wyjść przechodziąc ją (1) w prawo, (2) na wprost lub (3) zawracając", 3))
          {
            case 1: Postac.pozycja=2; break;	
            case 2: Postac.pozycja=0; break;	
            case 3: Postac.pozycja=3; break; 	

          }

          break;
        }  
      break;	// koniec switch dla polany wschodniej 01
    case 2: 	//zachodnia polana 02
      if (Postac.plec=='m')
      	puts (" Doszedłeś do polany z niewielkim wzniesieniem po środku --- 02 ---");
      else
      	puts (" Dotarłaś do polany na której po środku łaskawie ustawił się niewielki pagórek --- 02 ---");
      
      //w zależności od tego z kąd przyszedłem są inne wyjścia:
      switch (Postac.pozycja_stara) 
      {
        case 0: 	// 00-->02
          switch(wybor(" z polanki można wyjść (1) skręcając na niej w prawo, (2) przechodząc ją na wprost lub (3) zawracając,", 3))
          {
            case 1: Postac.pozycja=1; break;
            case 2: Postac.pozycja=3; break;
            case 3: Postac.pozycja=0; break;

          }
          break;
        case 1:		// 01-->02
          switch(wybor(" z polanki można wyjść (1) skręcając na niej w prawo, (2) skręcając na niej w lewo lub (3) zawracając,", 3))
          {
            case 1: Postac.pozycja=3; break;
            case 2: Postac.pozycja=0; break;
            case 3: Postac.pozycja=1; break;

          }
          break;
        case 3: 	// 03-->02
          switch(wybor(" z polanki można wyjść (1) skręcając na niej w lewo, (2) przechodząc ją na wprost lub (3) zawracając,", 3))
          {
            case 1: Postac.pozycja=1; break;
            case 2: Postac.pozycja=0; break;
            case 3: Postac.pozycja=3; break;

          }
          break;
      } 
      Postac.pozycja_stara=2;
      break; //koniec switch dla polany zachodniej 02
    case 3:	//północna polana 03
      switch (Postac.plec)
      {
      	case 'm':
      		puts (" Dotarłeś do polany powstałej przez wyrąb lasu, na środku jest złożone drzewo --- 03 ---");
      		break;
      	case 'k':
      		puts (" Przed tobą otwiera się malownicza przestrzeń z ułożonym stosem pni po środku");
      		puts (" z mnóstwem przepięknych stołków z pni i malowniczo porozrzucanych gałęzi.");
      		puts (" Całość stanowi wzruszający obraz \"Wyrąb lasu\" --- 03 ---"); 
      	case 'i':
      		puts (" Z przerażeniem odkrywasz zbezczeszczoną przez ludzkie istoty przestrzeń lasu");
      		puts (" - te bezduszne istoty zabiły kilkudziesięciu przedstawicieli flory");
      		puts (" nazywanej przez nich \"drzewami\".");
      		puts (" Tylko po to by ułożyć je w stos na środku tego obszaru pełnego konających w cierpieniach konarów. --- 03 ---");  
      		break;
      }
      	
      //w zależności od tego z kąd przyszedłem są inne wyjścia:
      switch (Postac.pozycja_stara) 
      {
        case 1: 	// 01 --> 03
	  switch(wybor(" z polanki można wyjść (1) skręcając w lewo, (2) skręcając w prawo lub (3) zawracając", 3))
	  {
	    case 1: Postac.pozycja=2; break;
	    case 2: Postac.pozycja=99; break;
	    case 3: Postac.pozycja=1; break;

	  }
	  break;
        case 2:		// 02 --> 03
	  switch(wybor(" z polanki można wyjść (1) skręcając w lewo, (2) skręcając w prawo lub (3) zawracając,", 3))
	  {
	    case 1: Postac.pozycja=99; break;
	    case 2: Postac.pozycja=1; break;
	    case 3: Postac.pozycja=2; break;

	  }
          break;
 
      break;	//koniec polany północnej 03
  
      puts ("coś tu nie gra !!!, nie powinieneś tego widzieć, zgłoś błąd do dewelopera");
      puts ("");
  }
  Postac.pozycja_stara=3;

  }
} while (Postac.pozycja<99);
 
 koniec(Postac.plec);
 

}

