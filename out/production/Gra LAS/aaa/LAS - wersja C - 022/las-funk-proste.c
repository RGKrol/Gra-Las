#include <stdio.h>
#include <string.h>		//biblioteka do przetwarzania tekstu
//#include "las.h"


/* ----------------------------------------------------------- */
int wybor(char *tekst,int ilosc_odpowiedzi) 
{ 	//tekst do pytania oraz ilość możliwych odpowiedzi
  int wyborek;
  do
  {
    puts (tekst);
    printf (" gdzie idziesz?  ");
    scanf("%i", &wyborek);
    if (wyborek<1 || wyborek>ilosc_odpowiedzi) puts (" powtórzę pytanie:");
  } while (wyborek<1 || wyborek>ilosc_odpowiedzi);
  return wyborek;
}
//*****************************************************************************
void start_po_wyborze_puci( char p)
{
   switch (p)
   {
   	case 'm':
   		puts ("\n Witam Cię odważny człowieku, cieszymy się, ");
   		puts (" że łaskawie zgodziłeś się podjąć to szlachetne wyzwanie.");
   		puts ("\n Więc przystąpmy do zadania !!! \n\n");
   		break;
   	case 'k':
   		puts ("\n Miło nam, że tak dzielna i światowa Kobieta jak Ty podjęła się");
   		puts (" tego zawiłego wyzwania. Mamy nadzieję, że czekająca Cię przygoda");
   		puts (" wniesie do twojego życia wiele pozytywnych emocji, ");
   		puts (" dzięki którym radośnie odbierzesz proponowaną przez nas przygodę.");
   		puts (" Nie przedłużając, [...] daj się ponieść wydarzeniom !\n\n");
   		break;
   	case 'i':
   		puts ("\n Szlachetna Istoto, jakże miło nam powitać Cię wśród nas.");
   		puts (" Czujemy się zaszczyceni mogąc dołożyć kroplę emocji i zrozumienia,");
   		puts (" do twego istnienia.");
   		puts (" Baw się dobrze przeżywając przedstawioną tu przygodę!");
   		puts (" Powodzenia !!! \n\n");
   		break;
   }

   scanf ("ok? %s", &p);

}
//*****************************************************************************


char wybor_tekst(char *tekst, char *odp)
// tekst - pytanie do gracza
// odp - możliwe jednoliterowe odpowiedzi gracza
{
   char p;	//tu będzie ostateczna odpowiedź gracza
   char p_odp[100];
   int ilosc_odpowiedzi= strlen (odp);
   short int czy_ok=0; 		//0=źle, 1=zgodna - czy odpowiedz jest zgodna ;-)
   
   do
   {
   	printf (" %s ", tekst);
   	scanf ("%99s", p_odp);
   	for (int i=0; i< ilosc_odpowiedzi; i++)
   		if (p_odp[0]==odp[i]) 
   		{
   			czy_ok=1;
   			p=p_odp[0];
   		}
   		
   } while (czy_ok==0);   
   
   start_po_wyborze_puci(p); 
   
   return p;
}
//*****************************************************************************

void koniec (char plec)
{
	switch (plec)
	{
		case 'm':
			puts ("                  !!! BRAWO !!!!");
 			puts (" Udało Ci się opuścić las, wyszedłeś na wielki obszar pokryty polami !");
 			puts (" pola przecinane są wieloma drogami - teraz wystarczy wrócić do domu !!!");
 			puts (" No ale to już inna gra ;-) ");
			break;
		case 'k':
			puts ("                   !!! BRAWO !!!");
			puts (" Opuściłaś ten ciasny, zarośnięty obszar lasu");
			puts (" w którym Znalazłaś się tak niespodziewanie");
			puts (" Twoja intuicja jest NIEZRÓWNANA,");
			puts (" jedynie Kobieta tak znakomicie panująca nad emocjami");
			puts (" mogła znaleźć wyjście z tego labiryntu.");
			puts (" Przed tobą rozpościera się aż po horyzont przepiękna równina");
			puts (" pokryta różnokolorowymi polami, poprzecinanymi fantazyjnie poprowadzonymi drogami");
			puts (" możesz wrócić do domu/cywilizacji, droga wolna ...");
			puts (" ...");
			puts (" Ale, nie widać żadnych drogowskazów, czy żywej duszy.");
			puts (" ...");
			puts (" To jak wrócisz to już inna historia.\n");
			break;
		case 'i':
			puts ("\n              !!! PRZECUDNIE !!!");
			puts ("            !!! Fantastycznie !!!");
			puts ("              !!! KOSMICZNIE !!!\n");
			puts (" Porzuciłaś ten ohydny, odrażający, pełen brutalności");
			puts (" przybytek natury. Pozostawiając za sobą te wspomnienia ");
			puts (" gwałtu na naturze, ohydne zielone pnącza pałętające się pod nogami");
			puts (" i starające się zniszczyć tę Przepiękną Twarz i Ramiona !!!");
			puts (" Twoja Czi i wyczucie Kosmicznej Energii są rewelacyjne !!!");
			puts (" Po wsze czasy bardowie, poeci i YouTub będą chwalić twą odwagę,");
			puts (" zaradność i inne kosmiczne oraz mistyczne przymioty.");
			puts (" Na trwałe wpisałaś się do Księgi Życia !!!");
			puts (" Wszelakosz tylko istota, która za nic ma te ohydne,");
			puts (" staroświeckie i poniżające określenia biologii jednostki");
			puts (" mogła osiągnąć tak wiele w tak krótkim czasie !!!");
			puts ("\n Teraz zostało już tylko obwieścić światu twe czyny.");
			puts (" A fe, cofam to - to kosmos zachwycony twym działaniem ");
			puts (" sam rozniesie po wszechświecie twe czyny.");
			puts (" Wystarczy tylko dotrzeć na plac centralny nagrań YouTub'erów i TikTock'erów");
			puts (" aby mogli podziwiać po wsze czasy twe dokonania.");
			puts (" Zostało tylko pokonać tę nie kończącą się przestrzeń przed Tobą");
			puts (" To jedynie płaski teren upstrzony polami i chaotycznie poprowadzonymi");
			puts (" ... drogami?");
			puts (" To nic trudnego dla tak Cudownej Istoty jak TY !!!");
			puts (" Wystarczy tylko zapytać o drogę ... ");
			puts (" tych niewidocznych nigdzie, prze-nigdzie, ludzi !");
			puts ("\n Ale to, zupełnie inna opowieść.\n");
			break;
	}
}
//*****************************************************************************
