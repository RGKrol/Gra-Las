package aaa;

public class Las {

    public static void Wstepniak (){
        System.out.println("Witaj w super trudnej i wymagającej grze \n");
        System.out.println("\t\t\t\tLAS\n");
        System.out.println("W grze zostajesz postaciom, która zgubiła się w lesie.");
        System.out.println("Twoje zadanie wydaje się tylko z pozoru łatwe:");
        System.out.println("\t\t--- Wróć do domu ---\n\n");
    }
    public static char Wybor(String pytanie, String mozliweOdpowiedzi){
        while(true){
            System.out.println(pytanie);
            //nie wiem jak zapytać o odpowiedź wiec narazie założę odpowiedź
            String odpGracza = "m";
            if (odpGracza.length()!=1){
                System.out.println("Poproszę o odpowiedź w postaci jednej litery\n");
                continue;
            }
            for(char odpPojedyncza : mozliweOdpowiedzi.toCharArray()){
                if(odpPojedyncza == odpGracza.toCharArray()[0])
                    return odpGracza.toCharArray()[0];
            }
        }
    }
    public static void TekstDoPuci(char plec, String tekstDoWyswietlenia){
        // rozdzielenie tekstu na tablicę tak aby poszczególne puci były rozdzielone
        String [] t = tekstDoWyswietlenia.split("#");
        // wyłapuję interesujący mnie tekst w zależności od puci gracza
        for (String tekst : t){
            if (tekst.toCharArray()[0] == plec) {
                System.out.print(tekst.substring(1, tekst.length()));
                break;  //po co marnować czas skoro interesuje mnie jedna odpowiedź
            }
        }
    }
    public static void WprowadzenieDlaNowejPostaci(char plec){

            TekstDoPuci(plec, "mObudziłeś się #kObudziłąś się #iBudzisz się ");
        System.out.println("w środku lasu. Pamiętasz to miejsce.");
        System.out.print("Dobrze się tu ");
            TekstDoPuci(plec, "mbawiłeś#kbawiłaś#ibawiłaś");
        System.out.println(" wczorajszej nocy. ");
        System.out.print("Ale dlaczego ");
            TekstDoPuci(plec, "mzasnąłeś?#kzasnełaś?#izmużył  oczy?");
        System.out.println(" i dlaczego ci idioci byli tak bezczelni, że nie zabrali Cię ze sobą?\n");

        System.out.println("No dobra, stało się. Trzeba wrócić do domu.");
        System.out.println("Więc gdzie jesteś?\n");

        System.out.println("Stoisz na leśnej polanie,");
        System.out.println("Po środku okrąg z kamieni, wewnątrz którego dogasa ognisko.");
        System.out.println("Trawa wydeptana, kilka kamieni i kłód drewna, które służyły za siedzenia.\n");
        System.out.println("Nigdzie nie widać butelek, puszek, papierków i temu podobnych,");
        System.out.println("no tak śmieci zabrali a o tobie zapominieli :-(\n");

        System.out.println("Ale którędy można stąd wyjść?\n...\n...\no jest !!!\n");

        /*  tu wejście do metody która pozwoli graczowi podjąć decyzję jak opuścić daną lokoację
            tu jest inne wywołanie metody decyzji gracza bo to startowa decyzja i gracz ma dwie możliwości
            "iść na wschód" lub "iść na zachód",
                        potem będzie tu możliwość zawrócenia lub przejścia przez tę polanę na wprost

            metoda przyjmuje:
            String  - opis możliwych wyjść z polany zależny od
                        --- być może z tego zrezygnuję gdyż opisy będą przechowywane gdzie indziej
<<<<<<< HEAD
                        --- docelowo teksty będą przechowywane w bazie danych
            int     - poprzednia pozycja gracza (z kąd przyszedł)
            int     - aktualna pozycja gracza (gdzie doszedł)
            w zależności gdzie jest gracz i jak tam dotarł opisy będą różne !!!
=======
            int     - poprzednia pozycja gracza (z kąd przyszedł)
            int     - aktualna pozycja gracza (gdzie doszedł)
            w zależności gdzie jest gracz i jak tam doszedł opisy będą różne !!!
>>>>>>> github/master
            opis danej lokacji będzie stały ale
                opis możliwych wyjść będzie różny bo w końcu wchodzimy do lokacji z różnej strony
         */
    }

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// main /////////////////////////////
////////////////////////////////////////////////////////////////////////////////
    public static void main(String[] args) {
        Wstepniak();
        Postac postac = new Postac();
        //wybór puci postaci oparty na uniwersalnej metodzie wyboru
        //nie wiem obecnie jak przekazać takie długie treści do metody i ładnie to przedstawić w kodzie
        //
        String tekstDoWyswietlenia = "Potrzebuję znać twoją płeć,\n";
                tekstDoWyswietlenia+="aby wiedzieć jak się do Ciebie zwracać.\n";
                tekstDoWyswietlenia+="Proszę wybierz (m) jeżeli jesteś mężczyzną, (k) jeżeli jesteś kobietą,\n";
                tekstDoWyswietlenia+="(i) jeżeli nie identyfikujesz się z pozostałymi wyborami";

        postac.plec = Wybor(tekstDoWyswietlenia, "mki");

        WprowadzenieDlaNowejPostaci(postac.plec);
        /*
            główna pętla gry
<<<<<<< HEAD
            tu gracz podejmuje decyzje którędy opuścić lokację doputy nie wybierze ścieszki prowadzącej nazewnątrz lasu
=======
            tu gracz podejmuje decyzje którędy opuścić lokację odputy nie wybierze ścieszki prowadzącej nazewnątrz lasu
>>>>>>> github/master
            opis metody w opisie powyższej metody
            te metody powstaną gdy nauczę się pobierać dane od gracza ;-)
         */
    }
}
